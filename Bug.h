#ifndef BUG_H
#define BUG_H

#include <utility>
#include <list>
#include <string>

class Bug {
protected:
    int id;
    std::pair<int, int> position;  // (x,y) 0..9
    int direction;                 // 1=N,2=E,3=S,4=W
    int health;
    bool alive;
    std::list<std::pair<int,int>> path;

public:
    Bug(int id, int x, int y, int dir, int health);
    virtual ~Bug() {}

    // Getters
    int getId() const { return id; }
    std::pair<int,int> getPosition() const { return position; }
    int getHealth() const { return health; }
    bool isAlive() const { return alive; }
    int getDirection() const { return direction; }
    const std::list<std::pair<int,int>>& getPath() const { return path; }

    // Setters
    void setHealth(int h);
    void setAlive(bool a) { alive = a; }
    void setDirection(int d) { direction = d; }
    void setPosition(int x, int y) { position = {x,y}; }

    bool isWayBlocked() const;
    void addToPath();

    // Pure virtual
    virtual void move() = 0;
    virtual std::string getType() const = 0;
    virtual std::string getExtraInfo() const { return ""; }
};

#endif