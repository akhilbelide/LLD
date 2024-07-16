#include<iostream>
#include<vector>
using namespace std;

class Wicket;

class Person{
    public:
    int age;
    string name;
};

enum BattingStyle{
    LEFT_HANDED,
    RIGHT_HANDED
};

enum BowlingStyle{
    RIGHT_ARM_FAST,
    RIGHT_ARM_LEG_SPIN,
    LEFT_ARM_FAST,
    LEFT_ARM_OFF_SPIN,
};

class BattingScoreCard{
    public:
    int runs;
    int bowls_faced;
    int fours;
    int sixes;
    Wicket *wkt_details;
};

class BowlingScoreCard{
    public:
    int bowls_balled;
    int runs_given;
    int wickets_taken;
    int maidens;
};

class Player{
    public:
    Person *p;
    BattingStyle bat_style;
    BowlingStyle bowl_style;
    bool isWK;
    bool isCaptain;
    BattingScoreCard *bat_card;
    BowlingScoreCard *bowl_card;
};

class BattingController{

};

class BowlingController{
    public:
    vector<Player*> bowlers;
};

class Team{
    public:
    vector<Player*> *players;
    BattingController *bat_controller;
    BowlingController *bowl_controller; 
};

enum BallType{
    NORMAL,
    EXTRAS
};

enum RunType{
    ONE,
    TWO,
    WIDE,
    THREE,
    NO_BALL,
    FOUR,
    SIX
};

enum WicketType{
    BOWLED,
    CAUGHT,
    LBW
};

class Wicket{
    public:
    Player *bowler;
    WicketType type;
};


class ScoreCardUpdaterObserver{
    public:
    virtual void update(Ball *ball_details)=0;
};

class Ball{
    public:
    BallType ball_type;
    RunType run_type;
    Player *batter;
    Player *bowler;
    Wicket *wkt;
    vector<ScoreCardUpdaterObserver*> *updaters;

    void notify(){

    }
};

class Overs{
    public:
    vector<Ball*> balls;
};

class Inning{
    public:
    Team *batiing_team;
    Team *bowling_team;
    vector<Overs*> overs;
};

class MatchType{
    public:
    virtual int number_of_overs()=0;
    virtual int max_overs_per_bowler()=0;
};

class T20Match : public MatchType{
    public:
    int number_of_overs(){
        return 20;
    }
    int max_overs_per_bowler(){
        return 4;
    }
};

class ODIMatch : public MatchType{
    public:
    int number_of_overs(){
        return 50;
    }
    int max_overs_per_bowler(){
        return 10;
    }
};

class TestingMatch : public MatchType{
    public:
    int number_of_overs(){
        return 4;
    }
    int max_overs_per_bowler(){
        return 1;
    }
};


class BowlingCardUpdater : public ScoreCardUpdaterObserver{
    void update(Ball *ball_details){

    }
};  

class BattingCardUpdater : public ScoreCardUpdaterObserver{
    void update(Ball *ball_details){

    }
};


class Match{
    public:
    string venue; // or even create a class to hold the venue details
    Team *A;
    Team *B;
    vector<Inning*> *innings;
    Team toss_winner;
    MatchType *type;

    Match(string _venue, Team *_A, Team *_B, MatchType *type){

    }
};


int main(){
    //Match *match1 = new Match("Eden Gardens", TeamA, TeamB, new T20Match());
    return 0;
}