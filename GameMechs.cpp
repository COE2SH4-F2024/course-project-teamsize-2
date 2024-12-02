#include "GameMechs.h"

GameMechs::GameMechs()
{
    bool exitflag;
    food.symbol = 'o';
    score = 0;
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    food.symbol = 'o';
    bool exitflag;
    
}

GameMechs::~GameMechs()
{
    delete[] this;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;

}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;

}
    

char GameMechs::getInput() const
{
    return input;

}

int GameMechs::getScore() const
{
    return score;

}

void GameMechs::incrementScore()
{
    score = score+1;
    
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;

}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;

}


void GameMechs::setExitTrue()
{
    exitFlag = true;

}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
    
}

void GameMechs::setInput(char this_input)
{
    input = this_input;

}

void GameMechs::clearInput()
{
    input = 0;

}

void GameMechs::generateFood(objPos blockOff){
    int x,y;
    do{
        x = rand() % (18) + 1;
        y = rand() % (8) + 1;
    }while(x == blockOff.getObjPosX() && y == blockOff.getObjPosY());

    food.setObjPosX(x);
    food.setObjPosY(y);

}

objPos& GameMechs::getFoodPos(){
    return(food);
}
int GameMechs::getFoodPosX()const{
    return(food.getObjPosX());
}
int GameMechs::getFoodPosY()const{
    return(food.getObjPosY());
}

// More methods should be added here