/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

class ListElem
{
private:
	Student data;
    ListElem* next;
	ListElem* previous;

public:
    ListElem(const Student& pData, ListElem* const pNext, ListElem* const pPrevious);

    void setData(const Student& pData);
    void setNext(ListElem* const pNext);
	void setPrevious(ListElem* const pNext);

    Student getData() const;
    ListElem* getNext() const;
	ListElem* getPrevious() const;
};

#endif

