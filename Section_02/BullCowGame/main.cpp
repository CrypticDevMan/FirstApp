#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;

// the entry point for our application
int main() 
{
	PrintIntro();
	bool bPlayAgain = false;
	do {
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);
	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of.\n";
	std::cout << std::endl;
	return;
}

// plays the game.
void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	// TODO change from FOR loop to WHILE loop
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess(); // TODO make loop check for valid guess's

		// submit valid guess to the game
		// print number of bulls and cows.

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

// get a guess from the player
std::string GetGuess()
{
	int currentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << currentTry << ". Please enter your guess for the isogram: ";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	std::string Response = "";
	getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		std::cout << "We are now replying the game.\n";
		return true;
	} else {
		std::cout << "We are ending the game.\n";
		return false;
	}
	std::cout << std::endl;
}
