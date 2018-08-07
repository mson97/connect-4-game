//
// Created by Minhee Son on 11/17/17.
//

#ifndef CONNECTN_BOARD_H
#define CONNECTN_BOARD_H

  void displayBoard(char** board, const int numRows, const int numCols);
  char** createBoard(const int numRows, const int numCols, const char blankSpace);
  void cleanUp(char ***board, const int numRows);

#endif //CONNECTN_BOARD_H
