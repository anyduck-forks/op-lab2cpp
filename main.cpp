#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "student.hpp"
#include "utils.hpp"

using namespace std;

string getDirectory();

// Зчитує дані з усіх csv файлів в папці у вектор з studentIn
vector<studentIn> loadTable(string direcotry);

void saveTable(vector<studentOut> table_rating);


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
    table_rating = cuttingList(table_rating);
    cout << "===========" << endl;
    for (studentOut rating_student : table_rating)
        print(rating_student);
    cout << "Мінімальна оцінка для стипендії це " << table_rating.back().avgRating << endl;

    saveTable(table_rating);

    return 0;
}

string getDirectory()
{
    string directory;
    cout << "Введіть шлях папки з CSV фалами: ";
    getline(cin, directory);

    return directory;
}

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
    void saveTable(vector<studentOut> table_rating){
        ofstream outcsv("./rating.csv");
        for (studentOut rating_student : table_rating)
        {
         outcsv << rating_student.surname << "," << rating_student.avgRating << endl;
        }
        outcsv.close();
    }