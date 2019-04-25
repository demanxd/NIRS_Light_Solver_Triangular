#include <iostream>
#include <cmath>

const static float Pi = 3.141592653589793;
const static float w = 120 * Pi;
const static float c = 3 * pow(10,8);
const static float tacos = Pi / 180;                //some mexicans


float p()
{

};


float z(int betta)
{
   return p() * cos(betta * tacos);
};


///what about tau??
float t(float tau, int R, int betta)
{
    return tau + z(betta)/c + R/c;
};


float Rs(int R, int l, int betta)
{
    return sqrt(pow(R,2) + pow(l,2) - 2*R*l*cos(betta * tacos));
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
