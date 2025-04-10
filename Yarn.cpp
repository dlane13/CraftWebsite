//
// Created by 2023d on 2/22/2025.
//

#include "Yarn.h"

//constructors
Yarn::Yarn() {
    weight = 0;
    yards = 0;
    color = "";
};

Yarn::Yarn(int weight, int yards, string color) {
    this->weight = weight;
    this->yards = yards;
    this->color = color;
};

//getters
int Yarn::get_weight() {
    return weight;
};

int Yarn::get_yards() {
    return yards;
};

string Yarn::get_color() {
    return color;
};

//setters
void Yarn::set_weight(int weight) {
    this->weight = weight;
};

void Yarn::set_yards(int yards) {
    this->yards = yards;
};

void Yarn::set_color(string color) {
    this->color = color;
};

void Yarn::printYarn() {
    cout << "Yarn weight: " << get_weight() << endl;
    cout << "Number of yards of yarn needed: " << yards << endl;
    cout << "Color of yarn: " << color << endl;
};
