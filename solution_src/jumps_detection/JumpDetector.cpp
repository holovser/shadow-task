#include "JumpDetector.h"
#include <iostream>
#include <cmath>

std::vector<std::vector<std::pair<double, double>>> JumpDetector::detect(std::vector<std::pair<double, double>> input) {
    std::vector<std::vector<std::pair<double, double>>> result;
    double acceptableDifferenceMultiplier = 300.0;

    std::vector<std::pair<double, double>> tmpSection;
    for (int i = 0; i < input.size() - 1; i++) {
        tmpSection.emplace_back(input[i].first, input[i].second);


        if ((i+1) == (input.size() - 1)) {
            tmpSection.emplace_back(input[i+1].first, input[i+1].second);
            result.push_back(tmpSection);
            break;
        }

        if (abs(input[i].second - input[i+1].second) < 1.0) {
            continue;
        } else {
            result.push_back(tmpSection);
            tmpSection.clear();
        }
    }

    return result;
}