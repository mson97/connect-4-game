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
  return win(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn) ||
      tie(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn);
}

bool win(char **board,
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
  int inARow = 0;
  if (piecesToWin > numCols) { // row isn't long enough to have a horizontal win
    return false;
  } else {
    for (int col = 0; col < numCols - 1; ++col) {
      if (board[rowPlayed][col] == blankSpace) {
        inARow = 0;
        continue;
      } else if (board[rowPlayed][col] != board[rowPlayed][col + 1]) {
        inARow = 0;
        continue;
      } else if (board[rowPlayed][col] == board[rowPlayed][col + 1] && board[rowPlayed][col] == piece) {
        ++inARow;
      }
      if (inARow == piecesToWin - 1) {
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
  int inARow = 0;
  if (piecesToWin > numRows) {
    return false;
  } else {
    for (int row = 0; row < numRows - 1; ++row) {
      if (board[row][colPlayed] == blankSpace) {
        inARow = 0;
        continue;
      } else if (board[row][colPlayed] != board[row + 1][colPlayed]) {
        inARow = 0;
        continue;
      } else if (board[row][colPlayed] == board[row + 1][colPlayed] && board[row][colPlayed] == piece) {
        ++inARow;
      }
      if (inARow == piecesToWin - 1) {
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
  if (piecesToWin > smallerDim) {
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
  int inARow;
  for (int posRow = 0; posRow <= numRows - piecesToWin; ++posRow) {
    inARow = 1;
    for (int pos = 0; pos < numCols - 1; ++pos) {
      if ((posRow + pos > numRows - 2) || (pos > numCols - 2)) {
        break;
      } else {
        if (board[posRow + pos][pos] == blankSpace) {
          inARow = 1;
        } else if (board[posRow + pos][pos] != board[posRow + pos + 1][pos + 1]) {
          inARow = 1;
        } else if (board[posRow + pos][pos] == board[posRow + pos + 1][pos + 1] && board[posRow + pos][pos] == piece) {
          ++inARow;
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
        if (board[pos][pos + posCol] == blankSpace) {
          inARow = 1;
        } else if (board[pos][pos + posCol] != board[pos + 1][pos + posCol + 1]) {
          inARow = 1;
        } else if (board[pos][pos + posCol] == board[pos + 1][pos + posCol + 1] && board[pos][pos + posCol] == piece) {
          ++inARow;
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
  int inARow;
  for (int posRow = 0; posRow <= numRows - piecesToWin; ++posRow) {
    inARow = 1;
    for (int pos = 0; pos < numCols - 1; ++pos) {
      if ((posRow + pos > numRows - 2) || (numCols - (pos + 1) < 1)) {
        break;
      } else {
        if (board[posRow + pos][numCols - (pos + 1)] == blankSpace) {
          inARow = 1;
        } else if (board[posRow + pos][numCols - (pos + 1)] != board[posRow + pos + 1][numCols - (pos + 2)]) {
          inARow = 1;
        } else if (board[posRow + pos][numCols - (pos + 1)] == board[posRow + pos + 1][numCols - (pos + 2)] &&
            board[posRow + pos][numCols - (pos + 1)] == piece) {
          ++inARow;
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
        if (board[pos][numCols - (posCol + pos + 1)] == blankSpace) {
          inARow = 1;
        } else if (board[pos][numCols - (posCol + pos + 1)] != board[pos + 1][numCols - (posCol + pos + 2)]) {
          inARow = 1;
        } else if (board[pos][numCols - (posCol + pos + 1)] == board[pos + 1][numCols - (posCol + pos + 2)] &&
            board[pos][numCols - (posCol + pos + 1)] == piece) {
          ++inARow;
        }
        if (inARow == piecesToWin) {
          return true;
        }
      }
    }
  }
  return false;
}

bool tie(char **board,
         const int numRows,
         const int numCols,
         const char blankSpace,
         const int piecesToWin,
         int rowPlayed,
         int colPlayed,
         const int playerTurn) {
  return !win(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn) &&
      isBoardFull(board, numRows, numCols, blankSpace);
}

bool isBoardFull(char **board, const int numRows, const int numCols, const int blankSpace) {
  for (int row = 0; row < numRows; ++row) {
    for (int col = 0; col < numCols; ++col) {
      if (board[row][col] == blankSpace) {
        return false;
      }
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
  if (win(board, numRows, numCols, blankSpace, piecesToWin, rowPlayed, colPlayed, playerTurn)) {
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
