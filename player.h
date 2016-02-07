#pragma once
extern class_okno okno;
#include <vector>
#include <cstdlib>

struct bullets
{
	sf::Vector2f polozenie;
	sf::Vector2f vector;
};

class player
{
private:
	double HP,HP_max;
	sf::Sprite gracz;
	sf::Texture texture;
	sf::Vector2f wymiary;
	sf::Vector2f predkosc;
	sf::CircleShape target;
	sf::RectangleShape target_lineX,target_lineY;
	sf::RectangleShape dzialo[5];
	sf::RectangleShape HP_bar, HP_bar_tlo;
	sf::Vector2i mysz;
	float kat;
	std::vector<bullets> pociski;
	sf::Clock zegar_strzalu;
	int weapon_level;
	bool super_atak;
	sf::SoundBuffer ora_buffer;
	sf::Sound ora_sound;



public:

	sf::Vector2f pozycja()
	{
		sf::Vector2f polozenie = gracz.getPosition();
		return polozenie;
	}
	sf::Vector2f wymiar()
	{
		return wymiary;
	}

	void dodaj_predkosc(float x, float y)
	{
		predkosc.x+=x;
		predkosc.y+=y;
	}

	void przesuniecie_gracza()
	{
        if(!(pozycja().x > wymiar().x / 1.5 && pozycja().x < okno.szerokosc_okna - wymiar().x / 1.5))
            {predkosc.x=-predkosc.x*1.3;predkosc.y*=1.3;}
        if(!(pozycja().y > wymiar().y / 2 && pozycja().y < okno.wysokosc_okna - wymiar().y / 1.5))
            {predkosc.y=-predkosc.y*1.3;predkosc.x*=1.3;}
        gracz.move(predkosc);
        predkosc.x/=1.08;
        predkosc.y/=1.08;
	}


	sf::FloatRect ramka()
	{
		sf::FloatRect obwodka = gracz.getGlobalBounds();
		return obwodka;
	}

	void ustaw_dzialo(sf::Vector2i myszka, std::vector<bullets> &pociski_wrogow, sf::Music &muzyka_tlo)
	{
        przesuniecie_gracza();

		sf::Vector2f zaczepienie_dziala = pozycja();
		zaczepienie_dziala.y -= wymiary.y/6.0f;
		dzialo[0].setPosition(zaczepienie_dziala);

		zaczepienie_dziala = pozycja();
		zaczepienie_dziala.y += wymiary.y/5.5f;
		zaczepienie_dziala.x -= wymiary.x/2.5f;
		dzialo[1].setPosition(zaczepienie_dziala);

		zaczepienie_dziala = pozycja();
		zaczepienie_dziala.y += wymiary.y/5.5f;
		zaczepienie_dziala.x += wymiary.x/2.5f;
		dzialo[2].setPosition(zaczepienie_dziala);

		zaczepienie_dziala = pozycja();
		zaczepienie_dziala.y -= wymiary.y/3.5f;
		zaczepienie_dziala.x -= wymiary.x/5.0f;
		dzialo[3].setPosition(zaczepienie_dziala);

		zaczepienie_dziala = pozycja();
		zaczepienie_dziala.y -= wymiary.y/3.5f;
		zaczepienie_dziala.x += wymiary.x/5.0f;
		dzialo[4].setPosition(zaczepienie_dziala);



		mysz = myszka;
		angle(mysz);
		dzialo[0].setRotation(kat);
		dzialo[1].setRotation(kat);
		dzialo[2].setRotation(kat);
		dzialo[3].setRotation(kat);
		dzialo[4].setRotation(kat);


		target.setPosition(sf::Vector2f(mysz.x, mysz.y));
		HP_bar.setPosition(gracz.getPosition().x, gracz.getPosition().y + (wymiary.y * 6 / 10));
		HP_bar_tlo.setPosition(gracz.getPosition().x, gracz.getPosition().y + (wymiary.y * 6 / 10));

		target_lineX.setPosition(sf::Vector2f(mysz.x, mysz.y));
		target_lineY.setPosition(sf::Vector2f(mysz.x, mysz.y));

		if(super_atak)
			logika_super_ataku(pociski_wrogow, muzyka_tlo);
	}

	void strzal()
	{
		if(super_atak==false)
			switch (weapon_level)
			{
			case 1:
				bron1();	break;
			case 2:
				bron2();	break;
			case 3:
				bron3();	break;
			default:
			case 4:
				bron4();	break;
			}

	}

	void bron1(), bron2(), bron3(), bron4(), super_bron(bool final_modo);

	void logika_super_ataku(std::vector<bullets> &pociski_wrogow, sf::Music &muzyka_tlo)
	{
		if (ora_sound.getPlayingOffset() > sf::seconds(2))
			pociski_wrogow.clear();
		if (ora_sound.getPlayingOffset() > sf::seconds(3.4) && ora_sound.getPlayingOffset() < sf::seconds(6.8))
			super_bron(false);																			//final modo
		if (ora_sound.getPlayingOffset() > sf::seconds(7.4) && ora_sound.getPlayingOffset() < sf::seconds(7.6))
			super_bron(true);																			//final modo
		if (ora_sound.getPlayingOffset() > sf::seconds(7.7))
		{
			super_atak = false;
			muzyka_tlo.setVolume(100);
		}
	}

