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
float t(float tau, int R)
{
    return tau + z()/c + R/c;
};


float Rs(int R, int l, int betta)
{
    return sqrt(pow(R,2) + pow(l,2) - 2*R*l*cos(betta * tacos));
};


float cosy(int R, int l, int betta)
{
    return ((R - l*cos(betta*tacos))/Rs());
};







using namespace std;

int main()
{
    cout << cos(30 * tacos) << endl;
    return 0;
}
