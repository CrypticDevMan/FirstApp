#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAXIMUM_TRIES = 8;
	MyMaxTries = MAXIMUM_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;

	MyCurrentTry = 1;
	return;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!bIsIsoGram(Guess)) // if the guess isn't a isogram,
	{
		return EWordStatus::NOT_ISOGRAM;
	}
	else if (!bIsLowercase(Guess)) // if the guess isn't all lowercase
	{
		return EWordStatus::NOT_LOWERCASE;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is incorrect
	{
		return EWordStatus::INCORRECT_LENGTH;
	}
	else // otherwise
	{
		return EWordStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WORDLENGTH = MyHiddenWord.length();

	for (int32 i = 0; i < WORDLENGTH; i++) // loop through all letters in the hidden word
	{
		for (int32 j = 0; j < WORDLENGTH; j++) // compare letters agaisnt the guess
		{
			if (Guess[j] == MyHiddenWord[i]) // if they match
			{
				if (i == j) // if they're in the same place
				{
					BullCowCount.Bulls++; // increment bulls
				}
				else 
				{
					BullCowCount.Cows++; // increment cows
				}
			}
		}
	}
	if (BullCowCount.Bulls == WORDLENGTH) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount; // increment the turn number
}

bool FBullCowGame::bIsIsoGram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) // for all letters of the word
	{
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) { 
			return false; // if the letter is in the map
		} else { 
			LetterSeen[Letter] = true; 
		} 
	}
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::bIsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
