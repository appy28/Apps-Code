//============================================================================
// Name        : BlackJackUsingClass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <cassert>
#include<ctime>
#include<cstdlib>

using namespace std;

class Card
{
public:
	enum CardRank
	{
		RANK_TWO,
		RANK_THREE,
		RANK_FOUR,
		RANK_FIVE,
		RANK_SIX,
		RANK_SEVEN,
		RANK_EIGHT,
		RANK_NINE,
		RANK_TEN,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANK
	};

	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUIT
	};

	private:
	CardRank m_card;
	CardSuit m_suit;

	public:

	Card (CardRank rank = MAX_RANK, CardSuit suit = MAX_SUIT)
	: m_card(rank), m_suit(suit)
	{

	}

	void printCard() const
	{
		switch(m_card)
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

		switch(m_suit)
		{
			case SUIT_CLUB:       cout<<"C";break;
			case SUIT_DIMOND:     cout<<"D";break;
			case SUIT_HEART:      cout<<"H";break;
			case SUIT_SPADE:      cout<<"S";break;
		}
	}

	int getCardValue() const
	{
		switch (m_card)
		{
		   case RANK_TWO:		return 2;
		   case RANK_THREE:	    return 3;
		   case RANK_FOUR:		return 4;
		   case RANK_FIVE:		return 5;
		   case RANK_SIX:		return 6;
		   case RANK_SEVEN:	    return 7;
		   case RANK_EIGHT:	    return 8;
		   case RANK_NINE:		return 9;
		   case RANK_TEN:		return 10;
		   case RANK_JACK:		return 10;
		   case RANK_QUEEN:	    return 10;
		   case RANK_KING:		return 10;
		   case RANK_ACE:		return 11;
		}

	    return 0;
	}
};

class Deck
{
	array<Card,52> m_deck;
	int m_cardIndex = 0;

	// Generate a random number between min and max (inclusive)
	// Assumes srand() has already been called
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	void swapCard(Card &a, Card &b)
	{
		Card temp = a;
		a = b;
		b = temp;
	}

public:
	Deck()
    {
		int card = 0;
		for (int suit =0;suit<Card::MAX_SUIT;suit++)
			for(int rank =0;rank<Card::MAX_RANK;rank++)
			{
				m_deck[card]=Card(static_cast<Card::CardRank>(rank),static_cast<Card::CardSuit>(suit));
			    ++card;
			}
    }

	void printDeck()
	{
		for (const auto &card : m_deck)
		{
			card.printCard();
			cout<< ' ';
		}

		cout<<"\n" ;
	}

	void shuffleDeck()
	{
		// Step through each card in the deck
		for (int index = 0; index < 52; ++index)
		{
			// Pick a random card, any card
			int swapIndex = getRandomNumber(0, 51);
			// Swap it with the current card
			swapCard(m_deck[index], m_deck[swapIndex]);

			m_cardIndex =0 ; //start a new deal
		}
	}

	const Card& dealCard()
	{
		assert(m_cardIndex < 52);
		return m_deck[m_cardIndex++];
	};
};

char getPlayerChoice()
{
	cout<<"Enter s(to stand) or h (to hit):";
	char choice;

	do
	{
		cout<<"Enter your Choice : ";
		cin>>choice;
	}
	while(choice != 's' && choice !='h');

	return choice;
}

bool playBalckJack(Deck &deck)
{
	int playerTotal = 0;
	int dealerTotal = 0;

	dealerTotal += deck.dealCard().getCardValue();

	cout<<"Dealer total is showing:"<<dealerTotal<<endl;

	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	while(1)
	{
		cout <<"Player total is :"<<playerTotal<<endl;

		char choice = getPlayerChoice();

		if (choice =='s')
			break;

		playerTotal += deck.dealCard().getCardValue();

		if (playerTotal > 21)
			return false;
	}

	if (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		cout<<"Dealer Total is now ::"<<dealerTotal<<endl;
	}

	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}
int main()
{
	/*const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEART);
	cardQueenHearts.printCard();
	std::cout << " has the value " << cardQueenHearts.getCardValue() << '\n';*/

	Deck deck;
	//deck.printDeck();
	deck.shuffleDeck();
	//deck.printDeck();

	/*cout<<"The first card has a value "<<deck.dealCard().getCardValue()<<endl;
	cout<<"the second card has a value "<<deck.dealCard().getCardValue()<<endl;*/

	if(playBalckJack(deck))
		cout<<"You won..!!"<<endl;
	else
		cout<<"You Loose, Dealer Won..!!"<<endl;

	return 0;
}
