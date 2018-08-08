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
  if (!isValidFormat(numArgsRead, numArgsNeeded)) {
    return false;
  } else if (!isInBounds(colPlayed, 0, numCols - 1)) {
    return false;
  } else if (board[0][colPlayed] != blankSpace) { // top row must be avail
    return false;
  } else {
    return true;
  }
}

void makeMove(char **board, const int numRows, const int numCols, const int colPlayed, const char blankSpace,
              int playerTurn, int *rowPlayed) {
  char move;
  if (playerTurn == 0) {
    move = 'X';
  } else {
    move = 'O';
  }
  for (int row = numRows - 1; row >= 0; --row) { // start from bottom row
    if (board[row][colPlayed] == blankSpace) {
      board[row][colPlayed] = move;
      *rowPlayed = row;
      break;
    }
  }
}

int changeTurn(const int playerTurn) {
  if (playerTurn == 0) {
    return 1;
  } else {
    return 0;
  }
}