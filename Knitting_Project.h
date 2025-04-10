//
// Created by 2023d on 2/20/2025.
//

#ifndef KNITTING_PROJECT_H
#define KNITTING_PROJECT_H

#include "Project.h"
#include "Yarn.h"
#include <vector>
#include <string>
using namespace std;

/*
This class is a child of the Project class, as it represents a more specific type of project.
It has constructors, getters, setters, as well as a specific function to capture the types of knitting stitches
 */


class Knitting_Project: public Project {
public:
    //constructors
    //default constructor
    Knitting_Project();

    //non-default constructor, takes in yarn and needles
    explicit Knitting_Project(int needles, vector<string> stitches, Yarn yarn);

    //getters
    int get_needles();
    vector<string> get_stitches();
    Yarn get_yarn();

    //setters
    void set_needles(int needles);
    void set_stitches(vector<string> stitches);
    void set_yarn(Yarn yarn);

    //other methods

    /* method to get info about a knitting project from the user
     * requires: a vector of project objects and a knitting_project object
     * effects: adds fields to a default knitting_project object and adds object a vector of Projects
     */
    void get_knitting_project_from_user();
    /* method to print a knitting project to the console
     * requires: nothing
     * effects: prints fields of a knitting project to the console
     */
    void printProject() override;

protected:
   //will have-a yarn
    int needles;
   //array which holds stitch names
    vector<string> stitches;
    Yarn yarn;
};



#endif //KNITTING_PROJECT_H
