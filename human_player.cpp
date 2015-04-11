#include <iostream>
#include <limits>

#include "human_player.h"
#include "core/util.h"

namespace human_player {

HumanPlayer::HumanPlayer( std::string name ) :
    _name(name)
{}

void HumanPlayer::begin_game() {
    // no-op
}

void HumanPlayer::end_game() {
    // no-op
}

void HumanPlayer::end_round() {
    for( unsigned i = 0; i < core::player_count(); i++ )
        std::cout << "Player " << i << " guessed " << core::guess(i)
            << " and played " << core::hand(i) << " choptsicks.\n";
}

std::string HumanPlayer::name() const {
    return _name;
}

int HumanPlayer::hand() {
    int my_index = core::index( this );

    std::cout << "Human " << _name << ", type how many chopsticks"
        << " you will use this round: ";
    int hand;

    while( true ) {
        std::cin >> hand;
        if( !std::cin ) {
            std::cout << "Please type a number: ";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            continue;
        }
        if( hand > core::chopsticks(my_index) ) {
            std::cout << "You have only " << core::chopsticks(my_index)
                << " chopsticks.\n"
                << "Type a valid number of chopsticks: ";
            continue;
        }
        if( hand < 0 ) {
            std::cout << "You cannot play a negative number of chopsticks!\n"
                << "Type a valid number of chopsticks: ";
            continue;
        }
        break;
    }
    return hand;
}

int HumanPlayer::guess() {
    for( unsigned i = 0; i < core::player_count(); i++ ) {
        if( core::guess(i) >= 0 )
            std::cout << "Player " << i << " guessed " 
                      << core::guess(i) << ".\n";
    }

    std::cout << "Human " << _name << ", type your guess for this round: ";
    int guess;
    while( true ) {
        std::cin >> guess;
        if( !std::cin ) {
            std::cout << "Please type a number: ";
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
            continue;
        }
        if( guess < 0 ) {
            std::cout << "Your cannot guess a negative number of chopsticks!\n"
                << "Type a valid guess. ";
            continue;
        }
        if( guess > core::chopstick_count() ) {
            std::cout << "There are only " << core::chopstick_count()
                << " chopsticks in the table.\n"
                << "Type a smaller guess. ";
            continue;
        }
        if( !core::valid_guess(guess) ) {
            std::cout << "Another player already guessed this value.\n"
                << "Type another guess. ";
            continue;
        }
        break;
    }
    return guess;
}

} // namespace human_player
