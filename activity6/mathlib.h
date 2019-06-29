#ifndef MATHLIB_H
#define MATHLIB_H

#include <array>

namespace mathlib {
    
    float distance(float a, float b);
    int distance(int a, int b);

    float distance(std::array<float, 3> a, std::array<float, 3> b = {0, 0, 0});

    float curcumference(float radius);

    float total_walking_distance(const std::array<std::array<float, 3>, 10>& locations);

}

#endif
