// @file leibnitz_pi.cpp
// @brief uses a for loop to imitate summation and approximate pi
// @author Kali Cajala

#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

int main() {
    int n = 0;
    double piOver4 = 0.0;
    double pi = 0.0;

    std::cout << "Please enter a non-negative integer upper limit of summation for the Leibnit formula for computing pi: " << std::endl;
    cin >> n;    

    for (int k = 0; k <= n; k++) {
        piOver4 += ((pow(-1.0, k)) / (2 * k + 1));
    }
    
    pi = piOver4 * 4;

    std::cout << "PI (approx): " << std::fixed << std::setprecision(15) << pi << "; n: " << n << std::endl;
    std::cout << "PI (actual): 3.141592653589793" << std::endl;
    std::cout << "Decimal digits of precicion: " << DBL_DIG << std::endl;
    std::cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << std::endl;
    std::cout << "Next representable number from 3.141592653589793: " << std::nextafter(3.141592653589793, 3.14) << std::endl;
}