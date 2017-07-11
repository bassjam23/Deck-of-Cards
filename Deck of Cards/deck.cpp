//
//  deck.cpp
//  Deck of Cards
//
//  Created by Cameron Smith on 12/26/16.
//  Copyright © 2016 Cameron Smith. All rights reserved.
//

#include "deck.hpp"
#include <algorithm>

Card::Card()
{
    
}

Card::Card(int cardValue, string cardSuit)
{
    value = cardValue;
    suit = cardSuit;
}

string Card::print()
{
    if (value == 14) valueName = "A";
    if (value == 13) valueName = "K";
    if (value == 12) valueName = "Q";
    if (value == 11) valueName = "J";
    if (value == 10) valueName = "10";
    if (value == 9) valueName = "9";
    if (value == 8) valueName = "8";
    if (value == 7) valueName = "7";
    if (value == 6) valueName = "6";
    if (value == 5) valueName = "5";
    if (value == 4) valueName = "4";
    if (value == 3) valueName = "3";
    if (value == 2) valueName = "2";
    return (valueName + " of " + suit);
}

DeckOfCards::DeckOfCards()
{
    // string values[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int values[] = {14,13,12,11,10,9,8,7,6,5,4,3,2};
    string suits[] = {"Hearts","Diamonds","Clubs","Spades"};
    int count = 0;
    for (int valCt = 0;valCt<13;valCt++)
    {
        for (int suitCt = 0; suitCt < 4; suitCt++)
        {
            Deck[count] = Card(values[valCt],suits[suitCt]);
            count++;
        }
    }
}

void DeckOfCards::shuffle()
{
    for (int first=0;first<52;first++)
    {
        int second = (rand() + time(0))%52;
        Card temp = Deck[first];
        Deck[first] = Deck[second];
        Deck[second] = temp;
    }
    dealCount = 0;
}

Card DeckOfCards::DealCard()
{
    return (Deck[dealCount++]);
}

