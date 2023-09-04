#pragma once
#include "MyApp.hpp"
#include "string"
class Range
{
private:
    DirCheck dirChk;
    double firstNum;
    double lastNum;
    std::string firstDate;
    std::string lastDate;

public:
    Range(/* args */);
    ~Range();
private:
    void GetValues(std::string type, int &fileIterator) // Gets stored values and assigning them to variables for easier usage
    {
        
        try
        {
            if(!dirChk.colsValue[fileIterator].empty())
            {
                std::string value = dirChk.colsValue[fileIterator];
                std::string num1, num2;
                bool separator = false;
                for(const auto &chr : value)
                {   
                    if(chr == ':') separator=true;
                    else if(!separator) num1+=chr;
                    else if(separator) num2+=chr;
                }
                if(!separator) throw(dirChk.fileNames[fileIterator].string());
                else 
                {
                    if(num1 < num2)
                    {
                        this->firstNum = std::stod(num1);
                        this->lastNum = std::stod(num2);
                    }
                    else
                    {
                        this->firstNum = std::stod(num2);
                        this->lastNum = std::stod(num1);
                    }
                }
            }
        }
        catch(const std::string& e)
        {
            dirChk.errorMes.emplace_back("Please specify valid range at file: "+e+", line: 3");
        }
        
    }

    void ifInt() // if type == int, result will be outputed with int format.
    {
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(this->firstNum,this->lastNum);
        int result = dist(mt);
        std::cout << "\"" << result << "\"";

    }
    void ifFloat() // if type == float, result will be outputed with float format.
    {
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(this->firstNum,this->lastNum);
        float result = dist(mt);
        std::cout << "\"" << result << "\"";
    }
    void ifDecimal() // if type == decimal, result will output double format (though this doesnt work as intended yet).
    {
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(this->firstNum,this->lastNum);
        std::cout << "\"" << dist(mt) << "\"";
    }

public:
    void CheckType(std::string& type, int &fileIterator) // reads the type from stored data and activate correct method.
    {
        this->GetValues(type,fileIterator);
        if(type == "int") return ifInt();
        else if(type == "float") return ifFloat();
        else if(type == "decimal") return ifDecimal();
        else dirChk.errorMes.emplace_back("Please specify valid variable type at file: "+dirChk.fileNames[fileIterator].string()+", line: 1");
    }

};

Range::Range(/* args */)
{
}

Range::~Range()
{
}
