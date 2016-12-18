#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class explosion
{
  int ktora_klatka;
  std::vector<sf::Sprite> eksplozja_klatka;
 
  public:

  bool rysuj_klatke(sf::RenderWindow &okienko)
  {
    okienko.draw(eksplozja_klatka.at(ktora_klatka));
    ktora_klatka++;
    if((unsigned)ktora_klatka<eksplozja_klatka.size())
      return false;
    else
      return true;
  }

  void ustaw_skale(float skala)
  {
    for (unsigned int i = 0;i < eksplozja_klatka.size();i++)
      eksplozja_klatka.at(i).setScale(skala, skala);
  }

  explosion(sf::Vector2f polozenie,std::vector<sf::Sprite> eksplozja_klatka_src)
  {
    eksplozja_klatka=eksplozja_klatka_src;

    for(unsigned int i=0;i<eksplozja_klatka.size();i++)
      eksplozja_klatka.at(i).setPosition(polozenie);
    ktora_klatka=0;
  }
};
