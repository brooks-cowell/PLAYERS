#include "players.h"

Player::Player(const std::string& name, int startingBalance)
    : name(name), balance(startingBalance), position(0) {}

std::string Player::getName() const {
    return name;
}

int Player::getBalance() const {
    return balance;
}

int Player::getPosition() const {
    return position;
}

void Player::movePosition(int spaces) {
    position = (position + spaces) % 40; // Wrap around the board if necessary
}

void Player::adjustBalance(int amount) {
    balance += amount;
}

void Players::setupPlayers(int startingBalance) {
    int numPlayers;
    std::cout << "Enter the number of players: ";
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; ++i) {
        std::string name;
        std::cout << "Enter the name for player " << (i + 1) << ": ";
        std::cin >> name;
        playerList.emplace_back(name, startingBalance);
    }

    if (numPlayers > 6) {
        createTeams();
    }
    else {
        numTeams = numPlayers;
    }
}

void Players::createTeams() {
    int numPlayers = playerList.size();
    numTeams = std::min(6, numPlayers);
    int baseTeamSize = numPlayers / numTeams;
    int extraPlayers = numPlayers % numTeams;

    // Prompt for team names
    std::cout << "Enter names for each team:\n";
    teamNames.resize(numTeams);
    for (int i = 0; i < numTeams; ++i) {
        std::cout << "Enter name for Team " << (i + 1) << ": ";
        std::cin >> teamNames[i];
    }

    teams.resize(numTeams);
    int playerIndex = 0;
    for (int i = 0; i < numTeams; ++i) {
        for (int j = 0; j < baseTeamSize; ++j) {
            teams[i].push_back(playerList[playerIndex++]);
        }
    }

    std::srand(static_cast<unsigned>(std::time(0)));
    for (int i = 0; i < extraPlayers; ++i) {
        int randomTeam = std::rand() % numTeams;
        teams[randomTeam].push_back(playerList[playerIndex++]);
    }
}

void Players::displayPlayers() {
    if (playerList.size() <= 6) {
        std::cout << "\nPlayers in the game:\n";
        for (const Player& player : playerList) {
            std::cout << player.getName() << " (Balance: $" << player.getBalance() << ", Position: " << player.getPosition() << ")\n";
        }
    }
    else {
        std::cout << "\nTeams in the game:\n";
        for (size_t i = 0; i < teams.size(); ++i) {
            std::cout << teamNames[i] << " (Team " << (i + 1) << "): ";
            for (const Player& player : teams[i]) {
                std::cout << player.getName() << " ";
            }
            std::cout << std::endl;
        }
    }
}

int Players::numPlayers() const {
    return playerList.size();
}
