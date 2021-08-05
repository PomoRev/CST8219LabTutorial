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

#ifndef RANDOM
    #define RANDOM
    #include <random>
#endif

using namespace std;
using namespace CARDDECK;


// definitions of card member functions

// getters for card object

short card::getSuit() const { return suit; }

short card::getValue() const { return value; }

string card::getSuitName() const {

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

string card::getValueName() const {

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

ostream & CARDDECK::operator << (ostream & out, const card & cardToPrint){

    if (cardToPrint.getSuit() == JOKER) out << cardToPrint.getSuitName();
    else out << cardToPrint.getValueName() << " of " << cardToPrint.getSuitName();

    return out;

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

        cout << "  " << i;

    }

    cout << endl;

}

void deck::shuffleDeck(int numberOfTimes){

    // This function will randomize our vector of cards numberOfTimes amount of times
    // using the shuffle() from <random>.
    // 

    for (int i = 0; i < numberOfTimes; i++){
        std::random_device rd;
        std::default_random_engine rng(rd());
        shuffle(deckOfCards.begin(), deckOfCards.end(), rng); 
    }   

}

int deck::numberOfCards() const{

    // simply returns the number of cards left in the deck.

    return deckOfCards.size();

}

card deck::drawCard() {

    // draws the last card of the deck, removing it from the deck and 
    // returning it to the calling environment.
    // place a guard around this when you call it if it is possible the deck is depleted.

    card cardToDraw = deckOfCards.back();
    deckOfCards.pop_back();
    return cardToDraw;

}

hand::hand(card firstCard){

    handOfCards.push_back(firstCard);

}

int  hand::getCardIndex(short suit, short value){

    // search for the index of a specific card and if found return
    // its index in the vector, otherwise return -1

    int index = -1, currentCard = 0;


    while ((currentCard < getNumberCards()) && (index == -1) ){

        card cardToCheck = handOfCards[currentCard];

        if (cardToCheck.getValue() == value){

            if (cardToCheck.getSuit() == suit){

                index = currentCard;

            }

        }

        currentCard++;

    }

    return index;

}

void hand::addCardToHand(card cardToAdd){

    // adds a card to the hand vector

    handOfCards.push_back(cardToAdd);

}

void hand::showHandText(){

    // print out the deck in text

    cout << "My hand: ";

    for (card i : handOfCards){

        cout << " " << i;

    }

    cout << endl;

}

card hand::playCard(int index){

    // Using the index we will remove the card returning a copy to
    // to the calling environment. 

    card playedCard(handOfCards[index].getSuit(), handOfCards[index].getValue());
    handOfCards.erase(handOfCards.begin() + index);

    return playedCard;

}

void hand::sortHand(short typeOfSort){

    // Use bubble sort to arrange the cards in a hand in the following orders:
    // SUIT (by value ascending and then grouped by suit)
    // VALUE_ASC (by value from small to large)
    // VALUE_DESC (by value from large to small)

    if ((typeOfSort == SUIT) || (typeOfSort == VALUE_ASC)){

        // 2, 4, 6, 3, 1
        // 1, 4, 6, 3, 2
        // 1, 3, 6, 4, 2 -> 1, 2, 6, 4, 3
        // 1, 2, 4, 6, 3 -> 1, 2, 3, 6, 4
        // 1, 2, 3, 4, 6

        // [HEAD]   -> compare with remaining cards in vector [HEAD +  1-end] when card[0] < card[0+#] then swap

        for (int head = 0; head < (handOfCards.size() -1); head++ ){

            // outer loop governs which left side card we are comparing

            for (int inside = head + 1; inside < (handOfCards.size()); inside++ ){

                // inner loop compares the head card with each subsequent card in the vector

                if (handOfCards[head].getValue() > handOfCards[inside].getValue()) swap(handOfCards[head], handOfCards[inside]);

            }
        }

        if (typeOfSort == SUIT){

            // group by suit

            for (int head = 0; head < (handOfCards.size() -1); head++ ){

            // outer loop governs which left side card we are comparing

                for (int inside = head + 1; inside < (handOfCards.size()); inside++ ){

                    // inner loop compares the head card with each subsequent card in the vector

                    if (handOfCards[head].getSuit() > handOfCards[inside].getSuit()) swap(handOfCards[head], handOfCards[inside]);

                }
            }

        }

    } else {

        for (int head = 0; head < (handOfCards.size() -1); head++ ){

            // outer loop governs which left side card we are comparing

            for (int inside = head + 1; inside < (handOfCards.size()); inside++ ){

                // inner loop compares the head card with each subsequent card in the vector

                if (handOfCards[head].getValue() < handOfCards[inside].getValue()) swap(handOfCards[head], handOfCards[inside]);

            }
        }

    }

    return;
}