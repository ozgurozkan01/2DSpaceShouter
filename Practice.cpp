//
// Created by ozgur on 9/11/2021.
//

#include "Practice.h"

// Private Functions

void Practice::initVariables()
{
    this->window = nullptr;

    // Game Logic;
    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
}

void Practice::initWindow()
{
    this->videomode.height = 600;
    this->videomode.width = 800;

    this->window = new sf::RenderWindow(videomode,"My First Game!",sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144); // FPS REQUESTİNG - but it may not always certain.

}

void Practice::initEnemies()
{
    this->enemy.setPosition(450.f,345.f);
    this->enemy.setSize(sf::Vector2f(100.f,50.f));
    this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    //this->enemy.setOutlineColor(sf::Color::Green);
    //this->enemy.setOutlineThickness(1.f);
}


// Constructors and Destructors
Practice::Practice()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}

Practice::~Practice()
{
    delete this->window; // if you use pointer variable , after you use , you should delete it
}
// Accessors
const bool Practice::running() const
{
    return this->window->isOpen();
}
// Functions

void Practice::spawnEnemy() {
    /**
        @return void
        Spawns enemies and sets their colors and positions.
        -Sets a random position.
        -Sets a random color.
        -Adds enemy to the vector.
     */
    this->enemy.setPosition(
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)), // [0,RAND_MAX)  return random number
            static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
    );

    this->enemy.setFillColor(sf::Color::Red);

    // Spawn the enemy
    this->enemies.push_back(this->enemy); // Vector
}

void Practice::pollEvents()
{
    while(this->window->pollEvent(this->evnt))
    {
        switch (this->evnt.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;

            case sf::Event::KeyPressed:
                if(this->evnt.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                    break;
                }

        }
    }
}

void Practice::updateMousePositions()
{
    // Update the mouse positions
    // mouse position relative to window (Vector2i)
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Practice::updateEnemies()
{

    /**
        Updates the enemy spawn timer and spawns enemies
        when the total amount of enemies is smaller than the maximum.
        Moves the enemies downwards.
        Removes the enemies at the edge of the screen
    */

    // Updating the timer for enemy spawning
    if(this->enemies.size() < this->maxEnemies)
    {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            //Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f; // RESET
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    for(int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false ;
        this->enemies[i].move(0.f,5.f);

        // Check if clicked upon
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
            {
                // Delete the enemy
                this->enemies.erase(this->enemies.begin() +i);
            }
        }

        // If the enemy is past the bottom of the screen
        if(this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            deleted = true;

            this->points += 10.f;
        }
        if(deleted)
            this->enemies.erase(this->enemies.begin() +i);
    }
}

void Practice::update()
{
    this->pollEvents();
    this->updateMousePositions();
    this->updateEnemies();

}

void Practice::renderEnemies()
{
    // Rendering all the enemies - draw on the screen
    for(auto &e : this->enemies)
    {
        this->window->draw(e);

    }
}

void Practice::render()
{
    /*
     -clear old frame
     -render objects
     -display frame in window
     Render the game objects
      */
    this->window->clear();
    // Draw game objects
    this->renderEnemies();

    this->window->display();
}




