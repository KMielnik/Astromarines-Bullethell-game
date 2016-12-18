#include "main_header.h"

class_okno okno;



int main()
{
  srand( time( NULL ) );
  sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(okno.szerokosc_okna, okno.wysokosc_okna), "Alpha 0.000000005",sf::Style::Fullscreen);
  window->requestFocus();
  window->setMouseCursorVisible(false);
  window->setFramerateLimit(60);
 
  game gra(window);

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

