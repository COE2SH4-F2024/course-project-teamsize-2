#include "objPos.h"
#include "stdlib.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 3;
    pos->y = 3;
    symbol = '*'; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//RULE OF 4

objPos::~objPos()
{
    delete[] pos;
}

objPos::objPos(const objPos& other){
    pos = new Pos;
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol = other.symbol;

}
objPos& objPos::operator = (const objPos &other){
    if(this != NULL){
        pos = new Pos;
        pos->x = other.pos->x;
        pos->y = other.pos->y;
        symbol = other.symbol;
    }
    return *this;
}


void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPosX(int xPos){
    pos->x = xPos;
}

void objPos::setObjPosY(int yPos){
    pos->y = yPos;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

int objPos::getObjPosX() const{
    return pos->x;
}

int objPos::getObjPosY() const{
    return pos->y;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
