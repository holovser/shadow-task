#include "JumpJoiner.h"

#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::pair<double, double>> JumpJoiner::join(std::vector<std::vector<std::pair<double, double>>> inputSections)
{
    std::vector<std::pair<double, double>> joinedDataset;

    auto lastSection = inputSections[inputSections.size() - 1];

    for (int i = 0; i < inputSections.size(); i++) {
        auto& currentSection = inputSections[i];

        if (i != (inputSections.size() - 1)) {
            auto& nextSection = inputSections[i+1];
            double desiredValue = (nextSection[0].second + currentSection[currentSection.size()-1].second) / 2;
            smoothSectionEnd(currentSection, desiredValue - currentSection[currentSection.size()-1].second);
        }

        if (i != 0) {
            auto& prevSection = inputSections[i-1];
            double desiredValue = prevSection[prevSection.size()-1].second;
            smoothSectionBeginning(currentSection, (desiredValue - currentSection[0].second));
        }

        joinedDataset.insert(joinedDataset.end(), currentSection.begin(), currentSection.end());
    }

    return joinedDataset;
}

void JumpJoiner::smoothSectionBeginning(std::vector<std::pair<double, double>>& section, double sectionsDifference) {

    int sectionHeadEnd = section.size() * (1.0 - m_sectionHeadOrTailLengthMult);
    int elementsCount = sectionHeadEnd;
    double differencePerElement = sectionsDifference / double(elementsCount);

    int k = 0;
    for ( int j = sectionHeadEnd; j >= 0; j--, k++) {
        section[j].second += (differencePerElement*k);
    }
}

void JumpJoiner::smoothSectionEnd(std::vector<std::pair<double, double>>& section, double sectionsDifference) {

    int sectionTailStart = section.size() * m_sectionHeadOrTailLengthMult;
    int elementsCount = section.size() - sectionTailStart;
    double differencePerElement = sectionsDifference / double(elementsCount);

    int k = 1;
    for ( int j = sectionTailStart; j < section.size(); j++, k++) {
        section[j].second += (differencePerElement*k);
    }
}