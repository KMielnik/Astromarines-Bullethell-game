#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "okno.h"
#include "player.h"

extern class_okno okno;

class enemy
{
  protected:
    double HP;
    double HP_max;
	std::vector<sf::Sprite> wrog;
	sf::Texture tekstura_wroga;
	int klatka_wroga;
    sf::Vector2f wymiary;
    sf::RectangleShape HP_bar, HP_bar_tlo;
    float kat;
    sf::Clock zegar_strzalu;
    int nr_typu_wroga;
  public:

    virtual void przemieszczenie()
    {
		for(sf::Sprite &przeciwnik : wrog)
      przeciwnik.move(0, 1 * okno.skalaX);
    }

    bool wylecial_za_mape()
    {
      if (wrog.at(0).getPosition().x<-10*wymiary.x || wrog.at(0).getPosition().x>okno.szerokosc_okna + 10 * wymiary.x) return true;
	  if (wrog.at(0).getPosition().y<-10 * wymiary.y || wrog.at(0).getPosition().y>okno.wysokosc_okna + 10*wymiary.y) return true;
      return false;
    }


    sf::Vector2f pozycja()
    {
      sf::Vector2f polozenie = wrog.at(0).getPosition();
      return polozenie;
    }


    sf::FloatRect ramka()
    {
      sf::FloatRect obwodka = wrog.at(0).getGlobalBounds();
      return obwodka;
    }


    enemy()
    {
	  for (sf::Sprite &przeciwnik : wrog)
	  {
			przeciwnik.setScale(0.2f, 0.25f);
			przeciwnik.setOrigin(334 / 2, 224 / 2);
	  }
      
      wymiary.x = 334 * 0.2f;
      wymiary.y = 224 * 0.3f;
      int losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
	  for (sf::Sprite &przeciwnik : wrog)
      przeciwnik.setPosition(losowa_pozycja_x, 0-wymiary.y);

      HP_bar.setSize(sf::Vector2f(wymiary.x, 3));
      HP_bar.setOrigin(sf::Vector2f(wymiary.x / 2, 1.5));
      HP_bar.setFillColor(sf::Color::Red);
      HP_bar_tlo.setSize(sf::Vector2f(wymiary.x + 2, 5));
      HP_bar_tlo.setOrigin(sf::Vector2f(wymiary.x / 2 + 1, 2.5));
      HP_bar_tlo.setFillColor(sf::Color::White);

      HP_max = 20;
      HP = HP_max;
    }

    bool obrazenia(player &gracz)
    {
      std::vector<bullets> pociski=gracz.get_pociski();
      for(unsigned int i=0;i<pociski.size();i++)
        if(wrog.at(0).getGlobalBounds().contains(pociski[i].polozenie.x, pociski[i].polozenie.y))
		{
          HP--;
          HP_bar.setSize(sf::Vector2f((HP_bar_tlo.getSize().x-2) * HP / HP_max, 3));
          gracz.usun_pocisk(i);
          if(HP<=0)
            return true;                                                                                //umarl :(
        }
      return false;                                                                                               //nie umarl
    }

    virtual void strzal(std::vector<bullets> &pociski){}


    virtual int typ_wroga()
    {
      return nr_typu_wroga;
    }



    virtual void rysuj_wroga(sf::RenderWindow &okienko)
    {
      HP_bar.setPosition(wrog.at(0).getPosition().x, wrog.at(0).getPosition().y + (wymiary.y * 7 / 10));
      HP_bar_tlo.setPosition(wrog.at(0).getPosition().x, wrog.at(0).getPosition().y + (wymiary.y * 7 / 10));


	  okienko.draw(wrog.at(int(klatka_wroga / 10)));
	  klatka_wroga++;
	  if (klatka_wroga >= 60)
		  klatka_wroga = 0;
      okienko.draw(HP_bar_tlo);
      okienko.draw(HP_bar);

    }

    virtual ~enemy()
    {

    }
};
