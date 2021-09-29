//
// Created by ozgur on 9/24/2021.
//

#ifndef SFML_SHOOTER_H
#define SFML_SHOOTER_H

#include "SFML/Graphics.hpp"

class Bullet;
#include "Bullet.h"

class Shooter {
public:
    std::vector<Bullet*>bullets;

    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    sf::Vector2f position;

    float bulletSpeed = 10.f;

public:
    void AddBullet(Bullet* bullet);
    void DeleteBullet(int index);
    void CalculateDirection(sf::Vector2f mousePos);
    void CalculateAimNorm();
    Bullet* CreateBullet(sf::Vector2f mousePos);
    void Fire(sf::Vector2f mousePos);


};

#endif //SFML_SHOOTER_H
