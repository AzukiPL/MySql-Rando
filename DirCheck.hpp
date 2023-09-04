#pragma once
#include "MyApp.hpp"
#include <fstream>
namespace fs = std::filesystem;

class DirCheck // class responsible for scanning directories and reading data
{
public:
    DirCheck();
    ~DirCheck();

public:

    inline static std::vector<std::string> errorMes;
    inline static std::vector<fs::path> fileNames;
    inline static std::vector<std::string> colsType;
    inline static std::vector<std::string> colsValue;
    inline static std::vector<std::string> colsMethod;
    inline static int fileAmount = 0;

private:
    fs::path path = "Columns";
    std::fstream file;
    std::string line;

public:
    void GetColsNames() // method does exacly what name says
    {
        for(const auto &file : fs::directory_iterator(path)) 
        {
            if(fs::exists(file)) 
            {
                this->fileNames.emplace_back(file.path().stem());
                this->fileAmount++;
            }
        }
    }
    void GetColsType() // each column in SQL has its own type, Int, Varchar, Email and so on, this method stores this type in variable
    {
        for(const auto &file : fs::directory_iterator(path)) 
        {
            if(fs::exists(file))
            {
                this->file.open(file.path());
                std::getline(this->file, line);
                this->colsType.emplace_back(this->line);
                this->file.close();
            }
        }
    }

    void GetColsMethod() // column method is neccessary for correct randomization effect i want to take place, example "Range" method will give random output within range given by user, "Increment" method will increment value with each iteration, and so on
    {
        for(const auto &file : fs::directory_iterator(path)) 
        {
            if(fs::exists(file))
            {
                int i = 0;
                this->file.open(file.path());
                while(std::getline(this->file, line)) {
                    if(i==0)  {i++; continue;}
                    else if(i==1)  {i++; this->colsMethod.emplace_back(this->line); break;}
                }
                this->file.close();
            }
        }
    }
        void GetColsValue() // Value is the Method's parameter to operate
    {
        for(const auto &file : fs::directory_iterator(path)) 
        {
            if(fs::exists(file))
            {
                int i = 0;
                this->file.open(file.path());
                while(std::getline(this->file, line)) {
                    if(i==2) {i++; this->colsValue.emplace_back(this->line); break;}
                    i++;
                }
                this->file.close();
            }
        }
    }



};

DirCheck::DirCheck()
{
}

DirCheck::~DirCheck()
{
}
