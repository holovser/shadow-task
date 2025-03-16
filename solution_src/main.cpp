#include "InputFileParser.h"
#include <vector>


int main() {
    InputFileParser parser("/Users/serhiiholovko/Documents/shadow-task/input/sample.txt");

    std::vector<std::pair<int, int>> result;
    parser.parse(result);
}