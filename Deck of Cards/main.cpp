//
//  main.cpp
//  Deck of Cards
//
//  Created by Cameron Smith on 12/26/16.
//  Copyright © 2016 Cameron Smith. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "deck.hpp"

using namespace std;

#define size 52


int main() {
    DeckOfCards deck;
    Card currentCard;
    deck.shuffle();
    /* TEST CHECK WHOLE DECK 
     for (int i=0;i<52;i++)
    {
        currentCard = deck.DealCard();
        cout << currentCard.print() << endl;
    } */
    
    deck.P1[0] = deck.DealCard(); Card p1c1 = deck.P1[0];
    deck.P2[0] = deck.DealCard(); Card p2c1 = deck.P2[0];
    deck.P1[1] = deck.DealCard(); Card p1c2 = deck.P1[1];
    deck.P2[1] = deck.DealCard(); Card p2c2 = deck.P2[1];
    
    Card burn1 = deck.DealCard();
    deck.P1[2] = deck.DealCard(); deck.P2[2] = deck.P1[2]; Card flop1 = deck.P1[2];
    deck.P1[3] = deck.DealCard(); deck.P2[3] = deck.P1[3]; Card flop2 = deck.P1[3];
    deck.P1[4] = deck.DealCard(); deck.P2[4] = deck.P1[4]; Card flop3 = deck.P1[4];
    Card burn2 = deck.DealCard();
    deck.P1[5] = deck.DealCard(); deck.P2[5] = deck.P1[5]; Card turn = deck.P1[5]; deck.turnDealt = 1;
    Card burn3 = deck.DealCard();
    deck.P1[6] = deck.DealCard(); deck.P2[6] = deck.P1[6]; Card river = deck.P1[6]; deck.riverDealt = 1;
    
    cout << "Player 1" << endl;
    cout << p1c1.print() << "   " << p1c2.print() << endl;
    cout << "Player 2" << endl;
    cout << p2c1.print() << "   " << p2c2.print() << endl;
    cout << "Board" << endl;
    cout << flop1.print() << "   " << flop2.print() << "   " << flop3.print() << "   " << turn.print() << "   " << river.print() << endl;
    
    deck.P1[0].value = 13; deck.P1[0].suit = "Hearts";
    deck.P1[1].value = 11; deck.P1[1].suit = "Clubs";
    deck.P1[2].value = 9; deck.P1[2].suit = "Hearts";
    deck.P1[3].value = 8; deck.P1[3].suit = "Hearts";
    deck.P1[4].value = 8; deck.P1[4].suit = "Clubs";
    deck.P1[5].value = 8; deck.P1[5].suit = "Diamonds";
    deck.P1[6].value = 7; deck.P1[6].suit = "Hearts";
    
    cout << "Player 1's hand is " << deck.determineHand(1, deck.P1) << endl;
   // cout << "Player 2's hand is " << deck.determineHand(2, deck.P2) << endl;
    
    /* Card Player1Card1 = Card("A", "Spades"), Player1Card2 = Card("K", "Diamonds");
    Card Player2Card1 = Card("7", "Clubs"), Player2Card2 = Card("2", "Hearts"); */
    
    
    return 0;
}

