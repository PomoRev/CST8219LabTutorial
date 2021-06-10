/* Class Building Test File for Card Deck Project
 * Prof. Frank Emanuel (c) 2021
 * CST8219 C++
 * 
 * deck.h : card, deck, and hand object library
 */

#ifndef STRING
    #define STRING
    #include <string>
#endif

namespace CARDDECK{

// Deck Related Constants

enum { SPADES = 0, DIAMONDS, HEARTS, CLUBS, JOKER };
enum { ACE = 1, JACK = 11, QUEEN, KING };

/*  Class: DECK::card
 * 
 *  To create an individual playing card.
 *  
 *  Data members: suit, value
 *  Methods:
 *      showCard      - displays a card
 *      getCard       - returns a card object
 *      getSuit       - returns the suit value
 *      getSuitName   - returns a string of the card name
 *      getValue      - returns the denomination of the card as a value
 *      getValueName  - returns a string of the card's suit name
 */

    class card{

    private:

        short value;    // this is the denomination of the card: A through KING
        short suit;     // this is the suit of the card: hearts, spades, clubs, diamonds

    public:

        // Constructors & Destructor

        card(short cardSuit, short cardValue){ suit = cardSuit; value = cardValue;};
        card() : card ( JOKER, 0){};
        ~card() {};

        // Setters & Getters

  //      card getCard();
        short getSuit();
        std::string getSuitName();
        short getValue();
 //      std::string getValueName();

        // Utility Methods

        void showCard();

    };


   

/*
    card deck
    // private data

        collection of cards

    // constructors - deconstructor

        constructors for different numbers of cards

    // utility functions: show deck (test), shuffle deck, draw card, reset deck

        show deck
        shuffle
        draw
        reset


    card hand
    // private

        collection of cards

    // constructors - deconstructor

        constructor for no cards
        constructor with one card to start
        constructor with a hand of cards

    // utility functions: show hand, play card, sort by suit, sort by value, discard cards


        show hand
        play card
        sort by value
        sort by suit
        discard cards
        discard hand */

}