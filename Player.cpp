#include "Player.h"
#include <iostream>
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    bodyPositions = new objPosArrayList();
    myDir = DOWN;
    bodyPositions->insertHead(playerPos);

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

void Player::moveBody(){
    for(int i = 0; i < bodyPositions->getSize(); i++){
        if(myDir == 0){
            if(bodyPositions->getObjX(i) == 1){
                bodyPositions->setObjX(i, 18);
            }
            else{
                bodyPositions->setObjX(i,(bodyPositions->getObjX(i) -1));
            }
        }
        else if(myDir == 1){
            if(bodyPositions->getObjX(i) == 18){
                bodyPositions->setObjX(i, 1);
            }
            else{
                bodyPositions->setObjX(i,(bodyPositions->getObjX(i) +1));
            }
        }
        else if(myDir == 2){
            if(bodyPositions->getObjY(i) == 1){
                bodyPositions->setObjY(i, 8);
            }
            else{
                bodyPositions->setObjY(i,(bodyPositions->getObjY(i) -1));
            }
        }
        else if(myDir == 3){
            if(bodyPositions->getObjY(i) == 8){
                bodyPositions->setObjY(i, 1);
            }
            else{
                bodyPositions->setObjY(i,(bodyPositions->getObjY(i) +1));
            }
        }
    }
}
/*
void Player::moveBody(){
    if (myDir == 0){
        for(int i = 0; i < bodyPositions->getSize(); i++){
        }
    }
    else if(myDir == 1){
        for(int i = 0; i < bodyPositions->getSize(); i++){
        }

    }
    else if(myDir == 2){
        for(int i = 0; i < bodyPositions->getSize(); i++){
        }
    }
    else if(myDir == 3){
        for(int i = 0; i < bodyPositions->getSize(); i++){
        }
    }
}*/

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