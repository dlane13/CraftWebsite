//
// Created by 2023d on 2/2/2025.
//
#include "Project.h"
#include <string>
#include <iostream>
#include <sqlite3.h>
//compile this project using g++ main.cpp -o main -l sqlite3
using namespace std;

//default constructor
Project::Project() : name("unnamed"), status(INACTIVE), link("No link provided"), details("No details") {

}

//constructor
Project::Project(string name, statusOptions status, string link, string details) {
     setName(name);
     setStatus(status);
     setLink(link);
     setDetails(details);
}

//getters
string Project::getName() const {
  return name;
}

Project::statusOptions Project::getStatus() const {
  return status;
}

string Project::getLink() const {
  return link;
}

string Project::getDetails() const {
  return details;
}

//setters
void Project::setName(string name) {
  this->name = name;
}

void Project::setStatus(int status) {
  switch (status) {
    case 0: {
      this->status = INACTIVE;
      break;
    }
    case 1: {
      this->status = CURRENT;
      break;
    }
    case 2: {
      this->status = COMPLETE;
      break;
    }
    default: {
      this->status = INACTIVE;
      break;
    }
  }
}

void Project::setLink(string link) {
  this->link = link;
}

void Project::setDetails(string details) {
  this->details = details;
}

void Project::printProject() {
  cout << "---------------------------------------" << endl;
  cout << "Project Name: " << getName() << endl;
  statusOptions projectStatus = getStatus();
  switch (projectStatus) {
    case (INACTIVE): {
      cout << "Project Status: Not Started" << endl;
      break;
    }
    case (CURRENT): {
      cout << "Project Status: In Progress" << endl;
      break;
    }
    case (COMPLETE): {
      cout << "Project Status: Complete" << endl;
      break;
    }
  }
  cout << "Project Pattern Link: " << getLink() << endl;
  cout << "Project Details: " << getDetails() << endl;
}

void Project::printProjectToFile(ofstream& outputFile) {
    if (outputFile.is_open()) {
      cout << "Output file open" << endl;
    } else {
      cout << "OUTPUT FILE NOT OPEN" << endl;
    }
    outputFile << "---------------------------------------" << "\n";
    outputFile << "Project Name: " << getName() << "\n";
    statusOptions projectStatus = getStatus();
    switch (projectStatus) {
      case (INACTIVE): {
        outputFile << "Project Status: Not Started" << "\n";
        break;
      }
      case (CURRENT): {
        outputFile << "Project Status: In Progress" << "\n";
        break;
      }
      case (COMPLETE): {
        outputFile << "Project Status: Complete" << "\n";
        break;
      }
    }
    outputFile << "Project Pattern Link: " << getLink() << "\n";
    outputFile << "Project Details: " << getDetails() << "\n";
}

string Project::get_sentence_from_user() {
  string sentence;
  //flag to reprompt user until valid input is received
  bool flag = false;
  //only needs to hold a value to be qualified as a sentence, so length of string can't be zero
  while (!flag) {
    getline(cin, sentence);
    //if user enters some value
    if (!sentence.empty()) {
      flag = true;
      //if user just hits enter
    } else {
      cin.clear();
      cout << "No input. Please answer the question: ";
    }
  }
  cin.clear();
  return sentence;
}

char Project::get_char_from_user() {
  // NOTE: a char is not restricted to an alphabet letter
  //variable to use with getline()
  string input;
  //variable to return at end
  char returnChar;
  //flag to reprompt user for input until valid input is received
  bool flag = false;
  //will reprompt for a character from user until it can be read into a char variable
  while(!flag) {
    //if input cannot be read into a char variable, clear cin and reprompt
    if (!getline(cin, input)) {
      cin.clear();
      string restOfBadLine;
      getline(cin, restOfBadLine);
      cout << "That is not a character. Try again: ";
      //if user enters more than one character
    } else if (input.length() > 1) {
      cin.clear();
      cout << "That is not a single character! Please enter one character: ";
      //if user just hits enter
    } else if (input.empty()) {
      cin.clear();
      cout << "No input. Please enter a character: ";
      //if user enters valid input
    } else {
      flag = true;
      returnChar = input.at(0);
    }
  }
  return returnChar;
}

int Project::get_int_from_user() {
  //variable to be returned at end
  int input;
  //flag to reprompt user until valid input is entered
  bool flag = false;
  while(!flag) {
    //numbers are different, and we still need to use getline in order to handle whitespace and hitting enter
    //create a string to hold string input for getline
    string stream;
    //create stringstream object to hold stream value so it can be read into an int later
    stringstream ss;
    getline(cin, stream);
    //read stream value into ss buffer
    ss << stream;
    //if user hits enter
    if (stream.empty()) {
      cin.clear();
      cout << "No input. Please enter an integer between 0 and 2: ";
      //if user enters something that can't be read into an int variable
    } else if (!(ss >> input)) {
      cin.clear();
      cout << "That is not an integer. Try again: ";
      //if user enters numbers followed by letters/characters, since ss will not enter fail state if at least first character is a number
    } else if (stream != to_string(input)) {
      cin.clear();
      cout << "That is not an integer. Try again: ";
      //user enters valid input
    } else {
      flag = true;
    }
  }
  cin.clear();
  return input;
}
