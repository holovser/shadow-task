
#pragma once 

#include <vector>

class JumpJoinerAbstract {
public:
    virtual ~JumpJoinerAbstract() {}
    virtual std::vector<std::pair<double, double>> join(std::vector<std::vector<std::pair<double, double>>> inputSections) = 0;
};

class JumpJoiner : public JumpJoinerAbstract {
public:
    ~JumpJoiner() {}
    std::vector<std::pair<double, double>> join(std::vector<std::vector<std::pair<double, double>>> inputSections);

private:

    void smoothSectionBeginning(std::vector<std::pair<double, double>> &section, double sectionsDifference);
    void smoothSectionEnd(std::vector<std::pair<double, double>> &section, double sectionsDifference);

    double m_sectionHeadOrTailLengthMult = 0.8;

};