#ifndef HAND_H
#define HAND_H

#include "Card.h"


class Hand
{
public:
	
	Hand();
	
	Hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5);

	void set_hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5);

	void get_hand();

	int high_card();
	
	int has_pair();

	int has_two_pair();

	int has_three_of_a_kind();

	int has_straight();

	bool has_flush();

	int has_four_of_a_kind();

private:
	
	Card hand[5];

	int high_card;

	int pair;

	int two_pair;

	int three_of_a_kind;

	int straight;

	bool flush;

	int four_of_a_kind;

};

#endif