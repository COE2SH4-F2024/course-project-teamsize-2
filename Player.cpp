#include "Player.h"
#include <iostream>
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = UP;

    // more actions to be included
}


Player::~Player()
{
    //delete[] playerPosList;
    delete[] this;

    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir(){
    char input = mainGameMechsRef->getInput();
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'w':
                if(myDir != 3){
                    myDir = UP;
                }
                break;
            case 'a':
                if(myDir != 1){
                    myDir = LEFT;
                }
                break;
            case 's':
                if(myDir != 2){
                    myDir = DOWN;
                }
                break;
            case 'd':
                if(myDir != 0){
                    myDir = RIGHT;
                }
                break;
            default:
                break;
        }
    mainGameMechsRef->clearInput();
        // PPA3 input processing logic 
    }         
}

void Player::movePlayer()
{
    if (myDir == 0){
        if(playerPos.getObjPosX() == 1){
            playerPos.setObjPosX(18);
        }
        else{
            playerPos.setObjPosX((playerPos.getObjPosX() - 1));
            //MacUILib_printf("weee");
    }

    }
    else if(myDir == 1){
        if(playerPos.getObjPosX() == 18){
            playerPos.setObjPosX(1);
        }
        else{
            playerPos.setObjPosX((playerPos.getObjPosX() + 1));
        }

    }
    else if(myDir == 2){
        if(playerPos.getObjPosY() == 1){
            playerPos.setObjPosY(8);
        }
        else{
            playerPos.setObjPosY((playerPos.getObjPosY() - 1));
        }
    }
    else if(myDir == 3){
        if(playerPos.getObjPosY() == 8){
            playerPos.setObjPosY(1);
        }
        else{
            playerPos.setObjPosY((playerPos.getObjPosY() + 1));
        }
    }
    // PPA3 Finite State Machine logic
}

// More methods to be added