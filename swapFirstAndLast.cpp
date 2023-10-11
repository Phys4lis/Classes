/* This program will swap the first and last letters of each word in a string
 * Date: 10/11/23
 * Author: Roger Li
 */

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  int index;
  int firstTime = 0;
  // Input
  char input[50];
  cin.get(input, 51);
  cin.get();
  for (int i = 0; i < strlen(input); i++) {
    // Swapping first and last letters for the first word
    if (input[i] == ' ' && firstTime == 0) {
      index = i;
      firstTime++;
      char temp;
      temp = input[0];
      input[0] = input[i-1];
      input[i-1] = temp;
    }
    // Swapping first and last letters for the middle words
    else if (input[i] == ' ' && firstTime != 0) {
      char temp;
      temp = input[index+1];
      input[index+1] = input[i-1];
      input[i-1] = temp;
      index = i;
    }
  }
  // Swapping the last word
  char temp;
  temp = input[index+1];
  input[index+1] = input[strlen(input)-1];
  input[strlen(input)-1] = temp;
  // Output
  cout << input;
  return 0;
}
