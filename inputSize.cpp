//
// Created by 4epe3 on 12.02.2023.
//
#include "header.h"
// подсчет числа строчек в файле инпут.тхт
int inputSize() {
    std::ifstream sizeOfInput("input.txt");
    if (!sizeOfInput){std::cout << "input.txt not found"; return -1;}
    std::string uzbek;
    int n = 0;
    while (!sizeOfInput.eof()) {
        std::getline(sizeOfInput, uzbek);
        n += 1;
    }
    return n;
    sizeOfInput.close();
}