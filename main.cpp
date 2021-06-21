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

    cout << "Create a Card and display it" << endl;

    card FirstCard;
    card SecondCard(CLUBS, 6);

    FirstCard.showCard();
    SecondCard.showCard();

    cout << "Copy second card into first card, this is the first card: ";

    FirstCard = SecondCard;

    FirstCard.showCard();

    cout << endl;


    return EXIT_SUCCESS;
}



