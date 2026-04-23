#ifndef FOOD_H 
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "GameMechs.h"

using namespace std; 


class Food
{
    private:
        char input;                //for user input
        objPos foodPos;                 
        

    public: 
        Food();
        ~Food(); 

       
        

        void generateFood(objPosArrayList* blockoff);  //randomly generate food pos avoiding boundaries
        
        objPos getFoodPos() const; 
        
        int getFoodPosX() const;        //get x and y corods respectively
        int getFoodPosY() const;

};

#endif