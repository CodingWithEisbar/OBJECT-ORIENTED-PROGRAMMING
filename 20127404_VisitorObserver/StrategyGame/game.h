#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
using namespace std;

class CHARACTER {
protected:
	int _hp;
	int _atk;
	int _def;
	STATE* _state;
public:
	CHARACTER(int hp, int atk, int def);
	int hp();
	int atk();
	int def();
	void setState(STATE*);
	void setHp(int);
	void setAtk(int);
	void setDef(int);
	bool isAlive();
	virtual string toString() = 0; //pure virtual function


};

class IVisitable {
public:
	virtual void attack(SWORDMAN&);
	virtual void attack(KNIGHT&);
	virtual void attack(PIKEMAN&);
	virtual void hitBy(SWORDMAN&);
	virtual void hitBy(KNIGHT&);
	virtual void hitBy(PIKEMAN&);
};


class SWORDMAN : public CHARACTER, public IVisitable
{
public:
	SWORDMAN(int, int, int);
	string toString();
	void attack(SWORDMAN&);
	void attack(KNIGHT&);
	void attack(PIKEMAN&);
	void hitBy(SWORDMAN&);
	void hitBy(KNIGHT&);
	void hitBy(PIKEMAN&);
};


class KNIGHT: public CHARACTER, public IVisitable {
public:
	KNIGHT(int, int, int);
	string toString();
	void attack(SWORDMAN&);
	void attack(KNIGHT&);
	void attack(PIKEMAN&);
	void hitBy(SWORDMAN&);
	void hitBy(KNIGHT&);
	void hitBy(PIKEMAN&);
};


class PIKEMAN: public CHARACTER, public IVisitable {
public:
	PIKEMAN(int, int, int);
	string toString();
	void attack(SWORDMAN&);
	void attack(KNIGHT&);
	void attack(PIKEMAN&);
	void hitBy(SWORDMAN&);
	void hitBy(KNIGHT&);
	void hitBy(PIKEMAN&);
};

class STATE
{
public:
	virtual int transformHp(int old) =  0;
	virtual int transformAtk(int old) = 0;
	virtual int transformDef(int old) = 0;
};

class NORMALSTATE : public STATE {
public: 
	int transformHp(int old);
	int transformAtk(int old);
	int transformDef(int old);
};

class SUPER_SWORDMAN_STATE : public STATE {
public:
	int transformHp(int old);
	int transformAtk(int old);
	int transformDef(int old);
};

class SUPER_KNIGHT_STATE : public STATE {
public:
	int transformHp(int old);
	int transformAtk(int old);
	int transformDef(int old);
};

class SUPER_PIKEMAN_STATE : public STATE {
public:
	int transformHp(int old);
	int transformAtk(int old);
	int transformDef(int old);
};


class PLAYER {
public:
	vector<shared_ptr<CHARACTER>> pieces;
	typedef void (GAME::* CheckCallBack) (PLAYER*);
	CheckCallBack checker = NULL;
public:
	void add(shared_ptr<CHARACTER>);
	string toString();
};

class GAME {
private: 
	PLAYER _player1;
	PLAYER _player2;
	vector<shared_ptr<RULE>> _rules;
public:
	GAME();
	void start();
	void play();
	void checkRule(shared_ptr<PLAYER>);
	void apply(shared_ptr<PLAYER>);
	string toString();
};

class RULE {
public:
	virtual bool satisfyWith(shared_ptr<PLAYER>) = 0;
	virtual void apply(shared_ptr<PLAYER>) = 0;
};

class SUPER_SWORDMAN_RULE: public RULE {
public:
	bool satisfyWith(shared_ptr<PLAYER>);
	void apply(shared_ptr<PLAYER>);
};

class SUPER_KNIGHT_RULE : public RULE {
	bool satisfyWith(shared_ptr<PLAYER>);
	void apply(shared_ptr<PLAYER>);
};

class SUPER_PIKEMAN_RULE: public RULE {
	bool satisfyWith(shared_ptr<PLAYER>);
	void apply(shared_ptr<PLAYER>);
};


#endif