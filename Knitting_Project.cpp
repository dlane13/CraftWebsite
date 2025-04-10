//
// Created by 2023d on 2/20/2025.
//

#include "Knitting_Project.h"

//constructors
Knitting_Project::Knitting_Project() : Project() {
    needles = 0;
    stitches = vector<string>();
    yarn = Yarn();
}

Knitting_Project::Knitting_Project(int needles, vector<string> stitches, Yarn yarn) : Project() {
    this->needles = needles;
    this->stitches = stitches;
    this->yarn = yarn;
}

//getters
int Knitting_Project::get_needles() {
    return needles;
}

vector<string> Knitting_Project::get_stitches() {
    return stitches;
}

Yarn Knitting_Project::get_yarn() {
    return yarn;
}

//setters
void Knitting_Project::set_needles(int needles) {
    this->needles = needles;
}

void Knitting_Project::set_stitches(vector<string> stitches) {
    this->stitches = stitches;
}

void Knitting_Project::set_yarn(Yarn yarn) {
    this->yarn = yarn;
}

void Knitting_Project::printProject() {
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
  cout << "Project needles: " << get_needles() << endl;
  cout << "Project stitches: ";
  for (string s : get_stitches()) {
    cout << s << ", ";
  }
  cout << endl;
  yarn.printYarn();
  cout << "Project Details: " << getDetails() << endl;
}


void Knitting_Project::get_knitting_project_from_user() {

        //get name of project
        cout << "What is the name of your project? ";
        string name = get_sentence_from_user();
        setName(name);

        //get status of project, validate input
        cout << "What is the status of the project? Enter 0 for not started, 1 for in progress, and 2 for complete: ";
        bool correctStatus = false;
        int statusInput;
        while (!correctStatus) {
            statusInput = get_int_from_user();
            if (statusInput <= 2 && statusInput >= 0) {
                correctStatus = true;
            } else {
                cout << "This is not one of the requested numbers. Please try again: ";
            }
        }
        setStatus(statusInput);

        //get link to pattern for project
        cout << "Please enter the link to the pattern for the project: ";
        string link = get_sentence_from_user();
        setLink(link);

        //get needles size for project
        cout << "Please enter the size of the needles for your project: ";
        int needles = get_int_from_user();
        set_needles(needles);

        //get stitches for the project
        cout << "Please enter the stitches which are needed for this project, separated by commas: ";
        string stitches = get_sentence_from_user();
        vector<string> stitches_vector;
        string stitch = "";
        //creates a vector of string based on how user separated their stitches names
        for (char c : stitches) {
            if (c == ',') {
                stitches_vector.push_back(stitch);
                stitch = "";
            } else {
                stitch += c;
            }
        }
        stitches_vector.push_back(stitch);
        set_stitches(stitches_vector);

        //get yarn object from user
        cout << "Please enter the weight of your yarn for this project as an integer: ";
        int weight = get_int_from_user();
        cout << "Please enter the number of yards of yarn you need for this project: ";
        int yards = get_int_from_user();
        cout << "Please enter the color of your yarn for this project: ";
        string color = get_sentence_from_user();
        Yarn yarn = Yarn(weight, yards, color);
        set_yarn(yarn);

        //get detail about project if user wants to enter detail, if user doesn't follow instructions about y or n just don't add detail
        cout << "Would you like to provide more detail about the project? Enter y for yes or n for no: ";
        char enter_detail = get_char_from_user();
        string detail;
        if (enter_detail == 'y' || enter_detail == 'Y') {
            cout << "Please provide more detail: ";
            detail = get_sentence_from_user();
        } else {
            detail = "No detail provided.";
        }
        setDetails(detail);

        //print out entire project so they can see what they entered
        cout << "Thank you for your entry! Here is what you entered: " << endl;
        printProject();

        //now that user can see entry, give them ability to change something
        cout << "Would you like to change any part of your entry? Enter y for yes or n for no: ";
        char change = get_char_from_user();
        if (change == 'y' || change == 'Y') {
            cout << "What would you like to change? Enter 1 for the name, 2 for the status, 3 for the link, 4 for the hook, 5 for the stitches, 6 for the yarn, and 7 for the details: ";
            int whatToChange = get_int_from_user();
            switch (whatToChange) {
                case 1: {
                    cout << "What is the name of your project? ";
                    string newName = get_sentence_from_user();
                    setName(newName);
                    break;
                }
                case 2: {
                    cout << "What is the status of the project? Enter 0 for not started, 1 for in progress, and 2 for complete: ";
                    bool correctStatus = false;
                    int newStatusInput;
                    while (!correctStatus) {
                        newStatusInput = get_int_from_user();
                        if (newStatusInput <= 2 && newStatusInput >= 0) {
                            correctStatus = true;
                        } else {
                            cout << "This is not one of the requested numbers. Please try again: ";
                        }
                    }
                    setStatus(newStatusInput);
                    break;
                }
                case 3: {
                    cout << "Please enter the link to the pattern for the project: ";
                    string newLink = get_sentence_from_user();
                    setLink(newLink);
                    break;
                }
                case 4: {
                    cout << "Please enter the size of the hook for your project: ";
                    int needles = get_int_from_user();
                    set_needles(needles);
                }
                case 5: {
                    cout << "Please enter the stitches which are needed for this project, separated by commas: ";
                    string stitches = get_sentence_from_user();
                    vector<string> stitches_vector;
                    string stitch = "";
                    //creates a vector of string based on how user separated their stitches names
                    for (char c : stitches) {
                        if (c == ',') {
                            stitches_vector.push_back(stitch);
                            stitch = "";
                        } else {
                            stitch += c;
                        }
                    }
                    set_stitches(stitches_vector);
                }
                case 6: {
                    cout << "Please enter the weight of your yarn for this project as an integer: ";
                    int weight = get_int_from_user();
                    cout << "Please enter the number of yards of yarn you need for this project: ";
                    int yards = get_int_from_user();
                    cout << "Please enter the color of your yarn for this project: ";
                    string color = get_sentence_from_user();
                    Yarn yarn = Yarn(weight, yards, color);
                    set_yarn(yarn);
                }
                case 7: {
                    cout << "Please enter some details about your project: ";
                    string newDetail = get_sentence_from_user();
                    setDetails(newDetail);
                    break;
                }
            }
        }
}



