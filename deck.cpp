/* Library Member Function Definitions for the Card Deck Project
 * Prof. Frank Emanuel (c) 2021
 * CST8219 C++
 * 
 * deck.cpp : defines all of the member functions declared in deck.h
 * 
 */


#ifndef DECK_H
    #define DECK_H
    #include "deck.h"
#endif

using namespace playingcards;

// Member functions for the class card

card::card(short suit, short value){

    this->suit = suit;
    this->value = value;

}

card::card() : card (JOKER, 0) {}

// Setters & Getters

short card::getSuit(){ return suit; }

std::string card::getSuitName(){

    std::string suitName = "No Suit";

    switch (suit){

        case SPADES: 
            suitName = "Spades";
            break;
        case DIAMONDS: 
            suitName = "Diamonds";
            break;          
        case CLUBS: 
            suitName = "Clubs";
            break;
        case HEARTS: 
            suitName = "Hearts";
            break;
        case JOKER: 
            suitName = "Joker";

    }

    return suitName;

}

short card::getValue(){ return value; }

std::string card::getValueName(){

    std::string valueName;

    switch (getValue())
    {
        case ACE:
            valueName = "Ace";
            break;
        case JACK:
            valueName = "Jack";
            break; 
        case QUEEN:
            valueName = "Queen";
            break; 
        case KING:
            valueName = "King";
            break; 

        default:
            valueName = std::to_string(getValue());
            break;
    }

    return valueName;

}

card card::operator= (const card& toAssign){

    // Allows us to copy a card into another card.

    suit = toAssign.suit;
    value = toAssign.value;

    return *this;
}

// Utility Methods

void card::showCard(){

    if (getSuit() == JOKER)
        std::cout << "The card is a " << getSuitName() << std::endl;
    else 
        std::cout << "The card is: " << getValueName() << " of " << getSuitName() << std::endl;

}