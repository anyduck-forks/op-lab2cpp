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

studentIn csv2studentIn(std::string);
std::string studentOut2csv(studentOut);
void print(studentIn);
