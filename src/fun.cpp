// Copyright 2022 UNN-IASR
#include "fun.h"
#include <vector>
using std::vector;

unsigned int faStr1(const char *str) {
    unsigned int k = 0;
    bool b = true;
    for (; *str != '\0'; str++) {
        if (*str >= '0' && *str <= '9') {
            b = true;
        }
        if (*str == ' ' || *str == '\t') {
            if (b == false && *(str-1) != ' ')
                k += 1;
            else
                b = false;
        }
    }
    return k;
}

unsigned int faStr2(const char *str) {
    unsigned int k = 0;
    bool b = false;
    char c = ' ';
    for (; *str != '\0'; str++) {
        if (*str >= 'A' && *str <= 'Z') {
            if (c == ' ')
                b = true;
            else
                b = false;
        } else if ((*str <= 'a' || *str >= 'z') && *str != ' ') {
            b = false;
        }
        if (*str == ' ' || *str == '\t') {
            if (b == true)
                k += 1;
            b = false;
        }
        c = *str;
    }
    return k;
}

unsigned int faStr3(const char *str) {
    int k = 0;
    vector<int> v;
    for (; *str != '\0'; str++) {
        if (*str != ' ' && *str != '\t') {
            k++;
        }
        if (*str == ' ' || *str == '\t') {
            v.push_back(k);
            k = 0;
        }
    }
    v.push_back(k);
    unsigned int sum = 0;
    unsigned int len = v.size();
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0)
            sum += v[i];
        else
            len -= 1;
    }
    unsigned int n = 0;
    if (len == 0)
        n = 0;
    else
        n = sum / len;
    return n;
}
