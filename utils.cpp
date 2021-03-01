#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delim) {
    vector<string> out;
    size_t start = 0, end;
    string line;

    do {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
        start = end + 1;
    } while (end != string::npos);

    return out;
}
