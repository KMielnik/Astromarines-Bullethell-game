#pragma once

class level
{
public:

    virtual bool logika_poziomu( sf::RenderWindow *window,
                                 std::map<std::string, sf::Keyboard::Key> controls )
    {
        return true;
    }

    virtual void wyswietl_poziom(sf::RenderWindow *window)
    {

    }



    virtual ~level()
    {

    }
};
