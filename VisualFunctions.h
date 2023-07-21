#ifndef STCTEST_VISUALFUNCTIONS_H
#define STCTEST_VISUALFUNCTIONS_H
#include "ConfigBarChart.h"
#include "Ffile.h"
#include "Statistic.h"
#include <iostream>
#include "stb_easy_font.h"
using std::cin, std::string, std::cout;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    string file_name;
    int len;
    cin >> file_name >> len;
    Ffile file(file_name);
    unsigned char* file_mass = file.fread(file.getSize());
    Statistic stat(file_mass);
    int* stat_mass = stat.makeStatistic(len, file.getSize());
    int stat_size = (int) pow(2, len);
    int max_value = stat.getMaxValue();
    int column_width = WINDOW_WIDTH / stat_size;
    for (int i = 0; i < stat_size; i++) {
        cout << i << ": " << stat_mass[i] << "\n";
        glRecti(i * column_width, 0, i * column_width + column_width, WINDOW_HEIGHT * ((double) stat_mass[i] / (double) max_value));
    }
    glFlush();
}


#endif //STCTEST_VISUALFUNCTIONS_H
