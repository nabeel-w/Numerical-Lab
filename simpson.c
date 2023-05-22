#include <stdio.h>
#include <math.h>

// Function to integrate
double f(double x) {
    return x * x;  // Example function: x^2
}

// Simpson's 1/3 rule implementation
double simpsonsOneThirdRule(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // Initialize sum

    // Calculate sum of function values at intermediate points
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2.0 * f(x);
        else
            sum += 4.0 * f(x);
    }

    return (h / 3.0) * sum;  // Return the approximate integral value
}

int main() {
    double a, b;  // Lower and upper limits of integration
    int n;        // Number of subintervals

    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);

    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);

    printf("Enter the number of subintervals (should be even): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error: Number of subintervals should be even.\n");
        return 1;
    }

    double result = simpsonsOneThirdRule(a, b, n);
    printf("Approximate integral: %.6lf\n", result);

    return 0;
}
