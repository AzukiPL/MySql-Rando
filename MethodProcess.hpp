#pragma once
#include "MyApp.hpp"
#include "string"
#include "Range.hpp"

class MethodProcess // class responsible for processing scanned data, and selecting proper methods
{
private:
    DirCheck dirChk;
    Range range;
public:
    MethodProcess();
    ~MethodProcess();

private:
    void IncrementMethod() {} // currently these methods are empty placeholders, possibly ill need remove them like in range.checktype case you can see at line 32
    void DecrementMethod() {}
    void RandomizeMethod() {}



public:
    void SelectMethod() 
    {
        for(int i=0; i<dirChk.fileAmount;i++)
        {
            std::string method = dirChk.colsMethod[i];
            if(i!=0) std::cout << ", ";
            if(method == "increment") this->IncrementMethod();
            else if(method == "decrement") this->DecrementMethod();
            else if(method == "randomize") this->RandomizeMethod();
            else if(method == "range") range.CheckType(dirChk.colsType[i],i);
            else dirChk.errorMes.emplace_back("Please specify valid method at file: "+dirChk.fileNames[i].string()+", line: 2"); // because file is supposed to have method written on its 2nd line, this will give error message in case of exception
        }
    }


};

MethodProcess::MethodProcess()
{
}

MethodProcess::~MethodProcess()
{
}
