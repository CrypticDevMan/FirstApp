#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


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
	constexpr int guessAllowed = 5;
	for (int i = 0; i < guessAllowed; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

// get a guess from the player
std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Please enter your guess for the isogram: ";
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
