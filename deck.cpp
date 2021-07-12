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
//

card::card(short suit, short value){

    this->suit = suit;
    this->value = value;

}

card::card() : card (JOKER, 0) {}

// Setters & Getters

short card::getSuit() const { return suit; }

std::string card::getSuitName() const {

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

short card::getValue() const { return value; }

std::string card::getValueName() const {

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

std::ostream & playingcards::operator << (std::ostream & out, const card & cardToPrint) { 

    if (cardToPrint.getSuit() == JOKER) out << "Joker";
    
    else out << cardToPrint.getValueName() << " of " << cardToPrint.getSuitName(); 

    return out;

}

// Member functions for the class deck
//

deck::deck(int numberCards){

    numberCardsFullDeck = numberCards;

    // 52 card deck (standard) make cards from ACE to KING in each of four suits

    if (numberCards == STANDARDDECK){

        for (int i = 0; i < 4; i++){ // loop throught the suits

            for ( int j = ACE; j < (KING + 1); j++ ){ // loop through the card denominations

                cards.push_back(card(i,j));

            }

        }
    }

}

// utility functions

void deck::showDeck(){

    std::cout << "Deck contains: ";

    for (int i = 0; i < numberCardsLeft(); i++ ){

        std::cout << cards[i];

        (i < numberCardsLeft() - 1) ? std::cout << ", " : std::cout << "." << std::endl;

    }

}

int deck::numberCardsLeft(){

    return cards.size();

}

void deck::shuffle(){

    // randomly place each card into the deck (numberofcards left)

    std::srand(time(NULL));

    for (int shuffleTime = 0; shuffleTime < 4; shuffleTime++){

        for (int i = 0; i < numberCardsLeft(); i++){

            int offSet = (std::rand() % numberCardsLeft());
            std::swap(cards[i], cards[offSet]);

        }

    }
}


        // void resetDeck();        
        // card drawCard(); // removes a card from the deck and returns it to the calling environment
