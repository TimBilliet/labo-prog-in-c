#include <stdio.h>

// Function to approximate sin(x) using Taylor series with 1 loop
double taylor_sin(double x, int terms) {
    double result = 0.0;  // Final result (sum of series)
    double term = x;      // The first term (x^1 / 1!)
    int sign = 1;         // Alternating sign (-1)^i
    int n = 1;            // Denominator factorial (starts at 1)

    for (int i = 1; i <= terms; i++) {
        result += sign * term;  // Add the current term with alternating sign

        // Update for the next term:
        n += 2;                         // Next term uses the next odd number in the denominator
        term *= x * x / (n * (n - 1));  // Update term for x^(2*i+1) / (2*i+1)!
        sign *= -1;                     // Alternate the sign for the next term
    }

    return result;
}

int main() {
    double x;
    int terms;


    x = 4;

    terms = 10;
    // Calculate sin(x) using the Taylor series approximation
    double approx_sin = taylor_sin(x, terms);

    // Display the result
    printf("Approximation of sin(%.2lf) using %d terms is: %.10lf\n", x, terms, approx_sin);

    return 0;
}
