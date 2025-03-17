#include <gtest/gtest.h>
#include "JumpDetector.h"

TEST(JumpDetectionTest, BasicTest) {
    
    std::vector<std::pair<double, double>> input = {
        {1.0, 2.1}, {2.0, 2.0}, {3.0, 2.2}, // First section (close values)
        {4.0, 3.5}, {5.0, 3.6},             // Second section (jump from 2.2 → 3.5)
        {6.0, 5.0}, {7.0, 5.2}, {8.0, 5.1}  // Third section (jump from 3.6 → 5.0)
    };

    std::vector<std::vector<std::pair<double, double>>> expectedOutput = {
        {{1.0, 2.1}, {2.0, 2.0}, {3.0, 2.2}},
        {{4.0, 3.5}, {5.0, 3.6}},
        {{6.0, 5.0}, {7.0, 5.2}, {8.0, 5.1}}
    };

    JumpDetector jumpDetector;
    std::vector<std::vector<std::pair<double, double>>> actualOutput = jumpDetector.detect(input);

    ASSERT_EQ(actualOutput.size(), expectedOutput.size()) << "Mismatch in number of detected sections";

    // Compare each section
    for (size_t i = 0; i < expectedOutput.size(); ++i) {
        ASSERT_EQ(actualOutput[i].size(), expectedOutput[i].size()) << "Mismatch in section " << i;

        for (size_t j = 0; j < expectedOutput[i].size(); ++j) {
            EXPECT_DOUBLE_EQ(actualOutput[i][j].first, expectedOutput[i][j].first) 
                << "Mismatch at section " << i << ", index " << j << " (first element)";
            EXPECT_DOUBLE_EQ(actualOutput[i][j].second, expectedOutput[i][j].second) 
                << "Mismatch at section " << i << ", index " << j << " (second element)";
        }
    }

}