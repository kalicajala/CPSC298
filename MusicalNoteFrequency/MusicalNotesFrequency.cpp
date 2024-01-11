#include <iostream>
#include <cmath>

int main() {
    std::cout << "Reference Frequency: 16.35 Hz" << std::endl;
    std::cout << "Speed of Sound: 345 m/s" << std::endl;
    std::cout << "Note: C0; nu: 0; frequency: 16.35; wavelength: 2110.09 cm" << std::endl;
    
    double f_r = 16.35;
    double f_kv = 0.0;
    int v = 0;
    double k = 1.0;
    int c = 345;
    double w_kv = 0.0;


    f_kv = f_r * pow(2, v) * pow(2, (k / 12));
    w_kv = (c / f_kv) * 100;
    std::cout << "Note: C#0; nu: " << v << "; k: " << k << "; frequency: " << f_kv << " Hz; wavelenegth: " << w_kv << " cm" << std::endl;

    f_r = 18.35;
    v = 0;
    k = 0.0;
    f_kv = f_r * pow(2, v) * pow(2, (k / 12));
    w_kv = (c / f_kv) * 100;
    std::cout << "Note: D0; nu: " << v << "; k: " << k << "; frequency: " << f_kv << " Hz; wavelenegth: " << w_kv << " cm" << std::endl;

    f_r = 16.35;
    v = 4;
    k = 0.0;
    f_kv = f_r * pow(2, v) * pow(2, (k / 12));
    w_kv = (c / f_kv) * 100;
    std::cout << "Note: C4; nu: " << v << "; k: " << k << "; frequency: " << f_kv << " Hz; wavelenegth: " << w_kv << " cm" << std::endl;

    f_r = 18.35;
    v = 7;
    k = 3.0;
    f_kv = f_r * pow(2, v) * pow(2, (k / 12));
    w_kv = (c / f_kv) * 100;
    std::cout << "Note: D#7; nu: " << v << "; k: " << k << "; frequency: " << f_kv << " Hz; wavelenegth: " << w_kv << " cm" << std::endl;

    f_r = 16.35;
    v = 8;
    k = 0.0;
    f_kv = f_r * pow(2, v) * pow(2, (k / 12));
    w_kv = (c / f_kv) * 100;
    std::cout << "Note: C8, nu: " << v << "; k: " << k << "; frequency: " << f_kv << " Hz; wavelenegth: " << w_kv << " cm" << std::endl;

}

