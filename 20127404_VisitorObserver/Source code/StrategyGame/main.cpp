// 20127404
// NGUYEN TRUNG NGUYEN
// 20CLC07

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "randomIntegerGenerator.h"
using namespace std;

//Random Integer Generator
auto _rig = RandomIntegerGenerator::instance();

// Forward declaration
class Character;
class Swordman;
class Knight;
class Pikeman;
class IVisitable;
class State;
class NormalState;
class SuperSwordmanState;
class SuperKnightState;
class SuperPikemanState;
class Player;
class Game;
class Rule;
class SuperSwordmanRule;
class SuperKnightRule;
class SuperPikemanRule;

// Class declaration

class Character {
protected:
    int _hp;
    int _atk;
    State* _state;
public:
    Character(int hp, int atk);
    int hp() { return _hp; }
    int atk() { return _atk; }
    void setState(State*);
    void setHp(int value) { _hp = value > 0 ? value : 0; }
    void setAtk(int value) { _atk = value; }
    bool isAlive() { return _hp > 0; }

    virtual void attack(Character* opponent) = 0;
    virtual string toString() = 0;
};


class IVisitable {
public:
    virtual void attack(Swordman&) = 0;
    virtual void attack(Knight&) = 0;
    virtual void attack(Pikeman&) = 0;
    virtual void hitBy(Swordman&) = 0;
    virtual void hitBy(Knight&) = 0;
    virtual void hitBy(Pikeman&) = 0;

    void select(Character*);
};

class Swordman : public Character, public IVisitable {
public:
    Swordman(int, int);
    string toString();
    void attack(Swordman&);
    void attack(Knight&);
    void attack(Pikeman&);
    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Pikeman&);

    void attack(Character*);
};

class Knight : public Character, public IVisitable {
public:
    Knight(int, int);
    string toString();
    void attack(Swordman&);
    void attack(Knight&);
    void attack(Pikeman&);
    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Pikeman&);

    void attack(Character*);
};

class Pikeman : public Character, public IVisitable {
public:
    Pikeman(int, int);
    string toString();
    void attack(Swordman&);
    void attack(Knight&);
    void attack(Pikeman&);
    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Pikeman&);

    void attack(Character*);
};

class State {
public:
    virtual int transformHp(int old) = 0;
    virtual int transformAtk(int old) = 0;
};

class NormalState : public State {
public:
    int transformHp(int old);
    int transformAtk(int old);
    
};

class SuperSwordmanState : public State {
    int transformHp(int old);
    int transformAtk(int old);
    
};

class SuperKnightState : public State {
    int transformHp(int old);
    int transformAtk(int old);
    
};

class SuperPikemanState : public State {
    int transformHp(int old);
    int transformAtk(int old);
    
};

class Player {
public:
    vector<Character*> pieces;

    typedef void (Game::* CheckCallBack) (Player*);
    CheckCallBack checker = NULL;

public:
    void add(Character*);
    string toString();
};

class Game {
private:
    Player _player1;
    Player _player2;
    vector<Rule*> _rules;
public:
    Game();
    void start();
    void play(int&, int&, int&); // hai nguoi choi danh nhau
    void checkRule(Player*);
    void apply(Player*);
    string toString();
};

class Rule {
public:
    virtual bool satisfyWith(Player*) = 0;
    virtual void apply(Player*) = 0;
};

class SuperSwordmanRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};

class SuperKnightRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};

class SuperPikemanRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};


// Class implementation
// ---- Character -----
Character::Character(int hp, int atk) {
    _hp = hp;
    _atk = atk;
    _state = new NormalState();
}

void Character::setState(State* value) { _state = value; }

// ---- IVisitable ----
void IVisitable::select(Character* opponent) {
    if (typeid(*opponent) == typeid(Swordman)) {
        attack(*((Pikeman*)opponent));
    }
    else if (typeid(*opponent) == typeid(Knight)) {
        attack(*((Swordman*)opponent));
    }
    else if (typeid(*opponent) == typeid(Pikeman))
    {
        attack(*((Knight*)opponent));
    }
}

// ---- Swordman -----
Swordman::Swordman(int hp, int atk): Character(hp, atk) {}

