#pragma once
#include <cstdlib>

class enemy3 : public enemy
{
    float ktore_dzialo;

    void strzal(std::vector<bullets> &pociski)
    {
        sf::Time czas = zegar_strzalu.getElapsedTime();
        if (czas.asMilliseconds() > 30)
        {
            bullets pocisk;
            switch((int)trunc(ktore_dzialo))
            {
            case 1:
                pocisk.polozenie.x = wrog.getPosition().x+wymiary.x/3.9f;
                pocisk.polozenie.y = wrog.getPosition().y-wymiary.y/2;
                pocisk.vector.x = 2;
                pocisk.vector.y = -4.7;
                break;
            case 3:
                pocisk.polozenie.x = wrog.getPosition().x+wymiary.x/3.9f;
                pocisk.polozenie.y = wrog.getPosition().y+wymiary.y/2;
                pocisk.vector.x = 2;
                pocisk.vector.y = 4.7f;
                break;
            case 6:
                pocisk.polozenie.x = wrog.getPosition().x-wymiary.x/3.9f;
                pocisk.polozenie.y = wrog.getPosition().y-wymiary.y/2;
                pocisk.vector.x = -2;
                pocisk.vector.y = -4.7f;
                break;
            case 4:
                pocisk.polozenie.x = wrog.getPosition().x-wymiary.x/3.9f;
                pocisk.polozenie.y = wrog.getPosition().y+wymiary.y/2;
                pocisk.vector.x = -2;
                pocisk.vector.y = 4.7f;
                break;
            case 2:
                pocisk.polozenie.x = wrog.getPosition().x+wymiary.x/2;
                pocisk.polozenie.y = wrog.getPosition().y;
                pocisk.vector.x = 5.13f;
                pocisk.vector.y = 0;

                break;
            case 5:
                pocisk.polozenie.x = wrog.getPosition().x-wymiary.x/2;
                pocisk.polozenie.y = wrog.getPosition().y;
                pocisk.vector.x = -5.13f;
                pocisk.vector.y = 0;
                break;

            }
            ktore_dzialo+=0.1f;
            if(ktore_dzialo>7)
                ktore_dzialo=1;
            pociski.push_back(pocisk);
            zegar_strzalu.restart();

        }
    }
    public:
	enemy3(std::vector<sf::Texture*> enemytexture)
	{
		nr_typu_wroga = 3;
		wrog.setTexture(*enemytexture[3]);
		wrog.setScale(0.3f, 0.3f);
		wrog.setOrigin(200 / 2, 176 / 2);
		wymiary.x = 200 * 0.3f;
		wymiary.y = 176 * 0.3f;
		int losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
		wrog.setPosition(losowa_pozycja_x, 0-wymiary.y);


		HP_bar.setSize(sf::Vector2f(wymiary.x, 3));
		HP_bar.setOrigin(sf::Vector2f(wymiary.x / 2, 1.5));
		HP_bar.setFillColor(sf::Color::Red);
		HP_bar_tlo.setSize(sf::Vector2f(wymiary.x + 2, 5));
		HP_bar_tlo.setOrigin(sf::Vector2f(wymiary.x / 2 + 1, 2.5));
		HP_bar_tlo.setFillColor(sf::Color::White);

		ktore_dzialo=1;

		HP_max = 5;
        HP = HP_max;
	}
};
