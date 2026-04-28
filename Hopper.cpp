#include "Hopper.h"
#include <cstdlib>

Hopper::Hopper(int id, int x, int y, int dir, int health, int hopLen)
    : Bug(id, x, y, dir, health), hopLength(hopLen) {}

void Hopper::move() {
    if (!alive) return;
    int newX = position.first;
    int newY = position.second;
    // try full hop
    for (int step = 0; step < hopLength; ++step) {
        int nextX = newX, nextY = newY;
        switch(direction) {
            case 1: nextY--; break;
            case 2: nextX++; break;
            case 3: nextY++; break;
            case 4: nextX--; break;
        }
        if (nextX >= 0 && nextX < 10 && nextY >= 0 && nextY < 10) {
            newX = nextX;
            newY = nextY;
        } else {
            // hit wall: stop moving, fall on last valid cell
            break;
        }
    }
    // if no movement possible (blocked at first step), change direction and retry full hop
    if (newX == position.first && newY == position.second) {
        while (isWayBlocked()) {
            direction = (rand() % 4) + 1;
        }
        // retry full hop
        newX = position.first; newY = position.second;
        for (int step = 0; step < hopLength; ++step) {
            int nextX = newX, nextY = newY;
            switch(direction) {
                case 1: nextY--; break;
                case 2: nextX++; break;
                case 3: nextY++; break;
                case 4: nextX--; break;
            }
            if (nextX >= 0 && nextX < 10 && nextY >= 0 && nextY < 10) {
                newX = nextX;
                newY = nextY;
            } else break;
        }
    }
    position = {newX, newY};
    addToPath();
}