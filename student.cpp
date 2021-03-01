#include <iostream>
#include <string>
#include <vector>

#include "student.hpp"
#include "utils.hpp"

using namespace std;

// TODO: remove stub
studentIn csv2studentIn(string student) {
    vector<string> tmp = split(student, ',');
    studentIn out;
    out.surname = tmp.at(0);
    for (size_t i = 1; i < 6; i++) {
        out.rating.push_back(stoi(tmp.at(i)));
    }
    out.isContract = false; // tmp.at(6)
    return out;
}

// TODO: remove stub
string studentOut2csv(studentOut student) {
    return "Test,80.000";
}

void print(studentIn student) {
    cout << student.surname << " ";
    for (int score: student.rating)
        cout << score << " ";
    cout << student.isContract << endl;
}
