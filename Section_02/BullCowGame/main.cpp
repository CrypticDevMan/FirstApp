/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;
void PrintGameSummary();
//FText ignoreMe = "R74475";

// the entry point for our application
int main()
{
	PrintIntro();
	bool bPlayAgain = false;
	do
	{
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);
	return 0;
}

// introduce the game
void PrintIntro()
{
	std::cout << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of.\n";
	std::cout << std::endl;
	return;
}

// plays the game.
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess(); // TODO make loop check for valid guess

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

		std::cout << std::endl;
	}
	PrintGameSummary();
	return;
}

// get a guess from the player
// loop continually until the user gets a valid guess.
FText GetValidGuess()
{
	FText Guess = "";
	EWordStatus Status = EWordStatus::INVALID_STATUS;
	do
	{
		int32 currentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << currentTry << ". Please enter your guess for the isogram: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::NOT_ISOGRAM:
			std::cout << "Your entered guess is not valid, please enter a valid isogram guess.\n";
			std::cout << "An isogram is a word with no repeating letters\n";
			break;
		case EWordStatus::INCORRECT_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n";
			break;
		case EWordStatus::NOT_LOWERCASE:
			std::cout << "Please use all lowercase characters when entering a guess\n";
			break;
		default:
			break;
		}
	} while (Status != EWordStatus::OK); // keep looping until we get no errors
		return Guess;
	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word? (y/n)";
	FText Response = "";
	getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		std::cout << "We are now replying the game.\n";
		std::cout << std::endl;
		return true;
	}
	else
	{
		std::cout << "We are ending the game.\n";
		return false;
	}
	std::cout << std::endl;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU HAVE WON!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
