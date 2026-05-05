//Author: Joel Soto
//Date: 4/21/2026
//Purpose: Project 10

#include<stdio.h>
#include <stdbool.h>

#define WORD_LENGTH 5
#define MAX_GUESSES 6 

void readWord(char mystery[]);
void getGuess(char guess[]);
bool isValidGuess(char guess []);
void makeLowercase(char word[]);
bool isLetter(char ch);
bool wordsMatch(char word1[], char word2[]);
void saveGuess(char guesses[][WORD_LENGTH + 1], char guess[], int guessNum);
void printGuesses(char mystery[], char guesses[][WORD_LENGTH + 1], int guessCount);
void printOneGuess(char mystery[], char guess[]);
bool letterInWord(char mystery[], char letters); 

int main(){

	char mystery[WORD_LENGTH + 1];
	char guess[WORD_LENGTH + 1];
	char guesses[MAX_GUESSES][WORD_LENGTH + 1];
	
	int guessCount = 0;
	bool won = false;
	
	readWord(mystery);
	makeLowercase(mystery);
	
	while (guessCount < MAX_GUESSES && !won) {
		printf("GUESS %d! Enter your guess: ", guessCount + 1);
		getGuess(guess);
		
		while (!isValidGuess (guess)) { 
			printf("Your guess must be 5 letters long.\n");
			printf("please try again: ");
			getGuess(guess);
		}
	
	makeLowercase(guess);
	saveGuess(guesses, guess, guessCount);
	guessCount++;
	
	printf("================================\n");
	printGuesses(mystery, guesses, guessCount);
	
	if (wordsMatch(mystery, guess)) {
		won = true; 
		}
	}
	
	if (won) {
		printf("You won in %d guesses!\n", guessCount);
		printf("Nice!\n");
	} 
	else { 
		printf("You lost, better luck next time!");
		}
return 0;
}
	void readWord(char mystery[]) {
		FILE * file = fopen("word.txt", "r");
		
	if (file == NULL) {
		printf("Could not open word.txt\n");
		mystery[0] = '\0';
		return;
	}
	
	fscanf(file, "%5s", mystery);
	fclose(file);
	
}

	void getGuess(char guess[]) {
		scanf(" %5s", guess);
		
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF) {
		
		}
	}
	
	bool isValidGuess(char guess []) {
		int i = 0;
		
		while (guess[i] != '\0') {
			if (!isLetter(guess[i])) {
				return false;
			}
			i ++;
		}
		
		if (i != WORD_LENGTH) {
			return false;
		}
		
		return true;
	}
	
	bool isLetter(char ch) {
		if (ch >= 'a' && ch <= 'z'){
			return true;
		}
		if (ch >= 'A' && ch <= 'Z'){
			return true;
		}
		
		return false;
	}
	
	void makeLowercase(char word[]) {
		int i; 
		
		for (i = 0; word[i] != '\0'; i++) {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				word[i] = word[i] + 32; 
			}
		}
	}
	
	bool wordsMatch(char word[], char word2[]) { 
		int i;
		
		for (i = 0; i < WORD_LENGTH; i++) {
			if (word[i] != word2[i]) {
				return false;
			}
		}
		
		return true; 
	}
	
	void saveGuess(char guesses[][WORD_LENGTH + 1], char guess[], int guessNum) {
	int i; 
	
	for (i = 0; i < WORD_LENGTH; i++) {
		guesses[guessNum][i] = guess[i];
	}
	
	guesses[guessNum][WORD_LENGTH] = '\0';
	}
	
	void printGuesses(char mystery[], char guesses[][WORD_LENGTH + 1], int guessCount) {
	int i;
	
	for (i = 0; i < guessCount; i++) {
		printOneGuess(mystery, guesses[i]);
		printf("\n");
		}
	}
	
	void printOneGuess(char mystery[], char guess[]) {
		int i;
		
		for (i = 0; i < WORD_LENGTH; i++) {
			if (guess[i] == mystery[i]) {
				printf(" %c", guess[i] - 32);
			}
			else { 
				printf(" %c", guess[i]);
			}
		}
			
		printf("\n");
		
		for (i = 0; i < WORD_LENGTH; i++) {
			if (guess[i] != mystery[i] && letterInWord(mystery, guess[i])){
				printf("^");
			}
			else {
			printf(" ");
			}
		}
		
		printf("\n");
		}
		
		bool letterInWord(char mystery[], char letter) {
			int i;
			
			for (i = 0; i < WORD_LENGTH; i++) {
				if (mystery[i] == letter) { 
				return true; 
				}
			}
		return false;
		}
			
			
	
