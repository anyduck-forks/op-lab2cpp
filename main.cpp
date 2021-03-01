#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "student.hpp"

using namespace std;


vector<studentIn> loadCsv(string path) {
    vector<studentIn> out;
    ifstream csv(path);
    string line;

    if (!csv.is_open()) {
        cerr << "Не вдалося відкрити файл - \"" + path + "\"" << endl;
        return out;
    }

    getline(csv, line); // пропускаємо перший рядок
    while (getline(csv, line))
        out.push_back(csv2studentIn(line));
    csv.close();
    return out;
}


int main() {
    vector<studentIn> table = loadCsv("./examples/students1.csv");

    for (studentIn student: table)
        print(student);

    return 0;
}
