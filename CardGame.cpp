//============================================================================
// Name        : CardGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<array>
#include "CardGame.h"
#include<ctime>
#include<cstdlib>
using namespace std;

struct Card
{
	CardRank rank;
	CardSuit suit;
};

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case RANK_TWO:		return 2;
	case RANK_THREE:	return 3;
	case RANK_FOUR:		return 4;
	case RANK_FIVE:		return 5;
	case RANK_SIX:		return 6;
	case RANK_SEVEN:	return 7;
	case RANK_EIGHT:	return 8;
	case RANK_NINE:		return 9;
	case RANK_TEN:		return 10;
	case RANK_JACK:		return 10;
	case RANK_QUEEN:	return 10;
	case RANK_KING:		return 10;
	case RANK_ACE:		return 11;
	}

    return 0;
}
void printCard(const Card &card)
{
	switch(card.rank)
	{
	case RANK_TWO:        cout<<"2";break;
	case RANK_THREE:      cout<<"3";break;
	case RANK_FOUR:       cout<<"4";break;
	case RANK_FIVE:       cout<<"5";break;
	case RANK_SIX:        cout<<"6";break;
	case RANK_SEVEN:      cout<<"7";break;
	case RANK_EIGHT:      cout<<"8";break;
	case RANK_NINE:       cout<<"9";break;
	case RANK_TEN:        cout<<"10";break;
	case RANK_JACK:       cout<<"J";break;
	case RANK_QUEEN:     cout<<"Q";break;
	case RANK_KING:       cout<<"K";break;
	case RANK_ACE:        cout<<"A";break;
	}

	switch(card.suit)
	{
	case SUIT_CLUB:       cout<<"C";break;
	case SUIT_DIMOND:     cout<<"D";break;
	case SUIT_HEART:      cout<<"H";break;
	case SUIT_SPADE:      cout<<"S";break;
	}
}

void printDeck(const array<Card,52> &deck)
{
	for(const auto &card:deck)
	   {
          printCard(card);
          cout<<" ";
	   }
	cout<<"\n";
}

void swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
 	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(array<Card,52> &deck)
{
	for(int index=0;index<52;index++)
	{
		int swapIndex = getRandomNumber(0,51);
		swapCard(deck[index],deck[swapIndex]);
	}
}

char getPlayersChoice()
{
	cout<<"Type h to hit and s to stop:";
	char choice;
	do
	{
		cin>>choice;
	}
	while(choice != 'h' && choice != 's');

		return choice;
}
bool playBlackJack(const array<Card,52> &deck)
{
	//set up the initial game store
	const Card *cardptr = &deck[0];

	int playerTotal=0;
	int dealerTotal=0;

	//Deal the Dealer one card
	dealerTotal+= getCardValue(*cardptr++);

	//Deal Player two cards
	playerTotal+= getCardValue(*cardptr++);
	playerTotal+= getCardValue(*cardptr++);

	//Player goes first
	while(1)
	{
		cout<<"You have "<<playerTotal<<endl;

		//see if the Player has busted
		if(playerTotal>21)
		   return false;

		char choice=getPlayersChoice();
		if(choice == 's')
		   break;

		playerTotal+=getCardValue(*cardptr++);
	}

	//if player has not busted then Dealer will deal till his total reaches 17 points
	while(dealerTotal<17)
	{
		dealerTotal+= getCardValue(*cardptr++);
		cout<<"The Dealer now has "<<dealerTotal<<endl;
	}

	//if Dealer Busted,Player wins
	if(dealerTotal>21)
		return true;

	return(playerTotal>dealerTotal);
}


int main() {

	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // discard first random value

	array<Card,52> deck;

	int card=0;
	for (int suit =0;suit< MAX_SUIT;suit++)
		for(int rank=0;rank<MAX_RANK;rank++)
		{
			deck[card].suit = static_cast<CardSuit>(suit);
			deck[card].rank = static_cast<CardRank>(rank);
			card++;
		}

	//printDeck(deck);
	shuffleDeck(deck);
	//printDeck(deck);
	if(playBlackJack(deck))
		cout<<"Player has Won...!!!"<<endl;
	else
		cout<<"You Lose..Dealer Won..!!"<<endl;

	return 0;
}
