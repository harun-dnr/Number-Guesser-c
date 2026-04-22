#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_POINTS 100

#define EASY_PENALTY   10
#define MEDIUM_PENALTY 20
#define HARD_PENALTY   25

int generate_number(int min, int max);
void clear_input_buffer(void);

int main() {
    char difficulty;
    int min = 1, max = 100;
    int secret_number;
    int guess;
    int points = MAX_POINTS;
    int attempts = 0;
    int penalty = EASY_PENALTY;

    srand(time(NULL));

    printf(">>>NUMBER GUESSER GAME<<<\n\n");

    // Difficulty selection
    while (1) {
        printf("\nSelect difficulty:\n");
        printf("E - Easy   (1-25)\n");
        printf("M - Medium (1-50)\n");
        printf("H - Hard   (1-100)\n");
        printf("Choice: ");

        if (scanf(" %c", &difficulty) != 1) {
            clear_input_buffer();
            continue;
        }

        difficulty = toupper(difficulty);

        if (difficulty == 'E') {
            max = 25;
            penalty = EASY_PENALTY;
            break;
        } else if (difficulty == 'M') {
            max = 50;
            penalty = MEDIUM_PENALTY;
            break;
        } else if (difficulty == 'H') {
            max = 100;
            penalty = HARD_PENALTY;
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("\nPenalty per wrong guess: %d\n", penalty);

    secret_number = generate_number(min, max);

    printf("\nGuess the number between %d and %d\n", min, max);

    // Game loop
    while (points > 0) {
        printf("\n>> Enter your guess: ");

        if (scanf("%d", &guess) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        attempts++;

        if (guess == secret_number) {
            printf("\nCorrect! You guessed it in %d attempts.\n", attempts);
            printf("Final score: %d\n", points);
            break;
        }

        if (guess < secret_number) {
            printf("Too low! Try higher.\n");
        } else {
            printf("Too high! Try lower.\n");
        }

        // Penalty application
        if (points >= penalty) {
            points -= penalty;
        } else {
            points = 0;
        }

        printf("Points remaining: %d\n", points);
    }

    if (points == 0) {
        printf("\nGame over! The number was: %d\n", secret_number);
    }

    printf("\nThanks for playing!\n");
    return 0;
}

// Random number generator
int generate_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Clear input buffer
void clear_input_buffer(void) {
    while (getchar() != '\n');
}
