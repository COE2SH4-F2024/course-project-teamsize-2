#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList();
        ~objPosArrayList();

        int getSize() const;
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement(objPos &returnPos) const;
        objPos getTailElement(objPos &returnPos) const;
        objPos getElement(int index, objPos &returnPos) const;
        int getObjX(int x) const;
        int getObjY(int x) const;
        void setObjX(int index, int xPos) const;
        void setObjY(int index, int yPos) const;
};

#endif