#pragma once

class level1 : public level
{
    sf::Texture tekstura_tla;
    sf::Sprite tlo;
    player *gracz;
    std::vector<sf::Texture*> enemytexture;
    std::vector<enemy*> wrogowie;
	std::vector<bullets> pociski_wrogow;
    std::vector<explosion> eksplozje;
    std::vector<sf::Sprite> eksplozja_klatka;
    sf::Texture eksplozja_sprite;
    sf::Clock zegar_wroga;
    sf::Clock zegar_poziomu;
    sf::Font font_wyswietlacz;
    sf::Text wyswietlacz;
    sf::Music muzyka_tlo;
public:
    bool logika_poziomu( sf::RenderWindow *window,
                         std::map<std::string, sf::Keyboard::Key> controls )
    {
        tworzenie_wroga();
        poruszanie_gracza(controls);
		gracz->ustaw_dzialo(sf::Mouse::getPosition(*window), pociski_wrogow, muzyka_tlo);
        if(logika_czasu_poziomu())
            return true;                                                                            //koniec czasu nastepny lvl
        logika_wrogow();

        return false;                                                                                     //dalej ten sam poziom
    }

    void wyswietl_poziom(sf::RenderWindow *window)
    {
        window->clear(sf::Color::Black);

        window->draw(tlo);
        for (unsigned int i = 0;i < eksplozje.size();i++)
			if (eksplozje.at(i).rysuj_klatke(*window))
				eksplozje.erase(eksplozje.begin() + i);
		for (auto & wrog : wrogowie)
			wrog->rysuj_wroga(*window);

		sf::CircleShape kolko(3);
		kolko.setOrigin(3, 3);
		for (auto &x : pociski_wrogow)
		{
			kolko.setPosition(x.polozenie);
			window->draw(kolko);
		}
		gracz->rysuj_gracza(*window);
		window->draw(wyswietlacz);
		window->display();
    }

    


    level1(player *gracz_src)
    {
        tekstura_tla.loadFromFile("assets\\spacebg.jpg");
        tlo.setTexture(tekstura_tla);
        tlo.setOrigin(3000/2,okno.wysokosc_okna);
        tlo.setPosition(okno.szerokosc_okna/2,-3000+2*okno.wysokosc_okna);

        gracz = gracz_src;

        //ustawianie tekstur wrogow
        for(int i=0;i<=3;i++)
        {
            sf::Texture *texture = new sf::Texture;
            std::string nazwapliku="assets\\enemy";
            nazwapliku+=i+'0';
            nazwapliku+=".png";
            texture->loadFromFile(nazwapliku);
            enemytexture.push_back(texture);
        }

        //ustawianie eksplozji
        eksplozja_sprite.loadFromFile("assets\\explosion.png");
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                sf::Sprite sprite_klatki;
                sprite_klatki.setOrigin(50,40);
                sprite_klatki.setTexture(eksplozja_sprite);
                sprite_klatki.setTextureRect(sf::IntRect(j*100,i*100,100,100));
                eksplozja_klatka.push_back(sprite_klatki);
            }

        //licznik czasu
        font_wyswietlacz.loadFromFile("assets\\zegar.ttf");
        wyswietlacz.setFont(font_wyswietlacz);
        wyswietlacz.setCharacterSize(30);
        wyswietlacz.setPosition(okno.szerokosc_okna-60,okno.wysokosc_okna-50);
        wyswietlacz.setColor(sf::Color::White);

        muzyka_tlo.openFromFile("assets\\level1bg.ogg");
        muzyka_tlo.setLoop(true);
        muzyka_tlo.play();
    }

    ~level1()
    {
        for(unsigned int i=0;i<enemytexture.size();i++)
            delete enemytexture.at(i);

        for(unsigned int i=0;i<wrogowie.size();i++)
            delete wrogowie.at(i);

        muzyka_tlo.stop();
    }

