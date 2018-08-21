// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <SFML/Graphics.hpp>
#include "./GameMain.hpp"
#include "./Player.hpp"
#include "./Log.hpp"
#include "./Tools.hpp"
#include "./Pathways.hpp"

#define HD sf::VideoMode(1280, 720)
#define HDN sf::VideoMode(1366, 768)
#define NTSC sf::VideoMode(720, 480)

int main() {
    log("Game starting...");
    Pathways::loadFromFile();
    sf::ContextSettings cs(0,0,16,2,1,0,false);
    sf::RenderWindow window(NTSC, "Game", sf::Style::Default, cs);
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
        Tools::updateTime();
        player.update();
        window.clear(sf::Color::White);
        player.draw(window);
        window.display();
    }
    Log::close();
    return 0;
}
