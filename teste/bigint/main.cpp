#include "bigint.hpp"
#include <iostream>

int main()
{
    bigint result(0);
	// std::cout << (result << 1) << std::endl;

	std::cout << bigint::addition("00", "9") << std::endl;
    // for (int i = 0; i < 48; i++) {
    //     result = (result << 1) + bigint(9);
    // }
    // std::cout << result << std::endl;
    return (0);
}