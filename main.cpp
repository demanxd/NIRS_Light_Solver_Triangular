#include <iostream>
#include <cmath>
#include "math_func.h"
#include "error_lib.h"










///Greetings



void inputVariables(Nvalues &Nss, int *R, int *l, int *betta)
{
    //int R[Nss.Nr], l[Nss.Nl], betta[Nss.Nb];
    std::cout << "Please, input your " << Nss.Nr << " values for R" << std::endl;
    for (int i = 0; i < Nss.Nr; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> R[i];
    }
    std::cout << "Please, input your " << Nss.Nl << " values for l" << std::endl;
    for (int i = 0; i < Nss.Nl; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> l[i];
    }
    std::cout << "Please, input your " << Nss.Nb << " values for betta angle" << std::endl;
    for (int i = 0; i < Nss.Nb; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> betta[i];
    }
}


int inputNubers(Nvalues &Nss)
{
    std::cout << "Please, input number of R" << std::endl;
    std::cin >> Nss.Nr;
    std::cout << "\nPlease, input number of l" << std::endl;
    std::cin >> Nss.Nl;
    std::cout << "\nPlease, input number of betta" << std::endl;
    std::cin >> Nss.Nb;

    return Nss.Nr+Nss.Nl+Nss.Nb;
}





int main()
{
    Greetings();
    Nvalues Nss;
    int Ns = inputNubers(Nss);                         //N summary

    if(errorCounts(Nss))
        return(0);

    int R[Nss.Nr], l[Nss.Nl], betta[Nss.Nb];
    inputVariables(Nss, R,l,betta);

    return 0;
}
