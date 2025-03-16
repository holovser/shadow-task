#include "GaussianFilter.h"

#include <vector>
#include <string>   // For std::stoi, std::stod, and std::string
#include <stdexcept>
#include <iostream>


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <kernel_size> <std_deviation>" << std::endl;
        return 1;
    }

    unsigned int kernelSize = 0;
    double standardDeviation = 0;

    // try {
    //     kernelSize = std::stoi(argv[1]);
    //     standardDeviation = std::stod(argv[2]);

    //     // Output the parsed values
    //     std::cout << "Kernel size: " << kernelSize << std::endl;
    //     std::cout << "Standard deviation: " << standardDeviation << std::endl;
    // } catch (const std::invalid_argument& e) {
    //     std::cerr << "Invalid argument: " << e.what() << std::endl;
    //     return 1;
    // } catch (const std::out_of_range& e) {
    //     std::cerr << "Argument out of range: " << e.what() << std::endl;
    //     return 1;
    // }

    InputFileParser parser("/Users/serhiiholovko/Documents/shadow-task/input/sample.txt");
    OutputFileWriter outputWriter("/Users/serhiiholovko/Documents/shadow-task/input/filtered_output.txt");

    GaussianFilter filter(parser, outputWriter);
    filter.filter(55, 45.0);

}