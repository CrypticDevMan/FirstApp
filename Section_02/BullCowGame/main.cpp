#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

// the entry point for our application
int main() 
{
	PrintIntro();
	PlayGame();
	return 0;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of.\n";
	cout << endl;
	return;
}

// plays the game.
void PlayGame()
{
	constexpr int guessAllowed = 5;
	for (int i = 0; i < guessAllowed; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

// get a guess from the player
string GetGuess()
{
	string Guess = "";
	cout << "Please enter your guess for the isogram: ";
	getline(cin, Guess);
	return Guess;
}