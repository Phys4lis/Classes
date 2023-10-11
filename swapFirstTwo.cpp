/* This program swaps the first two letters of every word by finding the spaces in a string with a vector and an iterator
 * Date: 10/11/23
 * Author: Roger Li
 */


#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main () {
  vector<int> spaceIndexes;
  char input[80];
  cin.get(input, 81);
  cin.get();
  for (int i = 0; i < strlen(input) - 1; i++) {
    if (input[i] == ' ' && input[i+2] != ' ') {
      spaceIndexes.push_back(i);
    }
  }
  for (vector<int>::iterator iter = spaceIndexes.begin(); iter != (spaceIndexes.end() - 1); iter++) {
    char temp;
    temp = input[*iter+1];
    input[*iter+1] = input[*iter+2];
    input[*iter+2] = temp;
  }
    if (input[1] != ' '){
      char temp;
      temp = input[1];
      input[1] = input[0];
      input[0] = temp;
    }
  cout << input;
  return 0;
}
