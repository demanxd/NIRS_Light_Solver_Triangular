#include <iostream>
#include <cmath>

const static float Pi = 3.141592653589793;
const static float w = 120 * Pi;
const static float c = 3 * pow(10,8);
const static float tacos = Pi / 180;                //some mexicans





float Rs(int R, int l, int betta)
{
    return sqrt(pow(R,2) + pow(l,2) - 2*R*l*cos(betta * tacos));
};


float tau0(int R, int l, int betta)
{
    return (-R/(c * (1 + cos(betta * tacos))));
}


float tau1(int R, int l, int betta)
{
    return ((-R/c - l*cos(betta * tacos))/(1-c*cos(betta * tacos)));
}


///what about tau??
float t00(int R, int l, int betta)
{
    return tau0(R, l, betta);
};

float t01(int R, int l, int betta)
{
    return tau1(R, l, betta);
};

float t10(int R, int l, int betta)
{
    return tau0(R, l, betta) + ((1/c)*(l + sqrt(pow(R,2)+pow(l,2)-2*R*l*cos(betta * tacos))-R));
};

float t11(int R, int l, int betta)
{
    return tau1(R,l,betta) + ((1/c)*(l + sqrt(pow(R,2)+pow(l,2)-2*R*l*cos(betta * tacos))-R));
};

float t20(int R, int l, int betta)
{
    return tau0(R, l, betta) + ((1/c)*(l+Rs(R, l, betta)));
};

float t21(int R, int l, int betta)
{
    return tau1(R,l,betta) + ((1/c)*(l+Rs(R, l, betta)));
};


float cosy(int R, int l, int betta)
{
    return ((R - l*cos(betta*tacos))/Rs(R, l, betta));
};


float E0(int R, int l, int betta)
{
    return ( -((w)/2*Pi*R)*(1/tan(betta/2)) );
};


float E1(int R, int l, int betta)
{
    return ( -(2*(cosy(R,l,betta)/sin(betta * tacos))) );
};


float E2(int R, int l, int betta)
{
    return ( tan((betta * tacos)/2) );
};







using namespace std;

int main()
{
    cout << cos(30 * tacos) << endl;
    return 0;
}
