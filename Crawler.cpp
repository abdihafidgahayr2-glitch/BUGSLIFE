#include "Crawler.h"
#include <cstdlib>
#include <ctime>

Crawler::Crawler(int id, int x, int y, int dir, int health)
    : Bug(id, x, y, dir, health) {}

void Crawler::move() {
    if (!alive) return;
    int newX = position.first;
    int newY = position.second;
    switch(direction) {
        case 1: newY--; break;
        case 2: newX++; break;
        case 3: newY++; break;
        case 4: newX--; break;
    }
    if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
        position = {newX, newY};
    } else {
        // blocked: change direction randomly until we can move
        while (isWayBlocked()) {
            direction = (rand() % 4) + 1;
        }
        newX = position.first;
        newY = position.second;
        switch(direction) {
            case 1: newY--; break;
            case 2: newX++; break;
            case 3: newY++; break;
            case 4: newX--; break;
        }
        position = {newX, newY};
    }
    addToPath();
}