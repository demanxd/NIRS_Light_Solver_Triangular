#ifndef MATH_FUNC_H_INCLUDED
#define MATH_FUNC_H_INCLUDED
#pragma once


#include "structs.h"
#include <cstring>
#include "error_lib.h"

std::string name;




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

///evaluate tau
void evalTau(int R, int l, int betta)
{
    t00(R, l, betta);
    t01(R, l, betta);
    t10(R, l, betta);
    t11(R, l, betta);
    t20(R, l, betta);
    t21(R, l, betta);

};

///evaluate E
void evalE(int R, int l, int betta)
{
    E0(R, l, betta);
    E1(R, l, betta);
    E2(R, l, betta);
};

///evaluate start
void startEvaluate(int R, int l, int betta)
{
    evalTau(R, l, betta);
    evalE(R, l, betta);
    //name = "startEvaluate";
    //errorFormula(name);
};

#endif // MATH_FUNC_H_INCLUDED
