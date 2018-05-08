/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DummyMap.h
 * Author: den
 *
 * Created on May 7, 2018, 9:39 PM
 */

#ifndef DUMMYMAP_H
#define DUMMYMAP_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

struct Position {
    int x;
    int y;
};

class Controller {
public:
    int num;
};

class ConsoleController : public Controller {
};

class StationaryController : public Controller {
};

class Character {
public:
    char sign;
    int stamina;
    int strength;
    Position pos;
    Controller* m_controller;
};

class Player : public Character {
};

class Enemy : public Character {
};

struct Item {
    std::string m_str = "cool";
};

struct Tile {
    Character* m_char;
    Tile* remoteTile;
    Item* m_item;
    Position pos;
    char m_sign;


};

struct DummyMap {

    DummyMap() {
    }

    DummyMap(const std::vector<std::string>& map);

    ~DummyMap();

    bool loadFromFile(const std::vector<std::string>& map);
    bool loadEntities(const std::string& str);
    void print() const;

    Character* makeCharacter(const std::string& name, const std::string& data);
    Item* makeItem(const std::string& name, const std::string& data);
    Tile* makeTile(const std::string& name, const std::string& data);

    bool isItem(const std::string& str) {
        for (int i = 0; i < items.size(); ++i)
            if (items[i] == str) return true;
        return false;
    }

    bool isSpecialTile(const std::string& str) {
        for (int i = 0; i < specialTiles.size(); ++i)
            if (specialTiles[i] == str) return true;
        return false;
    }

    std::vector<Character*> m_charVec;
    std::vector<Item*> m_itemVec;
    std::vector<Tile*> m_tiles;

    std::vector<std::pair<std::string, Position> > fields;

    char** m_map;
    int m_height;
    int m_width;



    const static std::vector<std::string> items;
    const static std::vector<std::string> specialTiles;

};

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

    if (name == "Character")
        makeCharacter(name, str);
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

Character* makeCharacter(const std::string& name, const std::string& data);

Item* makeItem(const std::string& name, const std::string& data);

Tile* makeTile(const std::string& name, const std::string& data);




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





#endif /* DUMMYMAP_H */

