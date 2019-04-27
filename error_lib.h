#ifndef ERROR_LIB_H_INCLUDED
#define ERROR_LIB_H_INCLUDED

#pragma once

#include "math_func.h"
#include "auxiliary_funcs.h"



bool errorCounts(Nvalues Nss)
{
    if ((Nss.Nr == 0)||(Nss.Nl == 0)||(Nss.Nb == 0))
    {
        std::cout << "Error!\n------\nError number 0001\n------" << std::endl;
        WaitingEnter();
        return true;
    }
    else
        return false;
}
#endif // ERROR_LIB_H_INCLUDED
