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
    enum { SUIT, VALUE_ASC, VALUE_DESC };

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

        short getSuit() const;
        std::string getSuitName() const;
        short getValue() const;
        std::string getValueName() const;

        // Utility Methods

        void showCardText();
        friend std::ostream & operator << (std::ostream &, const card &);

    };

/*  Class: CARDDECK::deck
 * 
 *  To create a deck of playing cards.
 *  
 *  Data members: vector of cards, number of card remaining
 *  Methods:
 *      showDeckText    - displays all the remaining cards in the deck (test)
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
        void shuffleDeck(int numberOfTimes = 1);
        card drawCard();
        int numberOfCards() const;
       
    };

/*  Class: CARDDECK::hand
 * 
 *  To create a hand of playing cards which is a smaller collection (subset) from the deck
 *  that allow us to build individual hands for players, kitties, mucks, etc. 
 *  
 *  Data members: vector of cards
 * 
 *  Methods:
 *      get numbercards - returns the number of cards currently in hand
 *      get card index  - return the index of a card or -1 when not found.
 *      add card        - adds a card to the hand
 *      show hand       - reveal the hand to the player (or some kind of output)
 *      play card       - removes a card from the hand returning it to the calling environment
 *      sort hand       - sorts the hand of cards by the value 
 *                      - sorts the hand of cards by the suit
 *      discard card    - removes a cards from the hand ??? is this the same as play card where return is ignored?
 *      discard hand    - removes all cards from the hand
 * 
 */ 

    class hand
    {
    private:

        std::vector<card> handOfCards;  // the cards for the hand

    public:

        // constructor and destructor

        hand(){};
        hand(card);
        ~hand() {};

        // getters and setters

        inline int getNumberCards() const {
            return handOfCards.size();
        }
        int getCardIndex(short suit, short value);

        void addCardToHand(card);

        // utility functions

        void showHandText();
        card playCard(int index);
        void sortHand(short typeOfSort);
        void discardCard(int index);
        void discardHand();

    };

}