/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.cpp
 * Author: den
 * 
 * Created on May 7, 2018, 9:07 PM
 */

#include "Parser.h"
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::vector;
using std::cout; using std::endl;

Parser::Parser() {}

Parser::Parser(const string& str) {
    readFile(str);
}

Parser::Parser(const Parser& orig) {
}

Parser::~Parser() {
}

void Parser::readFile(const string& str) 
{
    ifstream ifs;
    ifs.open(str);
    string temp;
    while (ifs.good())
    {
        std::getline(ifs,temp);
        m_stringVec.push_back(temp);
    }
}

void Parser::print() const {
    for (int i = 0; i < m_stringVec.size(); ++i)
        cout << m_stringVec[i] << endl;
}