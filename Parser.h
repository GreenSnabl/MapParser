/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Parser.h
 * Author: den
 *
 * Created on May 7, 2018, 9:07 PM
 */

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

class Parser {
public:
    Parser();
    Parser(const std::string& str);
    ~Parser();
    
    void readFile(const std::string& str);
    
    void print() const;
    
    std::vector<std::string> m_stringVec;

    
    
    Parser(const Parser& orig);
};

#endif /* PARSER_H */

