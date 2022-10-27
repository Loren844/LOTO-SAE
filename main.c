#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "creerCartons.h"

int main()
{
    srand(time(NULL));
    for(int i=0;i<3;i++)
    {
       creerCarton();
       printf("\n");
    }

}
