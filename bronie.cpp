#include "main_header.h"


void player::bron1()
{
  sf::Time czas = zegar_strzalu.getElapsedTime();
  if (czas.asMilliseconds() > 200)
  {
    float y = pozycja().y - mysz.y - wymiary.y / 6.0f;
    float x = mysz.x - pozycja().x;                                    //aby zrozumiec podpisz 1 pakt z diab³em
    float z = sqrt(pow(x, 2) + pow(y, 2));
    float nowe_z = dzialo[0].getSize().y + 2;
    float nowe_x = x / (z / nowe_z);
    float nowe_y = -(y / (z / nowe_z));

    bullets pocisk;
    pocisk.polozenie.x = dzialo[0].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[0].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 2;
    pocisk.vector.y = nowe_y / 2;

    pociski.push_back(pocisk);
    zegar_strzalu.restart();
  }
}

void player::bron2()
{
  sf::Time czas = zegar_strzalu.getElapsedTime();
  if (czas.asMilliseconds() > 50)
  {
    float y = pozycja().y - mysz.y - wymiary.y / 6.0f;
    float x = mysz.x - pozycja().x;
    float z = sqrt(pow(x, 2) + pow(y, 2));
    float nowe_z = dzialo[0].getSize().y + 2;
    float nowe_x = x / (z / nowe_z);
    float nowe_y = -(y / (z / nowe_z));

    bullets pocisk;
    pocisk.polozenie.x = dzialo[0].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[0].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x/4;
    pocisk.vector.y = nowe_y/4;

    pociski.push_back(pocisk);
    zegar_strzalu.restart();
  }
}

void player::bron3()
{
  sf::Time czas = zegar_strzalu.getElapsedTime();
  if (czas.asMilliseconds() > 150)
  {
    float y = pozycja().y - mysz.y - wymiary.y / 6.0f;
    float x = mysz.x - pozycja().x;
    float z = sqrt(pow(x, 2) + pow(y, 2));
    float nowe_z = dzialo[0].getSize().y + 2;
    float nowe_x = x / (z / nowe_z);
    float nowe_y = -(y / (z / nowe_z));

    bullets pocisk;

    pocisk.polozenie.x = dzialo[0].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[0].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 1;
    pocisk.vector.y = nowe_y / 1;
    pociski.push_back(pocisk);

    pocisk.polozenie.x = dzialo[1].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[1].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 1;
    pocisk.vector.y = nowe_y / 1;
    pociski.push_back(pocisk);

    pocisk.polozenie.x = dzialo[2].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[2].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 1;
    pocisk.vector.y = nowe_y / 1;
    pociski.push_back(pocisk);

    zegar_strzalu.restart();
  }
}

void player::bron4()
{
  sf::Time czas = zegar_strzalu.getElapsedTime();
  if (czas.asMilliseconds() > 100)
  {
    float y = pozycja().y - mysz.y - wymiary.y / 6.0f;
    float x = mysz.x - pozycja().x;
    float z = sqrt(pow(x, 2) + pow(y, 2));
    float nowe_z = dzialo[0].getSize().y + 2;
    float nowe_x = x / (z / nowe_z);
    float nowe_y = -(y / (z / nowe_z));

    bullets pocisk;

    pocisk.polozenie.x = dzialo[0].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[0].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 1;
    pocisk.vector.y = nowe_y / 1;
    pociski.push_back(pocisk);

    pocisk.polozenie.x = dzialo[1].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[1].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 3;
    pocisk.vector.y = nowe_y / 3;
    pociski.push_back(pocisk);

    pocisk.polozenie.x = dzialo[2].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[2].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 3;
    pocisk.vector.y = nowe_y / 3;
    pociski.push_back(pocisk);

    pocisk.polozenie.x = dzialo[3].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[3].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 2;
    pocisk.vector.y = nowe_y / 2;
    pociski.push_back(pocisk);

    pocisk.polozenie.x = dzialo[4].getPosition().x + nowe_x;
    pocisk.polozenie.y = dzialo[4].getPosition().y + nowe_y;
    pocisk.vector.x = nowe_x / 2;
    pocisk.vector.y = nowe_y / 2;
    pociski.push_back(pocisk);

    zegar_strzalu.restart();
  }
}