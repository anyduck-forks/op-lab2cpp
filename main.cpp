#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "student.hpp"
#include "utils.hpp"

using namespace std;

string getDirectory()
{
    string directory;
    cout << "Введіть шлях папки з CSV фалами: ";
    getline(cin, directory);

    return directory;
}

// Зчитує дані з csv файлу у вектор з studentIn
vector<studentIn> loadCsv(string path)
{
    vector<studentIn> out;
    ifstream csv(path);
    string line;

    if (!csv.is_open())
    {
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
vector<studentIn> loadTable(string direcotry)
{
    vector<studentIn> out, tmp;
    vector<string> files = listFiles(direcotry, ".csv");
    for (string file : files)
    {
        tmp = loadCsv(file);
        out.insert(out.end(), tmp.begin(), tmp.end());
    }

    return out;
}

int main()
{
    string directory = getDirectory();
    vector<studentIn> table = loadTable(directory);
    vector<studentIn> table_budget = budgetStudents(table);
    for (studentIn student : table)
        print(student);
    cout << "===========" << endl;
    for (studentIn budget_student : table_budget)
        print(budget_student);

    vector<studentOut> table_rating = calcAverageMark(table_budget);
    cout << "===========" << endl;
    for (studentOut rating_student : table_rating)
        print(rating_student);

    table_rating = sortingList(table_rating);
    cout << "===========" << endl;
    for (studentOut rating_student : table_rating)
        print(rating_student);
    return 0;
}
