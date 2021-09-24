//
// Created by ozgur on 9/24/2021.
//

#ifndef SFML_SHOOTER_H
#define SFML_SHOOTER_H
#include <iostream>
#include <vector>
#include "Bullet.h"

class Shooter {
public:
    std::vector<Bullet> bullets;

    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    float bulletSpeed;

public:
    void AddBullet(Bullet bullet);
    void DeleteBullet(int index);
    void CalculateDirection(sf::Vector2f mousePos, sf::Vector2f shooterPos);
    void CalculateAimNorm();
    void CreateBullet(sf::Vector2f mousePos, sf::Vector2f shooterPos);
};


#endif //SFML_SHOOTER_H
