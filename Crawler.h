#ifndef CRAWLER_H
#define CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(int id, int x, int y, int dir, int health);
    void move() override;
    std::string getType() const override { return "Crawler"; }
};

#endif