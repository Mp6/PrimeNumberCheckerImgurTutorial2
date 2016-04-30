/**
*  @file    PrimeNumberChecker.cpp
*  @author  Mp6
*  @date    4/30/16
*  @version 1.0
*
*  This program was created to demonstrate the basic concepts of loops and functions.
*  This program can be modified or used by anybody, it is intended for educational 
*  purposes.  
*/

//Includes and namespace
#include "stdafx.h"
#include <iostream>

using namespace std;

//Function Definiation
bool IsNumberPrime(int number_to_check);

int main()
{
	//Define some variables
	int input_number = 0;
	bool run_loop = true;
	char input_character;

	//Use a do while loop to execute at least once
	do {
		//We don't put an endl here to keep everything on the same line, this is ok!
		cout << "Please enter a number to check if it is prime: ";

		//Get the number from the user
		cin >> input_number;

		//Use the function to check if the number is prime and give an appropriate output
		if (IsNumberPrime(input_number))
		{
			cout << "The number is prime!" << endl;
		}
		else
		{
			cout << "The number is not prime!" << endl;
		}

		//Check to see if we should continue by asking the user
		cout << "Would you like to check another number? (y/n) " << endl;
		cin >> input_character;

		//Use a switch to make it easier to check for both lower and upper case n,
		//if y we just do nothing, if n set run_loop to false to break the loop,
		//if other character output an error message, wait for one more input,
		//and exit the program
		switch (input_character)
		{
		case 'y':
		case 'Y':
			break;
		case 'n':
		case 'N':
			run_loop = false;
			break;
		default:
			cout << "Unkown answer, exiting loop, enter any character to exit." << endl;
			cin >> input_character;
			run_loop = false;
			break;
		}

	} while (run_loop);

	//Exit the program
    return 0;
}

bool IsNumberPrime(int number_to_check)
{
	//Assume the number is prime
	bool is_prime = true;

	//Divide the number by a divisor until we reach number_to_check - 1, if we don't find
	//a divisor (when the remainder is equal to 0) then our assumption holds and the number
	//is prime
	for (int divisor = 2; divisor < number_to_check; divisor++)
	{
		//Check to see if there is no remainder when dividing the number (this means it's not prime!)
		if (number_to_check % divisor == 0)
		{
			//Set is_prime to false and break the loop (no reason to continue as we know it's not prime)
			is_prime = false;
			break;
		}
	}

	//Return whether or not the value was prime
	return is_prime;
}