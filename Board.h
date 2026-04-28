#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Bug.h"

class Board {
private:
    std::vector<Bug*> bugs;
public:
    ~Board();
    void initializeFromFile(const std::string& filename);
    void displayAllBugs() const;
    Bug* findBugById(int id) const;
    void tapBoard();
    void displayLifeHistories() const;
    void displayCells() const;
    void runSimulation();
    void writeLifeHistoriesToFile(const std::string& filename) const;
    int aliveCount() const;
};

#endif