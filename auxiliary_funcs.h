#ifndef AUXILIARY_FUNCS_H_INCLUDED
#define AUXILIARY_FUNCS_H_INCLUDED

#pragma once


void WaitingEnter()
{
    std::cin.ignore(1024, '\n');
    std::cout << "Press enter to continue...";
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
    std::cout << "Version 1.01" <<std::endl;
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
}



#endif // AUXILIARY_FUNCS_H_INCLUDED
