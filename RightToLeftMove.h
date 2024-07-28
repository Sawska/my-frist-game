#ifndef RIGHTTOLEFTMOVE_H
#define RIGHTTOLEFTMOVE_H

#include "MoveStrategy.h"

class RightToLeftMove : public MoveStrategy {
public:
    void move(int& x, int& y) const override {
        x--;
    }
};

#endif // RIGHTTOLEFTMOVE_H
