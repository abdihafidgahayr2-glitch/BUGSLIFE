#include "Bug.h"

Bug::Bug(int id, int x, int y, int dir, int health)
    : id(id), position({x,y}), direction(dir), health(health), alive(true) {
    addToPath();  // record starting position
}

void Bug::setHealth(int h) {
    health = h;
    if (health <= 0) alive = false;
}

bool Bug::isWayBlocked() const {
    int x = position.first;
    int y = position.second;
    if (direction == 1 && y == 0) return true;
    if (direction == 2 && x == 9) return true;
    if (direction == 3 && y == 9) return true;
    if (direction == 4 && x == 0) return true;
    return false;
}

void Bug::addToPath() {
    path.push_back(position);
}