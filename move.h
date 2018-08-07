//
// Created by Minhee Son on 11/17/17.
//

#ifndef CONNECTN_MOVE_H
#define CONNECTN_MOVE_H
#include <stdbool.h>

  void getMove(char **board, const int numRows, const int numCols, const char blankSpace, int* colPlayed);
  bool isValidMove(const int numArgsRead, const int numArgsNeeded, char **board, const int numRows,
                 const int numCols, int colPlayed, const char blankSpace);
  void makeMove(char** board, const int numRows, const int numCols, const int colPlayed, const char blankSpace,
              int playerTurn, int* rowPlayed);
  int changeTurn(const int playerTurn);

#endif //CONNECTN_MOVE_H
