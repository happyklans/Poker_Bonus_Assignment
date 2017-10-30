#include "Card.h"



Card::Card() //default constructor
{
	card_value = 0;

	suite = 0;
}

Card::Card(int constructor_value, char constructor_suite) //parameterized constructor
{
	card_value = constructor_value;

	suite = constructor_suite;
}
void Card::set_card_value(int constructor_value, char constructor_suite) // set function/mutator
{
	card_value = constructor_value;

	suite = constructor_suite;

	return;
}


int Card::get_card_value() // get function/ assesor
{
	return card_value;
}

char Card::get_card_suite()
{
	return suite;
}




/*----------------------------------------friend functions----------------------------------------------*/

bool operator == (Card& card_on_left, Card& card_on_right)
{
	if (card_on_left.get_card_value() == card_on_right.get_card_value())
		return true;
	else
	{
		return false;
	}
}

bool operator != (Card& card_on_left, Card& card_on_right)
{
	return !(card_on_left == card_on_right);
}

bool operator < (Card& card_on_left, Card& card_on_right)
{
	if (card_on_left.get_card_value() < card_on_right.get_card_value())
		return true;
	else
	{
		return false;
	}
}

bool operator > (Card& card_on_left, Card& card_on_right)
{
	if (card_on_left.get_card_value() > card_on_right.get_card_value())
		return true;
	else
	{
		return false;
	}
}

bool operator <= (Card& card_on_left, Card& card_on_right)
{
	if (card_on_left == card_on_right || card_on_left < card_on_right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator >= (Card& card_on_left, Card& card_on_right)
{
	if (card_on_left == card_on_right || card_on_left > card_on_right)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ifstream & operator >> (std::ifstream& in, Card& card)
{
	card.card_value = in.get();

	card.suite = in.get();

	
	in.ignore();

	return in;
	
}

std::ofstream & operator << (std::ofstream& out, Card& card)
{
	out << card.card_value << card.suite << ' ';

	return out;
}

std::istream & operator >> (std::istream& in, Card& card)
{
	card.card_value = in.get();

	card.suite = in.get();

	in.ignore();

	return in;
}

std::ostream & operator << (std::ostream& out, Card& card)
{
	out << card.card_value << card.suite << ' ';

	return out;
}