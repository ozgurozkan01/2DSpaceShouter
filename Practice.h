//
// Created by ozgur on 9/11/2021.
//
#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#ifndef SFML_PRACTICE_H
#define SFML_PRACTICE_H


class Practice {
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videomode;
    sf::Event evnt; // you should not use event variable name

    //Mouse positions
    sf::Vector2i mousePosWindow; //
    sf::Vector2f mousePosView;

    // Game Logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    // Game objects
    std::vector<sf::RectangleShape> enemies; // std::vector<> variable_name = {assign values};
    sf::RectangleShape enemy;


    //Private Functions
    void initVariables();
    void initWindow();
    void initEnemies();
public:
    // Constructors / Destructors
    Practice();
    virtual ~Practice();
    //Accessors
    const bool running() const;

    // Functions
    void spawnEnemy();

    void pollEvents(); // INCLUDE GAME LOOP
    void updateMousePositions();
    void updateEnemies();
    void update(); // INCLUDE POOLEVENTS FUNCTION

    void renderEnemies();
    void render(); //
};


#endif //SFML_PRACTICE_H
