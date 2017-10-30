#ifndef HAND_H
#define HAND_H

#include "Card.h"

#define HAND_SIZE 5

class Hand
{
public:
	
	Hand();
	
	Hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5);

	void set_hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5);

	void get_hand();

	void high_card();
	
	void has_pair();

	void has_two_pair();

	void has_three_of_a_kind();

	void has_straight();

	void has_flush();

	void has_four_of_a_kind();

private:
	
	Card hand[HAND_SIZE];

	int highest_card;

	int pair;

	int two_pair[2];

	int three_of_a_kind;

	int straight;

	bool flush;

	int four_of_a_kind;

};

#endif