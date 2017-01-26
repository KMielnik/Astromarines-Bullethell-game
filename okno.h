#pragma once
#include <SFML/Graphics.hpp>

class class_okno
{
  public:
	  float szerokosc_okna;
	  float wysokosc_okna;
	  int domyslne;
	  float skalaX;
	  float skalaY;

	class_okno()
	{
		szerokosc_okna = float(sf::VideoMode::getDesktopMode().width);
		wysokosc_okna = float(sf::VideoMode::getDesktopMode().height);
		domyslne = 0;
		skalaX = szerokosc_okna / 1920.f;
		skalaY = wysokosc_okna / 1080.f;
	}
};

