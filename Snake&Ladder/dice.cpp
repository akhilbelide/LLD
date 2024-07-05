#include "dice.h"
#include<time.h>
#include <cstdlib>
using namespace std;

Dice::Dice(int _min, int _max){
        min=_min;
        max=_max;
    }

int Dice::rollDice(){
    srand(time(0));
    int num = min + (rand()%(max-min+1));
    return num;
}