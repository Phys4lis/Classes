#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>

using namespace std;

struct Student {
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

int correctInput();
void add(Student* &s, vector<Student*> &v);
void print(vector<Student*> v);
void del(vector<Student*> &v);

int main() {
  vector<Student*> studentList;
  bool running = true;
  while (running == true) {
    int option = correctInput();
      //If the user wants to add a new student
      if (option == 1) {
	Student *student = new Student();
	add(student, studentList);
      }
      // Runs through the vector and prints out the students.
      else if (option == 2) {
	print(studentList);
      }
      // Remove a student from the student list based on their student ID.
      else if (option == 3) {
	del(studentList);
      }
      // Quit the program
      else if (option == 4) {
	running = false;
      }
  }
}

int correctInput() {
  bool leaveLoop = false;
  cout << "Enter one of the following options: ADD, PRINT, DELETE, or QUIT (uppercase)" << endl;
  while (leaveLoop == false) {
    char input[15];
    cin.get(input, 15);
    cin.ignore(15, '\n');
    if (input[0] == 'A' && input[1] == 'D' && input[2] == 'D' && strlen(input) == 3) {
      return 1;
    }
    else if (input[0] == 'P' && input[1] == 'R' && input[2] == 'I' && input[3] == 'N' && input[4] == 'T' && strlen(input) == 5) {
      return 2;
    }
    else if (input[0] == 'D' && input[1] == 'E' && input[2] == 'L' && input[3] == 'E' && input[4] == 'T' && input[5] == 'E' && strlen(input) == 6) {
      return 3;
    }
    else if (input[0] == 'Q' && input[1] == 'U' && input[2] == 'I' && input[3] == 'T' && strlen(input) == 4) {
      return 4;
    }
    else {
      cout << "Please enter a valid option." << endl;
    }
  }
  return -1;
}

void add(Student* &s, vector<Student*> &v) {
  // Prompt first name
  cout << "Please enter a first name." << endl;
  char input[20];
  cin.get(input, 20);
  cin.get();
  strcpy(s->firstName, input);
  // Prompt last name
  cout << "Please enter a last name." << endl;
  cin.get(input, 20);
  cin.get();
  strcpy(s->lastName, input);
  // Prompt id
  bool correctID = false;
  while (correctID == false) {
    cout << "Please enter an id." << endl;
    int intInput;
    cin >> intInput;
    cin.get();
    int temp = 0;
    for (vector<Student*>::iterator iter = v.begin(); iter < v.end(); iter++) {
      if (intInput == (*iter)->id) {
        temp++;
      }
    }
    if (temp == 0) {
      s->id = intInput;
      correctID = true;
    }
    else {
      cout << "That ID is already being used!" << endl;
    }
  }
  // Prompt gpa
  cout << "Please enter a gpa." << endl;
  float floatInput;
  cin >> floatInput;
  cin.get();
  s->gpa = floatInput;
  // Add the struct pointer to the vector
  v.push_back(s);
  cout << endl;
}

void print(vector<Student*> v) {
  cout << "Here's a list of the current students:" << endl;
  // Got help with iterators & dereferencing from Lucas Johnson 
  for (vector<Student*>::iterator iter = v.begin(); iter < v.end(); iter++) {
    // Output each student's information. Precision code from geeksforgeeks.org
    cout << (*iter)->firstName << " " << (*iter)->lastName << ", " << fixed << setprecision(2) << (*iter)->id << ", " << (*iter)->gpa << endl;
  }
  cout << endl;
}

void del(vector<Student*> &v) {
  cout << "Please enter the student ID of the student you want to remove from the list." << endl;
  int intInput;
  cin >> intInput;
  cin.get();
  for (vector<Student*>::iterator iter = v.begin(); iter != v.end(); iter++) {
    // If any id matches with the inputted id, remove that student from the list.
    if (intInput == (*iter)->id) {
      // Remove the pointer from the heap 
      delete *iter;
      // Remove the element from the vector
      v.erase(iter);
      return;
    }
  }
  cout << endl;
}
