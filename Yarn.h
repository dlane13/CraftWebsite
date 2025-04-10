//
// Created by 2023d on 2/22/2025.
//

#ifndef YARN_H
#define YARN_H

#include "Project.h"
#include <string>
#include <iostream>
using namespace std;


class Yarn {
public:
    //constructors
    Yarn();

    Yarn(int weight, int yards, string color);

    //getters
    int get_weight();

    int get_yards();

    string get_color();

    //setters
    void set_weight(int weight);

    void set_yards(int yards);

    void set_color(string color);

    /* method to print a yarn object to the console
     * requires: nothing
     * effects: prints fields of a yarn object to console
     */
    void printYarn();

protected:
    int weight;
    int yards;
    string color;
};



#endif //YARN_H
