#include "bigint.hpp"
#include <iostream>

int main()
{
    bigint result(0);
    for (int i = 0; i < 48; i++) {
        result = (result << 1) + bigint(9);
    }
    std::cout << result << std::endl;
    
}