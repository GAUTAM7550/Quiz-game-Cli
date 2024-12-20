#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<windows.h>

#define MAX_PLAYERS 10
#define MAX_ATTEMPTS 10
#define MAX_ROUNDS 5

char words[][20] = {"computer", "programming", "algorithm", "memory", "keyboard", "mouse", "screen", "printer", "software", "hardware"};

int main() {
    char choice;
    int num_players, round, player, word_idx, i, j;
    char scrambled_word[20], guess[20];
    int player_score[MAX_PLAYERS] = {0};
    int  num_attempts, attempt;

    srand(time(NULL));
system("color 4");
    printf("=============WELCOME TO THE WORD SCRAMBLE GAME !============\n");
    printf("------------------------------------------------------------\n");

    do { printf("\n");
    system("color 8");
        printf("Enter 'p' to play or 'q' to exit: ");
        scanf(" %c", &choice);

        if (choice == 'p') {system("color a");
            printf("Enter the number of players (max %d): ", MAX_PLAYERS);
            scanf("%d", &num_players);
               if (num_players > MAX_PLAYERS) {
                system("color 4");
                printf("Invalid number of players\n");
                continue;
               
            }
            char players[50];
            for(int i=0; i<num_players; i++)
          
          {system("color 3");
          	printf("Enter the name of the player %d:",i+1);
          scanf("%s",&players[i]);
          	
          }system("color e");
           printf("Enter the number of attempts per player (max %d): ", MAX_ATTEMPTS);
            scanf("%d", &num_attempts);
          printf("\n");
            for (round = 1; round <= MAX_ROUNDS; round++) {
            	system("color 9");
        printf("\nRound %d\n", round);


  // Randomize order of words
        srand(time(NULL));
        for (i = 0; i < 10; i++) {
        j = rand() % 10;
        char temp[30];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
  } 
  // Loop through players
  for (player = 1;  player <= num_players;  player++) {
    system("color 6");
    printf("\nPlayer %d's turn.\n", player);

    // Loop through attempts
 
    for (attempt = 1; attempt <= num_attempts; attempt++) {
      // Select wor
   
      word_idx = rand() % 10;
      strcpy(scrambled_word, words[word_idx]);

      // Scramble word
      for (i = 0; i < strlen(scrambled_word); i++) {
        j = rand() % strlen(scrambled_word);
        char temp = scrambled_word[i];
        scrambled_word[i] = scrambled_word[j];
        scrambled_word[j] = temp;
      }

      // Prompt player for guess
      system("color 2");
      printf("\nAttempt %d of %d. Unscramble the word: %s\nscrambled word =>", attempt, num_attempts, scrambled_word);
      scanf("%s", guess);

      // Check guess
      if (strcmp(guess, words[word_idx]) == 0) {system("color 3");
        printf("\nCorrect! The word was %s.\n", words[word_idx]);
        player_score[player-1]++;
        break;
      } else {system("color c");
        printf("\nIncorrect guess.The Correct word was %s\n", words[word_idx]);
      }
    }
  }
}	system("color 4");
            printf("\nGame over.\n");
            int max_score = 0;
            for (player = 1; player <= num_players; player++) {
                system("color 2");
                printf("Player %d's score: %d\n", player, player_score[player-1]);
                if (player_score[player-1] > max_score) {
                    max_score = player_score[player-1];
                }
            }system("color 9");
            printf("Winner(s):");
            for (player = 1; player <= num_players; player++) {
                if (player_score[player-1] == max_score) {
                    printf(" Player %d", player);
                }
            }
            printf("\n");
        }

 } while (choice != 'q');

    return 0;
}
