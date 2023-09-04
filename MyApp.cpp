#pragma once
#include "MyApp.hpp"
#include "MethodProcess.hpp"
class MyApp
{
public:
    MyApp();
    ~MyApp();

// Data
private:
    int recordAmount;
    std::string tableName;
    DirCheck dirChk;
    MethodProcess mProc;

// Methods
private:
    void InputTableName() 
    {
        std::cout << "Input table name: ";
        std::cin >> this->tableName;
    }
    void InputRecordsAmount() 
    {
        std::cout << "How many records would you like to generate?: ";
        std::cin >> this->recordAmount;
    }
    void GenerateCommand() // as method name says, this is supposed to generate (output) the final command to console
    {
        system("cls");
        
        int i=0;
        std::cout << "INSERT INTO `" << this->tableName << "` (`"; 
        for(auto &name : dirChk.fileNames)
        {
            if(i == 0) 
            {
                std::cout << name.string();
                i++;
                continue;
            }
            std::cout << "`,`" << name.string();
        }
        std::cout << "`) VALUES ";
        for(int i=0; i<this->recordAmount;i++)
        {
            if(i!=0) std::cout << ',';
            std::cout << '(';
            mProc.SelectMethod();
            std::cout << ')';
        }
        std::cout << ';'; 
        
    }
public:
    
    void Run() // method containing whole app flow
    {
        LoadDirData();
        mProc.SelectMethod();

        if(dirChk.errorMes.empty()) // in case of any error during Processing data i want program to output where user made error with files.
        {
            system("cls");
            this->InputTableName();
            this->InputRecordsAmount();
            
            try
            {
                std::cout << std::endl;
                this->GenerateCommand();
            }
            catch(const std::exception& e)
            {
               std::cout << "Error at command generation: " << e.what();
            }
        }
        else
        {
            std::cout << '\n';
             for(auto &error : dirChk.errorMes)
            {
                std::cout << error << '\n';
            }
            std::cout << "\nFor detailed instructions check README file.\n";
        }
    }

};

MyApp::MyApp() // no idea what this does but its there .<' its probably constructior and deconstructor, either way i dont need it i think.
{
}

MyApp::~MyApp()
{
}
