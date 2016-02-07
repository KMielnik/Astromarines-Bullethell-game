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
	if (czas.asMilliseconds() > 60)
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
		pocisk.vector.x = nowe_x/5;
		pocisk.vector.y = nowe_y/5;

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

void player::super_bron(bool final_modo)
{
	int opoznienie;
	int predkosc;
	if (final_modo)
	{
		opoznienie = 1;
		predkosc = 3;
	}
	else
	{
		opoznienie = 100;
		predkosc = 5;
	}

	sf::Time czas = zegar_strzalu.getElapsedTime();
	if (czas.asMilliseconds() > opoznienie)
	{
		bullets pocisk;
		//pocisk 1
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = 0;
		pocisk.vector.y = predkosc*3;
		pociski.push_back(pocisk);

		//pocisk 2
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = 0;
		pocisk.vector.y = -predkosc*3;
		pociski.push_back(pocisk);

		//pocisk 3
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc*3;
		pocisk.vector.y = 0;
		pociski.push_back(pocisk);

		//pocisk 4
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc*3;
		pocisk.vector.y = 0;
		pociski.push_back(pocisk);

		//pocisk 5
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc*2.5;
		pocisk.vector.y = predkosc;
		pociski.push_back(pocisk);

		//pocisk 6
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc*2.5;
		pocisk.vector.y = predkosc;
		pociski.push_back(pocisk);

		//pocisk 7
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc*2.5;
		pocisk.vector.y = -predkosc;
		pociski.push_back(pocisk);

		//pocisk 8
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc*2.5;
		pocisk.vector.y = -predkosc;
		pociski.push_back(pocisk);

		//pocisk 9
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc*1.5;
		pocisk.vector.y = predkosc*1.5;
		pociski.push_back(pocisk);

		//pocisk 10
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc*1.5;
		pocisk.vector.y = predkosc*1.5;
		pociski.push_back(pocisk);

		//pocisk 11
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc*1.5;
		pocisk.vector.y = -predkosc*1.5;
		pociski.push_back(pocisk);

		//pocisk 12
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc*1.5;
		pocisk.vector.y = -predkosc*1.5;
		pociski.push_back(pocisk);

		//pocisk 13
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc;
		pocisk.vector.y = predkosc*2.5;
		pociski.push_back(pocisk);

		//pocisk 14
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc;
		pocisk.vector.y = predkosc*2.5;
		pociski.push_back(pocisk);

		//pocisk 15
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = predkosc;
		pocisk.vector.y = -predkosc*2.5;
		pociski.push_back(pocisk);

		//pocisk 16
		pocisk.polozenie.x = gracz.getPosition().x;
		pocisk.polozenie.y = gracz.getPosition().y;
		pocisk.vector.x = -predkosc;
		pocisk.vector.y = -predkosc*2.5;
		pociski.push_back(pocisk);

		


		zegar_strzalu.restart();
	}
}
