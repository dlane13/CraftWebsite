//
// Created by 2023d on 2/20/2025.
//

#ifndef CROCHET_PROJECT_H
#define CROCHET_PROJECT_H

#include "Project.h"
#include "Yarn.h"
#include <vector>
#include <string>
#include <iostream>

/*
This is the Crochet_project class, which is a child of the Project class.

 */

class Crochet_Project : public Project {
public:
 //constructors
 Crochet_Project();

 explicit Crochet_Project(string hook, vector<string> stitches, Yarn yarn);

 //getters
 string get_hook();
 vector<string> get_stitches();
 Yarn get_yarn();

 //setters
 void set_hook(string hook);
 void set_stitches(vector<string> stitches);
 void set_yarn(Yarn yarn);

 //other methods

 /* method to get input from user and create a crochet project out of it
  * requires: a vector of projects to add to, a default crochet_project object
  * effects: adds fields to object and adds object to vector
  */
 void get_crochet_project_from_user(vector<Project> &projects, Crochet_Project &project);
 /* overridden method to print a crochet project to the console
  * requires: nothing
  * effects: prints the fields of a crochet_proejct object to the console
  */
 void printProject() override;

protected:
 //will have-a yarn, hook, should stitches be a different class? used in both knitting and crocheting
 string hook;
 vector<string> stitches;
 Yarn yarn;

};



#endif //CROCHET_PROJECT_H
