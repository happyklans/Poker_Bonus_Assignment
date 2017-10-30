#include "Hand.h"



Hand::Hand()
{
	Card null_card(0, 0);

	for (int i = 0; i < HAND_SIZE; i++)
	{
		hand[i] = null_card;
	}
}

Hand::Hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5)
{
	hand[0] = c1;

	hand[1] = c2;

	hand[2] = c3;

	hand[3] = c4;

	hand[4] = c5;
}

void Hand::set_hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5)
{
	hand[0] = c1;

	hand[1] = c2;

	hand[2] = c3;

	hand[3] = c4;

	hand[4] = c5;

	return;
}

void Hand::get_hand()
{
	for (int i = 0; i < HAND_SIZE; i++)
	{
		std::cout << hand[i];
	}

	return;
}

void Hand::high_card()
{
	Card high_card(0, 0);

	for (Card i : hand)
	{
	
		if (i > high_card)
			high_card = i;
	}

	highest_card = high_card.get_card_value();

	return;
}

void Hand::has_pair()
{
	for (int j = 0; j < HAND_SIZE - 1; j++)
	{
		for (int i = j+1; i < HAND_SIZE; i++)
		{
			if (hand[i] == hand[j])
			{
				pair = hand[i].get_card_value();

				return;
			}
			else pair = 0;
		}
	}

	return;
}

void Hand::has_two_pair()
{
	if (!pair)
	{
		two_pair[0] = 0;

		two_pair[1] = 0;

		return;
	}
	else
	{
		two_pair[0] = pair;

		for (int j = 0; j < HAND_SIZE - 1; j++)
		{
			for (int i = j + 1; i < HAND_SIZE; i++)
			{
				if (hand[i] == hand[j] && hand[i].get_card_value() != pair)
				{
					two_pair[1] = hand[i].get_card_value();

					return;
				}
				else two_pair[1] = 0;
			}
		}
	}

	return;
}

void Hand::has_three_of_a_kind()
{
	if (!pair)
	{
		three_of_a_kind = 0;

		return;
	}
	
	
	for (int i = 0; i < HAND_SIZE - 1; i++)
	{
		for (int j = i + 1; i < HAND_SIZE; j++)
		{
			if (hand[j] == hand[i])
			{
				for (int k = j + 1; k < HAND_SIZE; k++)
				{
					if (hand[k] == hand[i])
					{
						three_of_a_kind = hand[k].get_card_value();

						return;
					}
					else three_of_a_kind = 0;
				}
			}
		}
	}

	return;

}

void Hand::has_straight()
{
	int low_card = hand[0].get_card_value();

	if (!pair)
	{
		straight = 0;

		return;
	}

	for (int i = 0; i < HAND_SIZE; i++)
	{
		if (hand[i].get_card_value() < low_card)
			low_card = hand[i].get_card_value();
	}

	if ((highest_card - low_card) == 4)
	{
		straight = highest_card;

		return;
	}
	else straight = 0;
	return;
}

void Hand::has_flush()
{
	char test_suite = hand[0].get_card_suite();

	for (int i = 0; i < HAND_SIZE; i++)
	{
		if (hand[i].get_card_suite() != test_suite)
		{
			flush = false;

			return;
		}
		else flush = true;
	}

	return;
}

void Hand::has_four_of_a_kind()
{
	if (!pair)
	{
		four_of_a_kind = 0;

		return;
	}

	for (int i = 0; i < HAND_SIZE - 1; i++)
	{
		for (int j = i + 1; i < HAND_SIZE; j++)
		{
			if (hand[j] == hand[i])
			{
				for (int k = j + 1; k < HAND_SIZE; k++)
				{
					if (hand[k] == hand[i])
					{
						for (int l = k + 1; l < HAND_SIZE; l++)
						{
							if (hand[l] == hand[i])
							{
								four_of_a_kind = hand[i].get_card_value();

								return;
							}
							else four_of_a_kind = 0;
						}
					}
				}
			}
		}

		

	}

	return;

}