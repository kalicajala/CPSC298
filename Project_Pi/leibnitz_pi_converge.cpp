// @file leibnitz_pi_converge.cpp
// @brief uses a for loop to imitate summation and approximate pi using powers of 2
// @author Kali Cajala

#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

int main() {
    double piOver4 = 0.0;
    double pi = 0.0;
    int pow_n = 0;

    for (int n = 1; n <= 20; n++) {
        for (int k = 0; k <= pow(2, n); k++) {
            piOver4 += ((pow(-1.0, k)) / (2 * k + 1));
        }
        pi = 4 * piOver4;
        piOver4 = 0.0;
        pow_n = pow(2, n);
        std::cout << "PI: " << std::fixed << std::setprecision(15) << pi << "; n: " << pow_n << std::endl;

    }
}