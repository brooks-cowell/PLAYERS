#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

class Player {
public:
    Player(const std::string& name, int startingBalance);
    std::string getName() const;
    int getBalance() const;
    int getPosition() const;
    void movePosition(int spaces);
    void adjustBalance(int amount);

private:
    std::string name;
    int balance;
    int position;
};

class Players {
public:
    void setupPlayers(int startingBalance);
    void createTeams();
    void displayPlayers();
    int numPlayers() const;

private:
    std::vector<Player> playerList;
    std::vector<std::vector<Player>> teams;
    std::vector<std::string> teamNames;
    int numTeams;
};

#endif // PLAYERS_H
