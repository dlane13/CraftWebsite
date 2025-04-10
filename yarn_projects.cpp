//
// Created by Darby Lane on 3/23/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Project.h"
#include "Knitting_Project.h"
#include "Crochet_Project.h"

using namespace std;
/*
This is the only c++ function written for this project.
requires: 9 arguments from the user, passed through the php file, which are the executable plus eight user input
effects: adds html to a file and then prints the contents of this file, uses append to add on to projects already in file
 */
int main(int argc, char* argv[]) {
    //first argument is the type of project this is
    if (argc < 8) {
      cout << "<h3>";
      cout << "Issue with getting input from user" << "<br>";
      cout << "</h3>";
      return 1;
    }
    string project_type = argv[1];
    string project_name = argv[2];
    string project_status = argv[3];
    string project_link = argv[4];
    string yarn_weight = argv[5];
    string yarn_yards = argv[6];
    string yarn_color = argv[7];
    string project_details = argv[8];

    vector<unique_ptr<Project>> projects;
    Yarn yarn;
    if (project_type == "Knitting_Project") {
      auto project = make_unique<Knitting_Project>();
      project->setName(project_name);
      if (project_status == "not_started") {
        project->setStatus(0);
      } else if (project_status == "in_progress") {
        project->setStatus(1);
      } else {
        project->setStatus(2);
      }
      project->setLink(project_link);
      yarn = Yarn(stoi(yarn_weight), stoi(yarn_yards), yarn_color);
      project->set_yarn(yarn);
      project->setDetails(project_details);
      //project->printProject();
      projects.push_back(move(project));
      //project->printProject();

    } else {
      auto project = make_unique<Crochet_Project>();
      project->setName(project_name);
      if (project_status == "not_started") {
        project->setStatus(0);
      } else if (project_status == "in_progress") {
        project->setStatus(1);
      } else {
        project->setStatus(2);
      }
      project->setLink(project_link);
      yarn = Yarn(stoi(yarn_weight), stoi(yarn_yards), yarn_color);
      project->set_yarn(yarn);
      project->setDetails(project_details);
      //project->printProject();
      projects.push_back(move(project));
      //project->printProject();

    }

    //create file object to add to text file
    //open file in append mode to add to pre-existing data
    string filename = "../yarn_projects_file.txt";
    fstream project_file(filename, ios::app);

    project_file << "<article>";
    for (unique_ptr<Project>& project : projects) {
      project_file << "---------------------------------------" << "<br>";
      project_file<< "Project Name: " << project->getName() << "<br>";
      switch (project->getStatus()) {
        case (Project::INACTIVE): {
          project_file << "Project Status: Not Started" << "<br>";
          break;
        }
        case (Project::CURRENT): {
          project_file << "Project Status: In Progress" << "<br>";
          break;
        }
        case (Project::COMPLETE): {
          project_file << "Project Status: Complete" << "<br>";
          break;
        }
      }
      project_file << "Project Pattern Link: " << project->getLink() << "<br>";
      project_file << "Yarn Weight: " << yarn.get_weight() << "<br>";
      project_file << "Yarn Yards: " << yarn.get_yards() << "<br>";
      project_file << "Yarn Color: " << yarn.get_color() << "<br>";
      project_file << "Project Details: " << project->getDetails() << "<br>";
    }
    //close file to reset buffer before reading from it
    project_file << "</article>\n";
    project_file.flush();
    project_file.close();

    ifstream read_file(filename);

    string file_line;
    cout << "<h3>Yarn Projects:</h3>";
    while (getline(read_file, file_line)) {
      cout << file_line;
    }
    read_file.close();

    return 0;

}
