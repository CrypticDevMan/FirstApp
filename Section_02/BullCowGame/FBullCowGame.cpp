#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAXIMUM_TRIES = 8;
	MyMaxTries = MAXIMUM_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HIDDENWORDLENGTH = MyHiddenWord.length();
	for (int32 i = 0; i < HIDDENWORDLENGTH; i++)
	{
		// compare letters agaisnt the hidden word
		for (int32 j = 0; j < HIDDENWORDLENGTH; j++)
		{
			// if they match
			if (Guess[i] == MyHiddenWord[i])
			{
				// if they're in the same place
				if (i == j)
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				else
				{
					// increment cows
					BullCowCount.Cows++;
				}
			}
		}
	}

	// increment the turn number
	return BullCowCount;
}
