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

#ifndef VECTOR
    #define VECTOR
    #include <vector>
#endif

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

// constant values for decks

    const short STANDARDDECK = 52;

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

        card(short suit, short value);
        card();
        ~card(){}

        // Getters and Overloaded Operators

        short getSuit() const;
        std::string getSuitName() const;
        short getValue() const;
        std::string getValueName() const;
        card operator= (const card &);
        friend std::ostream & operator<< (std::ostream &, const card &);

        // Utility Methods

        void showCard();

    };

/*  Class: playingcards::deck
 * 
 *  Creates a deck of playing cards for use with a card game.
 *    
 *  Data members: vector of cards
 *  Member functions: resetDeck, shuffle, showDeck, drawCard, numberCardsLeft
 *  
 */

    class deck
    {

    private:
        std::vector<card> cards;
        int numberCardsFullDeck;

    public:

        // Constructors and Destructor

        deck(int numberCards = STANDARDDECK);
        ~deck(){};

        // utility functions

        void resetDeck();        
        void shuffle();
        void showDeck();
        card drawCard(); // removes a card from the deck and returns it to the calling environment
        int numberCardsLeft();        

    };
    
}