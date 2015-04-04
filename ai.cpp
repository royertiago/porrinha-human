#include <iostream>
#include "human_player.h"
#include "ai.h"

namespace human_player {

    Player * generate( int /*players*/, int /*chopsticks*/ ) {
        std::string name;
        std::cout << "Type the player's name:\n";
        std::getline( std::cin, name );
        return new HumanPlayer( name );
    }

} // namespace human_player
