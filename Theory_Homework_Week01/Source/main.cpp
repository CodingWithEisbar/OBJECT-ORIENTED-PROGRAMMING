//20127404
//Nguyen Trung Nguyen
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Soldier{
private:
    int _hitPoint;
    int _mana;
public:
    //Constructor
    Soldier(){
        _hitPoint = 0;
        _mana = 0;
    }
    Soldier(int hitPoint, int mana)
    {
        _hitPoint = hitPoint;
        _mana = mana;
    }
public:
    //Getter
    int getHitPoint() {return _hitPoint;}
    int getMana() {return _mana;}
    //Setter
    void setHitpoint(int value) {_hitPoint = value;}
    void setMana (int value) {_mana = value;}
public:
    string toString(){
        stringstream out;
        out<<"Hitpoint: "<<_hitPoint<<" Mana: "<<_mana;
        return out.str();
    }
public:
    //Methods
    void attack(){
        cout<<"\nAttacking the enemy!!";
    }

    void defend(){
        cout<<"\nProtect yourself son!";
    }
};

class Fraction{
private:
    int _numerator, _denominator;
public:
    //Constructor
    Fraction(){
        _numerator = 0;
        _denominator = 0;
    }
    Fraction(int numerator, int denominator){
        _numerator = numerator;
        _denominator = denominator;
    }
public:
    //Getter
    int getNumerator() {return _numerator;}
    int getDenominator() {return _denominator;}
    //Setter
    void setNumerator (int value){_numerator = value;}
    void setDenominator (int value){_denominator = value;}
public:
    //toString
    string toString(){
        stringstream out;
        out<<"Your fraction: "<<_numerator<<"/"<<_denominator;
        return out.str();
    }

};

class Point{
private:
    float _x,_y;
public:
    //Constructor
    Point(){
        _x = 0;
        _y = 0;
    }
    Point(int x, int y)
    {
        _x = x;
        _y = y;
    }
public:
    //Getter
    float getX() {return _x;}
    float getY() {return _y;}
    //Setter
    void setX (int value){_x = value;}
    void setY (int value){_y = value;}
    //toString
    string toString(){
        stringstream out;
        out<<"X: "<<_x<<" Y: "<<_y;
        return out.str();
    }
};

class Line{
private:
    Point _start, _end;
public:
    //Constructor
    Line(){
        _start.setX(0);
        _start.setY(0);
        _end.setX(0);
        _end.setY(0);
    }
    Line(float x1, float y1, float x2, float y2){
        _start.setX(x1);
        _start.setY(y1);
        _end.setX(x2);
        _end.setY(y2);
    }
public:
    //Getter
    float getStartX(){return _start.getX();}
    float getStartY(){return _start.getY();}
    float getEndX(){return _end.getX();}
    float getEndY(){return _end.getY();}
    //Setter
    void setStart(float x, float y){
        _start.setX(x);
        _start.setY(y);
    }
    void setEnd(float x, float y){
        _end.setX(x);
        _end.setY(y);
    }
    //toString
    string toString(){
        stringstream out;
        out<<"Your line start at: ("<<_start.getX()<<","<<_start.getY()<<")"<<" end at "
        <<"("<<_end.getX()<<","<<_end.getY()<<")";
        return out.str();
    }
};

int main (){
    Soldier s1 (15,26);
    Fraction f1 (1,2);
    Point p1(5,6);
    Line l1 (1,2,6,7);

    s1.attack();
    cout<<endl;
    s1.defend();
    cout<<endl<<s1.toString()<<endl;

    cout<<f1.toString()<<endl;
    cout<<p1.toString()<<endl;
    cout<<l1.toString()<<endl;
    cin.get();
    return 0;
}