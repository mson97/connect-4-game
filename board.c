//
// Created by Minhee Son on 11/17/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void displayBoard(char **board, const int numRows, const int numCols) {
  int numDigits;
  if (numRows >= 10 || numCols >= 10) { // lrg board
      numDigits = 2;
  } else {
    numDigits = 1;
  }
  if (numDigits == 1) { // print reg board
    for (int row = 0; row < numRows; ++row) {
      printf("%d ", numRows - (row + 1));
      for (int col = 0; col < numCols; ++col) {
        printf("%c ", board[row][col]);
      }
      printf("\n");
    }
    printf("  ");
    for (int col = 0; col < numCols; ++col) {
      printf("%d ", col);
    }
    printf("\n");
  }
  if (numDigits == 2) { // print lrg board
    for (int row = 0; row < numRows; ++row) {
      printf("%2d ", numRows - (row + 1));
      for (int col = 0; col < numCols; ++col) {
        printf("%2c ", board[row][col]);
      }
      printf("\n");
    }
    printf("   ");
    for (int col = 0; col < numCols; ++col) {
      printf("%2d ", col);
    }
    printf("\n");
  }
}

char **createBoard(const int numRows, const int numCols, const char blankSpace) {
  char **board = (char **) malloc(numRows * sizeof(char *));
  for (int row = 0; row < numRows; ++row) {
    board[row] = (char *) malloc(numCols * sizeof(char));
    for (int col = 0; col < numCols; ++col) {
      board[row][col] = blankSpace;
    }
  }
  return board;
}

void cleanUp(char ***board, const int numRows) {
  for (int row = 0; row < numRows; ++row) {
    free((*board)[row]);
  }
  free(*board);
  *board = NULL;
}