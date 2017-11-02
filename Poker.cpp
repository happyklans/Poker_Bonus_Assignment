/*
Benjamin Stanton and Conor McCandless
CSC 161 
11/2/17
*/

#include "Hand.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int number_of_players = 2;

int main()
{
	
	ifstream hand_file;

	Hand player_one;

	Hand player_two;

	string line;

	int player_one_wins = 0;

	int player_two_wins = 0;

	int split_pot = 0;


	hand_file.open("poker_hands.txt", ios::in);

	while (hand_file.good())
	{


		hand_file >> player_one;

		hand_file >> player_two;

		switch (compare_hand(player_one, player_two))
		{
		case -1:
			break;
		case 0:
			split_pot++;
			break;
		case 1:
			player_one_wins++;
			break;
		case 2:
			player_two_wins++;
			break;
		}

	}

	cout << " Player one won " << player_one_wins << " rounds. \n Player two won " <<
		player_two_wins << " rounds. \n They split the pot in " << split_pot << " rounds." << endl;

	if (player_one_wins > player_two_wins)
		cout << " Player one won the set overall." << endl;
	else if (player_two_wins > player_one_wins)
		cout << " Player two won the set overall." << endl;
	else
	{
		cout << " The players broke even in the set overall." << endl;
	}

	cin.get();

	return 0;
}