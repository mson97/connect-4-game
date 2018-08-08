#include <stdio.h>
#include "win.h"
#include "board.h"

bool isGameOver(char **board,
                const int numRows,
                const int numCols,
                const char blankSpace,
                const int piecesToWin,
                int rowPlayed,
                int colPlayed,
                const int playerTurn) {
  return isWin(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn) ||
      isTie(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn);
}

bool isWin(char **board,
         const int numRows,
         const int numCols,
         const char blankSpace,
         const int piecesToWin,
         int rowPlayed,
         int colPlayed,
         const int playerTurn) {
  return horizWin(board, numCols, blankSpace, piecesToWin, playerTurn, rowPlayed) ||
      vertWin(board, numRows, blankSpace, piecesToWin, playerTurn, colPlayed) ||
      diagWin(board, numRows, numCols, blankSpace, piecesToWin, playerTurn);
}

bool horizWin(char **board,
              const int numCols,
              const char blankSpace,
              const int piecesToWin,
              const int playerTurn,
              int rowPlayed) {
  char piece = playerPiece(playerTurn);
  int inARow = 1;
  if (piecesToWin > numCols) { // row too short
    return false;
  } else {
    for (int col = 0; col < numCols - 1; ++col) {
      if (board[rowPlayed][col] == piece && board[rowPlayed][col] == board[rowPlayed][col + 1]) {
        ++inARow;
      } else {
        inARow = 1;
        continue;
      }
      if (inARow == piecesToWin) {
        return true;
      }
    }
    return false;
  }
}

bool vertWin(char **board,
             const int numRows,
             const char blankSpace,
             const int piecesToWin,
             const int playerTurn,
             int colPlayed) {
  char piece = playerPiece(playerTurn);
  int inARow = 1;
  if (piecesToWin > numRows) { // col too short
    return false;
  } else {
    for (int row = 0; row < numRows - 1; ++row) {
      if (board[row][colPlayed] == piece && board[row][colPlayed] == board[row + 1][colPlayed]) {
        ++inARow;
      } else {
        inARow = 1;
        continue;
      }
      if (inARow == piecesToWin) {
        return true;
      }
    }
    return false;
  }
}

bool diagWin(char **board,
             const int numRows,
             const int numCols,
             const char blankSpace,
             const int piecesToWin,
             const int playerTurn) {
  int smallerDim;
  if (numRows > numCols) {
    smallerDim = numCols;
  } else {
    smallerDim = numRows;
  }
  if (piecesToWin > smallerDim) { // no possible diags
    return false;
  } else {
    return leftDiagWin(board, numRows, numCols, blankSpace, piecesToWin, playerTurn) ||
        rightDiagWin(board, numRows, numCols, blankSpace, piecesToWin, playerTurn);
  }
}

bool leftDiagWin(char **board,
                 const int numRows,
                 const int numCols,
                 const char blankSpace,
                 const int piecesToWin,
                 const int playerTurn) {
  char piece = playerPiece(playerTurn);
  int inARow = 1;
  for (int posRow = 0; posRow <= numRows - piecesToWin; ++posRow) {
    for (int pos = 0; pos < numCols - 1; ++pos) {
      if ((posRow + pos > numRows - 2) || (pos > numCols - 2)) {
        break;
      } else {
        if (board[posRow + pos][pos] == piece && board[posRow + pos][pos] == board[posRow + pos + 1][pos + 1]) {
          ++inARow;
        } else {
          inARow = 1;
        }
        if (inARow == piecesToWin) {
          return true;
        }
      }
    }
  }
  for (int posCol = 1; posCol <= numCols - piecesToWin; ++posCol) {
    inARow = 1;
    for (int pos = 0; pos < numRows - 1; ++pos) {
      if ((pos > numRows - 2) || (pos + posCol > numCols - 2)) {
        break;
      } else {
        if (board[pos][pos + posCol] == piece && board[pos][pos + posCol] == board[pos + 1][pos + posCol + 1]) {
          ++inARow;
        } else {
          inARow = 1;
        }
        if (inARow == piecesToWin) {
          return true;
        }
      }
    }
  }
  return false;
}

bool rightDiagWin(char **board,
                  const int numRows,
                  const int numCols,
                  const char blankSpace,
                  const int piecesToWin,
                  const int playerTurn) {
  char piece = playerPiece(playerTurn);
  int inARow = 1;
  for (int posRow = 0; posRow <= numRows - piecesToWin; ++posRow) {
    for (int pos = 0; pos < numCols - 1; ++pos) {
      if ((posRow + pos > numRows - 2) || (numCols - (pos + 1) < 1)) {
        break;
      } else {
        if (board[posRow + pos][numCols - (pos + 1)] == piece &&
            board[posRow + pos][numCols - (pos + 1)] == board[posRow + pos + 1][numCols - (pos + 2)]) {
          ++inARow;
        } else {
          inARow = 1;
        }
        if (inARow == piecesToWin) {
          return true;
        }
      }
    }
  }
  for (int posCol = 1; posCol <= numCols - piecesToWin; ++posCol) {
    inARow = 1;
    for (int pos = 0; pos < numCols - 1; ++pos) {
      if (pos > numRows - 2 || numCols - (posCol + pos + 1) < 1) {
        break;
      } else {
        if (board[pos][numCols - (posCol + pos + 1)] == piece &&
            board[pos][numCols - (posCol + pos + 1)] == board[pos + 1][numCols - (posCol + pos + 2)]) {
          ++inARow;
        } else {
          inARow = 1;
        }
        if (inARow == piecesToWin) {
          return true;
        }
      }
    }
  }
  return false;
}

bool isTie(char **board,
         const int numRows,
         const int numCols,
         const char blankSpace,
         const int piecesToWin,
         int rowPlayed,
         int colPlayed,
         const int playerTurn) {
  return !isWin(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn) &&
      isBoardFull(board, numRows, numCols, blankSpace);
}

bool isBoardFull(char **board, const int numRows, const int numCols, const int blankSpace) {
    for (int col = 0; col < numCols; ++col) { // check top row is full
      if (board[0][col] == blankSpace) {
        return false;
      }
    }
  return true;
}

void declareWinnerOrTie(const int playerTurn,
                        char **board,
                        const int numRows,
                        const int numCols,
                        const char blankSpace,
                        const int piecesToWin,
                        int rowPlayed,
                        int colPlayed) {
  displayBoard(board, numRows, numCols);
  if (isWin(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn)) {
    if (playerTurn == 0) {
      printf("Player 2 Won!\n");
    } else {
      printf("Player 1 Won!\n");
    }
  } else {
    printf("Tie game!\n");
  }
}

char playerPiece(const int playerTurn) {
  if (playerTurn == 1) {
    return 'X';
  } else {
    return 'O';
  }
}
