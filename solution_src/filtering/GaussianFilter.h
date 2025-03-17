#pragma once

#include <vector>
#include <string>

#include "InputFileParser.h"
#include "OutputFileWriter.h"
#include "JumpDetector.h"
#include "JumpJoiner.h"

class GaussianFilterAbstract {
public:
    virtual std::vector<std::pair<double, double>> filter(unsigned int gaussianKernelSize, double standardDeviation) = 0;
};


class GaussianFilter : GaussianFilterAbstract {
public:
    GaussianFilter(InputFileParserAbstract& parser, OutputFileWriterAbstract& fileWriter, 
        JumpDetectorAbstract& jumpDetector, JumpJoinerAbstract& jumpJoiner) 
        : m_parser(parser), m_fileWriter(fileWriter), m_jumpDetector(jumpDetector), m_jumpJoiner(jumpJoiner) {};
    std::vector<std::pair<double, double>> filter(unsigned int gaussianKernelSize, double standardDeviation);

private:
    std::vector<double> calculateGaussianKernel(unsigned int kernelSize, double standardDeviation);
    InputFileParserAbstract& m_parser;
    OutputFileWriterAbstract& m_fileWriter;
    JumpDetectorAbstract& m_jumpDetector;
    JumpJoinerAbstract& m_jumpJoiner;
};