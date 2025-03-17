#pragma once

#include <vector>


class JumpDetectorAbstract {
public:
    virtual ~JumpDetectorAbstract(){}
    virtual std::vector<std::vector<std::pair<double, double>>> detect(std::vector<std::pair<double, double>> input) = 0;
};


class JumpDetector : public JumpDetectorAbstract {
public:
    ~JumpDetector(){}
    std::vector<std::vector<std::pair<double, double>>> detect(std::vector<std::pair<double, double>> input);
};
