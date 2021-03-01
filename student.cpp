#include <iostream>
#include <string>
#include <vector>

#include "student.hpp"

using namespace std;

// TODO: remove stub
studentIn csv2studentIn(string student) {
    studentIn out;
    out.surname = "Test";
    out.rating = vector<int> {60, 70, 80, 90, 100};
    out.isContract = false;
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
