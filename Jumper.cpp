
#include "Jumper.h"
#include <cstdlib>


Jumper::Jumper(int id, int x, int y, int dir, int health, int dist)
    : Bug(id, x, y, dir, health), jumpDistance(dist) {}

void Jumper::move() {
    if (!alive) return;

    int newX = position.first;
    int newY = position.second;

    for (int step = 0; step < jumpDistance; ++step) {
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
            // Blocked – rotate 90° clockwise and restart the jump
            direction = (direction % 4) + 1;
            newX = position.first;
            newY = position.second;
            step = -1;  // restart loop
        }
    }

    position = {newX, newY};
    addToPath();
}