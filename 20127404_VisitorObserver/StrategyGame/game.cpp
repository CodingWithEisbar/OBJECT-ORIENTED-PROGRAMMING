#include "game.h"

// Class implementation
// ---- Character
CHARACTER::CHARACTER(int hp, int atk, int def)
{
	_hp = hp;
	_atk = atk;
	_def = def;
	_state = new NORMALSTATE();
}

int CHARACTER::hp() { return _state->transformHp(_hp); }
int CHARACTER::atk() { return _state->transformAtk(_atk); }
int CHARACTER::def() { return _state->transformHp(_def); }
void CHARACTER::setHp(int value) { _hp = value > 0 ? value : 0; }
void CHARACTER::setAtk(int value) { _atk = value > 0 ? value : 0; }
void CHARACTER::setDef(int value) { _def = value > 0 ? value : 0; }
bool CHARACTER::isAlive() { return _hp > 0; }
void CHARACTER::setState(STATE* value) { _state = value; }

// ---- Swordman ----
SWORDMAN::SWORDMAN(int hp, int atk, int def) :CHARACTER(hp, atk, def) {}
string SWORDMAN::toString()
{
	stringstream builder;
	builder << "Swordman HP: " << hp()
		<< " ATK: " << atk()
		<< " DEF: " << def();
	string result = builder.str();
	return result;
}

//             ATTACK
void SWORDMAN::attack(SWORDMAN& opponent)
{
	opponent.hitBy(*this); // this: Swordman*,  *this: Swordman
	if (opponent.isAlive())
	{
		hitBy(opponent);
	}
}

void SWORDMAN::attack(KNIGHT& opponent)
{
	opponent.hitBy(*this); // this: Swordman*,  *this: Swordman
	if (opponent.isAlive())
	{
		hitBy(opponent);
	}
}

void SWORDMAN::attack(PIKEMAN& opponent)
{
	opponent.hitBy(*this); // this: Swordman*,  *this: Swordman
	if (opponent.isAlive())
	{
		hitBy(opponent);
	}
}

//             HIT-BY
void SWORDMAN::hitBy(SWORDMAN& opponent)
{
	_hp = _hp - (opponent.atk() - _def);

}

void SWORDMAN::hitBy(KNIGHT& opponent)
{
	_hp = _hp - (opponent.atk() + 10 - _def);
}

void SWORDMAN::hitBy(PIKEMAN& opponent)
{
	_hp = _hp - (opponent.atk() - _def);
}

// ---- Knight ----
KNIGHT::KNIGHT(int hp, int atk, int def) :CHARACTER(hp, atk, def) {}
string KNIGHT::toString()
{
	stringstream builder;
	builder << "Knight HP: " << hp()
		<< " ATK: " << atk()
		<< " DEF: " << def();

	string result = builder.str();
	return result;
}

//             ATTACK
void KNIGHT::attack(SWORDMAN& opponent)
{
	opponent.hitBy(*this); // this: KNIGHT*,  *this: KNIGHT

	if (opponent.isAlive()) {
		hitBy(opponent); //hitBy(SWORDMAN&)
	}
}

void KNIGHT::attack(KNIGHT& opponent)
{
	opponent.hitBy(*this); // this: KNIGHT*,  *this: KNIGHT

	if (opponent.isAlive()) {
		hitBy(opponent); //hitBy(KNIGHT&)
	}
}

void KNIGHT::attack(PIKEMAN& opponent)
{
	opponent.hitBy(*this); // this: KNIGHT*,  *this: KNIGHT

	if (opponent.isAlive()) {
		hitBy(opponent); //hitBy(KNIGHT&)
	}
}

//             HIT-BY
void KNIGHT::hitBy(SWORDMAN& opponent)
{
	_hp = _hp - (opponent.atk() - _def);
}

void KNIGHT::hitBy(KNIGHT& opponent)
{
	_hp = _hp - (opponent.atk() - _def);
}

void KNIGHT::hitBy(PIKEMAN& opponent)
{
	_hp = _hp - (opponent.atk() * 2 - _def);
}

// ----- Pikeman ----
PIKEMAN::PIKEMAN(int hp, int atk, int def): CHARACTER(hp, atk, def) {}

string PIKEMAN::toString() {
	stringstream builder;
	builder << "Pikeman HP: " << hp()
		<< " ATK: " << atk()
		<< " DEF: " << def();

	string result = builder.str();
	return result;
}


//             ATTACK
void PIKEMAN::attack(KNIGHT& opponent)
{
	opponent.hitBy(*this); // this: KNIGHT*,  *this: KNIGHT

	if (opponent.isAlive()) {
		hitBy(opponent); //hitBy(KNIGHT&);
	}
}

void PIKEMAN::attack(PIKEMAN& opponent)
{
	opponent.hitBy(*this); // this: PIKEMAN*,  *this: PIKEMAN

	if (opponent.isAlive()) {
		hitBy(opponent); //hitBy(PIKEMAN&);
	}
}

//             HIT-BY
void PIKEMAN::hitBy(SWORDMAN& opponent)
{
	_hp = _hp - (opponent.atk() + 8 - _def);
}

void PIKEMAN::hitBy(KNIGHT& opponent)
{
	_hp = _hp - (opponent.atk() - _def * 2);
}

void PIKEMAN::hitBy(PIKEMAN& opponent)
{
	_hp = _hp - (opponent.atk() - _def);
}


// ---- States
int NORMALSTATE::transformHp(int old)
{
	return old;
}

int NORMALSTATE::transformAtk(int old)
{
	return old;
}

int NORMALSTATE::transformDef(int old)
{
	return old;
}

//--------SWORDMAN siêu cấp vô địch
// Three swordmen in the field, each swordman will have a bonus of tripling (3x) its current ATK.
int SUPER_SWORDMAN_STATE::transformAtk(int old)
{
	return old * 3; 
}

int SUPER_SWORDMAN_STATE::transformHp(int old)
{
	return old;
}

int SUPER_SWORDMAN_STATE::transformDef(int old)
{
	return old;
}


//--------KNIGHT siêu cấp vô địch
// Three Knights on the fields, each Knight will have a bonus of 2x its current ATK.
int SUPER_KNIGHT_STATE::transformHp(int old)
{
	return old;
}

int SUPER_KNIGHT_STATE::transformAtk(int old)
{
	return old * 2;
}

int SUPER_KNIGHT_STATE::transformDef(int old)
{
	return old;
}

//--------PIKEMAN siêu cấp vô địch
// Three spikemen on the fields, each spikeman will have a bonus of 5x its current ATK, 2x its current HP.
int SUPER_PIKEMAN_STATE::transformHp(int old)
{
	return old * 2;
}

int SUPER_PIKEMAN_STATE::transformAtk(int old)
{
	return old * 5;
}

int SUPER_PIKEMAN_STATE::transformDef(int old)
{
	return old;
}


//-------Player----------------
void PLAYER::add(shared_ptr<CHARACTER> item)
{
	pieces.push_back(item);
}

string PLAYER::toString()
{
	stringstream builder;
	builder << "Player info:" << endl;
	for (int i = 0; i < pieces.size(); i++) {
		builder << "     + " << pieces[i]->toString() << endl;
	}

	string result = builder.str();
	return result;
}

GAME::GAME() {
	_rules.push_back(make_shared<SUPER_SWORDMAN_RULE>());
	_rules.push_back(make_shared<SUPER_KNIGHT_RULE>());
	_rules.push_back(make_shared<SUPER_PIKEMAN_RULE>());

	_player1.checker = &GAME::checkRule;
	_player2.checker = &GAME::checkRule;

}