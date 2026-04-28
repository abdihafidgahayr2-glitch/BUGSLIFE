#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;
public:
    Hopper(int id, int x, int y, int dir, int health, int hopLen);
    void move() override;
    std::string getType() const override { return "Hopper"; }
    std::string getExtraInfo() const override { return std::to_string(hopLength); }
};

#endif