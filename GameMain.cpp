// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <iostream>
#include <SFML/Graphics.hpp>
#include "./GameMain.hpp"
#include "./DebugInfoPanel.hpp"
#include "./Player.hpp"
#include "./Log.hpp"
#include "./Map.hpp"
#include "./Tools.hpp"
#include "./Loader.hpp"

#define HD sf::VideoMode(1280, 720)
#define HDN sf::VideoMode(1366, 768)
#define NTSC sf::VideoMode(720, 480)

int main() {
    log("Game starting...");
    sf::Text text;
     log("Loading variables...");
    if (!Loader::loadVariables())
        close("Critical error: loading variables!");
    if (!Loader::loadFonts())
        close("Critical error: loading fonts!");
    text.setString("Loading...");
    text.setFillColor(sf::Color::White);
    text.setFont(mainFont);
    text.setPosition(10, 10);
    sf::RenderWindow window(NTSC, "Game", sf::Style::Default);

    int windowX = static_cast<int>(sf::VideoMode::getDesktopMode().width) /
    2 - window.getSize().x / 2;
    int windowY = static_cast<int>(sf::VideoMode::getDesktopMode().height) /
    2 - window.getSize().y / 2;
    window.setPosition({windowX, windowY});
    window.clear();
    window.draw(text);
    window.display();
    log("Loading objects...");
    Map::loadObjects();
    log("Loading map...");
    Map::loadFromFile("start");
    log("Initializate variables...");
    Player player;
    log("Game loop starting...");
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            log("Game close");
            Log::close();
            return 0;
        }
        // Update
        Tools::updateTime();
        Map::update();
        player.update();
        // Draw
        window.clear(sf::Color(117, 187, 253));
        Map::draw(window);
        player.draw(window);
        DebugInfoPanel::draw(window);
        window.display();
    }
    Log::close();
    return 0;
}

void close(std::string massege) {
    log(massege + "\nGame close");
    exit(0);
}
