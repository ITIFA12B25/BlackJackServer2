#ifndef GAMEMANAGER_H

#define GAMEMANAGER_H

#include <QHash>

#include <QString>

// Sehr einfacher Spielzustand (nur Totals für Prototyp)

struct GameState {

    int playerTotal = 0;
    int dealerTotal = 0;
    bool finished = false;

};

class GameManager

{
public:

    GameManager() = default;
    QString createGame();

    // Prüfen, ob gameId existiert

    bool exists(const QString& gameId) const;

    // Spielzustand holen

    GameState* state(const QString& gameId);

private:

    // Speichert alle Spiele: gameId -> GameState

    QHash<QString, GameState> m_games;

    // Erzeugt eine einfache ID

    QString newId() const;

};

#endif // GAMEMANAGER_H

