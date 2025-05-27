#include <stdio.h>

// A simple addition function
int add(int a, int b) {
    return a + b;
}

// A simple subtraction function
int subtract(int a, int b) {
    return a - b;
}

void calc(int a, int b, int (*op)(int, int)) {
    printf("%d\n", op(a, b));
}

int main() {
  
    // Passing different 
    // functions to 'calc'
    calc(10, 5, add);
  	calc(10, 5, subtract);
    return 0;
}