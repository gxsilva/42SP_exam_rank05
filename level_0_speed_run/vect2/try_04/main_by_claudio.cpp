/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_by_claudio.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:09:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/10 17:18:56 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
#include "vect2.hpp"

int main() {
    // --- Construction ---
    vect2 a(2, 3);
    vect2 b(1, 4);

    // --- operator[] ---
    assert(a[0] == 2);
    assert(a[1] == 3);
    std::cout << "[PASS] operator[]\n";

    // --- Addition ---
    vect2 add = a + b;
    assert(add[0] == 3 && add[1] == 7);
    std::cout << "[PASS] operator+\n";

    // --- Subtraction ---
    vect2 sub = a - b;
    assert(sub[0] == 1 && sub[1] == -1);
    std::cout << "[PASS] operator-\n";

    // --- Multiplication by scalar ---
    vect2 mul = a * 2;
    assert(mul == vect2(4, 6));
    std::cout << "[PASS] operator* (scalar)\n";

    // --- Equality from subject example ---
    assert(vect2(2, 2) * 2 == vect2(4, 4));
    std::cout << "[PASS] subject example: (vect2(2,2) * 2 == vect2(4,4))\n";

    // --- operator<< ---
    vect2 v(5, 7);
    std::cout << "[PRINT TEST] operator<< output: " << v << "\n";
    std::cout << "[PRINT TEST] expected output:   {" << v[0] << ", " << v[1] << "}\n";

    // --- Edge cases ---
    vect2 zero(0, 0);
    assert((zero + a) == a);
    assert((a - a) == zero);
    assert((a * 0) == zero);
    std::cout << "[PASS] edge cases (zero vector, self-subtraction, multiply by 0)\n";

    // --- Negative values ---
    vect2 neg(-3, -5);
    vect2 neg_add = neg + a;
    assert(neg_add[0] == -1 && neg_add[1] == -2);
    std::cout << "[PASS] negative values\n";

    std::cout << "\nAll tests passed!\n";
    return 0;
}