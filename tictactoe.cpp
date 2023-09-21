/* This program simulates a game of tic-tac-toe and keeps track of the players' wins.
 * Date: 9/21/23
 * Author: Roger Li
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int checkWin(char board[4][4]);
int checkDraw(char board[4][4]);

int main() {
  int playerMove = 0;
  int playerOneScore = 0;
  int playerTwoScore = 0;
  bool gameOver = false;
  bool firstTime = true;
  bool yn = true;
  bool round = true;
  int winOrNot;
  int row;
  int oWins = 0;
  int xWins = 0;
  int draw;
  
  char board[4][4];

  board[0][0] = ' ';
  board[1][0] = 'a';
  board[2][0] = 'b';
  board[3][0] = 'c';
  board[0][1] = '1';
  board[0][2] = '2';
  board[0][3] = '3';

  while (gameOver == false && yn == true) {
    if (firstTime == true) {
      for(int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
          board[i][j] = ' ';
        }
      }
      firstTime = false;
    }
    
    for(int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (j < 3) {
  	  cout << board[i][j];
        }
        if (j == 3) {
	  cout << board[i][j] << endl;
        }
      }
    }

    round = true;
    while (round == true) {
      // Prompt an input
      char input[9];
      cin.get(input, 8);
      cin.get();

      int column = input[1] - '0';

      // Player X's move
      if (playerMove == 0) {
        // Check for a valid input
        if ((column > 0 && column < 4) && (input[0] == 'a' || input[0] == 'b' || input[0] == 'c')){
	  if (input[0] == 'a') {
	    row = 1;
	  }
	  else if (input[0] == 'b') {
	    row = 2;
	  }
	  else if (input[0] == 'c') {
	    row = 3;
	  }
	  // Check if move is in an empty square
	  if (board[row][column] == ' ') {
	    board[row][column] = 'X';
	    playerMove = 1;
	    round = false;
	    winOrNot = checkWin(board);
	    // Check for a win
	    if (winOrNot == 1) {
	      for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
		  if (j < 3) {
		    cout << board[i][j];
		  }
		  if (j == 3) {
		    cout << board[i][j] << endl;
		  }
		}
	      }
	      xWins++;
	      cout << "X Wins!" << endl;
	      cout << "The current score is X:" << xWins << ", O:" << oWins << endl;
	    }
	  }
	  else {
	    cout << "You can't play there!" << endl;
	  }
	}  
	else {
	  cout << "Not a valid move, try again." << endl;
	}
      }
      // Player O's move
      else if (playerMove == 1) {
	// Check if move is valid
	if ((column > 0 && column < 4) && (input[0] == 'a' || input[0] == 'b' || input[0] == 'c')){
	  if (input[0] == 'a') {
	    row = 1;
	  }
	  else if (input[0] == 'b') {
	    row = 2;
	  }
	  else if (input[0] == 'c') {
	    row = 3;
	  }
	  // Checks if move is in an empty square
	  if (board[row][column] == ' ') {
	    board[row][column] = 'O';
	    playerMove = 0;
	    round = false;
	    winOrNot = checkWin(board);
	    // Check for a win
	    if (winOrNot == 1) {
	      for(int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
		  if (j < 3) {
		    cout << board[i][j];
		  }
		  if (j == 3) {
		    cout << board[i][j] << endl;
		  }
		}
	      }
	      oWins++;
	      cout << "O Wins!" << endl;
	      cout << "The current score is X:" << xWins << ", O:" << oWins << endl;
	    }
	  }
	  else {
	    cout << "You can't play there!" << endl;
	  }
	}
	else {
	  cout << "Not a valid move, try again." << endl;
	}
      }
    }
    draw = checkDraw(board);
    // If the game is a draw
    if (draw == 0 && winOrNot != 1) {
      cout << "The game ended in a draw!" << endl;
      cout << "The current score is X:" << xWins << ", 0:" << oWins << endl;
      winOrNot = 0;
      gameOver = true;
      // Prompt the player to play again
      char input2;
      cout << "Would you like to play again? (y/n)" << endl;
      cin >> input2;
      cin.get();
      if (input2 == 'y') {
	gameOver = false;
	firstTime = true;
      }
      else if (input2 == 'n') {
	yn = false;
      }
    }
    // If a player wins
    else if (winOrNot == 1) {
      winOrNot = 0;
      gameOver = true;
      // Prompt the player to play again
      char input2;
      cout << "Would you like to play again? (y/n)" << endl;
      cin >> input2;
      cin.get();
      
      if (input2 == 'y') {
	gameOver = false;
	firstTime = true;
      }
      else if (input2 == 'n') {
	yn = false;
      }
    }
  }
  return 0;
}

// Function for checking wins
int checkWin(char board[4][4]) {
  int temp = 0;
  // Checks horizontal wins
  if ((board[1][1] == 'X' && board[1][2] == 'X' && board[1][3] == 'X') || (board[1][1] == 'O' && board[1][2] == 'O' && board[1][3] == 'O')) {
    temp = 1;
}
  if ((board[2][1] == 'X' && board[2][2] == 'X' && board[2][3] == 'X') || (board[2][1] == 'O' && board[2][2] == 'O' && board[2][3] == 'O')) {
    temp = 1;
}
  if ((board[3][1] == 'X' && board[3][2] == 'X' && board[3][3] == 'X') || (board[3][1] == 'O' && board[3][2] == 'O' && board[3][3] == 'O')) {
    temp = 1;
}
  // Checks vertical wins
  if ((board[1][1] == 'X' && board[2][1] == 'X' && board[3][1] == 'X') || (board[1][1] == 'O' && board[2][1] == 'O' && board[3][1] == 'O')) {
    temp = 1;
}
  if ((board[1][2] == 'X' && board[2][2] == 'X' && board[3][2] == 'X') || (board[1][2] == 'O' && board[2][2] == 'O' && board[3][2] == 'O')) {
    temp = 1;
  }
  if ((board[1][3] == 'X' && board[2][3] == 'X' && board[2][3] == 'X') || (board[1][3] == 'O' && board[2][3] == 'O' && board[3][3] == 'O')) {
    temp = 1;
}
  // Checks diagonal wins
  if ((board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X') || (board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O')) {
    temp = 1;
}
  if ((board[1][3] == 'X' && board[2][2] == 'X' && board[3][1] == 'X') || (board[1][3] == 'O' && board[2][2] == 'O' && board[3][1] == 'O')) {
    temp = 1;
}
  return temp;
}

// Function for checking draws
int checkDraw(char board[4][4]) {
  int temp2 = 0;
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if (board[i][j] == ' ') {
	temp2 = 1;
      }
    }
  }
  return temp2;
}
