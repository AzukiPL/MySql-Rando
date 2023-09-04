#pragma once
#include <iostream>
#include <filesystem>
#include <vector>
#include "DirCheck.hpp"
#include <random>
DirCheck dirChk;
std::random_device rd;

void LoadDirData() // Loads neccessary data from files, this loads Cols names, methods, types, and values
{
    if(dirChk.fileNames.empty()) dirChk.GetColsNames();
    if(dirChk.colsMethod.empty()) dirChk.GetColsMethod();
    if(dirChk.colsType.empty()) dirChk.GetColsType();
    if(dirChk.colsValue.empty()) dirChk.GetColsValue();
}
