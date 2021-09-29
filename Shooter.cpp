//
// Created by ozgur on 9/24/2021.
//

#include "Shooter.h"
#include "math.h"

void Shooter::AddBullet(Bullet* bullet)
{
    bullets.push_back(bullet);
}

void Shooter::DeleteBullet(int index)
{
    bullets.erase(bullets.begin() + index);
}

Bullet* Shooter::CreateBullet(sf::Vector2f mousePos)
{
    CalculateDirection(mousePos);
    return new Bullet(bulletSpeed * aimDirNorm, this);
}

void Shooter::CalculateDirection(sf::Vector2f mousePos)
{
    aimDir = mousePos - position;
    CalculateAimNorm();
}

void Shooter::CalculateAimNorm()
{
    aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
}

void Shooter::Fire(sf::Vector2f mousePos)
{
    AddBullet(CreateBullet(mousePos));
}