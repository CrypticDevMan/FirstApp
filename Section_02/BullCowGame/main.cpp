#include <iostream>
#include <string>

using namespace std;

int main() 
{
	// introduce the game
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of.\n";
	cout << endl;

	// get a guess from the player
	string Guess = "";
	cout << "Please enter your guess for the isogram: "; 
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;

	// get a guess from the player
	cout << "Please enter your guess for the isogram: ";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was: " << Guess << endl;
	cout << endl;
	return 0;
}
