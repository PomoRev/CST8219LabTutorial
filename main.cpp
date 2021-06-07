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

#include "deck.h"

int main(int argc, char const *argv[])
{

    cout << "Create a Card and display it" << endl;

    using namespace playingcards;

    card FirstCard;
    card SecondCard(SPADES, ACE);

    FirstCard.showCard();
    SecondCard.showCard();


    return EXIT_SUCCESS;
}



