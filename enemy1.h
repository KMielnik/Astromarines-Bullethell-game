#pragma once
#include <cstdlib>

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
	            wrog.move(0, 10);
            break;

            case 2: //from down
	            wrog.move(0, -10);
            break;

            case 3:  //from left
	            wrog.move(10, 0);
            break;

            case 4: //from right
	            wrog.move(-10, 0);
            break;
	    }

        wrog.rotate(8);
	}



	enemy1(std::vector<sf::Texture*> enemytexture)
	{
		nr_typu_wroga = 1;

		wrog.setTexture(*enemytexture[1]);
		wrog.setScale(0.4f, 0.4f);
		wrog.setOrigin(143 / 2, 140 / 2);
		wymiary.x = 143 * 0.4f;
		wymiary.y = 140 * 0.4f;

		int kierunek = std::rand() % 4 + 1;
        int losowa_pozycja_x,losowa_pozycja_y;
        switch(kierunek)
        {
        case 1:
            losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
            wrog.setPosition(losowa_pozycja_x, 0-wymiary.y);
            origin_place=up;
            break;
        case 2:
            losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna-(wymiary.x/2)) + (int)wymiary.x/2;
            wrog.setPosition(losowa_pozycja_x, okno.wysokosc_okna+wymiary.y);
            origin_place=down;
            break;
        case 3:
            losowa_pozycja_y = std::rand() % (int)(okno.wysokosc_okna-(wymiary.y/2)) + (int)wymiary.y/2;
            wrog.setPosition(0-wymiary.x, losowa_pozycja_y);
            origin_place=left;
            break;
        case 4:
            losowa_pozycja_y = std::rand() % (int)(okno.wysokosc_okna-(wymiary.y/2)) + (int)wymiary.y/2;
            wrog.setPosition(okno.szerokosc_okna+wymiary.x, losowa_pozycja_y);
            origin_place=right;
            break;
        }


		HP_max = 1;
        HP = HP_max;
	}

    void rysuj_wroga(sf::RenderWindow &okienko)
	{

		okienko.draw(wrog);

	}
};
