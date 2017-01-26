#pragma once
#include "boss0.h"
#include <SFML/Graphics.hpp>
#include <string>

class boss1 : public boss0
{
	double HP;
	double HP_max;
  std::string kierunek_lotuX;
  std::string kierunek_lotuY;
  int przeleconeX;
  int przeleconeY;

  sf::Vector2f wymiary;
  std::vector<sf::Sprite> maincannon;
  sf::Texture tekstura_maincannon;
  int klatka_maincannon;
  bool alive;
  sf::Music SUPPAATTAKKU;

  public:
  void rysuj_bossa(sf::RenderWindow *window)
  {
	  if (alive)
	  {
		  window->draw(boss.at(int(klatka_bossa / 10)));
		  klatka_bossa++;
		  if (klatka_bossa >= 60)
			  klatka_bossa = 0;

		  window->draw(maincannon.at(int(klatka_maincannon / 7.5)));
		  klatka_maincannon++;
		  if (klatka_maincannon >= 37.5)
			  klatka_maincannon = 0;

		  window->draw(HP_bar_tlo);
		  window->draw(HP_bar);
	  }
    
  }

  bool ded()
  {
	  alive = 0;									//                   :(
	  return true;
  }

  void stopMusic()
  {
	  SUPPAATTAKKU.stop();
  }

  void przemieszczenie()
  {

    if (kierunek_lotuX == "lewo")
      for (auto &sprite : boss)
        sprite.move(-0.4 * okno.skalaX, 0 * okno.skalaY);

    if (kierunek_lotuX == "prawo")
      for (auto &sprite : boss)
        sprite.move(0.4 * okno.skalaX, 0 * okno.skalaY);

    if (kierunek_lotuY == "gora")
      for (auto &sprite : boss)
        sprite.move(0 * okno.skalaX, -0.15 * okno.skalaY);

    if (kierunek_lotuY == "dol")
      for (auto &sprite : boss)
        sprite.move(0 * okno.skalaX, 0.15 * okno.skalaY);

    przeleconeX++;
    przeleconeY++;

    if (przeleconeX > okno.szerokosc_okna/4)
    {
      if (kierunek_lotuX == "lewo")
        kierunek_lotuX = "prawo";
      else if (kierunek_lotuX == "prawo")
        kierunek_lotuX = "lewo";
      przeleconeX = 0;
    }

    if (przeleconeY > okno.wysokosc_okna / 6)
    {
      if (kierunek_lotuY == "gora")
        kierunek_lotuY = "dol";
      else if (kierunek_lotuY == "dol")
        kierunek_lotuY = "gora";
      przeleconeY = 0;
    }
  }

