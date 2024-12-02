#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

/*
Please read the READ ME file
*/

using namespace std;



#define DELAY_CONST 100000

bool exitFlag;

GameMechs *gm = new GameMechs();
Player *player;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    player = new Player(gm);
    gm->generateFood(player->getPlayerPos());

    exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar()){//checks if char is pressed and stores it cmd
        gm->setInput(MacUILib_getChar());
    }
    if (gm->getInput() == ' '){
        exitFlag = true;
    }
   
}

void RunLogic(void)
{
    player->updatePlayerDir();
    player->movePlayer();
    if(player->getPlayerPos().getObjPosX() == gm->getFoodPosX() && player->getPlayerPos().getObjPosY() == gm->getFoodPosY()){
        gm->generateFood(player->getPlayerPos());
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int x,y;
    for(y = 0; y < 10; y++){
        for(x = 0; x < 20; x++){
            if (y == 0 || y == 9 || x == 0 || x == 19) {
                MacUILib_printf("#");
            }
            else if (player->getPlayerPos().getObjPosX() == x && player->getPlayerPos().getObjPosY() == y)
            {
                MacUILib_printf("%c", player->getPlayerPos().getSymbol());
            }
            else if(gm->getFoodPosX() == x && gm->getFoodPosY() == y){
                MacUILib_printf("%c", 'o');
            }
            
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Press SPACE to quit");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
