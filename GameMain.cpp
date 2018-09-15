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
#include "./Camera.hpp"
#include "./Gui.hpp"

#define HD sf::VideoMode(1280, 720)
#define HDN sf::VideoMode(1366, 768)
#define HDNd2 sf::VideoMode(1366/2, 768/2)
#define NTSC sf::VideoMode(720, 480)

bool *fs;
Gui *gui;
sf::Text *text;
Camera *camera;
Player *player;
sf::RenderWindow *window;
sf::Event *evn;

void centerWindow(sf::RenderWindow *window){
    int windowX = static_cast<int>(sf::VideoMode::getDesktopMode().width) /
    2 - window->getSize().x / 2;
    int windowY = static_cast<int>(sf::VideoMode::getDesktopMode().height) /
    2 - window->getSize().y / 2;
    window->setPosition({windowX, windowY});
}

void init() {
    log("Initializate variables...");

    window = new sf::RenderWindow(HDNd2, "Game", sf::Style::Default);
    gui = new Gui();
    camera = new Camera();
    player = new Player();
    text = new sf::Text();
    fs = new bool(false);
    evn = new sf::Event();

    text->setString("Loading...");
    text->setFillColor(sf::Color::White);
    text->setFont(mainFont);
    text->setPosition(10, 10);

    camera->setRenderSize(sf::Vector2i(1366,768));
    camera->setTarget(player);

    window->clear();
    window->draw(*text);
    window->display();

    centerWindow(window);
}

void close(std::string massege) {
    delete(fs);
    delete(gui);
    delete(text);
    delete(camera);
    delete(player);
    delete(window);
    delete(evn);

    log(massege + "\nGame close");
    Log::close();

    exit(0);
}

int main() {
    log("Game starting...");

    if (!Loader::loadVariables())
        close("Critical error: loading variables!");

    if (!Loader::loadFonts())
        close("Critical error: loading fonts!");

    Map::loadObjects();
    Map::loadFromFile("start");

    init();
    
    log("Game loop starting...");
    while (window->isOpen()) {
        // Events
        while (window->pollEvent(*evn)) {
            if (evn->type == sf::Event::Closed)
                window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            close("");
            return 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
            if(!*fs){
                delete(window);
                window = new sf::RenderWindow(NTSC, "Game", sf::Style::Fullscreen);
            }else{
                delete(window);
                window = new sf::RenderWindow(NTSC, "Game", sf::Style::Default);
                centerWindow(window);
            }
            *fs = !*fs;
        }
        // Update
        Tools::updateTime();
        Map::update();
        player->update();
        camera->update(window);
        // Draw
        window->clear(sf::Color(117, 187, 253));
        Map::draw(window, camera);
        player->draw(window);
        gui->giveControl(window);
        DebugInfoPanel::draw(window);
        window->display();
    }
    return 0;
}
