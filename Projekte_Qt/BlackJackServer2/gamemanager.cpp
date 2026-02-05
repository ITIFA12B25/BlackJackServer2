#include "gamemanager.h"
#include <QRandomGenerator>

//GameManager::GameManager() = default;

QString GameManager::newId() const
{
    // Zufällige 6-stellige ID (Prototyp)
    const int n = QRandomGenerator::global()->bounded(100000, 999999);
    return QString::number(n);
}

QString GameManager::createGame()
{
    // Solange neue ID erzeugen, bis sie frei ist
    QString id;
    do { id = newId(); } while (m_games.contains(id));

    // Neuen leeren Zustand speichern
    m_games.insert(id, GameState{});
    return id;
}

bool GameManager::exists(const QString& gameId) const
{
    return m_games.contains(gameId);
}

GameState* GameManager::state(const QString& gameId)
{
    // nullptr, wenn Spiel nicht existiert
    if (!m_games.contains(gameId)) return nullptr;
    return &m_games[gameId];
}
