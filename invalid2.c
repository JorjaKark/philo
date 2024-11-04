#include "philosophers.h"

void invalid_nbr_of_parameters() {
    ft_fprintf(2, "Invalid number of parameters.\n");
}

void invalid_integer(int *ret) {
    ft_fprintf(2, "Invalid integer: out of range.\n");
    *ret = 0;
}