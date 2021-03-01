#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<string> loadCsv(string path) {
    vector<string> out;
    ifstream csv(path);
    string line;

    if (!csv.is_open()) {
        cerr << "Не вдалося відкрити файл - \"" + path + "\"" << endl;
        return out;
    }

    getline(csv, line); // пропускаємо перший рядок
    while (getline(csv, line))
        out.push_back(line);
    csv.close();
    return out;
}


int main() {
    vector<string> table = loadCsv("./examples/students1.csv");

    for (string student: table)
        cout << student << endl;

    return 0;
}