private:

    void tworzenie_wroga()
    {
        if(zegar_wroga.getElapsedTime()>sf::seconds(1))
        {
            int ktory_wrog = std::rand() % 3 + 1;
            enemy *temp_pointer;
            switch(ktory_wrog)
            {
            case 1:
                temp_pointer= new enemy1(enemytexture);
                break;
            case 2:
                temp_pointer= new enemy2(enemytexture);
                break;
            case 3:
                temp_pointer= new enemy3(enemytexture);
                break;
            default:
                temp_pointer= new enemy;
                break;
            }
            zegar_wroga.restart();

            wrogowie.push_back(temp_pointer);
        }
    }

    void poruszanie_gracza(std::map<std::string, sf::Keyboard::Key> controls)
    {
        if (sf::Keyboard::isKeyPressed(controls.at("left")))
			gracz->dodaj_predkosc(-0.7f, 0);
		if (sf::Keyboard::isKeyPressed(controls.at("right")))
			gracz->dodaj_predkosc(0.7f, 0);
		if (sf::Keyboard::isKeyPressed(controls.at("up")))
			gracz->dodaj_predkosc(0, -0.7f);
		if (sf::Keyboard::isKeyPressed(controls.at("down")))
			gracz->dodaj_predkosc(0, 0.7f);
		if (sf::Keyboard::isKeyPressed(controls.at("fire"))) gracz->strzal();
		if (sf::Keyboard::isKeyPressed(controls.at("super"))) gracz->start_super(muzyka_tlo);
    }

    void logika_wrogow()
    {
		sf::FloatRect ramka_gracz = gracz->ramka();

        for(unsigned int i=0;i<wrogowie.size();i++)
        {
            wrogowie.at(i)->przemieszczenie();
            if(wrogowie.at(i)->wylecial_za_mape())
            {
                delete wrogowie.at(i);
                wrogowie.erase(wrogowie.begin()+i);
                continue;
            }
            
            if(ramka_gracz.intersects(wrogowie.at(i)->ramka()))
                gracz->damaged();
			
            


            wrogowie.at(i)->strzal(pociski_wrogow);
			

            if(wrogowie.at(i)->obrazenia(*gracz))                                       //jesli umarl to :(
            {
                explosion wybuch(wrogowie.at(i)->pozycja(),eksplozja_klatka);
				switch (wrogowie.at(i)->typ_wroga())
				{
				case 1:
					wybuch.ustaw_skale(0.8);
					gracz->super_atak_ustaw_dostepny();
					break;
				case 2:
					wybuch.ustaw_skale(1.2);
					break;
				case 3:
					wybuch.ustaw_skale(1.0);
					break;
				}
				
                eksplozje.push_back(wybuch);
                delete wrogowie.at(i);
                wrogowie.erase(wrogowie.begin()+i);
                continue;
            }
        }

		for (unsigned int i = 0;i<pociski_wrogow.size();i++)
			if (ramka_gracz.contains(pociski_wrogow.at(i).polozenie))
			{
				gracz->damaged();
				pociski_wrogow.erase(pociski_wrogow.begin() + i);
			}

		logika_pociskow_wrogow();
    }

	void logika_pociskow_wrogow()
	{


		for (unsigned int i = 0; i < pociski_wrogow.size(); i++)
		{
			pociski_wrogow[i].polozenie += pociski_wrogow[i].vector;

			if (pociski_wrogow[i].polozenie.x<-30 || pociski_wrogow[i].polozenie.x>okno.szerokosc_okna + 30) pociski_wrogow.erase(pociski_wrogow.begin() + i);
			else if (pociski_wrogow[i].polozenie.y<-30 || pociski_wrogow[i].polozenie.y>okno.wysokosc_okna + 30) pociski_wrogow.erase(pociski_wrogow.begin() + i);
		}
	}

	bool logika_czasu_poziomu()
	{
		int pozostaly_czas_w_milisekundach = 60000 - zegar_poziomu.getElapsedTime().asMilliseconds();
		char tekstowy_czas[5];
		int milisekundy = pozostaly_czas_w_milisekundach % 1000;
		if (pozostaly_czas_w_milisekundach >= 0)
			sprintf_s(tekstowy_czas, "%i.%i", (pozostaly_czas_w_milisekundach - milisekundy) / 1000, milisekundy / 100);
		wyswietlacz.setString(tekstowy_czas);
		if (pozostaly_czas_w_milisekundach <= 0)
		{
			wyswietlacz.setString("0.0");
			for (unsigned int i = 0;i < wrogowie.size();i++)
			{
				explosion wybuch(wrogowie.at(i)->pozycja(), eksplozja_klatka);
				eksplozje.push_back(wybuch);
				delete wrogowie.at(i);
				wrogowie.erase(wrogowie.begin() + i);
			}
			if (pozostaly_czas_w_milisekundach <= -5000)
				return true;
		}
		return false;
	}
};