string Swordman::toString() {
    stringstream builder;
    builder << "Swordman HP: " << hp()
        << " ATK: " << atk();

    string result = builder.str();
    return result;
}
void Swordman::attack(Swordman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Swordman&)
    }
}
void Swordman::attack(Knight& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Swordman::attack(Pikeman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}

void Swordman::attack(Character* opponent)
{
    select(opponent);
}

void Swordman::hitBy(Swordman& opponent) {
    int newHp = _hp - opponent.atk();
    setHp(newHp);
}
void Swordman::hitBy(Knight& opponent) {
    int newHp = _hp - (opponent.atk() + 10);
    setHp(newHp);
}
void Swordman::hitBy(Pikeman& opponent) {
    int newHp = _hp - opponent.atk();
    setHp(newHp);
}

// ---- Knight -----
Knight::Knight(int hp, int atk) :Character(hp, atk) {}
string Knight::toString() {
    stringstream builder;
    builder << "Knight HP: " << hp()
        << " ATK: " << atk();

    string result = builder.str();
    return result;
}
void Knight::attack(Swordman& opponent) {
    opponent.hitBy(*this); // this: Knight*,  *this: Knight

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Swordman&)
    }
}
void Knight::attack(Knight& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Knight::attack(Pikeman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}

void Knight::attack(Character* opponent)
{
    select(opponent);
}

void Knight::hitBy(Swordman& opponent) {
    int newHp = _hp - opponent.atk();
    setHp(newHp);
}
void Knight::hitBy(Knight& opponent) {
    int newHp = _hp - opponent.atk();
    setHp(newHp);
}
void Knight::hitBy(Pikeman& opponent) {
    int newHp = _hp - (opponent.atk() + 25);
    setHp(newHp);
}

// ----- Pikeman -----
Pikeman::Pikeman(int hp, int atk) : Character(hp, atk) {}
string Pikeman::toString() {
    stringstream builder;
    builder << "Pikeman HP: " << hp()
        << " ATK: " << atk();

    string result = builder.str();
    return result;
}
void Pikeman::attack(Swordman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}

void Pikeman::attack(Knight& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Pikeman::attack(Pikeman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}

void Pikeman::attack(Character* opponent)
{
    select(opponent);
}

void Pikeman::hitBy(Swordman& opponent) {
    int newHp = _hp - (opponent.atk() + 12);
    setHp(newHp);
}
void Pikeman::hitBy(Knight& opponent) {
    int newHp = _hp - opponent.atk();
    setHp(newHp);
}
void Pikeman::hitBy(Pikeman& opponent) {
    int newHp = _hp - opponent.atk();
    setHp(newHp);
}

// ---- States
int NormalState::transformHp(int old) {
    return old;
}
int NormalState::transformAtk(int old) {
    return old;
}


//--------SWORDMAN siêu cấp vô địch
// Three swordmen in the field, each swordman will have a bonus of tripling (3x) its current ATK.
int SuperSwordmanState::transformAtk(int old)
{
    return old * 3;
}

int SuperSwordmanState::transformHp(int old)
{
    return old;
}



//--------KNIGHT siêu cấp vô địch
// Three Knights on the fields, each Knight will have a bonus of 2x its current ATK.
int SuperKnightState::transformHp(int old)
{
    return old;
}

int SuperKnightState::transformAtk(int old)
{
    return old * 2;
}



//--------PIKEMAN siêu cấp vô địch
// Three spikemen on the fields, each spikeman will have a bonus of 5x its current ATK, 2x its current HP.
int SuperPikemanState::transformHp(int old)
{
    return old * 2;
}

int SuperPikemanState::transformAtk(int old)
{
    return old * 5;
}


// -------Player----------------
void Player::add(Character* item) {
    pieces.push_back(item);
}

string Player::toString() {
    stringstream builder;
    builder << "Player info:" << endl;
    for (int i = 0; i < pieces.size(); i++) {
        builder << "     + " << pieces[i]->toString() << endl;
    }

    string result = builder.str();
    return result;
}

Game::Game() {
    _rules.push_back(new SuperSwordmanRule());
    _rules.push_back(new SuperKnightRule());
    _rules.push_back(new SuperPikemanRule());

    _player1.checker = &Game::checkRule;
    _player2.checker = &Game::checkRule;
}

void Game::checkRule(Player* player) {
    for (int i = 0; i < _rules.size(); i++) {
        if (_rules[i]->satisfyWith(player)) {
            _rules[i]->apply(player);
        }
    }
}

void Game::start() {
    // Generate randomly three chess pieces of three types Swordman, Spikeman and Knight for each team.
    for (int i = 0; i < 3; i++)
    {
        int p1_luckyNumber = _rig->next(1, 3);
        int p2_luckyNumber = _rig->next(1, 3);

        // Player 01 
        if (p1_luckyNumber == 1)
        {
            _player1.add(new Swordman(1000, 12));
        }
        else if (p1_luckyNumber == 2)
        {
            _player1.add(new Pikeman(800, 8));
        }
        else {
            _player1.add(new Knight(1500, 18));
        }

        // Player 02
        if (p2_luckyNumber == 1)
        {
            Character* create = new Swordman(1000, 12);
            _player2.add(create);
        }
        else if (p2_luckyNumber == 2)
        {
            _player2.add(new Pikeman(800, 8));
        }
        else {
            _player2.add(new Knight(1500, 18));
        }
    }

   
    checkRule(&_player1);
    checkRule(&_player2);
}

void Game::play(int &goFirst, int &blueTurn, int &redTurn) {
    // Random to decide which team will go first.
    if (goFirst == 1)
    {
        // Blue go first
        for (int i = 0; i < _player1.pieces.size(); i++)
        {
            _player1.pieces[i]->attack(_player2.pieces[i]);

        }
        goFirst = 0;
        redTurn = 1;
        blueTurn = 0;
    }
    else if (goFirst == 2)
    {
        //Red go first
        for (int i = 0; i < _player1.pieces.size(); i++)
        {
            _player2.pieces[i]->attack(_player1.pieces[i]);
            goFirst = 0;
            blueTurn = 1;
            redTurn = 0;
        }
    }
    else {
        if (blueTurn == 1)
        {
            for (int i = 0; i < _player1.pieces.size(); i++)
            {
                _player1.pieces[i]->attack(_player2.pieces[i]);
            }
            blueTurn = 0;
            redTurn = 1;
        }
        else if (redTurn == 1)
        {
            for (int i = 0; i < _player1.pieces.size(); i++)
            {
                _player2.pieces[i]->attack(_player1.pieces[i]);
            }
            blueTurn = 1;
            redTurn = 0;
        }
    }
    
}

string Game::toString() {
    stringstream builder;
    builder << "Blue team: " << endl;
    builder << _player1.toString() << endl;
    builder << "Red team: " << endl;
    builder << _player2.toString() << endl;

    string result = builder.str();
    return result;
}

// ---- SUPER_WARRIOR RULE
bool SuperSwordmanRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->pieces.size(); i++) {
        if (typeid(*(player->pieces[i])) == typeid(Swordman)) {
            count++;
        }
    }

    bool result = count == 3;
    return result;
}

