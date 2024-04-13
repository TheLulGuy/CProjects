#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game(int lowerLimit, int upperLimit){
    // rand generates random values using the same seed
    // this changes it so that the seed is the current time
    srand(time(NULL));

    int input;
    int guesses = 0;
    // int randomNumber = rand() % upperLimit + lowerLimit;
    int randomNumber = 50;
    while(1){
        // Starting prompt
        printf("Choose a random number between %d and %d >", lowerLimit, upperLimit);
        scanf("%d", &input);
        if(randomNumber > input){
            printf("Higher\n");
            guesses++;
        }
        else if(randomNumber < input){
            printf("Lower\n");
            guesses++;
        }
        else if(randomNumber == input){
            printf("Correct!\n");
            break;
        }
    }
    printf("You guessed the number in %d tries\n", guesses);
}

int main(){
    int lowerLimit = 0;
    int upperLimit = 100;
    char playAgain;


    game(lowerLimit, upperLimit);

    printf("Play again?\n");

    // scanf takes the \n as input, and thus never gets the users input
    // getchar() consumes the \n beforehand 
    getchar();
    scanf("%c", &playAgain);
    if(playAgain == 'y'){
        game(lowerLimit, upperLimit);
    }
    
}