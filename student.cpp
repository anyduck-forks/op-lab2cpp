#include <iostream>
#include <string>
#include <vector>

#include "student.hpp"
#include "utils.hpp"

using namespace std;

studentIn csv2studentIn(string student)
{
    vector<string> tmp = split(student, ',');
    studentIn out;

    out.surname = tmp.at(0);
    for (size_t i = 1; i < 6; i++)
        out.rating.push_back(stoi(tmp.at(i)));
    out.isContract = flag2bool(tmp.at(6));

    return out;
}

// TODO: remove stub
string studentOut2csv(studentOut student)
{
    return "Test,80.000";
}

void print(studentIn student)
{
    cout << student.surname << " ";
    for (int score : student.rating)
        cout << score << " ";
    cout << student.isContract << endl;
}

void print(studentOut student)
{
    cout << student.surname << " " << student.avgRating << endl;
}

vector<studentIn> budgetStudents(vector<studentIn> students)
{
    vector<studentIn> budgetList;
    for (studentIn student : students)
    {
        if (student.isContract == 0)
        {
            budgetList.push_back(student);
        }
    }
    return budgetList;
}

vector<studentOut> calcAverageMark(vector<studentIn> budgetList)
{
    vector<studentOut> averageMarkList;
    for (studentIn student : budgetList)
    {
        int sum = 0;
        for (int mark : student.rating)
        {
            sum += mark;
        }
        double avgRating = roundOff((double)sum / student.rating.size(), 3);

        studentOut student_budget;
        student_budget.surname = student.surname;
        student_budget.avgRating = avgRating;
        averageMarkList.push_back(student_budget);
    }
    return averageMarkList;
}

vector<studentOut> sortingList(vector<studentOut> averageMarkList)
{
    for (size_t i = 0; i < averageMarkList.size() - 1; i++)
    {
        for (size_t j = 0; j < averageMarkList.size() - i - 1; j++)
        {
            if (averageMarkList.at(j).avgRating < averageMarkList.at(j + 1).avgRating)
            {
                swap(averageMarkList.at(j), averageMarkList.at(j + 1));
            }
        }
    }
    return averageMarkList;
}

vector<studentOut> cuttingList(vector<studentOut> averageMarkList)
{
    size_t new_size = averageMarkList.size() * 40 / 100;
    averageMarkList.resize(new_size);
    return averageMarkList;
}
