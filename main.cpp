#include <iostream>
#include "Ffile.h"
#include "Statistic.h"
using std::cout, std::atoi, std::cin, std::string;

int main() {
    string file_name;
    cin >> file_name;
    int len;
    cin >> len;
    Ffile file(file_name);
    unsigned char* file_mass = file.fread(file.get_size());
    Statistic stat(file_mass);
    int* stat_mass = stat.make_statistic(len, file.get_size());
    for (int i = 0 ; i < pow(2, len); i++) {
        cout << i << ": " << stat_mass[i] << "\n";
    }
    return 0;
}
