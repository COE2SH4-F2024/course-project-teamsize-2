#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {LEFT, RIGHT, UP, DOWN, STOP};  // This is the direction state
        objPosArrayList* bodyPositions;

        Player(GameMechs* thisGMRef);
        ~Player();

        objPos getPlayerPos() const; // Upgrade this in iteration 3.       
        void updatePlayerDir();
        void movePlayer();
        void moveBody();

        // More methods to be added here

    private:
        objPos playerPos; // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif