//
// Created by 2023d on 2/20/2025.
//

#include "Crochet_Project.h"

Crochet_Project::Crochet_Project() : Project() {
    hook = "";
    stitches = vector<string>();
    yarn = Yarn();
}

Crochet_Project::Crochet_Project(string hook, vector<string> stitches, Yarn yarn) : Project() {
    this->hook = hook;
    this->stitches = stitches;
    this->yarn = yarn;
}

string Crochet_Project::get_hook() {
    return hook;
}

vector<string> Crochet_Project::get_stitches() {
    return stitches;
}

Yarn Crochet_Project::get_yarn() {
    return yarn;
}

void Crochet_Project::set_hook(string hook) {
    this->hook = hook;
}

void Crochet_Project::set_stitches(vector<string> stitches) {
    this->stitches = stitches;
}

void Crochet_Project::set_yarn(Yarn yarn) {
    this->yarn = yarn;
}

void Crochet_Project::get_crochet_project_from_user(vector<Project> &projects, Crochet_Project &project) {
    //create a project object
        //get name of project
        cout << "What is the name of your project? ";
        string name = get_sentence_from_user();
        project.setName(name);

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
        project.setStatus(statusInput);

        //get link to pattern for project
        cout << "Please enter the link to the pattern for the project: ";
        string link = get_sentence_from_user();
        project.setLink(link);

        //get needles size for project
        cout << "Please enter the size of the hook for your project: ";
        string hook = get_sentence_from_user();
        project.set_hook(hook);

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
        project.set_stitches(stitches_vector);

        //get yarn object from user
        cout << "Please enter the weight of your yarn for this project as an integer: ";
        int weight = get_int_from_user();
        cout << "Please enter the number of yards of yarn you need for this project: ";
        int yards = get_int_from_user();
        cout << "Please enter the color of your yarn for this project: ";
        string color = get_sentence_from_user();
        Yarn yarn = Yarn(weight, yards, color);
        project.set_yarn(yarn);

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
        project.setDetails(detail);

        //print out entire project so they can see what they entered
        cout << "Thank you for your entry! Here is what you entered: " << endl;
        project.printProject();

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
                    project.setName(newName);
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
                    project.setStatus(newStatusInput);
                    break;
                }
                case 3: {
                    cout << "Please enter the link to the pattern for the project: ";
                    string newLink = get_sentence_from_user();
                    project.setLink(newLink);
                    break;
                }
                case 4: {
                    cout << "Please enter the size of the hook for your project: ";
                    string hook = get_sentence_from_user();
                    project.set_hook(hook);
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
                    project.set_stitches(stitches_vector);
                }
                case 6: {
                    cout << "Please enter the weight of your yarn for this project as an integer: ";
                    int weight = get_int_from_user();
                    cout << "Please enter the number of yards of yarn you need for this project: ";
                    int yards = get_int_from_user();
                    cout << "Please enter the color of your yarn for this project: ";
                    string color = get_sentence_from_user();
                    Yarn yarn = Yarn(weight, yards, color);
                    project.set_yarn(yarn);
                }
                case 7: {
                    cout << "Please enter some details about your project: ";
                    string newDetail = get_sentence_from_user();
                    project.setDetails(newDetail);
                    break;
                }
            }
        }
        //add project to projects vector
        projects.push_back(project);
}

void Crochet_Project::printProject() {
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
    cout << "Project hook size: " << get_hook() << endl;
    cout << "Project stitches: ";
    for (string s : get_stitches()) {
        cout << s << ", ";
    }
    cout << endl;
    yarn.printYarn();
    cout << "Project Details: " << getDetails() << endl;
}
