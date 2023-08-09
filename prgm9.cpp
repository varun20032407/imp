#include <stdio.h>

int fibonacciSum(int n) {
    if (n <= 0) {
        return 0;
    }

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    int sum = fib[0] + fib[1];

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        sum += fib[i];
    }

    return sum;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sum = fibonacciSum(n);

    printf("Sum of the first %d terms of the Fibonacci series: %d\n", n, sum);

    return 0;
}