void DeckOfCards::insertionSort(Card array[], int n)
{
    int i, j;
    Card key;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i-1;
        while (j >=0 && array[j].value < key.value)
        {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}

string DeckOfCards::determineHand(int player, Card Player[7])
{
    /* cout << "Player " << player << " has:" << endl;
    for (int j = 0; j < 7; j++)
    {
        cout << Player[j].print() << "   ";
    }
    cout << endl; */
    int spades = 0, diamonds = 0, clubs = 0, hearts = 0;
    bool longStraight;
    
    int straightCount = 1, straightValue;
    int straightFlushCount = 1;
    int ofAKindCounter = 1;
    int ofAKindCount1 = 1, ofAKindValue1;
    int ofAKindCount2 = 1, ofAKindValue2;
    int ofAKindCount3 = 1, ofAKindValue3;
    string rank1, rank2, rank3, rank4, rank5;
    
    //SORT THE CARDS IN EITHER CASE
    insertionSort(Player, 7);
    cout << "After Sorting Player " << player << " has:" << endl;
    
    // CHECK EACH CARD IN HAND
    for (int cards = 0; cards < 7; cards++)
    {
        cout << Player[cards].print() << "   ";
        
        if (Player[cards].suit == "Spades") spades++;
        else if (Player[cards].suit == "Hearts") hearts++;
        else if (Player[cards].suit == "Diamonds") diamonds++;
        else clubs++;
        
        if (Player[cards].value == Player[cards+1].value + 1)
        {
            // cout << "Straight + 1" << endl;
            straightCount++; // cout << "straightCount is " << straightCount << endl;
            if (Player[cards].suit == Player[cards+1].suit) straightFlushCount++; else straightFlushCount = 1;
            straightValue = Player[cards].value;
            if (straightCount == 5) hasStraight = true;
            if (straightCount > 5) longStraight = true;
            if (straightFlushCount == 5) return ("Straight Flush");
        }
        else if (Player[cards].value == Player[cards+1].value)
        {
            if (ofAKindCounter > 1) // KEEP TRACK OF 3 OF A KIND AND 4
            // cout << "Pair + 1" << endl;
            if (ofAKindCounter == 1)
            {
                ofAKindValue1 = Player[cards].value;
                ofAKindCount1++;
            }
            else if (ofAKindCount2 == 1)
            {
                ofAKindValue2 = Player[cards].value;
                ofAKindCount2++;
            }
            else
            {
                ofAKindValue3 = Player[cards].value;
                ofAKindCount3++;
            }
        }
        else
        {
            // cout << "No straight or pair" << endl;
            straightCount = 1;
        }
    }
    
    // CHECK FOR FLUSH/STRAIGHT
    if (spades >= 5 || clubs >= 5 || diamonds >= 5 || clubs >= 5)
    {
        return "Flush";
    }
    if (hasStraight) return "Straight";
    if (ofAKindCount1 == 4 || ofAKindCount2 == 4 || ofAKindCount3 == 4) return "4 of a kind";
    if ((ofAKindCount1 == 3 && ofAKindCount2 == 2) || (ofAKindCount2 == 3 && ofAKindCount1 == 2)) return "Full house";
    else if (ofAKindCount1 == 3 || ofAKindCount2 == 3 || ofAKindCount3 == 3) return "3 of a kind";
    else if (ofAKindCount1 == 2 && ofAKindCount2 == 2) return "Two pair";
    else if (ofAKindCount1 == 2) return "Pair";
    else return "NAGT";
        
    
    
    
    
    
    
    
    
    return "Salsa";
    
 /*   // NAIVE WAY OF FINDING FLUSHES UNTIL I CAN THINK OF SOMETHING BETTER
    
    if (riverDealt)
    {
        if (River.suit == "Clubs") clubs++;
        if (River.suit == "Diamonds") diamonds++;
        if (River.suit == "Hearts") hearts++;
        if (River.suit == "Spades") spades++;
    }
    if (turnDealt)
    {
        if (Turn.suit == "Clubs") clubs++;
        if (Turn.suit == "Diamonds") diamonds++;
        if (Turn.suit == "Hearts") hearts++;
        if (Turn.suit == "Spades") spades++;
    }
    if (Flop1.suit == "Clubs") clubs++;
    if (Flop1.suit == "Diamonds") diamonds++;
    if (Flop1.suit == "Hearts") hearts++;
    if (Flop1.suit == "Spades") spades++;
    if (Flop2.suit == "Clubs") clubs++;
    if (Flop2.suit == "Diamonds") diamonds++;
    if (Flop2.suit == "Hearts") hearts++;
    if (Flop2.suit == "Spades") spades++;
    if (Flop3.suit == "Clubs") clubs++;
    if (Flop3.suit == "Diamonds") diamonds++;
    if (Flop3.suit == "Hearts") hearts++;
    if (Flop3.suit == "Spades") spades++;
    if (Player == 1)
    {
        if (P1C1.suit == "Clubs") clubs++;
        if (P1C1.suit == "Diamonds") diamonds++;
        if (P1C1.suit == "Hearts") hearts++;
        if (P1C1.suit == "Spades") spades++;
        if (P1C2.suit == "Clubs") clubs++;
        if (P1C2.suit == "Diamonds") diamonds++;
        if (P1C2.suit == "Hearts") hearts++;
        if (P1C2.suit == "Spades") spades++;
    }
    if (Player == 2)
    {
        if (P2C1.suit == "Clubs") clubs++;
        if (P2C1.suit == "Diamonds") diamonds++;
        if (P2C1.suit == "Hearts") hearts++;
        if (P2C1.suit == "Spades") spades++;
        if (P2C2.suit == "Clubs") clubs++;
        if (P2C2.suit == "Diamonds") diamonds++;
        if (P2C2.suit == "Hearts") hearts++;
        if (P2C2.suit == "Spades") spades++;
    }*/
    
}
void DeckOfCards::findWinner()
{
    
}
