/* Class Building Test File for Card Deck Project
 * Prof. Frank Emanuel (c) 2021
 * CST8219 C++
 * 
 * main.cpp : Initial Testing File (CODE TO TEST)
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

using namespace std;
using namespace CARDDECK;

int main (int argCount, char* argValues[]){  

    card myCard;
    card myOtherCard( HEARTS, 5);

    cout << "this is my card : " << myCard.getSuitName() << endl;
    cout << "this is my other card : " << myOtherCard.getValueName() 
         << " of " << myOtherCard.getSuitName() << endl;

    cout << "put another way : "; 
    myOtherCard.showCardText();
    cout << endl;

    deck aDeck;
    aDeck.showDeckText();

    aDeck.shuffleDeck();

    cout << "shuffled "<< aDeck.numberOfCards() << " cards to get " << endl;
    aDeck.showDeckText();

    cout << "take these cars: " << aDeck.drawCard() << " and " << aDeck.drawCard() << "." << endl;

    cout << "After I have these "<< aDeck.numberOfCards() << " cards." << endl;
    
    aDeck.showDeckText();

    hand myHand( aDeck.drawCard() );
    myHand.addCardToHand( aDeck.drawCard() );
    myHand.addCardToHand( aDeck.drawCard() );
    myHand.addCardToHand( aDeck.drawCard() );
    myHand.showHandText();

    short suit, value;
    char suitLetter;

    cout << "enter the suit letter (h,c,d,s): ";
    cin >> suitLetter;

    switch (suitLetter)
    {
        case 's': suit = SPADES; break;
        case 'h': suit = HEARTS; break;
        case 'd': suit = DIAMONDS; break;
        case 'c': suit = CLUBS; 
    }

    cout << "enter the value as a number (1-13): ";
    cin >> value;

    int found = myHand.getCardIndex(suit, value);

    if (found == -1) cout << "You do not have that card???" << endl;
    else{

        card myChosen = myHand.playCard(found);

        cout << "You played a(n) " << myChosen << endl;

    }

    // aDeck.showDeckText();

    return EXIT_SUCCESS;

}


