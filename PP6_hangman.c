 //include
#include "hangman_lib.h"
#include <stdio.h>
//main function
int main()
{
	//declare varibles
		//int, char, bool
	int letter;
	char YorN = true;
	bool giveup = false;
	bool result;
	//initialize random number generator
		//srand, time
	
	
	//print titale of program
		//printf
	printf("***************************\n");
	printf("Welcome to the Hangman Game\n");
	printf("***************************\n\n");
	printf("Which letter? (0  to exit the game): ");
	scanf("%d", &letter);
	
	while (YorN)
	{
		result = play(giveup);
		if (result == 1)
		{
			//print message
				//printf
			printf("You won the round! Well done!/n/n");			
		}
		else
		{
			//print message
				//printf
			printf("You lost the round");	
		}
		
		//print message play again
			//printf
		printf("Do you want to play a new round? [y|n]");
		//store user input
			//scanf
		scanf("%c", &YorN);
		//condition will proceed if true
			//if conditon
		if (YorN == 'n')
		{
			//setting letter equal to 1
			YorN = false;
		}
	}
	return 1;
	
}