/*
Benjamin Stanton & Conor McCandless
10/24/2017
Project Euler #54
*/


#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <fstream>


class Card
{
public:
	
	Card(); //default constructor

	Card(int value, char suite); //parameterized constructor

	void set_card_value(int value, char suite); // set function/mutator

	int get_card_value(); // get function/ assesor

	char get_card_suite(); // get function/ assesor

	//overloading logic operators

	friend bool operator == (Card& card_on_left, Card& card_on_right);

	friend bool operator != (Card& card_on_left, Card& card_on_right);

	friend bool operator < (Card& card_on_left, Card& card_on_right);

	friend bool operator > (Card& card_on_left, Card& card_on_right);

	friend bool operator <= (Card& card_on_left, Card& card_on_right);

	friend bool operator >= (Card& card_on_left, Card& card_on_right);

	friend std::ifstream & operator >> (std::ifstream& in, Card& card);

	friend std::ofstream & operator << (std::ofstream& in, Card& card);

private:
	
	int card_value;

	char suite;
};

#endif