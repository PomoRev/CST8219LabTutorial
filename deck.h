/* Class Building Test File for Card Deck Project
 * Prof. Frank Emanuel (c) 2021
 * CST8219 C++
 * 
 * deck.h : card, deck, and hand object library
 */

//  library include guard

#pragma once

//  prototype header guard for including libraries

#ifndef IOSTREAM
    #define IOSTREAM
    #include <iostream>
#endif

#ifndef STRING
    #define STRING
    #include <string>
#endif

// set up environment

using namespace std;

namespace playingcards{

// constant values for suits

    const short SPADES = 0;
    const short HEARTS = 1;
    const short CLUBS = 2;
    const short DIAMONDS = 3;
    const short JOKER = 4;

// constant values for card special card values

    const short ACE = 1;
    const short JACK = 11;
    const short QUEEN = 12;
    const short KING = 13;

/*  Class: playingcards::card
 * 
 *  Creates an individual card which has a suit and a value.
 *    
 *  Data members: suit (short), value (short)
 *  Member functions: showCard, getSuit, getSuitName, getValue, getValueName, getCard 
 *  
 */

    class card{

    private:
        short suit;
        short value;

    public:

        // Constructors & Destructor

        card(short suit, short value){

            this->suit = suit;
            this->value = value;

        }

        card(){

            // by default make a joker

            suit = JOKER;
            value = 0;

        }

        ~card(){}

        // Setters & Getters

        short getSuit(){ return suit; }

        string getSuitName(){

            string suitName = "No Suit";

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

        short getValue(){ return value; }

        // Utility Methods

        void showCard(){

            if (getValue() > 0)
                cout << "The card is: " << getValue() << " of " << getSuitName() << endl;
            else 
                cout << "The card is a " << getSuitName() << endl;

        }

    };

}