#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <QVector>
#include <QRandomGenerator>
// Repräsentiert ein Karten-Deck für Blackjack
class Deck
{
public:
     // Konstruktor: initialisiert ein neues gemischtes Deck
    Deck() { reset(); }
 // Erstellt ein neues 52-Karten-Deck und mischt es
    void reset()
    {
        // Standard-52-Karten-Deck erzeugen
        m_cards.clear();
        m_cards.reserve(52);

        const Suit suits[] = {Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades};
        const Rank ranks[] = {
            Rank::Two, Rank::Three, Rank::Four, Rank::Five, Rank::Six, Rank::Seven,
            Rank::Eight, Rank::Nine, Rank::Ten, Rank::Jack, Rank::Queen, Rank::King, Rank::Ace
        };

        for (Suit s : suits) {
            for (Rank r : ranks) {
                m_cards.push_back(Card{s, r});
            }
        }

        shuffle();
        m_index = 0;
    }

    // Mischt die Karten (Fisher–Yates)
    void shuffle()
    {
        // Fisher–Yates Shuffle
        for (int i = m_cards.size() - 1; i > 0; --i) {
            int j = QRandomGenerator::global()->bounded(i + 1);
            m_cards.swapItemsAt(i, j);
        }
    }

    Card draw()
    {
        // Wenn Deck leer -> neu mischen (Prototyp)
        if (m_index >= m_cards.size()) {
            reset();
        }
        return m_cards[m_index++];
    }

private:
    QVector<Card> m_cards;
    int m_index = 0;
};

#endif
