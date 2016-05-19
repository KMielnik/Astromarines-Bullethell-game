#pragma once
#include "boss0.h"
#include "boss1.h"
#include "level.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class level1boss : public level
{
  sf::Texture tekstura_tla;
  sf::Sprite tlo;
  player *gracz;
  boss0 *szef;
  sf::Music muzyka_tlo;
  std::vector<bullets> pociski_wrogow; /////fuj placeholder :P

  public:
  bool logika_poziomu( sf::RenderWindow *window,
      std::map<std::string, sf::Keyboard::Key> controls )
  {
    poruszanie_gracza(controls);
    gracz->ustaw_dzialo(sf::Mouse::getPosition(*window), pociski_wrogow, muzyka_tlo);
    szef->przemieszczenie();
    szef->ustaw_dziala();
    szef->obrazenia(*gracz);
    return false;																			 //dalej ten sam poziom
  }

  void wyswietl_poziom(sf::RenderWindow *window)
  {
    window->clear(sf::Color::Black);

    window->draw(tlo);

    szef->rysuj_bossa(window);
    gracz->rysuj_gracza(*window);


    window->display();
  }



  level1boss(player *gracz_src)
  {
    tekstura_tla.loadFromFile("assets//spacebg.jpg");
    tlo.setTexture(tekstura_tla);
    tlo.setOrigin(3000/2,okno.wysokosc_okna);
    tlo.setPosition(okno.szerokosc_okna/2,-3000+2*okno.wysokosc_okna);

    gracz = gracz_src;

    szef = new boss1;


    muzyka_tlo.openFromFile("assets//boss1bg.ogg");
    muzyka_tlo.setLoop(true);
    muzyka_tlo.play();


  }

  ~level1boss()
  {
    muzyka_tlo.stop();
  }

  private:



  void poruszanie_gracza(std::map<std::string, sf::Keyboard::Key> controls)
  {
    if (sf::Keyboard::isKeyPressed(controls.at("left")))
      gracz->dodaj_predkosc(-0.7f, 0);
    if (sf::Keyboard::isKeyPressed(controls.at("right")))
      gracz->dodaj_predkosc(0.7f, 0);
    if (sf::Keyboard::isKeyPressed(controls.at("up")))
      gracz->dodaj_predkosc(0, -0.7f);
    if (sf::Keyboard::isKeyPressed(controls.at("down")))
      gracz->dodaj_predkosc(0, 0.7f);
    if (sf::Keyboard::isKeyPressed(controls.at("fire"))) gracz->strzal();
    if (sf::Keyboard::isKeyPressed(controls.at("super"))) gracz->start_super(muzyka_tlo);
  }

};
