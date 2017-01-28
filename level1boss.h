#pragma once
#include "boss0.h"
#include "boss1.h"
#include "level.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "explosion.h"

class level1boss : public level
{
  sf::Texture tekstura_tla;
  sf::Sprite tlo;
  player *gracz;
  boss0 *szef;
  sf::Music muzyka_tlo;
  std::vector<bullets> pociski_wrogow; 
  std::vector<explosion> eksplozje;
  std::vector<sf::Sprite> eksplozja_klatka;
  sf::Texture eksplozja_sprite;
  sf::Clock zegar_wygranej;
  sf::Time czasPoWygranej;
  float secPoWygranej;


  public:
  bool logika_poziomu( sf::RenderWindow *window,
      std::map<std::string, sf::Keyboard::Key> controls )
  {
	sf::FloatRect ramka_gracz = gracz->ramka();
    poruszanie_gracza(controls);
    gracz->ustaw_dzialo(sf::Mouse::getPosition(*window), pociski_wrogow, muzyka_tlo);
    szef->przemieszczenie();
    szef->ustaw_dziala();
	szef->strzal(pociski_wrogow);

	if (gracz->zycie() < 0)
	{
		muzyka_tlo.stop();
		return true;
	}

	for (unsigned int i = 0;i<pociski_wrogow.size();i++)
		if (ramka_gracz.contains(pociski_wrogow.at(i).polozenie))
		{
			gracz->damaged();
			pociski_wrogow.erase(pociski_wrogow.begin() + i);
		}

	logika_pociskow_wrogow();

	if (szef->czyBossGrzeczny() == true)
		gracz->grzecznoscBossaOn();
	if (szef->czyBossGrzeczny() == false)
		gracz->grzecznoscBossaOff();

	if (szef->obrazenia(*gracz))                                       //jesli umarl to :(
	{
		szef->ded();
		czasPoWygranej = zegar_wygranej.getElapsedTime();
	}

		if (zegar_wygranej.getElapsedTime() >= (czasPoWygranej + sf::milliseconds((int)((secPoWygranej*1000)-1000))) &&
			zegar_wygranej.getElapsedTime() <= (czasPoWygranej + sf::milliseconds(2000)))
		{
			explosion wybuch(szef->pozycja() + sf::Vector2f(std::rand() % (int)(700*okno.skalaX) - (350*okno.skalaX), std::rand() % (int)(100*okno.skalaY) - (50*okno.skalaY)), eksplozja_klatka);
			wybuch.ustaw_skale(3.0 / (int)secPoWygranej+1);
			eksplozje.push_back(wybuch);
			secPoWygranej+=0.1;
		}


	if (zegar_wygranej.getElapsedTime() > (czasPoWygranej + sf::seconds(5)))
		return true;
    return false;																			 //dalej ten sam poziom
  }

  void logika_pociskow_wrogow()
  {


	  for (unsigned int i = 0; i < pociski_wrogow.size(); i++)
	  {
		  pociski_wrogow[i].polozenie += pociski_wrogow[i].vector;

		  if (pociski_wrogow[i].polozenie.x<-30 || pociski_wrogow[i].polozenie.x>okno.szerokosc_okna + 30) pociski_wrogow.erase(pociski_wrogow.begin() + i);
		  else if (pociski_wrogow[i].polozenie.y<-30 || pociski_wrogow[i].polozenie.y>okno.wysokosc_okna + 30) pociski_wrogow.erase(pociski_wrogow.begin() + i);
	  }
  }

  void wyswietl_poziom(sf::RenderWindow *window)
  {
    window->clear(sf::Color::Black);

    window->draw(tlo);

    szef->rysuj_bossa(window);
    gracz->rysuj_gracza(*window);
	sf::CircleShape kolko(3);
	kolko.setFillColor(sf::Color::Cyan);
	kolko.setOrigin(3, 3);
	for (auto &x : pociski_wrogow)
	{
		kolko.setPosition(x.polozenie);
		window->draw(kolko);
	}

	for (unsigned int i = 0;i < eksplozje.size();i++)
		if (eksplozje.at(i).rysuj_klatke(*window))
			eksplozje.erase(eksplozje.begin() + i);
    window->display();
  }



  level1boss(player *gracz_src)
  {
    tekstura_tla.loadFromFile("assets//spacebg.png");
    tlo.setTexture(tekstura_tla);
    tlo.setOrigin(1920/2,okno.wysokosc_okna);
    tlo.setPosition(okno.szerokosc_okna/2,-1080+2*okno.wysokosc_okna);

    gracz = gracz_src;

    szef = new boss1;

	eksplozja_sprite.loadFromFile("assets//explosion.png");
	for (int i = 0;i<9;i++)
		for (int j = 0;j<9;j++)
		{
			sf::Sprite sprite_klatki;
			sprite_klatki.setOrigin(50, 40);
			sprite_klatki.setTexture(eksplozja_sprite);
			sprite_klatki.setTextureRect(sf::IntRect(j * 100, i * 100, 100, 100));
			eksplozja_klatka.push_back(sprite_klatki);
		}

    muzyka_tlo.openFromFile("assets//boss1bg.ogg");
    muzyka_tlo.setLoop(true);
    muzyka_tlo.play();

	zegar_wygranej.restart();
	czasPoWygranej = sf::seconds(732891312);
	secPoWygranej = 0;
  }

  ~level1boss()
  {
    muzyka_tlo.stop();
	szef->stopMusic();
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
  }

};
