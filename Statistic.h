#ifndef STCTEST_STATISTIC_H
#define STCTEST_STATISTIC_H
#include <iostream>
#include <math.h>
#include <cstdlib>
using std::bitset, std::cout;

class Statistic {
private:
    unsigned short* mass;
    int max_value;
public:
    explicit Statistic(unsigned char* mass_) {
        mass = (unsigned short*) mass_;
        max_value = 0;
    }

    int getMaxValue() {
        return max_value;
    }

    int* makeStatistic(int len, int size) {
        int stat_size = (int)pow(2, len);
        int* stat = new int[stat_size];
        for (int i = 0; i < stat_size; i++) {
            stat[i] = 0;
        }
        unsigned short mask = (unsigned short) pow(2, len) - 1;
        short cur, prev = 0, rest = len;
        for (int i = size / 2 - 1; i >= 0; i--) {
            cur = mass[i];
            char prev_shift = sizeof(unsigned short) * 8 - len + rest;
            char cur_shift = len - rest;
            char point = rest - len;
            do {
                int index = (((mask << prev_shift) & prev) >> prev_shift) | (((mask >> cur_shift) & cur) << cur_shift);
                stat[index]++;
                if (stat[index] > max_value) {
                    max_value = stat[index];
                }
                rest = len;
                point += len;
                prev_shift = point;
                cur_shift = sizeof(unsigned short) * 8;
                prev = cur;
            } while (sizeof(unsigned short) * 8 - point > len);
            rest = len - (sizeof(unsigned short) * 8 - point);
        }
        return stat;
    }
};

#endif //STCTEST_STATISTIC_H
