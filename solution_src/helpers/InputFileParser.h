
#pragma once
#include <string>
#include <vector>


class InputFileParserAbstract {
public:
    InputFileParserAbstract() {}
    virtual ~InputFileParserAbstract() {}
    virtual int parse(std::vector<std::pair<double, double>>& result) = 0;
};


class InputFileParser : public InputFileParserAbstract {
public:
    InputFileParser(std::string filePath):m_filePath(filePath) {}
    ~InputFileParser(){}
    int parse(std::vector<std::pair<double, double>>& result);


private:
    std::string m_filePath;
};