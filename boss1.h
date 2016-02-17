#pragma once

class boss1 : public boss0
{
	
	char *kierunek_lotuX;
	char *kierunek_lotuY;
	int przeleconeX;
	int przeleconeY;

	std::vector<sf::Sprite> maincannon;
	sf::Texture tekstura_maincannon;
	int klatka_maincannon;

public:
    void rysuj_bossa(sf::RenderWindow *window)
    {
        window->draw(boss.at(int(klatka_bossa/10)));
        klatka_bossa++;
        if(klatka_bossa>=40)
            klatka_bossa=0;

		window->draw(maincannon.at(int(klatka_maincannon / 7.5)));
		klatka_maincannon++;
		if (klatka_maincannon >= 90)
			klatka_maincannon = 0;
    }

	void przemieszczenie()
	{

		if (kierunek_lotuX == "lewo")
			for (auto &sprite : boss)
				sprite.move(-0.4, 0);

		if (kierunek_lotuX == "prawo")
			for (auto &sprite : boss)
				sprite.move(0.4, 0);

		if (kierunek_lotuY == "gora")
			for (auto &sprite : boss)
				sprite.move(0, -0.15);

		if (kierunek_lotuY == "dol")
			for (auto &sprite : boss)
				sprite.move(0, 0.15);

		przeleconeX++;
		przeleconeY++;

		if (przeleconeX > okno.szerokosc_okna/4)
		{
			if (kierunek_lotuX == "lewo")
				kierunek_lotuX = "prawo";
			else if (kierunek_lotuX == "prawo")
				kierunek_lotuX = "lewo";
			przeleconeX = 0;
		}

		if (przeleconeY > okno.wysokosc_okna / 6)
		{
			if (kierunek_lotuY == "gora")
				kierunek_lotuY = "dol";
			else if (kierunek_lotuY == "dol")
				kierunek_lotuY = "gora";
			przeleconeY = 0;
		}
	}

	void ustaw_dziala()
	{
		for (int i = 0;i < 12;i++)
		{
			maincannon.at(i).setPosition(pozycja().x, pozycja().y-50);
		}
	}

	bool obrazenia(player &gracz)
	{
		std::vector<bullets> pociski = gracz.get_pociski();
		for (unsigned int i = 0;i<pociski.size();i++)
			if (maincannon.at(0).getGlobalBounds().contains(pociski[i].polozenie.x, pociski[i].polozenie.y))
			{
				HP--;
				gracz.usun_pocisk(i);
				if (HP <= 0)
					return true;                                                                                //umarl :(
			}
		return false;                                                                                               //nie umarl
	}

    boss1()
    {
        tekstura_bossa.loadFromFile("assets\\boss1.png");
        for(int i=0;i<4;i++)
        {
            sf::Sprite klatka_bossa;
            klatka_bossa.setOrigin(132,44);
            klatka_bossa.setScale(2,2);

            klatka_bossa.setPosition(okno.szerokosc_okna/2,okno.wysokosc_okna/8);
            klatka_bossa.setTexture(tekstura_bossa);
            klatka_bossa.setTextureRect(sf::IntRect(i*264,0,264,88));
            boss.push_back(klatka_bossa);

        }
        klatka_bossa=0;

		tekstura_maincannon.loadFromFile("assets\\boss1maincannon.png");
		/*for (int i = 0;i<12;i++)
		{
			sf::Sprite klatka_maincannon;
			klatka_maincannon.setOrigin(63.375, 40);
			klatka_maincannon.setScale(1.5, 1.5);
			klatka_maincannon.setRotation(180.0f);

			klatka_maincannon.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna / 8);
			klatka_maincannon.setTexture(tekstura_maincannon);
			klatka_maincannon.setTextureRect(sf::IntRect(i * 126.75, 0, 126.75, 80));
			maincannon.push_back(klatka_maincannon);

		}*/
		for (int i = 0;i<16;i++)
		{
			sf::Sprite klatka_maincannon;
			klatka_maincannon.setOrigin(28, 25);
			klatka_maincannon.setScale(3, 3);
			klatka_maincannon.setRotation(180.0f);

			klatka_maincannon.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna / 8);
			klatka_maincannon.setTexture(tekstura_maincannon);
			klatka_maincannon.setTextureRect(sf::IntRect(i * 56, 0, 56, 50));
			maincannon.push_back(klatka_maincannon);

		}
		klatka_maincannon = 0;

		kierunek_lotuX = "lewo";
		kierunek_lotuY = "dol";
		przeleconeX = okno.szerokosc_okna / 8;
		przeleconeY = okno.wysokosc_okna / 12;

		
    }

	~boss1()
	{

	}
};
