#include "GaussianFilter.h"

#include <vector>
#include <string>   // For std::stoi, std::stod, and std::string
#include <stdexcept>
#include <iostream>


int main(int argc, char* argv[]) {

    unsigned int kernelSize = 0;
    double standardDeviation = 0;

    InputFileParser parser("/Users/serhiiholovko/Documents/shadow-task/raw_data/sample.txt");
    OutputFileWriter outputWriter("/Users/serhiiholovko/Documents/shadow-task/raw_data/filtered_output.txt");
    JumpDetector jumpDetector;
    JumpJoiner jumpJoiner;

    GaussianFilter filter(parser, outputWriter, jumpDetector, jumpJoiner);
    filter.filter(45, 30.0);

}