#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include <algorithm> //max

#define HAND_SIZE 5

class Hand
{
public:
	
	Hand();
	
	Hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5);

	void set_hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5);

	int compare_hand(Hand & hand_one, Hand & hand_two);

	friend std::ifstream & operator >> (std::ifstream & in, Hand & hand_to_fill);

	friend std::ofstream & operator << (std::ofstream & out, Hand & hand_to_write);

private:
	
	Card hand[HAND_SIZE];

	int highest_card;

	int pair;

	int two_pair[2];

	int three_of_a_kind;

	int straight;

	bool flush;

	int full_house;

	int four_of_a_kind;

	int straight_flush;

	bool royal_flush;

	void get_hand();

	void high_card();

	void has_pair();

	void has_two_pair();

	void has_three_of_a_kind();

	void has_straight();

	void has_flush();

	void has_full_house();

	void has_four_of_a_kind();

	void has_straight_flush();

	void has_royal_flush();
};

#endif