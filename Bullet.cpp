//
// Created by ozgur on 9/18/2021.
//
#include "Bullet.h"
#include "math.h"

/*
Bullet::Bullet()
{
    currVelocity = sf::Vector2f (0.f,0.f);
    speed = 10.f;

    this->shape.setRadius(5.f);
    this->shape.setFillColor(sf::Color::White);
}

*/

void Bullet::SpawnPlayerBullet(sf::Vector2f mp, sf::Vector2f playerCenter)
{
    //aimDir = mp - playerCenter;
    //aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
    currVelocity = aimDirNorm * speed;

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        shape.setPosition(playerCenter);
        bullets.push_back(shape);
    }
}

void Bullet::Move()
{
    shape.move(currVelocity);

    if(shape.getPosition().x >= 800 ||
       shape.getPosition().x <= 0 ||
       shape.getPosition().y <= 0 ||
       shape.getPosition().y >= 600)
    {
        OnDelete();
    }
}

void Bullet::OnDelete()
{
    owner.DeleteBullet(index);

    delete this;
}

