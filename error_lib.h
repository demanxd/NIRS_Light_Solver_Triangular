#ifndef ERROR_LIB_H_INCLUDED
#define ERROR_LIB_H_INCLUDED

#pragma once

#include "structs.h"
#include "math_func.h"
#include "auxiliary_funcs.h"

#include <cstring>



bool CountsError(Nvalues Nss)
{
    if ((Nss.Nr == 0)||(Nss.Nl == 0)||(Nss.Nb == 0))
    {
        std::cout << "Error!\n------\nError number 0001\n------" << std::endl;
        WaitingEnter();
        return true;
    }
    else
        return false;
};

void FormulaError(std::string name)
{
    std::cout << "Error!\n------\nError number 1001\n------" << std::endl;
    std::cout << "In formula ||" << name << "|| no errors" << std::endl;
    WaitingEnter();
};

void ChangeError()
{
    std::cout << "Error Input" << std::endl;
};
#endif // ERROR_LIB_H_INCLUDED
