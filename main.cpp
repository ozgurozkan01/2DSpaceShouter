#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <vector>
#include "Bullet.h"
// CREATE AN ENEMY
class Enemy{
public:
    sf::CircleShape enemy;

    // Game Logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemy;

    Enemy(): enemySpawnTimerMax(50.f), enemySpawnTimer(enemySpawnTimerMax), maxEnemy(5){
        enemy.setRadius(25.f);
        enemy.setFillColor(sf::Color::Cyan);
        enemy.setOutlineColor(sf::Color::Red);
        enemy.setOutlineThickness(1.f);
    };
};

Bullet SpawnEnemyBullet(Enemy e1, sf::Vector2f playerCenter){

    Bullet b2;

    // Center of Enemy
    auto enemyCenter = sf::Vector2f(
            e1.enemy.getPosition().x + e1.enemy.getRadius(),
            e1.enemy.getPosition().y + e1.enemy.getRadius());

    // Direction of Enemy's bullets
    auto aimDirE = playerCenter - enemyCenter;
    auto aimDirNormE = aimDirE / static_cast<float>(sqrt(pow(aimDirE.x,2) + pow(aimDirE.y,2)));

    // Enemy Shooting
    b2.shape.setPosition(enemyCenter);
    b2.currVelocity = aimDirNormE * b2.maxSpeed;

    return b2;
}

std::vector<Bullet> MoveEnemyBullets(std::vector<Bullet> enemy_bullets)
{
    for(int i = 0; i< enemy_bullets.size(); i++){
        enemy_bullets[i].shape.move(enemy_bullets[i].currVelocity);

        if(enemy_bullets[i].shape.getPosition().x >= 800 ||
                enemy_bullets[i].shape.getPosition().x <= 0 ||
                enemy_bullets[i].shape.getPosition().y <= 0 ||
                enemy_bullets[i].shape.getPosition().y >= 600)
        {
            enemy_bullets.erase(enemy_bullets.begin()+i);
        }
    }
    return enemy_bullets;
}

int main()
{
    Bullet b1;
    std::srand((time(NULL)));
    // Window
    sf::RenderWindow window(sf::VideoMode(800,600),"My First Game", sf::Style::Default);

    // FPS
    window.setFramerateLimit(60);


    // Player
    sf::CircleShape player(25.f);
    player.setPosition(sf::Vector2f(375.f,450.f));
    player.setFillColor(sf::Color::Red);
    sf::Vector2f playerCenter;

    // Mouse Position
    sf::Vector2f mousePosWindow;

    // Aim Direction of bullets
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    // Enemy
    std::vector<Enemy> enemies;
    Enemy e1;

    sf::Vector2f enemyCenter;
    sf::Vector2f aimDirE;
    sf::Vector2f aimDirNormE;


    // Event
    sf::Event evnt;

    //BULLET
    std::vector<Bullet> bullets;
    std::vector<Bullet> bulletsE;

    // Game Loop
    while(window.isOpen())
    {
        // UPDATE
        while(window.pollEvent(evnt)){
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(evnt.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                        break;
                    }

            }

        }

        // Player Moving
        if(playerCenter.x < 775 && playerCenter.x > 25 &&
                playerCenter.y < 575 && playerCenter.y > 25)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
                player.move(-5.f,0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
                player.move(0.f,5.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
                player.move(5.f,0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
                player.move(0.0f,-5.f);
            }

        }

        if(playerCenter.x >= 775)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
                player.move(0.0f,-5.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
                player.move(-5.f,0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
                player.move(0.f,5.f);
            }
        }
        if(playerCenter.x <= 25)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
                player.move(0.f,5.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
                player.move(5.f,0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
                player.move(0.0f,-5.f);
            }
        }
        if(playerCenter.y <= 50)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
                player.move(-5.f,0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){ // Manuel moving character
                player.move(0.f,5.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
                player.move(5.f,0.0f);
            }
        }
        if(playerCenter.y >= 575)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){ // Manuel moving character
                player.move(5.f,0.0f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ // Manuel moving character
                player.move(0.0f,-5.f);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
                player.move(-5.f,0.0f);
            }
        }

        // Creating Enemy
        if(enemies.size() < e1.maxEnemy)
        {
            if(e1.enemySpawnTimer >= e1.enemySpawnTimerMax)
            {
                // Spawn enemy
                e1.enemy.setPosition(
                        static_cast<float>(rand() % static_cast<int>(window.getSize().x - e1.enemy.getScale().x/2)),
                        static_cast<float>(rand() % static_cast<int>(window.getSize().y - e1.enemy.getScale().y)/2));

                enemies.push_back(e1);

                e1.enemySpawnTimer = 0.f;
            }
            else
                e1.enemySpawnTimer += 1.f;
        }

        // Center of Player
        playerCenter = sf::Vector2f(
               player.getPosition().x + player.getRadius(),
                player.getPosition().y + player.getRadius());

        // Direction of bullets
        aimDir = mousePosWindow - playerCenter;
        aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x,2) + pow(aimDir.y,2)));

        // Mouse Position
        mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));

        for(int i = 0; i < enemies.size(); i++)
        {
            bulletsE.push_back(SpawnEnemyBullet(enemies[i], playerCenter));

            bulletsE = MoveEnemyBullets(bulletsE);
        }

        // Player Shooting
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            b1.shape.setPosition(playerCenter);
            b1.currVelocity = aimDirNorm * b1.maxSpeed;

            bullets.push_back(Bullet(b1));

        }

        for(int i = 0; i< bullets.size(); i++){
            bullets[i].shape.move(bullets[i].currVelocity);

            if(bullets[i].shape.getPosition().x >= 800 ||
               bullets[i].shape.getPosition().x <= 0 ||
               bullets[i].shape.getPosition().y <= 0 ||
               bullets[i].shape.getPosition().y >= 600)
            {
                bullets.erase(bullets.begin()+i);
            }

        }

        // Killing Enemy
        for(size_t i = 0; i < bullets.size(); i++)
        {
            for(size_t k = 0; k < enemies.size(); k++)
            {
                if(bullets[i].shape.getGlobalBounds().intersects(enemies[k].enemy.getGlobalBounds()))
                {
                    bullets.erase(bullets.begin()+i);
                    enemies.erase(enemies.begin()+k);

                    bulletsE.clear();
                }

            }
        }

        /**for(size_t i = 0; i < bulletsE.size(); i++)
        {
            if(bulletsE[i].shape.getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                bulletsE.erase(bulletsE.begin()+i);
                window.close();
                break;
            }
        }*/

        // RENDER
        window.clear();
        window.draw(player);

        for(auto &e : enemies)
        {
            window.draw(e.enemy);
        }

        for(int i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i].shape);
        }

        for(int i = 0; i< bulletsE.size(); i++)
        {
            window.draw(bulletsE[i].shape);
        }

        window.display();
    }
    // End of application
    return 0;
}
