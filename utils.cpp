#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
 
using namespace std;
namespace fs=filesystem;


vector<string> listFiles(string directory, string extension) {
    vector<string> out;
    if (fs::exists(directory) && fs::is_directory(directory)) {
        for (const auto & entry : fs::directory_iterator(directory))
            if(fs::is_regular_file(entry) && fs::path(entry).extension() == extension)
                out.push_back(entry.path().string());
    } else
        cerr << "Введеної директорії не існує - \"" + directory + "\"" << endl;
    return out;
}
