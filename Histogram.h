#ifndef STCTEST_HISTOGRAM_H
#define STCTEST_HISTOGRAM_H
#include <iostream>
#include "Ffile.h"
#include "Statistic.h"
#include "ConfigBarChart.h"
using std::string, std::cin;

class Histogram{
private:
    friend void init();
    friend void display();

    string file_name;
    int len;
    unsigned char* file_mass;
    int* stat_mass;
public:
    explicit Histogram() {
        file_name = "";
        len = 0;
        file_mass = {0};
        stat_mass = {0};
    }

    void initHistogram() {
        cin >> file_name >> len;
        Ffile file(file_name);
        unsigned char* file_mass = file.fread(file.getSize());
        Statistic stat(file_mass);
        int* stat_mass = stat.makeStatistic(len, file.getSize());
    }


};

#endif //STCTEST_HISTOGRAM_H
