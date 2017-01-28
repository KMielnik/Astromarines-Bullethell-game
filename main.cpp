#include "main_header.h"

class_okno okno;



int main()
{
  srand( time( NULL ) );
  auto *window = new sf::RenderWindow(sf::VideoMode(okno.szerokosc_okna, okno.wysokosc_okna), "ASTROMARINES THE GAME v1.17",sf::Style::Fullscreen);
  window->requestFocus();
  window->setMouseCursorVisible(false);
  window->setFramerateLimit(60);
  window->clear(sf::Color::Black);

  game gra(window);

  auto *tytul = new sf::Texture;
  if (!tytul->loadFromFile("assets//tytul.png"))
	  return -1;
  auto *fabula = new sf::Texture;
  if (!fabula->loadFromFile("assets//fabula.png"))
	  return -1;
  auto *autorzy = new sf::Texture;
  if (!autorzy->loadFromFile("assets//autorzy.png"))
	  return -1;
  int ktoryPanel = 1;
  sf::Sprite panelTytulowy;
  panelTytulowy.setScale(okno.skalaX, okno.skalaY);

  while (window->isOpen() && ktoryPanel <= 3)
  {


	  sf::Event Event;
	  while (window->pollEvent(Event))
	  {
		  if (Event.type == sf::Event::Closed || (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape)) window->close();
		  if (Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) ktoryPanel++;
	  }

	  window->clear();
	  switch (ktoryPanel)
	  {
	  case 1:
		  panelTytulowy.setTexture(*tytul);
		  break;
	  case 2:
		  panelTytulowy.setTexture(*fabula);
		  break;
	  case 3:
		  panelTytulowy.setTexture(*autorzy);
		  break;

	  }
	  window->draw(panelTytulowy);
	  window->display();


  }
  delete tytul, fabula;

  while (window->isOpen())
  {


    sf::Event Event;
    while (window->pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed || (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape)) window->close();
    }

    gra.logika_gry();
    gra.wyswietl_gre();

  }

  delete window;
  return 0;
}



