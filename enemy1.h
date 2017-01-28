#pragma once
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include "enemy.h"

class enemy1 : public enemy
{
  private:

    enum kierunek
    {
      up=1,
      down=2,
      left=3,
      right=4
    };
    kierunek origin_place;





  public:

    void przemieszczenie()
    {
      switch(origin_place)
      {
        case 1: //from up
			for (sf::Sprite & przeciwnik : wrog)
				przeciwnik.move(0 * okno.skalaX, 10 * okno.skalaY);
          break;

        case 2: //from down
			for (sf::Sprite & przeciwnik : wrog)
				przeciwnik.move(0 * okno.skalaX, -10 * okno.skalaY);
          break;

        case 3:  //from left
			for (sf::Sprite & przeciwnik : wrog)
				przeciwnik.move(10 * okno.skalaX, 0 * okno.skalaY);
          break;

        case 4: //from right
			for (sf::Sprite & przeciwnik : wrog)
				przeciwnik.move(-10 * okno.skalaX, 0 * okno.skalaY);
          break;
      }

	  for (sf::Sprite & przeciwnik : wrog)
		  przeciwnik.rotate(8);
    }



    enemy1(std::vector<sf::Texture*> enemytexture)
    {
      nr_typu_wroga = 1;
	  for (int i = 0;i<6;i++)
	  {
		  sf::Sprite klatka_wroga;
		  klatka_wroga.setOrigin(127.5, 127.5);
		  klatka_wroga.setScale(0.4f, 0.4f);

		  klatka_wroga.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna / 8);
		  klatka_wroga.setTexture(*enemytexture[1]);
		  klatka_wroga.setTextureRect(sf::IntRect(i * 255, 0, 255, 255));
		  wrog.push_back(klatka_wroga);

	  }
	  for (sf::Sprite &przeciwnik : wrog)
	  {
		  przeciwnik.setScale(0.3f*okno.skalaX, 0.3f*okno.skalaX);
		  przeciwnik.setOrigin(255 / 2, 255 / 2);
	  }
	  wymiary.x = 255 * 0.3f*okno.skalaX;
	  wymiary.y = 255 * 0.3f*okno.skalaX;

      int kierunek = std::rand() % 4 + 1;
      int losowa_pozycja_x,losowa_pozycja_y;
      switch(kierunek)
      {
        case 1:
          losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
		  for(sf::Sprite & przeciwnik : wrog)
          przeciwnik.setPosition(losowa_pozycja_x, 0-wymiary.y);
          origin_place=up;
          break;
        case 2:
          losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
		  for (sf::Sprite & przeciwnik : wrog)
			  przeciwnik.setPosition(losowa_pozycja_x, okno.wysokosc_okna+wymiary.y);
          origin_place=down;
          break;
        case 3:
          losowa_pozycja_y = std::rand() % (int)(okno.wysokosc_okna-(wymiary.y/2)) + (int)wymiary.y/2;
		  for (sf::Sprite & przeciwnik : wrog)
			  przeciwnik.setPosition(0-wymiary.x, losowa_pozycja_y);
          origin_place=left;
          break;
        case 4:
          losowa_pozycja_y = std::rand() % (int)(okno.wysokosc_okna-(wymiary.y/2)) + (int)wymiary.y/2;
		  for (sf::Sprite & przeciwnik : wrog)
			  przeciwnik.setPosition(okno.szerokosc_okna+wymiary.x, losowa_pozycja_y);
          origin_place=right;
          break;
      }


      HP_max = 1;
      HP = HP_max;
    }

  /*  void rysuj_wroga(sf::RenderWindow &okienko)
    {

      okienko.draw(wrog);

    }*/
};
