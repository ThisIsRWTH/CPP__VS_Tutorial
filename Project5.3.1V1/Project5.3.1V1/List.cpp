/**
 * @file List.cpp
 * content: linked list data structure
 */

#include "List.h"

List::List(): head(NULL), tail(NULL)
{
}

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_tail(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL,NULL);

	//If our list is empty
    if (tail == NULL && head == NULL)                                       // list empty?
    {
        tail = new_element;
		head = new_element;
    }
	//If our list is not Empty
    else
    {
		ListElem* cursor = head;

		while (cursor->getNext() != NULL)
		{
			cursor = (*cursor).getNext();
		}

		tail = new_element;
		(*cursor).setNext(new_element);
		new_element->setPrevious(cursor);
        //new_element->setNext(head);
    }

}

void List::enqueue_head(const Student &pData)
{
	ListElem* new_element = new ListElem(pData, NULL, NULL);

	//If our list is empty
	if (tail == NULL && head == NULL)                                       // list empty?
	{
		tail = new_element;
		head = new_element;
	}
	//If our list is not Empty
	else
	{

		new_element->setNext(head);
		head->setPrevious(new_element);
		head = new_element;
		//new_element->setNext(head);
	}

}

bool List::deleteElement(int matNum, Student& outputStudent)
{
	ListElem* cursor = head;

	while (cursor != NULL)
	{
		Student tempstudent = cursor->getData();
		if (tempstudent.getMatNr() == matNum)
		{
			break;
		}
		cursor = cursor->getNext();
	}

	//If the desired matriculation number does not exist in the list
	if (cursor == NULL)
	{
		return false;
	}

	//If the desired matriculation number exists in the list:

	//calculate the nextElement and the previousElement of the cursor
	ListElem* nextElem = cursor->getNext();
	ListElem* previousElem = cursor->getPrevious();

	if (nextElem != NULL && previousElem != NULL)
	{
		previousElem->setNext(nextElem);
		nextElem->setPrevious(previousElem);
		outputStudent = cursor->getData();
		delete cursor;
	}
	//if we find the matriculation number in head element
	else if(previousElem == NULL)
	{
		head = cursor->getNext();
		nextElem->setPrevious(NULL);
		outputStudent = cursor->getData();
		delete cursor;	 
	}
	//if we find the matriculation number in tail element
	else //if(nextElem==NULL)
	{
		tail = cursor->getPrevious();
		previousElem->setNext(NULL);
		outputStudent = cursor->getData();
		delete cursor;
	}

	return true;
}

bool List::dequeue(Student& pData)
{
	//ListElem* cursor = tail;
	//tail = cursor->getPrevious();
	//previousElem->setNext(NULL);
	//delete cursor;


    ListElem* cursor = head;

    if (head == NULL)                                       // list empty?
    {
        return false;
    }
    else if (head == tail)                                  // only one element
    {
        pData = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        while (cursor->getNext() != tail)
        {
            cursor = cursor->getNext();
        }

        pData = tail->getData();
        tail = cursor;
        delete cursor->getNext();
        tail->setNext(NULL);
    }

    return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards() const
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getNext();
    }
}

void List::print_backward() const
{
	ListElem* cursor = tail;

	while (cursor != NULL)
	{
		cursor->getData().print();

		cursor = cursor->getPrevious();
	}
}
