#include "objPosArrayList.h"
#include "stdio.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList(){
    listSize = 0;
    arrayCapacity = 200;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList(){
    for(int i = 0; i < arrayCapacity; i++){
        delete[] &aList[i];
    }
    delete[] aList;
}

int objPosArrayList::getSize() const{
    return listSize;
}

int objPosArrayList::getObjX(int index) const{
    return (aList[index].getObjPosX());
}
int objPosArrayList::getObjY(int index) const{
    return (aList[index].getObjPosY());
}

void objPosArrayList::setObjX(int index, int xPos) const{
    aList[index].setObjPosX(xPos);
}
void objPosArrayList::setObjY(int index, int yPos) const{
    aList[index].setObjPosY(yPos);
}

void objPosArrayList::insertHead(objPos thisPos){
    if(listSize < arrayCapacity){
        for(int i = listSize; i > 0; i--){
            aList[i+1] = aList[i];
        }
    }
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos){
    if(listSize > arrayCapacity){
        aList[listSize] = thisPos;
    }
    listSize++;
}

void objPosArrayList::removeHead(){
    for(int i = 0; i < listSize-1; i++){
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail(){
    aList[listSize].symbol = ' ';
    listSize--;
}

objPos objPosArrayList::getHeadElement(objPos &returnPos) const{
    returnPos = aList[0];
    return(returnPos);
}

objPos objPosArrayList::getTailElement(objPos &returnPos) const{
    returnPos = aList[listSize-1];
    return(returnPos);
}

objPos objPosArrayList::getElement(int index, objPos &returnPos) const{
    returnPos = aList[index];
    return(returnPos);
}