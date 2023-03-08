#include "operations.h"
#include <stdio.h>
#include <time.h>

int main() {
    printf("%i\n", clock());
    printf("%f\n", log(100, 10));
    printf("%i", clock());
}