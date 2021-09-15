#ifndef SFML_GAME_H
#define SFML_GAME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <vector>
#include "Game.h"

class Game {
private:
    // Player
    sf::RenderWindow* window;

    // Bullets
    sf::CircleShape shape;
    sf::Vector2f currVelocity = sf::Vector2f(0.f,0.f);
    float maxSpeed = 15.f;
    std::vector<sf::CircleShape> bullets;

    sf::Event evnt;

    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    sf::CircleShape player;

    void initWindow();
    void initPlayer();
    void initBullet();
public:
    Game();
    virtual ~Game();

    const bool running() const;
    void pollEvent();
    // Player Function
    void movePlayer();
    void PlayerCenter();

    // Bullet Fonction
    void CreateBullet();
    void ShootBullet();

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
