#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef, Food* thisFRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    mainFoodRef = thisFRef;
    myDir = STOP;

    objPos headPos(thisGMRef->getBoardSizeX() / 2,
                    thisGMRef->getBoardSizeY() / 2,
                    'O');
    playerPosList->insertHead(headPos);
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here

    //delete FoodPtr; 
    delete playerPosList; 
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic 
        char input = mainGameMechsRef->getInput();

        switch (input){
            case 'w':
            case 'W':
                if (myDir != DOWN)
                {
                    myDir=UP;
                }
                break; 

            case 's':
            case 'S':
                if (myDir != UP)
                {
                    myDir=DOWN;
                }
                break;

            case 'a':
            case 'A':
                if (myDir != RIGHT)
                {
                    myDir=LEFT; 
                }
                break; 
            
            case 'd':
            case 'D':
                if (myDir != LEFT)
                {
                    myDir= RIGHT;
                }
                break;
            default:
                break;

        }         
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    objPos tempHead(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y, playerPosList->getElement(0).getSymbol());

    switch(myDir){

        case LEFT:
            tempHead.pos->x--;
            if(tempHead.pos->x <1){ // Wrap around logic
                tempHead.pos->x = mainGameMechsRef-> getBoardSizeX() - 2;
            }
            break; 

        case RIGHT:
            tempHead.pos->x++;
              if (tempHead.pos->x >= mainGameMechsRef -> getBoardSizeX()-1){
                tempHead.pos->x=1; 
            }
            break;
        
        case DOWN:
            tempHead.pos->y++;
            if (tempHead.pos->y >= mainGameMechsRef-> getBoardSizeY()-1){
                tempHead.pos->y=1;
            }
            break;
        
        case UP: 
            tempHead.pos->y--;
            if (tempHead.pos->y < 1){
                tempHead.pos->y= mainGameMechsRef->getBoardSizeY()-2; 
            }
            break; 

        default:
            break; 
    }

    playerPosList->insertHead(tempHead);

    if (playerPosList->getHeadElement().pos->x == mainFoodRef->getFoodPosX() 
        && playerPosList->getHeadElement().pos->y==mainFoodRef->getFoodPosY()){ // check for food collision
            mainFoodRef->generateFood(playerPosList); // generate new food
            mainGameMechsRef->incrementScore();
    } else {
        playerPosList->removeTail(); // moving mech
    }

    for (int i = 1; i < playerPosList->getSize(); i++){ // check for collision
        const objPos playerTemp = playerPosList->getElement(i);
        if (playerPosList->getHeadElement().isPosEqual(&playerTemp)){     
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }
    }

    
}

// More methods to be added