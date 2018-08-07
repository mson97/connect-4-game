#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "win.h"
#include "move.h"

char **getValidInput(int numArgsRead, char **argsRead);
void usageAndExit();
void playGame(char** board, const int numRows, const int numCols, const int piecesToWin, const char blankSpace);

int main(int argc, char *argv[]) {
  int numRows, numCols, piecesToWin;
  const char blankSpace = '*';
  char **board;

  argv = getValidInput(argc, argv);
  numRows = atoi(argv[1]);
  numCols = atoi(argv[2]);
  piecesToWin = atoi(argv[3]);

  board = createBoard(numRows, numCols, blankSpace);
  playGame(board, numRows, numCols, piecesToWin, blankSpace);

  return 0;

}

char **getValidInput(int numArgsRead, char **argsRead) {
  if (numArgsRead < 4) {
    printf("Not enough arguments entered\n");
    usageAndExit();
  } else if (numArgsRead > 4) {
    printf("Too many arguments entered\n");
    usageAndExit();
  } else {
    for (int i = 1; i < 4; ++i) {
      if (atoi(argsRead[i]) <= 0) {
        printf("Improper arguments\n");
        usageAndExit();
      }
    }
  }
  return argsRead;
}

void usageAndExit() {
  printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
  exit(0);
}

void playGame(char** board, const int numRows, const int numCols, const int piecesToWin, const char blankSpace) {
  int colPlayed, rowPlayed = 0, playerTurn = 0;
  do {
    displayBoard(board, numRows, numCols);
    getMove(board, numRows, numCols, blankSpace, &colPlayed);
    makeMove(board, numRows, numCols, colPlayed, blankSpace, playerTurn, &rowPlayed);
    playerTurn = changeTurn(playerTurn);
  } while(!isGameOver(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn));

  declareWinnerOrTie(playerTurn, board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed);
  cleanUp(&board, numRows);
}
