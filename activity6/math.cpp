#include "mathlib.h"

#include <iostream>

const float ENEMY_VIEW_RADIUS_METERS = 5;

int main() {
    std::array<float, 3> enemy1_location = {2, 2, 0};
    std::array<float, 3> enemy2_location = {2, 4, 0};

    float enemy_distance = mathlib::distance(enemy1_location, enemy2_location);
    float distance_from_centre = mathlib::distance(enemy1_location);

    using mathlib::curcumference;
    float view_circumference_for_enemy = curcumference(ENEMY_VIEW_RADIUS_METERS);

    float total_distance = mathlib::total_walking_distance({
        enemy1_location,
        {2, 3, 0},
        {2, 3, 3},
        {5, 3, 3},
        {8, 3, 3},
        {8, 3, 2},
        {2, 3, 2},
        {2, 3, 1},
        {2, 3, 2},
        enemy2_location
    });

    std::cout << "The two enemies are " << enemy_distance << "m apart and can see for a circumference of "
              << view_circumference_for_enemy << "m. To go to from one to the other they need to walk "
              << total_distance << "m." << std::endl;
    
    return 0;
}