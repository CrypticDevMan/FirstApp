#pragma once
#include <string>

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string);

private:
	// initialized in constructor
	int MyCurrentTry;
	int MyMaxTries;
};
