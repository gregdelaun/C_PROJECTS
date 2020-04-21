#include <stdio.h>
#include "printf.h"
#include <limits.h>
#include <float.h>
#include <math.h>

int main(void)
{
    ft_printf("%jx", -4294967297);
    printf("\n");
    printf("%jx", -4294967297);
}
