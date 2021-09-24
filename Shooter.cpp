//
// Created by ozgur on 9/24/2021.
//

#include "Shooter.h"
#include "math.h"
void Shooter::AddBullet(Bullet bullet)
{
    bullets.push_back(bullet);
}

void Shooter::DeleteBullet(int index)
{
    bullets.erase(bullets.begin() + index);
}

void Shooter::CalculateAimNorm()
{
    aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
}

void Shooter::CalculateDirection(sf::Vector2f mousePos, sf::Vector2f shooterPos)
{
    aimDir = mousePos - shooterPos;
    CalculateAimNorm();
}

void Shooter::CreateBullet(sf::Vector2f mousePos, sf::Vector2f shooterPos)
{
    CalculateDirection(mousePos, shooterPos);

    sf::Vector2f x = bulletSpeed * aimDirNorm;

    auto bullet = new Bullet(x, this, 5);
}
