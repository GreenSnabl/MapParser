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
    Character(char sign, Position pos, int stamina, int strength, const std::string& controller) : m_sign{sign}, m_stamina{stamina}, m_strength{strength}, m_controller{controller} {} 
    char m_sign;
    int m_stamina;
    int m_strength;
    Position m_pos;
    std::string m_controller;
};
/*
class Player : public Character {
};

class Enemy : public Character {
};
*/
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

    DummyMap();
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


#endif /* DUMMYMAP_H */

