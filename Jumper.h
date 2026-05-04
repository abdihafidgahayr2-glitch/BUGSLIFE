

#ifndef BUGSLIFE_JUMPER_H
#define BUGSLIFE_JUMPER_H

#include "Bug.h"

class Jumper : public Bug {

private:

    int jumpDistance;  // 2-4 units
public:
    Jumper(int id, int x, int y, int dir, int health, int dist);
    void move() override;
    std::string getType() const override { return "Jumper"; }
    std::string getExtraInfo() const override { return std::to_string(jumpDistance); }
};


#endif //BUGSLIFE_JUMPER_H