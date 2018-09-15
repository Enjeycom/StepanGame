// Copyright 2018, Enjeycom
// Author: Enjeycom <enjeycom@gmail.com>

#ifndef GUI_HPP_
#define GUI_HPP_

#include "./Object.hpp"

class Gui {
 private:
    sf::View view;
 public:
    Gui();
    void giveControl(sf::RenderWindow *window);
};

#endif  // GUI_HPP_
