/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DummyMap.cpp
 * Author: den
 * 
 * Created on May 7, 2018, 9:39 PM
 */

#include "DummyMap.h"


DummyMap::DummyMap() {}

DummyMap::DummyMap(const std::vector<std::string>& map) {
    loadFromFile(map);
}

DummyMap::~DummyMap() {
    for (int i = 0; i < m_height; ++i)
        delete[] m_map[i];
    delete[] m_map;
}

bool DummyMap::loadFromFile(const std::vector<std::string>& map) {
    std::stringstream ss;
    ss << map[0];
    ss >> m_height >> m_width;

    m_map = new char*[m_height];
    for (int i = 0; i < m_height; ++i)
        m_map[i] = new char[m_width];
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            m_map[i][j] = map[i + 1][j];
        }
    }
    for (int i = m_height + 1; i < map.size(); ++i) {
        loadEntities(map[i]);
    }
}

bool DummyMap::loadEntities(const std::string& str) {
    std::stringstream ss;
    std::string name;
    ss << str;
    ss >> name;
    cout << name << endl;

    if (name == "Character") {
        if (Character* character = makeCharacter(name, str)) {
            m_charVec.push_back(character);
            cout << "Character " << character->m_sign <<  " { " << character->m_pos.x << "," << character->m_pos.y << "} " << character->m_controller << endl;
        }
    }
    else if (isSpecialTile(name))
        makeTile(name, str);
    else if (isItem(name))
        makeItem(name, str);
}

void DummyMap::print() const {
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            cout << m_map[i][j];
        }
        cout << endl;
    }
}

Character* DummyMap::makeCharacter(const std::string& name, const std::string& data)
{
    std::stringstream ss;
    ss << data;
    std::string name1, controllerType;
    Position pos;
    char sign;
    int strength, stamina;
    ss >> name1 >> sign >> pos.y >> pos.x >> controllerType >> strength >> stamina;  
    if (controllerType == "StationaryController") {
        return new Character(sign, pos, strength, stamina, controllerType);
    }
    else if (controllerType == "ConsoleController") {
        return new Character(sign, pos, strength, stamina, controllerType);
    }
    return nullptr;
}

Item* DummyMap::makeItem(const std::string& name, const std::string& data) {
    ;
}

Tile* DummyMap::makeTile(const std::string& name, const std::string& data)
{
    ;
}




const std::vector<std::string> DummyMap::items{
    "GreatSword",
    "ArmingSword",
    "Club",
    "RapierAndDagger",
    "Gambeson",
    "MailArmour",
    "Shield",
    "FullPlateArmour"};

const std::vector<std::string> DummyMap::specialTiles{
    "Door",
    "Switch",
    "Trap",
    "Lever"};



