#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QJsonArray>
#include <QHash>
#include <QPointer>
#include <QString>

#include "deck.h"
#include "hand.h"

class GameSession; // Vorwärtsdeklaration: Klasse ist woanders definiert

// Spielphase im Room (einfacher Status vom Spiel)
enum class GamePhase { WaitingForPlayers, Playing, Finished };

// Zustand eines Spielers im Room (Name + Karten + ob er schon stand/bust ist)
struct PlayerState {
    QString name;        // Spielername
    Hand hand;           // Karten auf der Hand
    bool stood = false;  // true = Spieler hat "stand" gemacht oder ist bust
};

// Gemeinsamer Room (Model A): 2 Spieler + Dealer + Deck
struct RoomState {
    QString roomId;  // eindeutige ID vom Room

    Deck deck;       // gemeinsamer Kartenstapel
    Hand dealer;     // Dealer-Hand

    PlayerState players[2];              // Spieler 0 und Spieler 1
    QPointer<GameSession> sessions[2];   // Session-Pointer für Broadcast an Clients

    GamePhase phase = GamePhase::WaitingForPlayers; // Startzustand: wartet auf Spieler
};

class GameManager
{
public:
    GameManager() = default; // Standard-Konstruktor

    // Room-Liste für den Client (JoinRoom) als JSON-Array
    QJsonArray roomsToJson() const;

    // Erstellt einen neuen Room und setzt den Ersteller als Spieler 0
    QString createRoom(GameSession* creatorSession, const QString& creatorName);

    // Spieler 1 tritt bei; wenn beide Spieler da sind, startet das Spiel
    bool joinRoom(const QString& roomId,
                  GameSession* joinerSession,
                  const QString& joinerName,
                  QString* errorOut = nullptr);

    // Zugriff auf einen RoomState per roomId (nullptr wenn nicht gefunden)
    RoomState* room(const QString& roomId);

    // Prüft, ob ein Room existiert
    bool roomExists(const QString& roomId) const;

    // Entfernt eine Session aus dem Room (z.B. bei Disconnect oder Leave)
    void leaveBySession(GameSession* s);

    // Sucht zu einer Session den Room und den Sitzplatz (0/1)
    bool findSeat(GameSession* s, QString* roomIdOut, int* seatOut) const;

    // Speichert Gewinner/Ergebnis in eine CSV-Datei (Server-Log)
    void appendWinnerCsv(const QString& roomId,
                         const QString& playerName,
                         const QString& outcome,
                         int playerTotal,
                         int dealerTotal);

private:
    // Alle Rooms: Key = roomId, Value = RoomState
    QHash<QString, RoomState> m_rooms;

    // Erzeugt eine zufällige 6-stellige ID für roomId
    QString newId() const;
};

#endif // GAMEMANAGER_H
