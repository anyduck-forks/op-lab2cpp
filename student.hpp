#pragma once
#include <string>
#include <vector>

struct studentIn
{
    std::string surname;
    std::vector<int> rating;
    bool isContract;
};

struct studentOut
{
    std::string surname;
    double avgRating;
};

// Конвертує рядок розділений комами в структуру
studentIn csv2studentIn(std::string);

// Вивід данних студентів
void print(studentIn);
void print(studentOut);

// Створює окремий список бюджетників
std::vector<studentIn> budgetStudents(std::vector<studentIn> students);

// Обчислює для кожного студента-бюджетника середній бал
std::vector<studentOut> calcAverageMark(std::vector<studentIn> budgetList);

// Сортує список бюджетників
void sortingList(std::vector<studentOut> &averageMarkList);

// Обрізає список до 40%
void cuttingList(std::vector<studentOut> &averageMarkList);
