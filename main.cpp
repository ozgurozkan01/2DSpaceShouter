
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{

    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;

    // Game Loop
    while(game.running())
    {
        //Update
        game.update();

        //Render
        game.render();
    }

    return 0;
}
