//
// Created by 4epe3 on 12.02.2023.
//
#include "header.h"
// данная функция создает и заполняет динамический массив и вектор
// после элементы массива печатаются в файл, элементы вектора печатаются в консоль
void workerArray(int n) {
    std::ifstream fin("input.txt");
    Worker *pWorker;                  // Указатель на массив
    pWorker = new Worker[n];          // создаем массив структур размера n
    std::vector<Worker> vecWorker(n); // создаем вектор из n структур
    std::string tajik; //
    for (int z = 0; z <
                    n; z++) {             // разбиваю каждую строчку на куски (при условии, что заранее известен стандарт ввода данных в инпут.тхт)
        std::getline(fin,
                     tajik);
        std::string fio;
        std::string cash;
        std::string percent;
        int i = 0;
        for (i; tajik[i] != ','; i++) {
            fio += tajik[i];
        }
        i += 2;
        for (i; tajik[i] != ','; i++) {
            cash += tajik[i];
        }
        i += 2;
        for (i; tajik[i] != '.'; i++) {
            percent += tajik[i];
        }
        double cashuzbek = std::stod(cash);       // строчки, содержащие зарплату и процент
        double percentuzbek = std::stod(percent); // привожу к типу данных double используя функцию std::stod()
        pWorker[z].set(fio, cashuzbek, percentuzbek);   // заполняем динам массив структур
        vecWorker[z].set(fio, cashuzbek, percentuzbek); // заполняем вектор структур
    }
    fin.close();
    /*************/
    std::ofstream out("output.txt");
    std::ofstream *P = &out;
    // печать в файл из динамического массива структур
    for(int i=0; i<n; i++) {pWorker[i].printInfo(P);} 
    double peopleCash = 0;
    for(int i=0; i<n; i++) {peopleCash += pWorker[i].zarplat();}
    out << "total salary is " << peopleCash << std::endl;
    out.close();
    // печать в консоль из вектора структур
    for(int i=0; i<n; i++) {vecWorker[i].printConsole();}
    peopleCash = 0;
    for(int i=0; i<n; i++) {peopleCash += pWorker[i].zarplat();}
    std::cout << "total salary is " << peopleCash << std::endl;
    /*************/
}