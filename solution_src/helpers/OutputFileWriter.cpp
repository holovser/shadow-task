#include "OutputFileWriter.h"

#include <fstream>
#include <vector>

int OutputFileWriter::write(const std::vector<std::pair<double, double>>& data) {
    std::ofstream outFile(m_fileName);

    outFile << "x   y " << "\n"; // header

    for (auto i : data) {
        outFile << i.first << " " << i.second << "\n";
    }

    outFile.close();

    return 0;
}