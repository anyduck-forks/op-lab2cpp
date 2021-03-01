#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "student.hpp"
#include "utils.hpp"

using namespace std;


// Зчитує дані з csv файлу у вектор з studentIn
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


// Зчитує дані з усіх csv файлів в папці у вектор з studentIn
vector<studentIn> loadTable(string direcotry) {
    vector<studentIn> out, tmp;
    vector<string> files = listFiles(direcotry, ".csv");
    for (string file : files) {
        tmp = loadCsv(file);
        out.insert(out.end(), tmp.begin(), tmp.end());
    }

    return out;
}


int main() {
    vector<studentIn> table = loadTable("./examples/");

    for (studentIn student: table)
        print(student);

    return 0;
}
