//
// Created by Minhee Son on 11/17/17.
//

#include <stdio.h>
#include "move.h"
#include "valid.h"

void getMove(char **board, const int numRows, const int numCols, const char blankSpace, int *colPlayed) {
  int numArgsRead;
  const int numArgsNeeded = 1;
  do {
    printf("Enter a column between 0 and %d to play in: ", numCols - 1);
    numArgsRead = scanf(" %d", colPlayed);
  } while (!isValidMove(numArgsRead, numArgsNeeded, board, numRows, numCols, *colPlayed, blankSpace));
}

bool isValidMove(const int numArgsRead, const int numArgsNeeded, char **board, const int numRows,
                 const int numCols, int colPlayed, const char blankSpace) {
  if (!isValidFormat(numArgsRead, numArgsNeeded)) { // has to be one argument entered
    return false;
  } else if (!isInBounds(colPlayed, 0, numCols - 1)) { // must be b/w 0 and max dimensions
    return false;
  } else if (board[0][colPlayed] != blankSpace) { // must be blank space at at least top row
    return false;
  } else {
    return true;
  }
}

void makeMove(char **board, const int numRows, const int numCols, const int colPlayed, const char blankSpace,
              int playerTurn, int *rowPlayed) {
  char piecePlayed;
  if (playerTurn == 0) {
    piecePlayed = 'X';
  } else {
    piecePlayed = 'O';
  }
  for (int row = numRows - 1; row >= 0; --row) { // iterates through rows from bottom to top
    if (board[row][colPlayed] == blankSpace) { // checks if the space is blank at the row
      board[row][colPlayed] = piecePlayed; // changes the blank space to player's piece
      *rowPlayed = row;
      break;
    }
  }
}

int changeTurn(const int playerTurn) {
  if (playerTurn == 0) { // playerTurn starts at 0
    return 1; // changes playerTurn to 1
  } else { // playerTurn starts at 1
    return 0; // changes playerTurn to 0
  }
}