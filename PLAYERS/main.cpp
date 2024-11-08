#include <iostream>
#include "players.h"

int main() {
    Players players;
    const int startingBalance = 1500; // Example starting money for Monopoly

    players.setupPlayers(startingBalance);
    players.displayPlayers();

    return 0;
}
