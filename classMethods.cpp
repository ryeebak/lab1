//
// Created by 4epe3 on 12.02.2023.
//
#include "header.h"
// определение методов класса
Worker::Worker(){        // пустой конструктор
    fio = "";
    cash = 0;
    percent = 0;
}
void Worker::set(std::string name, double c, double p){ // метод для инициализации полей для созданного "пустого" объекта
    fio = name;
    cash = c;
    percent = p;
}
double Worker::zarplat() const{
    double workerItogCash = this->cash * ((100 + this->percent)/100);
    return workerItogCash;
}
void Worker::printInfo(std::ofstream *outFile) const{       // метод для печати полей объекта в файл (функция принимает указатель на поток, поскольку поток создается вне описания методов класса для экономии времени/памяти/нервов)
    *outFile << fio << ", " << zarplat() << std::endl;
}
void Worker::printConsole() const{ // метод для печати полей объекта в консоль
    std::cout << fio << ", " << zarplat() << std::endl;
}
