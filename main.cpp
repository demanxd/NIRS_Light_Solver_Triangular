#include <iostream>
#include <cmath>

const static float Pi = 3.141592653589793;
const static float w = 120 * Pi;
const static float c = 3 * pow(10,8);
const static float tacos = Pi / 180;                //some mexicans

struct Nvalues
{
    int Nr;
    int Nl;
    int Nb;
};


///R'
float Rs(int R, int l, int betta)
{
    return sqrt(pow(R,2) + pow(l,2) - 2*R*l*cos(betta * tacos));
};

///tau
float tau0(int R, int l, int betta)
{
    return (-R/(c * (1 + cos(betta * tacos))));
}
//
float tau1(int R, int l, int betta)
{
    return ((-R/c - l*cos(betta * tacos))/(1-c*cos(betta * tacos)));
}


///tau final
float t00(int R, int l, int betta)
{
    return tau0(R, l, betta);
};
//
float t01(int R, int l, int betta)
{
    return tau1(R, l, betta);
};
//
float t10(int R, int l, int betta)
{
    return tau0(R, l, betta) + ((1/c)*(l + sqrt(pow(R,2)+pow(l,2)-2*R*l*cos(betta * tacos))-R));
};
//
float t11(int R, int l, int betta)
{
    return tau1(R,l,betta) + ((1/c)*(l + sqrt(pow(R,2)+pow(l,2)-2*R*l*cos(betta * tacos))-R));
};
//
float t20(int R, int l, int betta)
{
    return tau0(R, l, betta) + ((1/c)*(l+Rs(R, l, betta)));
};
//
float t21(int R, int l, int betta)
{
    return tau1(R,l,betta) + ((1/c)*(l+Rs(R, l, betta)));
};

///cos gamma
float cosy(int R, int l, int betta)
{
    return ((R - l*cos(betta*tacos))/Rs(R, l, betta));
};

///E block
float E0(int R, int l, int betta)
{
    return ( -((w)/2*Pi*R)*(1/tan(betta/2)) );
};
//
float E1(int R, int l, int betta)
{
    return ( -(2*(cosy(R,l,betta)/sin(betta * tacos))) );
};
//
float E2(int R, int l, int betta)
{
    return ( tan((betta * tacos)/2) );
};


///Greetings
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
    std::cout << "Version 0.03" <<std::endl;
    for (int i = 0; i < 27; ++i)
        std::cout << " ";
    std::cout << "You are welcome!" << std::endl;
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    for (int i = 0; i < 5; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}


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

    int R[Nss.Nr], l[Nss.Nl], betta[Nss.Nb];
    inputVariables(Nss, R,l,betta);

    return 0;
}
