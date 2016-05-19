#include <iostream>
#include <SFML/Graphics.hpp>
#include "okno.h"
using namespace std;

extern class_okno okno;

void settings()
{
  cout << "Ustawiasz samemu? 0/1/n";
  cin >> okno.domyslne;

  if (okno.domyslne)
  {
    cout << "Podaj szerokosc okna/n";
    cin >> okno.szerokosc_okna;
    cout << "Podaj wysokosc okna/n";
    cin >> okno.wysokosc_okna;


  }
}
