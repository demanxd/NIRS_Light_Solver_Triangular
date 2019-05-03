#ifndef AUXILIARY_FUNCS_H_INCLUDED
#define AUXILIARY_FUNCS_H_INCLUDED

#include <fstream>
#include <cstring>

#pragma once

std::string WAY = "/home/dvsh/cpp/NIRS_Light_Solving_Triangular/Data/";



void WaitingEnter()
{
    std::cin.ignore(1024, '\n');
    std::cout << "Press [Enter] to continue...";
    std::cin.get();
};


void Greetings()
{
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    std::cout << std::endl;
    for (int i = 0; i < 5; ++i)
        std::cout << " ";
    std::cout << "Programm for solving field of triangular antennas parameters" << std::endl;
    for (int i = 0; i < 29; ++i)
        std::cout << " ";
    std::cout << "Version 1.02" <<std::endl;
    for (int i = 0; i < 27; ++i)
        std::cout << " ";
    std::cout << "You are welcome!" << std::endl;
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    for (int i = 0; i < 5; ++i)
        std::cout << "\n";
    std::cout << std::endl;
};

void outputConsole(SolvedData Data)
{
    for (int i = 0; i < 6; ++i)
        std::cout << "tau " << i << ":....  :"  << Data.tau[i] << std::endl;
    for (int i = 0; i < 6; ++i)
        std::cout << "E " << i << ":....  :"  << Data.E[i] << std::endl;
};

void outputFile(SolvedData Data, float R, float l, int betta)
{
    std::string namefile = WAY + "Data R=" + std::to_string(R) + ".l=" + std::to_string(l) + ".betta=" + std::to_string(betta) + ".csv";
    std::ofstream file;
    file.open(namefile);
    for (int i = 0; i < 6; ++i)
        file << Data.tau[i] <<"; ";
    file << "\n";
    for (int i = 0; i < 6; ++i)
        file << Data.E[i] <<"; ";
    file << "\n";
    for (int i = 0; i < 6; ++i)
        file << Data.H[i] <<"; ";
    file.close();
}


#endif // AUXILIARY_FUNCS_H_INCLUDED
