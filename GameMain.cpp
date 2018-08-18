// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#include <SFML/Graphics.hpp>
#include "./GameMain.hpp"
#include "./Player.hpp"
#include "./Log.hpp"

#define HD sf::VideoMode(1280, 720)
#define HDN sf::VideoMode(1366, 768)
#define NTSC sf::VideoMode(720, 480)

int main() {
    Log::open();
    Log::write("Game starting...");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(NTSC, "Game", sf::Style::Default, settings);
    sf::View camera(sf::FloatRect(0, 0, 720, 480));
    Player player;
    Log::write("Game loop starting...");
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
             Log::write("Game close");
            Log::close();
            return 0;
        }

        player.update();
        camera.setCenter(player.getPosition());
        // window.setView(camera);
        window.clear(sf::Color::White);
        player.draw(window);
        window.display();
    }
    Log::close();
    return 0;
}
