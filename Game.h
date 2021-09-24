#ifndef SFML_GAME_H
#define SFML_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
class Game {
public:
    sf::RenderWindow* window;
    sf::Event evnt;

    Player pG;
    Enemy eG;
    Bullet bG;

    sf::Vector2f mousePosWindow;

    void initWindow();

    Game();
    virtual ~Game();

    const bool running() const;
    void pollEvent();
    void MousePosition();

    void update();
    void render();
};


/**
private:

    sf::RenderWindow* window;
    sf::Event evnt;

    sf::CircleShape my_hero;
    sf::CircleShape enemy;

    sf::Vector2i mousePosition;

    void initVariables();
    void initWindow();
    void initHero();

public:
    Game();
    virtual ~Game();

    void General_update();
    void General_render();

    void HeroRotation();
    void MousePosition();
    //void ShootBullet();

    const bool ReturnOpen() const;
    void Keyboard_Instruction();
    void pollEvent();

 * */
#endif //SFML_GAME_H