  void ustaw_dziala()
  {
    for (int i = 0;i < 5;i++)
    {
      maincannon.at(i).setPosition(pozycja().x, pozycja().y-20);
    }

	HP_bar.setPosition(okno.szerokosc_okna/2,okno.wysokosc_okna -50);
	HP_bar_tlo.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna - 50);
  }

  bool obrazenia(player &gracz)
  {
	  if (alive)
	  {
		  std::vector<bullets> pociski = gracz.get_pociski();
		  for (unsigned int i = 0;i < pociski.size();i++)
			  if (maincannon.at(0).getGlobalBounds().contains(pociski[i].polozenie.x, pociski[i].polozenie.y))
			  {
				  HP--;
				  HP_bar.setSize(sf::Vector2f((HP_bar_tlo.getSize().x - 2) * HP / HP_max, 3 * 3));
				  gracz.usun_pocisk(i);
				  if (HP <= 0)
					  return true;                                                                                //umarl :(
			  }
	  }
    return false;                                                                                               //nie umarl
  }

  boss1()
  {
    tekstura_bossa.loadFromFile("assets//boss1.png");
    for(int i=0;i<6;i++)
    {
      sf::Sprite klatka_bossa;
      klatka_bossa.setOrigin(500,104);
      klatka_bossa.setScale(0.7*okno.skalaX,0.7*okno.skalaY);

      klatka_bossa.setPosition(okno.szerokosc_okna/2,okno.wysokosc_okna/8);
      klatka_bossa.setTexture(tekstura_bossa);
      klatka_bossa.setTextureRect(sf::IntRect(i*1000,0,1000,208));
      boss.push_back(klatka_bossa);

    }
    klatka_bossa=0;

    tekstura_maincannon.loadFromFile("assets//boss1maincannon.png");
    /*for (int i = 0;i<12;i++)
      {
      sf::Sprite klatka_maincannon;
      klatka_maincannon.setOrigin(63.375, 40);
      klatka_maincannon.setScale(1.5, 1.5);
      klatka_maincannon.setRotation(180.0f);

      klatka_maincannon.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna / 8);
      klatka_maincannon.setTexture(tekstura_maincannon);
      klatka_maincannon.setTextureRect(sf::IntRect(i * 126.75, 0, 126.75, 80));
      maincannon.push_back(klatka_maincannon);

      }*/
    for (int i = 0;i<5;i++)
    {
      sf::Sprite klatka_maincannon;
      klatka_maincannon.setOrigin(256, 102);
      klatka_maincannon.setScale(0.7*okno.skalaX, 0.7*okno.skalaY);
      klatka_maincannon.setRotation(180.0f);

      klatka_maincannon.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna / 8);
      klatka_maincannon.setTexture(tekstura_maincannon);
      klatka_maincannon.setTextureRect(sf::IntRect(i * 512, 0, 512, 204));
      maincannon.push_back(klatka_maincannon);

    }
	wymiary.x = 512 * okno.skalaX;
	wymiary.y = 204 * okno.skalaY;
    klatka_maincannon = 0;

    kierunek_lotuX = "lewo";
    kierunek_lotuY = "dol";
    przeleconeX = okno.szerokosc_okna / 8;
    przeleconeY = okno.wysokosc_okna / 12;
	HP_max = 500;
	HP = HP_max;


	HP_bar.setSize(sf::Vector2f(wymiary.x*3, 3*3));
	HP_bar.setOrigin(sf::Vector2f(wymiary.x*3 / 2, 1.5*3));
	HP_bar.setFillColor(sf::Color::Red);
	HP_bar_tlo.setSize(sf::Vector2f(wymiary.x*3 + 2*3, 5*3));
	HP_bar_tlo.setOrigin(sf::Vector2f(wymiary.x*3 / 2 + 1*3, 2.5*3));
	HP_bar_tlo.setFillColor(sf::Color::White);

	SUPPAATTAKKU.openFromFile("assets//ORA.ogg");
	SUPPAATTAKKU.setLoop(true);
	alive = 1;													//ON ZYJEEEEEEEEEEEEEEEEEEEEEEE
  }

  void strzal(std::vector<bullets> &pociski)
  {
	  if (alive)
	  {
		  sf::Time czas = zegar_strzalu.getElapsedTime();
		  if (czas.asMilliseconds() > 200)
		  {
			  
			  
			  for (int i = 0;i <= 3;i++)
			  {
				  //Pocisk 1
				  bullets pocisk;
				  pocisk.polozenie.x = boss.at(0).getPosition().x;
				  pocisk.polozenie.y = boss.at(0).getPosition().y - wymiary.y / 10;
				  pocisk.vector.x = (std::rand() % 10 - 5) * okno.skalaX;
				  pocisk.vector.y = (std::rand() % 5 + 0.3) * okno.skalaY;
				  pociski.push_back(pocisk);


				  //Pocisk 2
				  //bullets pocisk;
				  pocisk.polozenie.x = boss.at(0).getPosition().x;
				  pocisk.polozenie.y = boss.at(0).getPosition().y + wymiary.y / 3;
				  pocisk.vector.x = (std::rand() % 10 - 5) * okno.skalaX;
				  pocisk.vector.y = (std::rand() % 5 + 0.3) * okno.skalaY;
				  pociski.push_back(pocisk);
			  }
			 


			  zegar_strzalu.restart();

		  }

		  if (HP <= HP_max / 2)
		  {
			  sf::Mouse::setPosition(sf::Vector2i(okno.szerokosc_okna / 2, okno.wysokosc_okna / 2));

			  if (SUPPAATTAKKU.getStatus() != SUPPAATTAKKU.Playing)
				  SUPPAATTAKKU.play();
			  
		  }
	  }
  }

  ~boss1()
  {
	  SUPPAATTAKKU.stop();
  }
};
