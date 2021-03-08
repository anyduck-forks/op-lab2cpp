#include <string>
#include <vector>

// Повертає список файлів з заданим росширення в заданій папці
std::vector<std::string> listFiles(std::string, std::string);

// Конвертує рядок в булеву змінну
bool flag2bool(std::string);

// Поділяє рядок за розділювачем
std::vector<std::string> split(std::string, char);

// Округлює число до заданої к-сті знаків після коми
double roundOff(double x, int precision);
