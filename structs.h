#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#pragma once

struct SolvedData
{
    float tau[6];
    float E[6];
    float H[6] = {0,0,0,0,0,0};
};


struct Nvalues
{
    int Nr;
    int Nl;
    int Nb;
    Nvalues();
    void Input(float *R, float *l, float *betta);
    void InputAuto(float *R, float *l, float *betta); //spec_func only for test
    int Sum();
};

Nvalues::Nvalues()
{
    std::cout << "Please, input number of R" << std::endl;
    std::cin >> this->Nr;
    std::cout << "\nPlease, input number of l" << std::endl;
    std::cin >> this->Nl;
    std::cout << "\nPlease, input number of betta" << std::endl;
    std::cin >> this->Nb;
};

void Nvalues::Input(float *R, float *l, float *betta)
{
    std::cout << "Please, input your " << this->Nr << " values for R" << std::endl;
    for (int i = 0; i < this->Nr; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> R[i];
    }
    std::cout << "Please, input your " << this->Nl << " values for l" << std::endl;
    for (int i = 0; i < this->Nl; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> l[i];
    }
    std::cout << "Please, input your " << this->Nb << " values for betta angle" << std::endl;
    for (int i = 0; i < this->Nb; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> betta[i];
    }
};

//spec_func only for test
void Nvalues::InputAuto(float *R, float *l, float *betta)
{
    for (int i = 0; i < this->Nr; ++i)
    {
        R[i] = i;
    }
    for (int i = 0; i < this->Nl; ++i)
    {
        l[i] = i;
    }
    for (int i = 0; i < this->Nb; ++i)
    {
        betta[i] = i;
    }
    std::cout << "All values added" << std::endl;
};

int Nvalues::Sum()
{
    return this->Nr * this->Nl * this->Nb;
};

#endif // STRUCTS_H_INCLUDED
