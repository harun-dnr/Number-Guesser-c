# Number Guesser (C)

A simple CLI (Command Line Interface) number guessing game written in C.
The player tries to guess a randomly generated number within a limited scoring system.

---

## Features

* Difficulty levels:

  * Easy (1–25) → 10 points penalty
  * Medium (1–50) → 20 points penalty
  * Hard (1–100) → 25 points penalty

* Score system:

  * Starts with 100 points
  * Points decrease after each wrong guess

* Feedback system:

  * Indicates whether the guess is too high or too low

* Attempt tracking:

  * Displays total number of attempts

* Input validation:

  * Prevents invalid (non-numeric) inputs

---

## Example Run

```bash

>>>NUMBER GUESSER GAME<<<

Select difficulty:
E - Easy   (1-25)
M - Medium (1-50)
H - Hard   (1-100)
Choice: M

Penalty per wrong guess: 20

Guess the number between 1 and 50

>> Enter your guess: 25
Too high!
Points remaining: 80

>> Enter your guess: 12
Too low!
Points remaining: 60

>> Enter your guess: 18
Correct! You guessed it in 3 attempts.
Final score: 60
```

---

## Concepts Used

* Random number generation (`rand`, `srand`, `time`)
* Input handling and buffer control
* Loops and conditional logic
* Functions for modular design
* Macros for configuration

---

## How to Run

Make sure you have a C compiler installed (e.g. GCC).

```bash
gcc main.c -o NumberGuesser
./NumberGuesser
```

---

## Project Structure

```
NumberGuesser/
│
├── main.c
└── README.md
```

---

## Future Improvements

* Replay option (play again without restarting)
* High score system (file-based)
* Improved UI/UX
* Optional colored terminal output

---

## Author

Harun Doner
Computer Engineering Student
