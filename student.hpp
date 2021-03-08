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

// конвертує рядок розділений комами в структуру
studentIn csv2studentIn(std::string);

// вивід данних студентів
void print(studentIn);
void print(studentOut);

// створює окремий список бюджетників
std::vector<studentIn> budgetStudents(std::vector<studentIn> students);

// обчислення для кожного студента-бюджетника середнього балу
std::vector<studentOut> calcAverageMark(std::vector<studentIn> budgetList);

// сортування списку бюджетників
void sortingList(std::vector<studentOut> &averageMarkList);

//обрізання списку до 40%
void cuttingList(std::vector<studentOut> &averageMarkList);
