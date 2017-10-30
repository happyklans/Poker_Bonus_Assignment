#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Hand.h"


class Deck
{
public:
	Deck();

	Hand deal();
	
private:

	Card deck[52];
};

#endif