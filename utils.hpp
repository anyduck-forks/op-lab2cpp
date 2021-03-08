#include <string>
#include <vector>


// Повертає список файлів з заданим росширення в заданій папці
std::vector<std::string> listFiles(std::string, std::string);

// конвертує рядок в булеву змінну
bool flag2bool(std::string);

// поділяє рядок за розділювачем
std::vector<std::string> split(std::string, char);

// округлення числа
double roundOff(double x, int precision);
