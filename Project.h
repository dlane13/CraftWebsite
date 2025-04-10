//
// Created by 2023d on 2/2/2025.
//
using namespace std;

#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <sstream>
#include <vector>
#include <fstream>

/* Project Class
 * Objects of this class represent yarn projects
 * Fields: name of project, type of project, status of project, link to project pattern, and extra details about project
 */
class Project {

public:
  enum statusOptions {
    INACTIVE,
    CURRENT,
    COMPLETE
  };
    /* Default constructor
       * Requires: nothing
       * Modifies: all fields of Project class
       * name = "unnamed", type = 'k', status = INACTIVE, link = "no link provided", details = "no details provided"
       */
  Project();
    /* Constructor
     * Requires: inputs for all fields
     * Modifies: All fields, sets to arguments
     */
  Project(string name, statusOptions status, string link, string details);

  /* Getters */
  string getName() const;
  statusOptions getStatus() const;
  string getLink() const;
  string getDetails() const;

  /* Setters */
    void setName(string name);
  void setStatus(int status);
  void setLink(string link);
    void setDetails(string details);

  /* method to print a project object to the console
   * requires: no input
   * effects: prints every field to console, but returns nothing and changes nothing
   */
  virtual void printProject();
  /* method to print a project object to a file
   * requires: no input
   * effects: prints the fields of the project object to the file
   * BUGGY
   */
  void printProjectToFile(ofstream& file);

  /*verifies sentence input from user
   *requires: no input
   *effects: returns a string whose input has been validated
   */

  //bool addProjectToDB();

  string get_sentence_from_user();
    /*verifies char input from user
     *requires: no input
     *effects: returns a verified character
     */
  char get_char_from_user();
    /*verifies int input from user
     *requires: no input
     *effects: returns a verified int
     */
  int get_int_from_user();

protected:
  string name;
  statusOptions status;
  string link;
  string details;

};



#endif //PROJECT_H
