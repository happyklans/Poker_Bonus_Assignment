#include "Hand.h"



Hand::Hand()
{
	Card null_card(0,0);

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

	get_hand();

	high_card();

	has_pair();

	has_two_pair();

	has_three_of_a_kind();

	has_straight();

	has_flush();

	has_full_house();

	has_four_of_a_kind();

	has_straight_flush();

	has_royal_flush();
}

void Hand::set_hand(Card & c1, Card & c2, Card & c3, Card & c4, Card & c5)
{
	hand[0] = c1;

	hand[1] = c2;

	hand[2] = c3;

	hand[3] = c4;

	hand[4] = c5;

	get_hand();

	high_card();

	has_pair();

	has_two_pair();

	has_three_of_a_kind();

	has_straight();

	has_flush();

	has_full_house();

	has_four_of_a_kind();

	has_straight_flush();

	has_royal_flush();

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
	char test_suit = hand[0].get_card_suit();

	for (int i = 0; i < HAND_SIZE; i++)
	{
		if (hand[i].get_card_suit() != test_suit)
		{
			flush = false;

			return;
		}
		else flush = true;
	}

	return;
}

void Hand::has_full_house()
{
	if (pair && three_of_a_kind)
		full_house = three_of_a_kind;
	else
	{
		full_house = 0;

		return;
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

void Hand::has_straight_flush()
{
	if (straight && flush)
		straight_flush = highest_card;
	else
	{
		straight_flush = 0;

		return;
	}

	return;
}

void Hand::has_royal_flush()
{
	if (straight_flush && highest_card == 14)
		royal_flush = true;
	else
	{
		royal_flush = false;

		return;
	}

	return;
}

/*----------------------------------------friend fuctions-----------------------------------------*/
int compare_hand(Hand & hand_one, Hand & hand_two)
{
	if (hand_one.royal_flush == true && hand_two.royal_flush == false)
		return 1;
	else if (hand_one.royal_flush == false && hand_two.royal_flush == true)
		return 2;
	else if (hand_one.royal_flush == true && hand_two.royal_flush == true)
		return 0;
	else if (hand_one.royal_flush == false && hand_two.royal_flush == false)
	{
		if (hand_one.straight_flush > hand_two.straight_flush)
			return 1;
		else if (hand_one.straight_flush < hand_two.straight_flush)
			return 2;
		else if (hand_one.straight_flush != 0 && 
			hand_two.straight_flush != 0 && hand_one.straight_flush == hand_two.straight_flush)
			return 0;
		else if (hand_one.straight_flush == 0 && hand_two.straight_flush == 0)
		{
			if (hand_one.four_of_a_kind > hand_two.four_of_a_kind)
				return 1;
			else if (hand_one.four_of_a_kind < hand_two.four_of_a_kind)
				return 2;
			else if (hand_one.four_of_a_kind != 0 
				&& hand_two.four_of_a_kind != 0 
				&& hand_one.four_of_a_kind == hand_two.four_of_a_kind)
				return 0;
			else if (hand_one.four_of_a_kind == 0 && hand_two.four_of_a_kind == 0)
			{
				if (hand_one.full_house > hand_two.full_house)
					return 1;
				else if (hand_one.full_house < hand_two.full_house)
					return 2;
				else if (hand_one.full_house != 0
					&& hand_two.full_house != 0
					&& hand_one.full_house == hand_two.full_house)
					return 0;
				else if (hand_one.full_house == 0 && hand_two.full_house == 0)
				{
					if (hand_one.flush == true && hand_two.flush == false)
						return 1;
					else if (hand_one.flush == false && hand_two.flush == true)
						return 2;
					else if (hand_one.flush == true && hand_two.flush == true)
						return 0;
					else if (hand_one.flush == false && hand_two.flush == false)
					{
						if (hand_one.straight > hand_two.straight)
							return 1;
						else if (hand_one.straight < hand_two.straight)
							return 2;
						else if (hand_one.straight != 0 && hand_two.straight != 0 
							&& hand_one.straight == hand_two.straight)
							return 0;
						else if (hand_one.straight == 0 && hand_two.straight == 0)
						{
							if (hand_one.three_of_a_kind > hand_two.three_of_a_kind)
								return 1;
							else if (hand_one.three_of_a_kind < hand_two.three_of_a_kind)
								return 2;
							else if (hand_one.three_of_a_kind != 0 && hand_two.three_of_a_kind != 0 
								&& hand_one.three_of_a_kind == hand_two.three_of_a_kind)
								return 0;
							else if (hand_one.three_of_a_kind == 0 && hand_two.three_of_a_kind == 0)
							{
								if (std::max(hand_one.two_pair[0], hand_one.two_pair[1]) > std::max(hand_two.two_pair[0], hand_two.two_pair[1]))
									return 1;
								else if (std::max(hand_one.two_pair[0], hand_one.two_pair[1]) < std::max(hand_two.two_pair[0], hand_two.two_pair[1]))
									return 2;
								else if (std::max(hand_one.two_pair[0], hand_one.two_pair[1]) != 0 && 
									std::max(hand_two.two_pair[0], hand_two.two_pair[1]) != 0 && 
									std::max(hand_one.two_pair[0], hand_one.two_pair[1]) == std::max(hand_two.two_pair[0], hand_two.two_pair[1]))
									return 0;
								else if (std::max(hand_one.two_pair[0], hand_one.two_pair[1]) == 0
									&& std::max(hand_two.two_pair[0], hand_two.two_pair[1]) == 0)
								{
									if (hand_one.pair > hand_two.pair)
										return 1;
									else if (hand_one.pair < hand_two.pair)
										return 2;
									else if (hand_one.pair != 0 && hand_two.pair != 0 && hand_one.pair == hand_two.pair)
										return 0;
									else if (hand_one.pair == 0 && hand_two.pair == 0)
									{
										if (hand_one.highest_card > hand_two.highest_card)
											return 1;
										else if (hand_one.highest_card < hand_two.highest_card)
											return 2;
										else if (hand_one.highest_card != 0 
											&& hand_two.highest_card != 0 
											&& hand_one.highest_card == hand_two.highest_card)
											return 0;
										else return -1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

std::ifstream & operator >> (std::ifstream & in, Hand & hand_to_fill)
{
	for (int i = 0; i < HAND_SIZE; i++)
	{
		in >> hand_to_fill.hand[i];
	}
	
	hand_to_fill.high_card();

	hand_to_fill.has_pair();

	hand_to_fill.has_two_pair();

	hand_to_fill.has_three_of_a_kind();

	hand_to_fill.has_straight();

	hand_to_fill.has_flush();

	hand_to_fill.has_full_house();

	hand_to_fill.has_four_of_a_kind();

	hand_to_fill.has_straight_flush();

	hand_to_fill.has_royal_flush();

	if (in.peek() == '\n')
		in.ignore();

	return in;
}

std::ofstream & operator << (std::ofstream & out, Hand & hand_to_write)
{
	for (int i = 0; i < HAND_SIZE; i++)
	{
		out << hand_to_write.hand[i];
	}

	return out;
}