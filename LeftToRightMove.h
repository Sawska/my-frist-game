#ifndef LEFTTORIGHTMOVE_H
#define LEFTTORIGHTMOVE_H

#include "MoveStrategy.h"

class LeftToRightMove : public MoveStrategy {
public:
    void move(int& x, int& y) const override {
        x++;
    }
};

#endif // LEFTTORIGHTMOVE_H

