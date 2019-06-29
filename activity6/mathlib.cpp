#include "mathlib.h"

#include <cmath>

namespace mathlib {
    const float PI = 3.14f;

    float distance(float a, float b) {
        return b - a;
    }

    int distance(int a, int b) {
        return b - a;
    }

    float distance(std::array<float, 3> a, std::array<float, 3> b) {
        return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2) + std::pow(b[2] - a[2], 2));
    }

    float curcumference(float radius) {
        return 2 * PI * radius;
    }

    float total_walking_distance(const std::array<std::array<float, 3>, 10>& locations) {
        float distance_walked_so_far = 0;

        for (int current_location = 1; current_location < 10; current_location++) {
            int previous_location = current_location - 1;
            float current_distance = distance(locations[previous_location], locations[current_location]);
            distance_walked_so_far += current_distance;
        }

        return distance_walked_so_far;
    }
}
