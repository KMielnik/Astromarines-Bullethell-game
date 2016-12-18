#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"

class enemy2 : public enemy
{

  void strzal(std::vector<bullets> &pociski)
  {
    sf::Time czas = zegar_strzalu.getElapsedTime();
    if (czas.asMilliseconds() > 200)
    {
      //Pocisk 1
      bullets pocisk;
      pocisk.polozenie.x = wrog.getPosition().x+wymiary.x/3;
      pocisk.polozenie.y = wrog.getPosition().y-wymiary.y/3;
      pocisk.vector.x = 3;
      pocisk.vector.y = -3;
      pociski.push_back(pocisk);


      //Pocisk 2
      //bullets pocisk;
      pocisk.polozenie.x = wrog.getPosition().x+wymiary.x/3;
      pocisk.polozenie.y = wrog.getPosition().y+wymiary.y/3;
      pocisk.vector.x = 3;
      pocisk.vector.y = 3;
      pociski.push_back(pocisk);


      //Pocisk 3
      //bullets pocisk;
      pocisk.polozenie.x = wrog.getPosition().x-wymiary.x/3;
      pocisk.polozenie.y = wrog.getPosition().y-wymiary.y/3;
      pocisk.vector.x = -3;
      pocisk.vector.y = -3;
      pociski.push_back(pocisk);


      //Pocisk 4
      //bullets pocisk;
      pocisk.polozenie.x = wrog.getPosition().x-wymiary.x/3;
      pocisk.polozenie.y = wrog.getPosition().y+wymiary.y/3;
      pocisk.vector.x = -3;
      pocisk.vector.y = 3;

      pociski.push_back(pocisk);
      zegar_strzalu.restart();

    }
  }

  public:
  enemy2(std::vector<sf::Texture*> enemytexture)
  {
    nr_typu_wroga = 2;

    wrog.setTexture(*enemytexture[2]);
    wrog.setScale(0.3f, 0.3f);
    wrog.setOrigin(219 / 2, 224 / 2);
    wymiary.x = 219 * 0.3f;
    wymiary.y = 224 * 0.3f;
    int losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
    wrog.setPosition(losowa_pozycja_x, 0-wymiary.y);


    HP_bar.setSize(sf::Vector2f(wymiary.x, 3));
    HP_bar.setOrigin(sf::Vector2f(wymiary.x / 2, 1.5));
    HP_bar.setFillColor(sf::Color::Red);
    HP_bar_tlo.setSize(sf::Vector2f(wymiary.x + 2, 5));
    HP_bar_tlo.setOrigin(sf::Vector2f(wymiary.x / 2 + 1, 2.5));
    HP_bar_tlo.setFillColor(sf::Color::White);

    HP_max = 10;
    HP = HP_max;
  }
};
