//
//  deck.hpp
//  Deck of Cards
//
//  Created by Cameron Smith on 12/26/16.
//  Copyright © 2016 Cameron Smith. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Card
{
public:
    Card();
    Card(int cardValue, string cardSuit);
    string print();
    int value;
    string valueName;
    string suit;
/*private:
    string value;
    string suit; */
};

class DeckOfCards
{
public:
    DeckOfCards();
    void shuffle();
    Card DealCard();
    Card P1C1;
    Card P1C2;
    Card P2C1;
    Card P2C2;
    Card Flop1;
    Card Flop2;
    Card Flop3;
    Card Turn;
    Card River;
    Card P1[7];
    Card P2[7];
    void insertionSort(Card array[], int n);
    string determineHand(int player, Card Player[7]);
    void findWinner();
    bool turnDealt;
    bool riverDealt;
    bool hasStraight;
    int boardSpades;
    int boardHearts;
    int boardDiamonds;
    int boardClubs;
private:
    Card Deck[52];
    Card currentCard;
    int dealCount;
    
};



















#endif /* deck_hpp */
