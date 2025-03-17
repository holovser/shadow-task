#include <gtest/gtest.h>
#include "JumpJoiner.h"

TEST(JumpJoinTest, BasicTest) {
    JumpJoiner joiner;

    std::vector<std::vector<std::pair<double, double>>> inputSections;


    std::vector<std::pair<double, double>> section1 = {
        {1.0, 2.1}, {2.0, 1.9}, {3.0, 2.3}, {4.0, 2.0}, {5.0, 1.8},
        {6.0, 2.2}, {7.0, 2.0}, {8.0, 1.7}, {9.0, 2.4}, {10.0, 2.1}
    };

    std::vector<std::pair<double, double>> section2 = {
        {11.0, 5.1}, {12.0, 4.8}, {13.0, 5.3}, {14.0, 4.9}, {15.0, 5.2},
        {16.0, 4.7}, {17.0, 5.0}, {18.0, 5.4}, {19.0, 4.6}, {20.0, 5.1}
    };

    std::vector<std::pair<double, double>> section3 = {
        {21.0, 8.2}, {22.0, 7.8}, {23.0, 8.4}, {24.0, 7.9}, {25.0, 8.3},
        {26.0, 7.7}, {27.0, 8.1}, {28.0, 7.6}, {29.0, 8.5}, {30.0, 8.0}
    };

    inputSections.push_back(section1);
    inputSections.push_back(section2);
    inputSections.push_back(section3);

    auto actualOutput = joiner.join(inputSections);

    std::vector<std::pair<double, double>> expectedOutput = {
        {1, 2.1},{2, 1.9},{3, 2.3},{4, 2},{5, 1.8},{6, 2.2},
        {7, 2},{8, 1.7},{9, 3.15},{10, 3.6},{11, 3.6},{12, 4.8},
        {13, 5.3},{14, 4.9},{15, 5.2},{16, 4.7},{17, 5},{18, 5.4},
        {19, 5.375},{20, 6.65},{21, 6.65},{22, 7.8},{23, 8.4},{24, 7.9},
        {25, 8.3},{26, 7.7},{27, 8.1},{28, 7.6},{29, 8.5},{30, 8}
    };

    for (size_t i = 0; i < expectedOutput.size(); ++i) {
        EXPECT_DOUBLE_EQ(actualOutput[i].first, expectedOutput[i].first) << "Mismatch at index " << i;
        EXPECT_DOUBLE_EQ(actualOutput[i].second, expectedOutput[i].second) << "Mismatch at index " << i;
    }
}