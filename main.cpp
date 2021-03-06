#include "Game.h"

#include <iostream>

int main()
{
    srand(time(0));

    try {
        Game game;
        game.run();
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
