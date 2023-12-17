#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

using s_float = boost::multiprecision::cpp_dec_float_100;

s_float power(const s_float& index, int degree){
    if (degree < 0){
        std::cerr << "Negative degree " << "\n";
        return 0;
    }

    s_float result = 1.0;

    for (int i = 0; i < degree; ++i){
        result *= index;
    }

    return result;
}

s_float boost_factorial(int num){
    s_float fact = 1;

    for (int i = num; i > 1; --i){
        fact *= i;
    }

    return fact;
}

int main() {
    s_float pi_ramanujan = 0; 
    double z = sqrt(8) / 9801;

    for (int k = 0; k < 12; ++k){
        s_float result1 = power(396.0, 4 * k);
        s_float result2 = power(boost_factorial(k), 4);

        s_float n = boost_factorial(4 * k) * (1103 + (26390 * k));
        s_float m = result1 * result2;

        pi_ramanujan +=  n / m;
    }
    
    pi_ramanujan =  1 / (pi_ramanujan * z);

    std::cout << "Pi Ramanujan: " << pi_ramanujan << "\n";
    
    s_float pi_boost = boost::math::constants::pi<s_float>();
    std::cout << "Pi Boost: " << pi_boost << "\n";

    s_float diff = fabs(pi_ramanujan - pi_boost);
    std::cout << "Difference: " << diff << "\n";

    return 0;
}
