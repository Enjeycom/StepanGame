// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include "./DebugInfoPanel.hpp"
#include "./Tools.hpp"

std::vector<info> DebugInfoPanel::infoes;

void DebugInfoPanel::set(std::string name, std::string value) {
    for (size_t i = 0; i < infoes.size(); i++) {
        if (infoes[i].name == name) {
            infoes[i].value = value;
            return;
        }
    }
    infoes.push_back({value, name});
}

void DebugInfoPanel::set(std::string name, int value) {
    set(name, std::to_string(value));
}

void DebugInfoPanel::set(std::string name, double value) {
    set(name, std::to_string(value));
}

void DebugInfoPanel::set(std::string name, bool value) {
    set(name, std::to_string(value));
}

void DebugInfoPanel::draw(sf::RenderWindow &window) {
    sf::Text text;
    text.setFont(mainFont);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
    for (size_t i = 0; i < infoes.size(); i++) {
        text.setPosition(10, i*20);
        text.setString(infoes[i].name + " = " + infoes[i].value);
        window.draw(text);
    }
}
