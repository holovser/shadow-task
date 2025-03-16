#pragma once

#include <string>


class OutputFileWriterAbstract {
public:
    virtual ~OutputFileWriterAbstract() {}
    virtual int write(const std::vector<std::pair<double, double>>& data) = 0;

};


class OutputFileWriter : public OutputFileWriterAbstract {
public:
    OutputFileWriter(std::string fileName) : m_fileName(fileName) {}
    ~OutputFileWriter() {}
    int write(const std::vector<std::pair<double, double>>& data);

private:
    std::string m_fileName;

};