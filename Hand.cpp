#include "Hand.h"



Hand::Hand()
{
	Card null_card(0, 0);

	for (int i = 0; i < 5; i++)
	{
		hand[i] = null_card;
	}
}

