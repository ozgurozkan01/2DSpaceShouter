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

    sf::Font font;
    sf::Text text;

    sf::Clock clock;
    sf::Time time;
    float deltaTime;

    std::vector<Enemy*> enemies;

    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerRestHpBar;

    float playerRestHpBar_x;
    float playerRestHpBar_y;

    // Game Logic

    int maxEnemy = 3;
    int enemyCounter;

    float enemySpawnTimer;
    float enemyBulletTimer;
    float playerHpTimer;
    float enemiesHpTimer;
    float attackCoolDown;

    Player* player;

    sf::Vector2f mousePosWindow;

    Game();
    virtual ~Game();

    void InitWindow();
    const bool running() const;
    void pollEvent();
    void MousePosition();
    void DrawBullets();
    void BulletsMove();
    void KillingEnemies();
    void KillingPlayer();
    void DeathEnemyCounter();
    void InitPlayerHpBar();
    void DrawPlayerHpBar();
    void CalcDeltaTime();
    void Timer();

    // PLAYER
    void CreatePlayer();
    void DrawPlayerBullets();
    void DrawPlayer();
    void PlayerFire();
    void PlayerBulletsMove();
    void UpdatePlayerHp();
    void UpdateAttack();
    const bool CanAttack();

    // ENEMY
    void DrawEnemyBullets();
    void CreatingEnemy();
    void DrawEnemies();
    void EnemiesFire();
    void EnemiesBulletsMove();
    void FireEnemiesBullet();
    void UpdateEnemiesHp();
    void UpdateEnemiesColor();

    // GAME
    void update();
    void render();
};

#endif //SFML_GAME_H
