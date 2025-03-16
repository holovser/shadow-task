#include "InputFileParser.h"

#include <iostream>
#include <fstream>
#include <sstream>

int InputFileParser::parse(std::vector<std::pair<int, int>> &result) {

    std::ifstream file(m_filePath);
    std::vector<std::pair<double, double>> data;
    std::string line;
    double x, y;
    
    if (!file) {
        std::cerr << "Error: Could not open file " << m_filePath << std::endl;
        return -1;
    }
    
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (iss >> x >> y) {
            std::pair<double, double> lineData;
            lineData.first = x;
            lineData.second = x;
            result.push_back(lineData);
        }
    }

    std::cout << "File " << m_filePath << " was parsed successfully" << std::endl;
    
    return 0;
}
