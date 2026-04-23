#include "Food.h"
#include "MacUILib.h"

Food::Food()
{

    foodPos.pos->x = -10;
    foodPos.pos->y = -10;
    foodPos.symbol = '*';

    

    srand(time(nullptr));
}


Food::~Food()
{
    
}

void Food::generateFood(objPosArrayList* blockOff)
{
    int size = blockOff->getSize();
    bool isValid = false;

    const int sizeX = 20;
    const int sizeY = 10;

    while (!isValid){
        isValid = true;

        foodPos.pos->x=(rand() % ((sizeX)-2))+1;
        foodPos.pos->y=(rand() % ((sizeY)-2))+1;
        
        for (int i=0; i < size; i++){
            if (foodPos.pos->x==blockOff->getElement(i).pos->x
                && foodPos.pos->y==blockOff->getElement(i).pos->y){
                    isValid = false; // Wrong food coords
                    break;
                }
        }
        foodPos.setObjPos(foodPos.pos->x, foodPos.pos->y, '*');
    }
}



int Food::getFoodPosX() const{
    return foodPos.pos->x;
}

int Food::getFoodPosY() const{
    return foodPos.pos->y;
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

