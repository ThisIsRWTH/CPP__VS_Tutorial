/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student& pData, ListElem* const pNext, ListElem* const pPrevious):
    data(pData), next(pNext), previous(pPrevious)
{
}

void ListElem::setData(const Student& pData)
{
    data = pData;
}


void ListElem::setNext(ListElem* const pNext)
{
    next = pNext;
}


Student ListElem::getData() const
{
    return data;
}


ListElem* ListElem::getNext() const
{
    return next;
}

void ListElem::setPrevious(ListElem* const pPrevious)
{
	previous = pPrevious;
}

ListElem* ListElem::getPrevious() const
{
	return previous;
}
