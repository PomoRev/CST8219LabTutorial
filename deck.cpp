/*  Card library for the Card Deck Project
 *  Prof. Frank Emanuel (c) 2021
 *  CST8219 C++
 * 
 *  deck.cpp : defines the member functions for deck.h
 * 
 * 
 */

#ifndef DECK
    #define DECK
    #include "deck.h"
#endif

#ifndef IOSTREAM
    #define IOSTREAM
    #include <iostream>
#endif

#ifndef STRING
    #define STRING
    #include <string>
#endif

#ifndef VECTOR
    #define VECTOR
    #include <vector>
#endif

using namespace std;
using namespace CARDDECK;


// definitions of card member functions

// getters for card object

short card::getSuit() { return suit; }

short card::getValue() { return value; }

string card::getSuitName() {

    string suitName;

    switch (getSuit())
    {
    case SPADES:
        suitName = "Spades";
        break;
    case CLUBS:
        suitName = "Clubs";
        break;
    case DIAMONDS:
        suitName = "Diamonds";
        break;
    case HEARTS:
        suitName = "Hearts";
        break;
    case JOKER:
        suitName = "Joker";
        break;
    }

    return suitName;

}

string card::getValueName() {

    // this function will return the text of the value, using a number fo the numbers
    // and the word for the special cards.

    string valueName;

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
            valueName = to_string(getValue());       
    }

    return valueName;

}

// utility functions for card object

void card::showCardText(){

    // displays the card on the screen as text

    if (suit == JOKER) std::cout << getSuitName();
    else std::cout << getValueName() << " of " << getSuitName();

}

deck::deck(int deckSize){

    this->deckSize = deckSize;
    resetDeck();

}

void deck::resetDeck(){

    // creates a card for each suit of each value (ACE to KING) and creates any necessary jokers
    // from 1 to 13 in each suit (4) = 52 cards, any remaining are jokers at this point.
   
    // resets the deck of cards collection to empty

    if(!deckOfCards.empty()) deckOfCards.resize(0); 

    if ( (deckSize - 52) > 0 ){
    
        // create jokers with the rest of the cards

        for (int i = (deckSize - 52); i > 0; i--)
        {
            // make some jokers
        
            deckOfCards.push_back( card() );
        }
    }    

    // create the rest of the cards

    for (int i = 0; i < 4; i++ ){

        // outer loop for suits

        for (int j = ACE; j <= KING; j++){

            // inner loop for values

            deckOfCards.push_back( card(i, j) );

            // cout << "pushed a card";

        }

    }

}


void deck::showDeckText(){

    // print out the deck in text

    cout << "My deck: ";

    for (card i : deckOfCards){

        i.showCardText();
        cout << "  ";

    }

    cout << endl;

}