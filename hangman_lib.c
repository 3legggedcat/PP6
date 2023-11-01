//include
#include "hangman_lib.h"

//function intializeRandom

void initializeRandom()
	{
		// initalize random number generator
			// functions: srand, time
		srand(time(NULL));
	}
	
//function getSecretWord

int getSecretWord(char secretWord[])
	{
		//declare random number and have it squal to a 
		//random number modula LEN_FRUITS
			//rnad, int
		int randNum = rand() % LEN_FRUITS;
		//point to the string in fruits at a index
			//const char*
		secretWord = strcpy(secretWord, FRUITS[randNum]);
		//string length of the word
			//int, strlen
		int wordLen = strlen(secretWord);
		//return worlen
		//return
		return wordLen;
	}
//function to build a array
void buildOutputArray(int size, char outputArray[])
{
	//loop from 0 to size and increase by one
	//for loop
	for (int i = 0; i < size; i++)
	{
		//set the outputArray to "_" at index i
		outputArray[i] = "_";
	}
	outputArray[size] = '\0';
	
}

//function to build a wrong guess array
void buildAttemptArray(char *array[7])
{
	for (int i = 0; i < 7; i++)
	{
		array[i] = '*';
	}

	array[ATTEMPTS] = '\0';
		
		
}

bool checkGuess(char guess, char* secretWord[])
{
	for (int i = 0; i < secretWord[i]; i++ )
	{
		if (secretWord[i] == guess)
		{
			return true;
		}
			
	}
	return false;
}
//function fillOutputArray
bool fillOutputArray(char guess, const char* secretWord[], char* outputArray)
{
	for (int i = 0; i < secretWord[i]; i++ )
	{
		if (secretWord[i] == guess)
		{
			if (outputArray[i] == '_')
			{
				outputArray[i] = guess;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}




//function fillAttemptsArray

bool fillAttemptsArray(char guess, char* array)
{
	for (int i = 0; i < 6; i++)
	{
		if (array[i] == '*')
		{
			array[i] = guess;
			return true;
		}
		else if (array[i] == guess)
		{
			return false;
		}
	}
}

bool checkVictory( const char outputArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (outputArray[i] == '_')
		{
			return false;
		}
	}
	return true;
}

bool checkDefeat( const char array[])
{
	for (int i = 0; i < ATTEMPTS; i++)
	{
		if (array[i] == '*')
		{
			return false;
		}
	}
	return true;
}



bool play(bool* giveup)
{
    char secretWord[MAX_FRUIT_SIZE];
    int size;
    char outputArray[MAX_FRUIT_SIZE];
    char array[ATTEMPTS + 1]; // +1 for null terminator
    char guess;

    initializeRandom();
    size = getSecretWord(secretWord);
    buildOutputArray(size, outputArray);
    buildAttemptArray(array);

    int attempts = 0;
    bool victory = false;
    bool defeat = false;

    printf("Guess the word: %s\n", outputArray);

    while (!victory && !defeat) 
	{
        printf("Enter your guess (or 0 to give up): ");
        scanf(" %c", &guess);

        if (guess == '0') 
		{
            *giveup = true;
            return false;
        }

        if (checkGuess(guess, secretWord)) 
		{
            if (fillOutputArray(guess, secretWord, outputArray)) 
			{
                printf("Correct guess: %s\n", outputArray);
                if (checkVictory(outputArray, size)) 
				{
                    *giveup = false;
                    return true;
                }
            } 
			else 
			{
                printf("Repeated guess. Try again.\n");
            }
        } 
		else 
		{
            if (fillAttemptsArray(guess, array)) 
			{
                attempts++;
                printf("Incorrect guess. Attempts remaining: %d\n", ATTEMPTS - attempts);
                if (attempts == ATTEMPTS) 
				{
                    defeat = true;
                }
            } 
			else 
			{
                printf("Repeated guess. Try again.\n");
            }
        }
    }

    if (defeat = true) 
	{
        *giveup = false;
        printf("You've run out of attempts. The word was: %s\n", secretWord);
    }

    return true;
}
	

	
