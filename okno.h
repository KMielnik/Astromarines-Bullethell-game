#pragma once
#include <SFML/Graphics.hpp>

class class_okno
{
  public:
    int szerokosc_okna = sf::VideoMode::getDesktopMode().width;
    int wysokosc_okna = sf::VideoMode::getDesktopMode().height;
    int domyslne = 0;

};

