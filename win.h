//
// Created by Minhee Son on 11/17/17.
//

#ifndef CONNECTN_WIN_H
#define CONNECTN_WIN_H
#include <stdbool.h>

  bool isGameOver(char **board, const int numRows, const int numCols, const char blankSpace, const int piecesToWin,
                  int rowPlayed, int colPlayed, const int playerTurn);
  bool win(char** board, const int numRows, const int numCols, const char blankSpace, const int piecesToWin,
         int rowPlayed, int colPlayed, const int playerTurn);
  bool horizWin(char **board, const int numCols, const char blankSpace, const int piecesToWin, const int playerTurn,
              int rowPlayed);
  bool vertWin(char **board, const int numRows, const char blankSpace, const int piecesToWin, const int playerTurn,
             int colPlayed);
  bool diagWin(char **board, const int numRows, const int numCols, const char blankSpace, const int piecesToWin,
             const int playerTurn);
  bool leftDiagWin(char **board, const int numRows, const int numCols, const char blankSpace, const int piecesToWin,
                 const int playerTurn);
  bool rightDiagWin(char **board, const int numRows, const int numCols, const char blankSpace, const int piecesToWin,
                  const int playerTurn);
  bool tie(char** board, const int numRows, const int numCols, const char blankSpace, const int piecesToWin,
         int rowPlayed, int colPlayed, const int playerTurn);
  bool isBoardFull(char **board, const int numRows, const int numCols, const int blankSpace);
  void declareWinnerOrTie(const int playerTurn, char **board, const int numRows, const int numCols,
                        const char blankSpace, const int piecesToWin, int rowPlayed, int colPlayed);
  char playerPiece(const int playerTurn);

#endif //CONNECTN_WIN_H
