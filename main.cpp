/* Class Building Test File for Card Deck Project
 * Prof. Frank Emanuel (c) 2021
 * CST8219 C++
 * 
 * main.cpp : Initial Testing File (CODE TO TEST)
 * 
 */

#ifndef IOSTREAM
    #define IOSTREAM
    #include <iostream>
#endif

#ifndef DECK_H
    #define DECK_H
    #include "deck.h"
#endif

using namespace std;
using namespace playingcards;

int main(int argc, char const *argv[])
{

    deck myDeck(56);
    //myDeck.showDeck();
    myDeck.shuffle();
    //myDeck.showDeck();

    cout << "draw a Card and display it" << endl;

    card FirstCard = myDeck.drawCard();
    card SecondCard = myDeck.drawCard();

    FirstCard.showCard();
    SecondCard.showCard();
    
    cout << "My two cards are: " << FirstCard << " and " << SecondCard << endl;
    
    // cout << "Copy second card into first card, this is the first card: ";

    // FirstCard = SecondCard;
    // FirstCard.showCard();

    cout << endl;

    hand myHand;

    myHand.addCard( myDeck.drawCard() );
    myHand.addCard( myDeck.drawCard() );
    myHand.addCard( myDeck.drawCard() );
    myHand.addCard( myDeck.drawCard() );
    myHand.addCard( myDeck.drawCard() );
    myHand.addCard( myDeck.drawCard() );

    myHand.showHand();

    cout << "unsorted" << endl;

    myHand.sortHand(BYVALUEASC);

    myHand.showHand();

    cout << "sorted" << endl;

    myHand.sortHand(BYVALUEDESC);

    myHand.showHand();

    cout << "sorted" << endl;

    myHand.sortHand(BYSUIT);

    myHand.showHand();

    cout << "sorted" << endl;

    hand myOtherHand;

    myOtherHand.addCard ( myHand.playCard(0) );

    myOtherHand.showHand();

    cout << endl;

    myHand.showHand();

    cout << endl;   

    // show deck with removed cards

    //myDeck.showDeck();

    cout << endl;

    return EXIT_SUCCESS;
}



