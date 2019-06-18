#ifndef AUXILIARY_FUNCS_H_INCLUDED
#define AUXILIARY_FUNCS_H_INCLUDED

#include <fstream>
#include <cstring>
#include "error_lib.h"

#pragma once

const static std::string WAY = "Data/";



void WaitingEnter()
{
    std::cin.ignore(1024, '\n');
    std::cout << "\nPress [Enter] to continue...";
    std::cin.get();
};

int Percent(int all, int now)
{
    return (now * 100) / all;
}


void ShowProgress(int stage)
{
    std::cout << "\r";
    for (int i = 0; i < stage/2; ++i)
        std::cout << ":";
    for (int i = 0; i < (100 - stage)/2; ++i)
        std::cout << ".";
}


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
    std::cout << "Version 2.1" <<std::endl;
    for (int i = 0; i < 27; ++i)
        std::cout << " ";
    std::cout << "You are welcome!" << std::endl;
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    for (int i = 0; i < 5; ++i)
        std::cout << "\n";
    std::cout << std::endl;
};

void OutputConsole(SolvedData Data)
{
    for (int i = 0; i < 12; ++i)
        std::cout << "tau " << i << ":....  :"  << Data.tau[i] << std::endl;
    for (int i = 0; i < 12; ++i)
        std::cout << "E " << i << ":....  :"  << Data.E[i] << std::endl;
    for (int i = 0; i < 12; ++i)
        std::cout << "H " << i << ":....  :"  << Data.H[i] << std::endl;
};

void OutputDifFiles(SolvedData Data, float R, float l, float betta)
{
    std::string namefile = WAY + "Data R=" + std::to_string(R) + ".l=" + std::to_string(l) + ".betta=" + std::to_string(betta) + ".csv";
    std::ofstream file;
    file.open(namefile);
    for (int i = 0; i < 12; ++i)
        file << Data.tau[i] <<"; ";
    file << "\n";
    for (int i = 0; i < 12; ++i)
        file << Data.E[i] <<"; ";
    file << "\n";
    for (int i = 0; i < 12; ++i)
        file << Data.H[i] <<"; ";
    file.close();
};

void OutputOneFile(Nvalues Nss, SolvedData *Data, float *R, float *l, float *betta)
{
    std::string namefile = WAY + "Data_All.csv";
    std::ofstream file;
    file.open(namefile);
    int n_el = 0;

    for (int i = 0; i < Nss.Nr; ++i)
        for (int j = 0; j < Nss.Nl; ++j)
            for (int k = 0; k < Nss.Nb; ++k)
            {
                file << "R[" << i+1 << "] = " << R[i] << " l[" << j+1 << "] = " << l[j] << " betta[" << k+1 << "] = " << betta[k] << "\n";
                ++n_el;
                for (int n = 0; n < 12; ++n)
                        file << Data[n_el].tau[n] <<";" << Data[n_el].E[n] << ";"<< Data[n_el].H[n] <<";\n";
                file << "\n";

            }
    file.close();
    std::cout << "\nOutput complete!" << std::endl;
};

void ChangeOutputInFile(Nvalues Nss, SolvedData *Data, float *R, float *l, float* betta)
{
    int ch;
    std::cout << "\nEvaluate is over!\nHow do you want to write results?\n[1-in one file\\2-in different files]  :";
    std::cin >> ch;
    int n_el = 0;
    switch (ch)
    {
        case 1:
            OutputOneFile(Nss, Data, R, l, betta);
        break;
        case 2:
            for (int i = 0; i < Nss.Nr; ++i)
                for (int j = 0; j < Nss.Nl; ++j)
                    for (int k = 0; k < Nss.Nb; ++k)
                    {
                        ++n_el;
                        OutputDifFiles(Data[n_el], R[i], l[j], betta[k]);
                    }
            std::cout << "\nOutput complete!" << std::endl;
        break;
        /*default:
            ChangeError();*/
    }
}


#endif // AUXILIARY_FUNCS_H_INCLUDED
