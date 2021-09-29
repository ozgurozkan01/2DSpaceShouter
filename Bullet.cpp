
#include "Bullet.h"

void Bullet::Move(int bulletIndex)
{
    shape.move(currVelocity);

    if( shape.getPosition().x >= 800 ||
        shape.getPosition().x <= 0 ||
        shape.getPosition().y <= 0 ||
        shape.getPosition().y >= 600)
    {
        OnDelete(bulletIndex);
    }
}

void Bullet::OnDelete(int bulletIndex)
{
    owner->DeleteBullet(bulletIndex);
}

void Bullet::InitBullet()
{
    shape.setRadius(1.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(owner->position);
    shape.setOutlineThickness(3.f);
    shape.setOutlineColor(sf::Color::Red);
}

