#include <iostream>
#include <cmath>
#include "math_func.h"
#include "error_lib.h"
#include "structs.h"


int main()
{
    Greetings();
    Nvalues Nss;

    if(CountsError(Nss))
        return(0);

    float* R = new float[Nss.Nr];
    float* l = new float[Nss.Nl];
    float* betta = new float[Nss.Nb];
    Nss.Input(R,l,betta);

    SolvedData* Data = new SolvedData[Nss.Sum()];
    int n_el = 0;
    int all = Nss.Nr * Nss.Nl * Nss.Nb;

    std::cout << "Status of progress:" << std::endl;

    for (int i = 0; i < Nss.Nr; ++i)
        for (int j = 0; j < Nss.Nl; ++j)
            for (int k = 0; k < Nss.Nb; ++k)
            {
                ++n_el;
                startEvaluate(R[i],l[j],betta[k], &Data[n_el]);
                ShowProgress(Percent(all, n_el));
            }

    ChangeOutputInFile(Nss, Data, R, l, betta);

    delete [] R;
    delete [] l;
    delete [] betta;

    WaitingEnter();
    return 0;
}
