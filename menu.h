#pragma once
#include "level.h"
#include <SFML/Graphics.hpp>
#include "okno.h"
#include "game.h"

extern class_okno okno;

class menu : public level
{
  sf::CircleShape target;
  sf::RectangleShape target_lineX,target_lineY;

  struct button
  {
    sf::RectangleShape pole;
    sf::FloatRect ramka;
    sf::Text napis;
    sf::Font font_przycisku;

    void rysuj_przycisk(sf::RenderWindow *window)
    {
      window->draw(pole);
      window->draw(napis);
    }

    button(const char nazwa[30], int pozycjaY)
    {
      pole.setSize(sf::Vector2f(okno.szerokosc_okna/5,okno.wysokosc_okna/10));
      pole.setFillColor(sf::Color::White);
      pole.setOutlineColor(sf::Color::Black);
      pole.setOutlineThickness(5);
      pole.setOrigin(pole.getSize().x/2,pole.getSize().y/2);
      pole.setPosition(okno.szerokosc_okna/2,pozycjaY);

      ramka = pole.getGlobalBounds();

      font_przycisku.loadFromFile("assets//zegar.ttf");
      napis.setFont(font_przycisku);
      napis.setColor(sf::Color::Black);
      napis.setCharacterSize(pole.getSize().y/1.3);
      napis.setString(nazwa);
      sf::FloatRect ramka_napisow = napis.getLocalBounds();
      napis.setOrigin(ramka_napisow.left + ramka_napisow.width/2.0f,
          ramka_napisow.top + ramka_napisow.height/2.0f);
      napis.setPosition(pole.getPosition());
    }
  };
  std::vector<button*> przyciski;




  void wskaznik_myszy(sf::RenderWindow *window)
  {
    sf::Vector2f mysz = sf::Vector2f(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y);
    target.setPosition(mysz.x,mysz.y);
    target_lineX.setPosition(mysz.x,mysz.y);
    target_lineY.setPosition(mysz.x,mysz.y);
  }



  public:
  bool logika_poziomu( sf::RenderWindow *window,
      std::map<std::string, sf::Keyboard::Key>controls)
  {
    wskaznik_myszy(window);

    sf::Vector2f mysz = sf::Vector2f(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y);

    //zmiana koloru po najechaniu i obsluga guzikow
    target.setFillColor(sf::Color::Red);
    target_lineX.setFillColor(sf::Color::Red);
    target_lineY.setFillColor(sf::Color::Red);
    for(unsigned int i=0;i<przyciski.size();i++)
      if(przyciski.at(i)->ramka.contains(mysz))
      {
        target.setFillColor(sf::Color::Green);
        target_lineX.setFillColor(sf::Color::Green);
        target_lineY.setFillColor(sf::Color::Green);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
          switch(i)
          {
            case 0:
              return true;
              break;
            case 1:
              window->close();
              break;
          }

      }
    controls.begin();

    return false;                                                                       //na zawsze w menu
  }

  void wyswietl_poziom(sf::RenderWindow *window)
  {
    window->clear(sf::Color(100, 100, 255, 150));

    for(unsigned int i=0;i<przyciski.size();i++)
      przyciski.at(i)->rysuj_przycisk(window);
    window->draw(target);
    window->draw(target_lineX);
    window->draw(target_lineY);

    window->display();
  }

  menu()
  {
    target.setRadius(3);
    target.setOutlineThickness(1);
    target.setOrigin(3, 3);
    target.setFillColor(sf::Color::Red);
    target.setOutlineColor(sf::Color::Black);

    target_lineX.setFillColor(sf::Color::Red);
    target_lineX.setSize(sf::Vector2f(2*okno.szerokosc_okna,1));
    target_lineX.setOrigin(okno.szerokosc_okna,0.5);
    target_lineY.setFillColor(sf::Color::Red);
    target_lineY.setSize(sf::Vector2f(1,2*okno.wysokosc_okna));
    target_lineY.setOrigin(0.5,okno.wysokosc_okna);

    button *przycisk = new button("START",(okno.wysokosc_okna*4)/6);
    przyciski.push_back(przycisk);

    przycisk = new button("EXIT",(okno.wysokosc_okna*5)/6);
    przyciski.push_back(przycisk);


  }

  ~menu()
  {

  }
};
