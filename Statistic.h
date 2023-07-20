#ifndef STCTEST_STATISTIC_H
#define STCTEST_STATISTIC_H
#include <iostream>
#include <math.h>
#include <cstdlib>
using std::bitset, std::cout;

class Statistic {
private:
    unsigned short* mass;
public:
    explicit Statistic(unsigned char* mass_) {
        mass = (unsigned short*) mass_;
    }

    int* make_statistic(int len, int size) {
        int* stat = new int[(int)pow(2, len)];
        unsigned short mask = (unsigned short) pow(2, len) - 1;
        short cur, prev = 0, rest = len;
        for (int i = size / 2 - 1; i >= 0; i--) {
            cur = mass[i];
            char prev_shift = sizeof(unsigned short) * 8 - len + rest;
            char cur_shift = len - rest;
            char point = rest - len;
            do {
                uint16_t mask_prev = mask << prev_shift;
                uint16_t konk_prev = mask_prev & prev;
                uint16_t shift_prev = konk_prev >> prev_shift;
                uint16_t mask_curr = mask >> cur_shift;
                uint16_t konk_curr = mask_curr & cur;
                uint16_t shift_curr = konk_curr << cur_shift;
                int index = shift_curr | shift_prev;
                //int index = (((mask << prev_shift) & prev) >> prev_shift) | (((mask >> cur_shift) & cur) << cur_shift);
                stat[index]++;
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
