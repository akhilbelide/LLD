using namespace std;

#ifndef DICE_H
#define DICE_H

class Dice{
    public:
    int min;
    int max;

    Dice(int _min, int _max);

    int rollDice();
};

#endif