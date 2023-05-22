#include <stdio.h>
#include <math.h>

// Function to integrate
double f(double x) {
    return x * x;  // Example function: x^2
}

// Trapezoidal rule implementation
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = (f(a) + f(b)) / 2.0;  // Initialize sum

    // Calculate sum of function values at intermediate points
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;  // Return the approximate integral value
}

int main() {
    double a, b;  // Lower and upper limits of integration
    int n;        // Number of subintervals

    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);

    printf("Enter the number of subintervals: ");
    scanf("%d", &n);

    double result = trapezoidalRule(a, b, n);
    printf("Approximate integral: %.6lf\n", result);

    return 0;
}
