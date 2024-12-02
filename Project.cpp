#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

/*
Please read the READ ME file
*/

using namespace std;



#define DELAY_CONST 150000
#define BOARDX = 20
#define BOARDY = 10

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
    player->moveBody();
    objPos* tempObj = new objPos();
    if(player->bodyPositions->getHeadElement(*tempObj).getObjPosX() == gm->getFoodPosX() && player->bodyPositions->getHeadElement(*tempObj).getObjPosY() == gm->getFoodPosY()){
        gm->incrementScore();
        gm->generateFood(player->getPlayerPos());
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int x,y;
    for(y = 0; y < 10; y++){
        for(x = 0; x < 20; x++){
            /*for(int i = 0; i < (player->bodyPositions->getSize()); i++){
                if(player->bodyPositions->getObjX(i) == x && player->bodyPositions->getObjY(i) == y){
                    MacUILib_printf("%c", player->getPlayerPos().getSymbol());
                }
            }*/
           //above for loop would be to print an entire snake, but I only need the head

            if(player->bodyPositions->getObjX(0) == x && player->bodyPositions->getObjY(0) == y){
                MacUILib_printf("%c", player->getPlayerPos().getSymbol());
            }//for the head
            else if (y == 0 || y == 9 || x == 0 || x == 19) {
                MacUILib_printf("#");
            }//border
            else if(gm->getFoodPosX() == x && gm->getFoodPosY() == y){
                MacUILib_printf("%c", 'o');
            }//food
            
            else{
                MacUILib_printf(" ");
            }//space
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("\nPress SPACE to quit");
    MacUILib_printf("\nScore: %d", gm->getScore());
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
