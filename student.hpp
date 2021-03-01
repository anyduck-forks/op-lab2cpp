#pragma once
#include <string>
#include <vector>

struct studentIn {
    std::string surname;
    std::vector<int> rating;
    bool isContract;
};

struct studentOut {
    std::string surname;
    float avgRating;
};

// конвертує рядок розділений комами в структуру
studentIn csv2studentIn(std::string);

// конвертує стуктуру в рядок розділений комами
std::string studentOut2csv(studentOut);
void print(studentIn);
