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

using namespace std;
using namespace CARDDECK;


// definitions of card member functions

// getters for card object

// card card::getCard(){
//     return *this;
// }

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


// utility functions for card object

void card::showCard(){

    // displays the card on the screen

//    std::cout << getValueName() << " of " << getSuitName();

}



