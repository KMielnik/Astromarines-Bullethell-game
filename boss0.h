#pragma once
#include <SFML/Graphics.hpp>
#include "player.h"

class boss0
{
  protected:
    double HP;
    double HP_max; 
    sf::RectangleShape HP_bar, HP_bar_tlo;
    std::vector<sf::Sprite> boss;
    sf::Texture tekstura_bossa;
    int klatka_bossa;
    std::vector<bullets> pociski;
    sf::Clock zegar_strzalu;
  public:

    sf::Vector2f pozycja()
    {
      sf::Vector2f polozenie = boss.at(0).getPosition();
      return polozenie;
    }

    sf::FloatRect ramka()
    {
      sf::FloatRect obwodka = boss.at(0).getGlobalBounds();
      return obwodka;
    }

    virtual bool obrazenia(player &gracz) = 0;

    virtual void rysuj_bossa(sf::RenderWindow *window) = 0;

    virtual void przemieszczenie() = 0;


    virtual void ustaw_dziala() = 0;



    ~boss0()
    {

    }
};
