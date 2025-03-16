#include "GaussianFilter.h"

#include "InputFileParser.h"

#include <iostream>
#include <cmath>
#include <fstream>

#define PI 3.141592
#define EULERS_NUMBER 2.71828

std::vector<std::pair<int, int>> GaussianFilter::filter(unsigned int gaussianKernelSize, double standardDeviation) {
    std::vector<std::pair<double, double>> input;
    if (m_parser.parse(input) != 0) {
        std::cerr << "Error: Could not get data from parser" << std::endl;
        return std::vector<std::pair<int, int>>();
    }

    if (gaussianKernelSize % 2 != 1) {
        throw std::runtime_error("Gaussian Kernel size must be an odd number");
    }

    auto gaussianKernel = calculateGaussianKernel(gaussianKernelSize, standardDeviation);

    int middleOfKernel = (gaussianKernelSize - 1) / 2;

    std::vector<std::pair<double, double>> output;

    for (int i = middleOfKernel; i < (input.size() - middleOfKernel); i++ ) {
        double newValue = 0.0;
        int kernelIndex = 0;
        for (int j = i - middleOfKernel; j <= i + middleOfKernel; j++, kernelIndex++) {
            newValue += gaussianKernel[kernelIndex] * input[j].second;
        }
        output.emplace_back(input[i].first, newValue);
    }

    m_fileWriter.write(output);

    return std::vector<std::pair<int, int>>();

}

std::vector<double> GaussianFilter::calculateGaussianKernel(unsigned int kernelSize, double standardDeviation) {
    std::vector<double> gaussianKernel(kernelSize);

    double normalizationFactor = (1.0)/(sqrt(2.0*PI*pow(standardDeviation, 2)));

    for (int i = 0; i <= (kernelSize - 1) / 2; i++) {
        double exponentialPart = pow(EULERS_NUMBER, -(pow(i, 2)/(2*pow(standardDeviation, 2))));

        int middleOfKernel = (kernelSize - 1) / 2;
        int indexLeft = middleOfKernel - i;
        int indexRight = middleOfKernel + i;
        double kernelValue = normalizationFactor * exponentialPart;

        gaussianKernel[indexLeft] = kernelValue;
        gaussianKernel[indexRight] = kernelValue;
    }

    return gaussianKernel;
}
