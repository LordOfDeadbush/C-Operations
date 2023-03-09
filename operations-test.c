#include "operations.h"
#include <stdio.h>
#include <time.h>

int main() {
    printf("%i\n", clock());
    printf("%i\n", factorial(10));
    printf("%i", clock());
}