void SuperSwordmanRule::apply(Player* player) {
    for (int i = 0; i < player->pieces.size(); i++) {
        player->pieces[i]->setState(new SuperSwordmanState());
    }
}

bool SuperKnightRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->pieces.size(); i++) {
        if (typeid(*(player->pieces[i])) == typeid(Knight)) {
            count++;
        }
    }

    bool result = count == 3;
    return result;
}

void SuperKnightRule::apply(Player* player) {
    for (int i = 0; i < player->pieces.size(); i++) {
        player->pieces[i]->setState(new SuperKnightState());
    }
}

bool SuperPikemanRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->pieces.size(); i++) {
        if (typeid(*(player->pieces[i])) == typeid(Knight)) {
            count++;
        }
    }

    bool result = count == 3;
    return result;
}

void SuperPikemanRule::apply(Player* player) {
    for (int i = 0; i < player->pieces.size(); i++) {
        player->pieces[i]->setState(new SuperKnightState());
    }
}

int main() {
    
    Game game;
    game.start();

    cout << "Begin" << endl;
    cout << game.toString() << endl;
    cout << endl;

    int goFirst = _rig->next(1, 2);
    int blueTurn = 0, redTurn = 0;
    for (int i = 0; i < 3; i++)
    {
        if (goFirst == 1) cout << "Blue team is attacking" << endl;
        else if (goFirst == 2) cout << "Red team is attacking" << endl;
        game.play(goFirst, blueTurn, redTurn);        
        cout << (blueTurn == 1 ? "Blue team is attacking" : "Red team is attacking") << endl;
    }
    cout << endl << "After 3 turn:" << endl;
    cout << game.toString();
    
    cin.get();
    return 0;
}
