#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <vector>

// CLASS BULLETS
class Bullet{
public:

    sf::CircleShape shape;
    sf::Vector2f currVelocity; // anlık hız
    float maxSpeed;

    Bullet(float radius = 5.f):currVelocity(0.f,0.f), maxSpeed(30.f)
    {
        this->shape.setRadius(radius);
        this->shape.setFillColor(sf::Color::White);
    }
};

class Enemies{
public:
    sf::RectangleShape enemy;

    // Game Logic
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemy;

    Enemies():enemySpawnTimerMax(50.f), enemySpawnTimer(enemySpawnTimerMax), maxEnemy(15){
        enemy.setSize(sf::Vector2f(25.f,50.f));
        enemy.setFillColor(sf::Color::Cyan);
        enemy.setOutlineColor(sf::Color::Red);
        enemy.setOutlineThickness(1.f);



    };

};

int main()
{
    Bullet b1;
    std::srand(static_cast<unsigned>(time(NULL)));
    // Window
    sf::RenderWindow window(sf::VideoMode(800,600),"My First Game", sf::Style::Default);
    window.setFramerateLimit(60);


    // Player
    sf::CircleShape player(25.f);
    player.setPosition(sf::Vector2f(375.f,450.f));
    player.setFillColor(sf::Color::Red);
    sf::Vector2f playerCenter;
    sf::Vector2f mousePosWindow;
    sf::Vector2f aimDir;
    sf::Vector2f aimDirNorm;

    // Enemies
    std::vector<sf::RectangleShape> enemies;
    Enemies e1;


    // Event
    sf::Event evnt;

     //BULLET
    std::vector<Bullet> bullets;

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

        // Enemy
        if(enemies.size() < e1.maxEnemy)
        {
            if(e1.enemySpawnTimer >= e1.enemySpawnTimerMax)
            {
                // Spawn enemy
                e1.enemy.setPosition(
                        static_cast<float>(rand() % static_cast<int>(window.getSize().x - e1.enemy.getSize().x)),
                        static_cast<float>(rand() % static_cast<int>(window.getSize().y - e1.enemy.getSize().y)));
                enemies.push_back(e1.enemy);
                e1.enemySpawnTimer = 0.f;
            }
            else
                e1.enemySpawnTimer += 1.f;
        }

        /**for(auto &e : enemies)
        {
            e.move(0.f, 5.f);
        }**/

        // Center of Player
        playerCenter = sf::Vector2f(
                player.getPosition().x + player.getRadius(),
                player.getPosition().y + player.getRadius());

        aimDir = mousePosWindow - playerCenter;
        aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x,2) + pow(aimDir.y,2)));

        // Mouse Position
        mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));

        // Shotting
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            b1.shape.setPosition(playerCenter);
            b1.currVelocity = aimDirNorm * b1.maxSpeed;

            bullets.push_back(Bullet(b1));
        }

        for(int i = 0; i< bullets.size(); i++){
            bullets[i].shape.move(bullets[i].currVelocity);
        }


        // RENDER
        window.clear();
        window.draw(player);

        for(auto &e : enemies)
        {
            window.draw(e);
        }

        for(int i = 0; i< bullets.size(); i++){
            window.draw(bullets[i].shape);
        }
        window.display();
    }
    // End of application
    return 0;
    /**
    sf::RectangleShape player(sf::Vector2f(15.f,15.f));

    // Init srand
    // srand is used to return random number in the programming .
    std::srand(static_cast<unsigned>(time(NULL))); // initialising srand ;

    // Init Game engine
    Game game;  // Game class has all functions and variables that we will use (Constructor automatically call functions that it has)
    //Game Loop
    while(game.running()){  // This function includes window.isOpen() function - we control that window is open or not with this function

        //UPDATE
        game.update(); // This method include all update functions and this functions include update methods
        //RENDER  - DRAWING THE WINDOW
        game.render(); // Render function and display
    }


     * // KEYBOARD INPUT
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){ // Manuel moving character
        player.move(-0.1f,0.0f);
    }

    window.clear();

     * // MOUSE INPUT
     if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i mousepos = sf::Mouse::getPosition(window);
        player.setPosition((float)mousepos.x,(float)mousepos.y);
    }

    */
}
