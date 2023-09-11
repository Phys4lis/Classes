/* This program reads in a series of characters and checks if it is a Palindrome or not.
 * 9/11/23
 * Author: Roger Li
 */


#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  char input[81];
  cin.get(input, 81);
  cin.get();

  int check;
  int alpha;

  
  int temp = 0;
  // Find the amount of letters/numbers
  for (int i = 0; i < strlen(input); i++) {
    input[i] = tolower(input[i]);
    // This code was from Programiz.com and checks whether a character is a digit or not.
    check = isdigit(input[i]);
    // this code was from Programiz.com and checks whether a character is in the alphabet.
    alpha = isalpha(input[i]);
    if (alpha != 0 || check || input[i] == ' ') {
      temp++;
    }
  }

  // Create a new character array with the appropriate size.
  char newInput[temp];
  int temp2 = 0;
  // Remove any symbols.
  for (int i = 0; i < strlen(input); i++) {
    check = isdigit(input[i]);
    alpha = isalpha(input[i]);
    if (alpha != 0 || check) {
      newInput[temp2] = input[i];
      temp2++;
    }
  }

  // Create a new character array and flip the input
  int temp3 = 0;
  char flippedInput[strlen(newInput)];
  for (int i = strlen(newInput) - 1; i > -1; i--) {
    flippedInput[temp3] = newInput[i];
    temp3++;
  }

  // Compare the input with the flipped input to check if the input is a palindrome.
  int palindrome = 0;
  for (int i = 0; i < strlen(newInput); i++) {
    if (newInput[i] == flippedInput[i]) {
      palindrome = palindrome + 0;
    }
    else {
      palindrome++;
    }
  }

  if (palindrome == 0) {
    cout << "Palindrome.";
  }
  else {
    cout << "Not a palindrome.";
  }
  
  return 0;
}


