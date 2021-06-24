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

    deck aDeck(56);
    aDeck.showDeckText();



    return EXIT_SUCCESS;

}


