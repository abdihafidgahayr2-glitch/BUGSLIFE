#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"
#include <fstream>
#include <sstream>
#include <iostream>

Board::~Board() {
    for (Bug* b : bugs) delete b;
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

// Stubs for other methods (will be implemented later)
void Board::displayAllBugs() const {}
Bug* Board::findBugById(int id) const { return nullptr; }
void Board::tapBoard() {}
void Board::displayLifeHistories() const {}
void Board::displayCells() const {}
void Board::runSimulation() {}
void Board::writeLifeHistoriesToFile(const std::string& filename) const {}
int Board::aliveCount() const { return 0; }