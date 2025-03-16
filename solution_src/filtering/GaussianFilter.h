#pragma once

#include <vector>
#include <string>

#include "InputFileParser.h"
#include "OutputFileWriter.h"

class GaussianFilterAbstract {
public:
    virtual std::vector<std::pair<int, int>> filter(unsigned int gaussianKernelSize, double standardDeviation) = 0;
};


class GaussianFilter : GaussianFilterAbstract {
public:
    GaussianFilter(InputFileParserAbstract& parser,
         OutputFileWriterAbstract& fileWriter) : m_parser(parser), m_fileWriter(fileWriter) {};
    std::vector<std::pair<int, int>> filter(unsigned int gaussianKernelSize, double standardDeviation);

private:
    std::vector<double> calculateGaussianKernel(unsigned int kernelSize, double standardDeviation);
    InputFileParserAbstract& m_parser;
    OutputFileWriterAbstract& m_fileWriter;
};