#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	INVALID_STATUS,
	OK,
	NOT_ISOGRAM,
	INCORRECT_LENGTH,
	NOT_LOWERCASE
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	EWordStatus CheckGuessValidity(FString) const;

	void Reset();
	// counts bulls and cows, and increases the try # assuming valid guess.
	FBullCowCount SubmitValidGuess(FString);

private:
	// initialized in constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool bIsIsoGram(FString) const;
	bool bIsLowercase(FString) const;
};
