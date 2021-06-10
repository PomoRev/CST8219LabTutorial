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

    cout << "this is my card : " << myCard.getSuitName() << endl;

    return EXIT_SUCCESS;

}


