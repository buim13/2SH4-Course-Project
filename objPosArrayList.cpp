#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction,
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;         
    arrayCapacity = ARRAY_MAX_CAP; 

    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity)
        return;
    for(int i = listSize; i > 0; i--)
        aList[i] = aList[i - 1];
    
    aList[0].setObjPos(thisPos);

    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
        return;
    aList[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{

    if (listSize > 0)
    {
        for (int i = 0; i < listSize - 1; i++)
            aList[i] = aList[i + 1];
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0)
        listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0]; // return the head element
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1]; // return the tail element
}

objPos objPosArrayList::getElement(int index) const
{
    if (index < 0)
        index = 0;

    if (index > listSize)
        return aList[listSize];

    return aList[index];
}