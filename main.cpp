/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: den
 *
 * Created on May 7, 2018, 9:01 PM
 */

#include <cstdlib>

#include "Parser.h"
#include "DummyMap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Parser p;
    p.readFile("./Maps/level1.txt");
    
    DummyMap dm;
    dm.loadFromFile(p.m_stringVec);
    dm.print();
    
    
    return 0;
}