	void rysuj_gracza(sf::RenderWindow &okienko)
	{
		sf::CircleShape kolko(3);
		kolko.setOrigin(3,3);

		for (unsigned int i = 0; i < pociski.size(); i++)
		{
			if (pociski[i].polozenie.x<-30 || pociski[i].polozenie.x>okno.szerokosc_okna + 30) pociski.erase(pociski.begin() + i);
			else if (pociski[i].polozenie.y<-30 || pociski[i].polozenie.y>okno.wysokosc_okna + 30) pociski.erase(pociski.begin() + i);
		}

		okienko.draw(gracz);
		okienko.draw(target);
		okienko.draw(target_lineX);
		okienko.draw(target_lineY);
		if (super_atak == false)
		{
			okienko.draw(dzialo[0]);
			if (weapon_level >= 3)
			{
				okienko.draw(dzialo[1]);
				okienko.draw(dzialo[2]);
			}
			if (weapon_level >= 4)
			{
				okienko.draw(dzialo[3]);
				okienko.draw(dzialo[4]);
			}
		}
		for (auto &x : pociski)
		{
			kolko.setPosition(x.polozenie);
			okienko.draw(kolko);
			x.polozenie += x.vector;
		}
		okienko.draw(HP_bar_tlo);
		okienko.draw(HP_bar);

	}

	player()
	{
		texture.loadFromFile("assets\\pojazd.png");
		texture.setSmooth(true);

		gracz.setTexture(texture);
		gracz.setScale(0.2f, 0.25f);
		gracz.setOrigin(256 / 2, 231 / 2);
		wymiary.x = 256 * 0.2f;
		wymiary.y = 231 * 0.3f;
		srand(time(NULL));
		gracz.setPosition(okno.szerokosc_okna/2, okno.wysokosc_okna-wymiary.y);

		target.setRadius(3);
		target.setOutlineThickness(1);
		target.setOrigin(3, 3);
		target.setFillColor(sf::Color::Red);

		target_lineX.setFillColor(sf::Color::Red);
		target_lineX.setSize(sf::Vector2f(2*okno.szerokosc_okna,1));
		target_lineX.setOrigin(okno.szerokosc_okna,0.5);
		target_lineY.setFillColor(sf::Color::Red);
		target_lineY.setSize(sf::Vector2f(1,2*okno.wysokosc_okna));
		target_lineY.setOrigin(0.5,okno.wysokosc_okna);

        predkosc.x=0.0f;
        predkosc.y=0.0f;

		dzialo[0].setSize(sf::Vector2f(3, 20));
		dzialo[0].setOrigin(sf::Vector2f(1.5, 20));
		dzialo[0].setFillColor(sf::Color::White);
		dzialo[0].setOutlineColor(sf::Color::Black);
		dzialo[0].setOutlineThickness(2);
		dzialo[1]=dzialo[0];
		dzialo[2]=dzialo[0];
		dzialo[3]=dzialo[0];
		dzialo[4]=dzialo[0];

		HP_bar.setSize(sf::Vector2f(wymiary.x, 3));
		HP_bar.setOrigin(sf::Vector2f(wymiary.x / 2, 1.5));
		HP_bar.setFillColor(sf::Color::Red);
		HP_bar_tlo.setSize(sf::Vector2f(wymiary.x + 2, 5));
		HP_bar_tlo.setOrigin(sf::Vector2f(wymiary.x / 2 + 1, 2.5));
		HP_bar_tlo.setFillColor(sf::Color::White);

		weapon_level = 0;
		HP_max = 100;
		HP = HP_max;

		ora_buffer.loadFromFile("assets\\ora_sound.ogg");
		ora_sound.setBuffer(ora_buffer);

	}


	void angle(sf::Vector2i aktualna_mysz)
	{
		float x, y;
		sf::Vector2i mysz = aktualna_mysz;
		x = mysz.x - pozycja().x;
		y = pozycja().y - mysz.y - wymiary.y/6.0f;

		kat = (atan2(x, y) / (2*3.1415f)) *360;
	}

	std::vector<bullets> get_pociski()
	{
	    return pociski;
	}

	void usun_pocisk(int nr_pocisku)
	{
		if(pociski.size()>nr_pocisku)
			pociski.erase(pociski.begin()+nr_pocisku);
	}

	bool damaged()
	{
		HP--;
		HP_bar.setSize(sf::Vector2f((HP_bar_tlo.getSize().x-2) * HP / HP_max, 3));
		if(HP<=0)
            return true;                                                             //Zabity na smierc
        return false;
	}

	void level_up()
	{
	    weapon_level++;
    }

	void start_super(sf::Music &muzyka_tlo)
	{
		muzyka_tlo.setVolume(20);
		if(ora_sound.getStatus()!=sf::Sound::Playing)
			ora_sound.play();
		super_atak = true;
	}
};

