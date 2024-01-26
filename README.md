# Bingo

Project Title: Bingo-Style Game Simulator

Description
This project features a C program designed to simulate a Bingo-style game. The game operates by reading a 5x5 card of integers from a file and then simulating a number-calling sequence. The goal is to mark numbers on the card until a winning condition, such as a complete row, column, or corners, is met.


Features

Dynamic Number Calling: Implements pseudo-random number generation to call game numbers.
Win Detection: Automatically checks for winning conditions in the game.

User Interaction: Allows players to control the game flow and exit when desired.


How to Run

Compile with the included Makefile.
Execute with command-line arguments for the seed and card file.
Ensure the card file follows the format detailed in the documentation.


Technologies

C programming language.
Makefile for easy compilation.
Standard C libraries for random generation and file I/O.
