// Lottery program that generates 10 random numbers between 1-50 inclusive.
//It requests user to generate his 10 play numbers and compares the stored number within the arrays.
//The user would foresee at the end-stage whether the game is WON or LOST.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>//fstream to allow create and write to txt file
using namespace std;

// function protoypes
void Hello_Message();
void End_Message();

void Game_replay(char* replay);//allows user to reatsortt lottery
int getWinning_Numbers(int Winning_Numbers[]);
//collates random generated lottery numbers
int getPlayed_Numbers(int Played_Numbers[]);
//collates user played numbers
int sortNumbers(int sortNumbers[]);
//sorts user numbers according to numbers stored from array 0-9.
void checkNumbers(int Winning_Numbers[], int Played_Numbers[]);
void Results_Message(int Win_counter);
//Win_counter to see winning matches.

// MAIN

int main()
{
	int Winning_Numbers[10];//array defined to store random numbers
	int Played_Numbers[10];//user played numbers stored
	char replay;//asks user to replay game

	Hello_Message();

	do//do while loop to replay game if user selects MATCHED
	{
	getWinning_Numbers(Winning_Numbers);
	getPlayed_Numbers(Played_Numbers);
	sortNumbers(Winning_Numbers);//sorts random numbers
	sortNumbers(Played_Numbers);//sorts user played numbers
	checkNumbers(Winning_Numbers, Played_Numbers);
	Game_replay(&replay);
	} while (replay == 'y' || replay == 'Y');
//asks user to replay game?
		End_Message();


		return 0;

}






//outputs welcome message
void Hello_Message()
{
	cout << setw(45) << "Welcome to National Lottery!" << endl << endl;

}
//end message
void End_Message()
{
	cout << setw << (49) << "Thanks for playing National Lottery!" << endl << endl;

}

// replayed game , then triggers char variable to trigger do/while loop
//while loop true, if false.

void Game_replay(char* replay)
{
    //prompting user if they would like to atsortt again.
	cout << setw(51) << "Would you like to play again? (y/n)" << endl;
	do
	{
		cin >> *replay;
	} while
		(*replay != 'y' &&
			*replay != 'Y' &&
			*replay != 'n' &&
			*replay != 'N');



}


//generates 10 random lottery numbers, 1-50 inclusive
int getWinning_Numbers(int Winning_Numbers[])
{


	srand(time(0));//sets random number algorithm

	for (int i = 0; i < 10; i++)
        //stores 10 random numbers in the array
	{
		Winning_Numbers[i] = 1 + (rand() %50);
		//random numbers 1-50 inclusive

		//prevents duplicate values
		while (Winning_Numbers [i] == Winning_Numbers[i-1])
		{
			Winning_Numbers[i] = 1 + (rand() &50);
		}
	}

}

//function allows user to input 10 lottery numbers for play (1-50 inclusive)
int getPlayed_Numbers(int Played_Numbers[])
{
	cout << setw(55) << "Please select ten lottery numbers (1-50) inclusive:" << endl;
//for loop to store 10 numbers from user in array.
	for (int i = 0; i < 10; i++)
	{
		cin >> Played_Numbers[i];
//creates txt file named mynumbers and stores user played numbers
		    ofstream result;
    result.open("mynumbers.txt");
    result<< "Your numbers " << Played_Numbers[i] <<endl;

    result.close();

		while (Played_Numbers[i] < 1 | Played_Numbers[i] > 50)
		{
			cout << "Invalid number !" << endl;
			cout << "please choose 1-50 inclusive: ";
			cin >> Played_Numbers[i];

			    ofstream result;
    result.open("mynumbers.txt");
    result<< "Your numbers " << Played_Numbers[i] <<endl;

    result.close();
		}


	}



}
//function sorts number elements within array
//bubble sort algorithm implemented within this approach
int sortNumbers(int sortNumbers[])
{
	int sort;
//swaps 9 numbers as there are 10 numbers
	for (int Win_counter = 9; Win_counter > 0; Win_counter--)
	{//this loops and swaps index 0-9 for the remaining 10 elements
		for (int i = 0; i < 9; i++)
		{//compares elements and swaps them lowest to highest.
			if (sortNumbers[i] > sortNumbers[i + 1])
			{
				sort = sortNumbers[i + 1];
				sortNumbers[i + 1] = sortNumbers[i];
				sortNumbers[i] = sort;
			}
		}
	}

}
//function takes both winning numbers and player numbers and compares.
//if numbers match accordingly in order, outputs MATCHED, otherwise UNMATCHED.

void checkNumbers(int Winning_Numbers[], int Played_Numbers[])
{
	string MATCHED = " MATCHED ";//if results is a match output MATCHED
	string UNMATCHED = " UNMATCHED ";//OUTPUT UNMATCHED if unmatch
	int Win_counter = 0;//count winning number total

	cout << endl;

	cout << " Winning Numbers *********** Played Numbers *********** Results" << endl;

	//compares all 10 elements within array
	for (int i = 0; i < 10; i++)
	{


		if (Winning_Numbers[i] == Played_Numbers[i])
		{
			cout << setw(11) << Winning_Numbers[i] << setw(18) << "||||||||||||||" << setw(6) << Played_Numbers[i] << setw(19) << "||||||||||||||" << setw(7) << MATCHED << endl;
			Win_counter++;

		}
		else
		{
			cout << setw(11) << Winning_Numbers[i] << setw(18) << "||||||||||||||" << setw(6) << Played_Numbers[i] << setw(19) << "||||||||||||||" << setw(7) << UNMATCHED << endl;
		}



	}
	Results_Message(Win_counter);


}
//finalise results


void Results_Message(int Win_counter)
{
	cout << endl;
	if (Win_counter == 10)//if.else to display results of player
	{
		cout << setw(28) << "You got" << Win_counter << " numbers out of 10" << endl;
		cout << setw(41) << "YOU WIN!" << endl << endl;
	}
	else
	{
		cout << setw(28) << "You got " << Win_counter << " numbers out of 10" << endl;
		cout << setw(41) << "YOU LOST!" << endl << endl;

	}
//creates and writes to txt file named results, the amount of winning number  out of 10.
    ofstream result;
    result.open("results.txt");

    result<< "You won " << Win_counter << " numbers out of 10" << endl;

    result.close();
}

#


