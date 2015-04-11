#include <cstdio>
#include <iostream>
#include "human_player.h"
#include "ai.h" // This include must come latter because it does not define Player*.

namespace human_player {

    const char help_message[] =
"[human] options\n"
"Creates an \"artifficial intelligence\" that is controlled by an human,\n"
"through interaction in the terminal.\n"
"\n"
"Options:\n"
"--name <player_name>\n"
"    Defines the player name, instead of asking to the user.\n"
"\n"
"--help\n"
"    Display this help and quit.\n"
;

    Player * generate( cmdline::args&& args ) {
        std::string name;
        bool name_set = false;

        while( args.size() > 0 ) {
            std::string arg = args.next();
            if( arg == "--help" ) {
                std::cout << help_message;
                std::exit(0);
            }
            if( arg == "--name" ) {
                if( args.size() == 0 ) {
                    std::cout << "No name supplied in command line.";
                    std::exit(1);
                }
                name = args.next();
                name_set = true;
                continue;
            }
            std::cout << args.program_name() << ": unrecognized option " << arg << '\n';
            std::exit(1);
        }

        if( !name_set ) {
            std::cout << "Type the player's name:\n";
            std::getline( std::cin, name );
        }

        return new HumanPlayer( name );
    }

} // namespace human_player
