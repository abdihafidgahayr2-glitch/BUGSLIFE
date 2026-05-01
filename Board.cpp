#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

Board::~Board() {
    for (Bug* b : bugs) delete b;
}

int Board::aliveCount() const {
    int count = 0;
    for (Bug* b : bugs) if (b->isAlive()) count++;
    return count;
}

void Board::initializeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open " << filename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(ss, token, ';')) {
            tokens.push_back(token);
        }
        if (tokens.size() < 6) continue;
        char type = tokens[0][0];
        int id = std::stoi(tokens[1]);
        int x = std::stoi(tokens[2]);
        int y = std::stoi(tokens[3]);
        int dir = std::stoi(tokens[4]);
        int health = std::stoi(tokens[5]);

        if (type == 'C') {
            bugs.push_back(new Crawler(id, x, y, dir, health));
        } else if (type == 'H') {
            int hopLen = std::stoi(tokens[6]);
            bugs.push_back(new Hopper(id, x, y, dir, health, hopLen));
        }
    }
    file.close();
    std::cout << "Loaded " << bugs.size() << " bugs.\n";
}

// Stubs for other methods
void Board::displayAllBugs() const {
    for (Bug* b : bugs) {
        std::cout << b->getId() << " " << b->getType() << " ("
                  << b->getPosition().first << "," << b->getPosition().second << ") "
                  << b->getHealth() << " ";
        switch(b->getDirection()) {
            case 1: std::cout << "North"; break;
            case 2: std::cout << "East"; break;
            case 3: std::cout << "South"; break;
            case 4: std::cout << "West"; break;
        }
        std::string extra = b->getExtraInfo();
        if (!extra.empty()) std::cout << " " << extra;
        std::cout << " " << (b->isAlive() ? "Alive" : "Dead") << std::endl;
    }
}

Bug* Board::findBugById(int id) const {
    for (Bug* b : bugs) {
        if (b->getId() == id) return b;
    }
    return nullptr;
}

void Board::tapBoard() {
    // freeze one random bug
    int freezeIndex = -1;
    if (!bugs.empty()) freezeIndex = rand() % bugs.size();

    // Move all (except frozen)
    for (size_t i = 0; i < bugs.size(); ++i) {
        if (freezeIndex != -1 && i == static_cast<size_t>(freezeIndex)) {
            std::cout << "Bug " << bugs[i]->getId() << " is frozen this tap.\n";
            continue;
        }
        if (bugs[i]->isAlive()) bugs[i]->move();
    }

    // ---- FIGHT ----
    // Group bugs by cell
    std::map<std::pair<int,int>, std::vector<Bug*>> cellMap;
    for (Bug* b : bugs) {
        if (b->isAlive()) {
            cellMap[b->getPosition()].push_back(b);
        }
    }
    // Fight in each cell
    for (auto& entry : cellMap) {
        auto& occupants = entry.second;
        if (occupants.size() <= 1) continue;
        // Pair them (take two at a time)
        for (size_t i = 0; i+1 < occupants.size(); i += 2) {
            Bug* a = occupants[i];
            Bug* b = occupants[i+1];
            for (int round = 0; round < 3; ++round) {
                int dmgA = rand() % 6;
                int dmgB = rand() % 6;
                a->setHealth(a->getHealth() - dmgA);
                b->setHealth(b->getHealth() - dmgB);
                if (!a->isAlive() || !b->isAlive()) break;
            }
            std::cout << "Fight between " << a->getId() << " and " << b->getId() << " ended.\n";
        }
        // Odd one out stays unscathed
    }
    std::cout << "Tap complete. " << aliveCount() << " bugs alive.\n";
}
// Display path history for each bug
void Board::displayLifeHistories() const {
    for (Bug* b : bugs) {
        std::cout << b->getId() << " " << b->getType() << " Path: ";
        for (const auto& pos : b->getPath()) {
            std::cout << "(" << pos.first << "," << pos.second << ") ";
        }
        if (b->isAlive())
            std::cout << "Alive!" << std::endl;
        else
            std::cout << "Dead" << std::endl;
    }
}

void Board::displayCells() const {
}

void Board::runSimulation() {
}

void Board::writeLifeHistoriesToFile(const std::string& filename) const {

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: cannot write to " << filename << std::endl;
        return;
    }
    for (Bug* b : bugs) {
        outFile << b->getId() << " " << b->getType() << " Path: ";
        for (const auto& pos : b->getPath()) {
            outFile << "(" << pos.first << "," << pos.second << ") ";
        }
        if (b->isAlive())
            outFile << "Alive!" << std::endl;
        else
            outFile << "Dead" << std::endl;
    }
    outFile.close();
    std::cout << "Life histories written to " << filename << std::endl;

}