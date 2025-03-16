
#pragma once
#include <string>
#include <vector>


class InputFileParserAbstract {
public:
    InputFileParserAbstract() {}
    virtual ~InputFileParserAbstract() {}
    virtual int parse(std::vector<std::pair<int, int>>& result) = 0;
};


class InputFileParser : InputFileParserAbstract {
public:
    InputFileParser(std::string filePath):m_filePath(filePath) {}
    ~InputFileParser(){}
    int parse(std::vector<std::pair<int, int>>& result);


private:
    std::string m_filePath;
};