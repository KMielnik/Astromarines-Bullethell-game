#pragma once
#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level1boss.h"
#include "menu.h"
#include <SFML/Audio.hpp>
#include "player.h"

class game
{
  player *gracz;
  level *poziom;
  int numer_poziomu;
  sf::RenderWindow *window;
  std::map<std::string, sf::Keyboard::Key> controls;
  sf::Font font_gry;
  sf::Music muzyka_tlo;

  void nastepny_poziom()
  {
    muzyka_tlo.pause();
    numer_poziomu++;
	if (gracz->zycie() < 0)
	{
		numer_poziomu = 0;
		delete gracz;
		gracz = new player();
		sf::Music deddd;
		deddd.openFromFile("assets//deddd.ogg");
		deddd.play();
		ekran_powitalny_poziomu("ZOSTALES ZNISZCZONY\nKONIEC GRY",false);
		muzyka_tlo.play();
	}
		
    switch(numer_poziomu)
    {
      case 0:
        delete poziom;
        poziom = new menu();
		muzyka_tlo.play();
        break;
      case 1:
        delete poziom;
        ekran_powitalny_poziomu("Poziom 1",true);
        poziom = new level1(gracz);
        break;
	  case 2:
		  delete poziom;
		  ekran_powitalny_poziomu("Poziom 2",true);
		  poziom = new level2(gracz);
		  break;
      case 3:
        delete poziom;
        ekran_powitalny_poziomu("BOSS",true);
        poziom = new level1boss(gracz);
        break;
	  case 4:
		  delete poziom;
		  ekran_powitalny_poziomu("GRATULACJE\n\nUDALO CI SIE\nOCZYSCIC WSZECHSWIAT",true);
		  numer_poziomu = -1;
		  poziom = new menu();
		  delete gracz;
		  gracz = new player();
		  break;
    }
  }

  void ekran_powitalny_poziomu(const char tekst[10], bool muzyka)
  {
	  if(muzyka)
		 muzyka_tlo.play();
    sf::Text napis_powitalny(tekst,font_gry);
    napis_powitalny.setCharacterSize(okno.wysokosc_okna/10);
    napis_powitalny.setFillColor(sf::Color::White);
    sf::FloatRect ramka_napisu = napis_powitalny.getLocalBounds();
    napis_powitalny.setOrigin(ramka_napisu.left + ramka_napisu.width/2.0f,
        ramka_napisu.top + ramka_napisu.height/2.0f);
    napis_powitalny.setPosition(sf::Vector2f(okno.szerokosc_okna/2,okno.wysokosc_okna/2));

    window->clear(sf::Color::Black);
    window->draw(napis_powitalny);
    window->display();

    sf::sleep(sf::seconds(3.5));                             //czaas wydluz
    muzyka_tlo.stop();
  }

  public:

  void logika_gry()
  {
    if(poziom->logika_poziomu(window, controls))                                        //jak sie stary skonczyl
      nastepny_poziom();

	if (numer_poziomu == -1)
		nastepny_poziom();
  }

  void wyswietl_gre()
  {
    poziom->wyswietl_poziom(window);
  }

  game(sf::RenderWindow *window_src)
  {
    gracz = new player();
    poziom = new menu();
    numer_poziomu = 0;   //tutaj zmien startowy poziom
    font_gry.loadFromFile("assets//font_gry.ttf");
    window=window_src;
    set_controls();
    muzyka_tlo.openFromFile("assets//menu.ogg");
    muzyka_tlo.setLoop(true);
    muzyka_tlo.play();
  }

  ~game()
  {
    delete gracz;
    delete poziom;
    muzyka_tlo.stop();
  }

  private:

  void set_controls( sf::Keyboard::Key left = sf::Keyboard::A,
      sf::Keyboard::Key right = sf::Keyboard::D,
      sf::Keyboard::Key up = sf::Keyboard::W,
      sf::Keyboard::Key down = sf::Keyboard::S,
      sf::Keyboard::Key fire = sf::Keyboard::Space,
      sf::Keyboard::Key super = sf::Keyboard::LShift)
  {
    controls["left"] = left;
    controls["right"] = right;
    controls["up"] = up;
    controls["down"] = down;
    controls["fire"] = fire;
  }
};
