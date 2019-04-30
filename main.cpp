#include <iostream>
#include <cmath>
#include "math_func.h"
#include "error_lib.h"
#include "structs.h"


int main()
{
    Greetings();
    Nvalues Nss;

    if(errorCounts(Nss))
        return(0);

    float R[Nss.Nr], l[Nss.Nl];
    int betta[Nss.Nb];
    Nss.Input(R,l,betta);
    SolvedData Data[Nss.Sum()];
    int n_el = 0;

    for (int i = 0; i < Nss.Nr; ++i)
        for (int j = 0; j < Nss.Nl; ++j)
            for (int k = 0; k < Nss.Nb; ++k)
            {
                ++n_el;
                startEvaluate(R[i],l[j],betta[k],Data[n_el]);
                outputConsole(Data[n_el]);
            }

    WaitingEnter();
    return 0;
}
