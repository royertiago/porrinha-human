#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

namespace human_player {

    class HumanPlayer : public Player {
        std::string _name;
    public:
        HumanPlayer( std::string name );

        /* Overriden methods */
        std::string name() const override;
        void begin_game() override;
        int hand() override;
        int guess() override;
        void end_round() override;
        void end_game() override;
    };

} // namespace human_player

#endif // HUMAN_PLAYER_H
