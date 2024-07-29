#ifndef MOVESTRATEGY_H
#define MOVESTRATEGY_H

class MoveStrategy {
public:
    virtual ~MoveStrategy() = default;
    virtual void move(int& x, int& y) const = 0;
};

#endif // MOVESTRATEGY_H
