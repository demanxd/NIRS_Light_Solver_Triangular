#ifndef MATH_FUNC_H_INCLUDED
#define MATH_FUNC_H_INCLUDED
#pragma once

#include <iostream>

#include "structs.h"
#include "error_lib.h"



const static float Pi = 3.141592653589793;
const static float w = 120 * Pi;
const static float c = 3 * pow(10,8);
const static float tacos = Pi / 180;                //some mexicans

///R'
float Rs(float R, float l,float betta)
{
    return sqrt(pow(R,2) + pow(l,2) - 2*R*l*cos(betta * tacos));
};

///tau
float tau0(float R, float l,float betta)
{
    return (-R/(c * (1 + cos(betta * tacos))));
}
//
float tau1(float R, float l,float betta)
{
    return (-R/c - l*cos(betta * tacos))/(1-c*cos(betta * tacos));
}


///tau finalx
float t00(float R, float l,float betta)
{
    return tau0(R, l, betta);
};
//
float t01(float R, float l,float betta)
{
    return tau1(R, l, betta);
};
//
float t10(float R, float l,float betta)
{
    return (tau0(R, l, betta) + ((1/c)*(l + sqrt(pow(R,2)+pow(l,2)-2*R*l*cos(betta * tacos))-R)));
};
//
float t11(float R, float l,float betta)
{
    return (tau1(R, l, betta) + ((1/c)*(l + sqrt(pow(R,2)+pow(l,2)-2*R*l*cos(betta * tacos))-R)));
};
//
float t20(float R, float l,float betta)
{
    return (tau0(R, l, betta) + ((1/c)*(l+Rs(R, l, betta))));
};
//
float t21(float R, float l,float betta)
{
    return (tau1(R, l, betta) + ((1/c)*(l+Rs(R, l, betta))));
};

///cos gamma
float cosy(float R, float l,float betta)
{
    return ((R - l*cos(betta*tacos))/Rs(R, l, betta));
};

///E block
float E0(float R, float l,float betta)
{
    return ( -((w)/2*Pi*R)*(1/tan(betta/2)) );
};
//
float E1(float R, float l,float betta)
{
    return ( -(2*(cosy(R,l,betta)/sin(betta * tacos))) );
};
//
float E2(float R, float l,float betta)
{
    return ( tan((betta * tacos)/2) );
};
///H block
float H(float E)
{
    return E/w;
}

///evaluate tau
void evalTau(float R, float l,float betta, SolvedData *Data)
{
    Data->tau[0] = t00(R, l, betta);
    Data->tau[1] = t01(R, l, betta);
    Data->tau[2] = t10(R, l, betta);
    Data->tau[3] = t11(R, l, betta);
    Data->tau[4] = t20(R, l, betta);
    Data->tau[5] = t21(R, l, betta);

    Data->FindMin();

    Data->tau[10] = Data->tau[5] + Data->min_tau + l / c;
    Data->tau[11] = Data->tau[10] * 2;
    Data->tau[8] = Data->tau[4] + Data->min_tau + l / c;
    Data->tau[9] = Data->tau[8] * 2;
    Data->tau[6] = Data->tau[3] + Data->min_tau + l / c;
    Data->tau[7] = Data->tau[6] * 2;
    Data->tau[4] = Data->tau[2] + Data->min_tau + l / c;
    Data->tau[5] = Data->tau[4] * 2;
    Data->tau[2] = Data->tau[1] + Data->min_tau + l / c;
    Data->tau[3] = Data->tau[2] * 2;
    Data->tau[0] = Data->tau[0] + Data->min_tau + l / c;
    Data->tau[1] = Data->tau[0] * 2;
};

///evaluate E
void evalE(float R, float l,float betta, SolvedData *Data)
{
    Data->E[0] = Data->E[1] = E0(R, l, betta);
    Data->E[2] = Data->E[3] = E0(R, l, betta);
    Data->E[4] = Data->E[5] = E1(R, l, betta);
    Data->E[6] = Data->E[7] = E1(R, l, betta);
    Data->E[8] = Data->E[9] = E2(R, l, betta);
    Data->E[10] = Data->E[11] = E2(R, l, betta);
};

///evaluate H
void evalH(SolvedData *Data)
{
    for (int i = 0; i < 12; ++i)
        Data->H[i] = H(Data->E[i]);
}

///evaluate start
void startEvaluate(float R, float l,float betta, SolvedData *Data)
{
    evalTau(R, l, betta, Data);
    evalE(R, l, betta, Data);
    evalH(Data);
};

#endif // MATH_FUNC_H_INCLUDED
