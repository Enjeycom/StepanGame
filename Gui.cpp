#include "./Gui.hpp"
#include "./Log.hpp"

Gui::Gui() {
    view.setViewport(sf::FloatRect(0, 0, 1.6, 2.2));
}

void Gui::giveControl(sf::RenderWindow *window) {
    window->setView(view);
}