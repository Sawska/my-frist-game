#ifndef MOVESTRATEGY_H
#define MOVESTRATEGY_H

class MoveStrategy {
public:
    virtual void move(int& x, int& y) const = 0;
    virtual ~MoveStrategy() = default;
};

#endif // MOVESTRATEGY_H
