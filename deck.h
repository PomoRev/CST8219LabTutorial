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

#ifndef VECTOR
    #define VECTOR
    #include <vector>
#endif

namespace CARDDECK{

// Deck Related Constants

    enum { SPADES = 0, DIAMONDS, HEARTS, CLUBS, JOKER };
    enum { ACE = 1, JACK = 11, QUEEN, KING };

/*  Class: CARDDECK::card
 * 
 *  To create an individual playing card.
 *  
 *  Data members: suit, value
 *  Methods:
 *      showCardText  - displays a card
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

        short getSuit();
        std::string getSuitName();
        short getValue();
        std::string getValueName();

        // Utility Methods

        void showCardText();

    };

/*  Class: CARDDECK::deck
 * 
 *  To create a deck of playing cards.
 *  
 *  Data members: vector of cards, number of card remainig
 *  Methods:
 *      showDeckText    - displays all the remaining cards in the deck
 *      resetDeck       - (re)creates the deck at the deck's size
 *      shuffle         - randomized the deck
 *      drawCard        - removes a card from the deck returning it as an object
 *      numberOfCards   - returns the number of cards remaining in the deck
 * 
 */ 

    class deck {

    private:
        
        std::vector<card> deckOfCards;  // the cards for the deck        
        int deckSize;                   // the size of the deck for building deck

    public:

        // constructor and destructor

        deck(int deckSize = 52);
        ~deck() {};

        // utility member functions

        void resetDeck();
        void showDeckText();
       
    };

/*
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