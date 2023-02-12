//
// Created by 4epe3 on 12.02.2023.
//
#ifndef L1FINALBUILD_HEADER_H
#define L1FINALBUILD_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int inputSize();
void workerArray(int n);
class Worker /* Класс - сотрудник предприятия */
{ // поля класса, доступ по умолчанию - private
    std::string fio; // фио сотрудника
    double cash;     // зарплата сотрудника
    double percent;  // надбавка к зп сотрудника
public: // перечисление методов класса
    Worker();
    void set(std::string name, double c, double p);
    double zarplat() const;
    void printInfo(std::ofstream *outFile) const;
    void printConsole() const;
};
#endif //L1FINALBUILD_HEADER_H
