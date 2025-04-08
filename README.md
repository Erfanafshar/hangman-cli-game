# Hangman CLI Game

A classic Hangman-style word guessing game implemented in C — with a twist. Instead of getting hanged, your character slowly drowns with each incorrect guess. This project demonstrates structured programming, file I/O, dynamic memory, and user interaction in a command-line interface.

## Features

- Multiple topics to choose from (e.g., video games, programming languages, food)
- Words loaded dynamically from `.txt` files using linked lists
- Interactive terminal-based gameplay with real-time feedback
- Save and resume game sessions with persistent scoring
- Custom scoring system based on word length and number of incorrect guesses
- ASCII art visualizes each stage of the drowning sequence (5 stages total)

## Tech Stack

- Language: C
- Concepts: File I/O, structs, linked lists, dynamic memory allocation, string handling
- Platform: Command Line Interface (CLI)

## Topics File Structure

```
topics/
├── video_games.txt
├── programming_languages.txt
├── foods.txt
└── AVAILABLE_TOPICS.txt
```

Each `.txt` file contains lowercase words separated by spaces, one file per topic.

## How to Run

1. Compile the program:

   ```bash
   gcc -o hangman main.c
   ```

2. Run the game:

   ```bash
   ./hangman
   ```

3. Follow the prompts to enter your name, choose a topic, and begin guessing letters.

## Notes

- Player progress and high scores can be saved and reloaded between sessions.
- Typing `Q` at any time will initiate a clean exit and optional save prompt.
- The character drowning sequence is visualized through progressive ASCII drawings after each incorrect guess.

## Preview

```
+-----+
| o o |
|  |  |
| --- |
+-----+
/\/\/\/\/\/\/\/\/\/\/\/\
/////////////////////////
\\\\\\\\\\\\
```
