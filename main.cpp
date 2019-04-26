#include <iostream>
#include <cmath>

const static float Pi = 3.141592653589793;
const static float w = 120 * Pi;
const static float c = 3 * pow(10,8);
const static float tacos = Pi / 180;                //some mexicans




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
    std::cout << "Version 0.02" <<std::endl;
    for (int i = 0; i < 27; ++i)
        std::cout << " ";
    std::cout << "You are welcome!" << std::endl;
    for (int i = 0; i < 70; ++i)
        std::cout << "=";
    for (int i = 0; i < 5; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}


void inputVariables(int Nr, int Nl, int Nb)
{
    int R[Nr], l[Nl], betta[Nb];
    std::cout << "Please, input your " << Nr << " values for R" << std::endl;
    for (int i = 0; i < Nr; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> R[i];
    }
    std::cout << "Please, input your " << Nl << " values for l" << std::endl;
    for (int i = 0; i < Nl; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> l[i];
    }
    std::cout << "Please, input your " << Nb << " values for betta angle" << std::endl;
    for (int i = 0; i < Nb; ++i)
    {
        std::cout << i+1 << ":       _:";
        std::cin >> betta[i];
    }
}


int inputNubers()
{
    int Nr, Nl, Nb;                 //N for any cases
    std::cout << "Please, input number of R" << std::endl;
    std::cin >> Nr;
    std::cout << "\nPlease, input number of l" << std::endl;
    std::cin >> Nl;
    std::cout << "\nPlease, input number of betta" << std::endl;
    std::cin >> Nb;

    inputVariables(Nr, Nl, Nb);

    return Nr+Nl+Nb;
}





int main()
{
    Greetings();
    int Ns = inputNubers();                         //N summary


    return 0;
}
