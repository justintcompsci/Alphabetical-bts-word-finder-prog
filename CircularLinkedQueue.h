#include <iostream>
#include<cassert>
using namespace std;

#ifndef QUEUE
#define QUEUE

template <typename QueueElement>
class Queue
{
public:
	/***** Function Members *****/
	/***** Constructor *****/

	Queue() : myBack(NULL) {};
	/*-----------------------------------------------------------------------
	  Construct a Queue object.

	  Precondition:  None.
	  Postcondition: An empty circular linked queue object has been constructed;
		  myBack are initialized to null.
	 ----------------------------------------------------------------------*/

	Queue(const Queue<QueueElement> & orig)
	{

		if (orig.empty()) {
			cerr << "*** Queue is empty --- **** \n";
		}
		else {

			myBack = new Node(orig.myBack->data);

			Node* ptr1 = orig.myBack->next;
			Node* ptr2 = myBack;

			while (ptr1 != orig.myBack) {
				ptr2->next = new Node(ptr1->data);
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			ptr2->next = myBack;
		}

	}
	//***********************************************************************/
	//Name: Queue(const Queue & orig)
	//
	//Pre: Original is the circular linked queue to be copied and is received as a const
	//reference parameter
	//
	//Post: A copy of the of the original CLQ has been contructed.
	//**********************************************************************/

	 ~Queue()
	{
		Node* ptr;

		if (empty()) {
			cerr << "*** Queue is empty --- **** \n";
		}

		else {
			ptr = myBack->next;
			myBack->next = NULL;
			while (ptr != NULL) {
				myBack = ptr;
				ptr = ptr->next;
				delete myBack;
			}
		}
	}
	//***********************************************************************/
	//Name: ~Queue
	//
	//Pre: None.
	//
	//Post: The cirular linked queue has been deallocated.
	//**********************************************************************/

	const Queue<QueueElement>& operator=(const Queue<QueueElement> &rhs)
	{
		if (this != &rhs) {
			this->~Queue();

			if (rhs.empty())
				myBack = NULL;

			else {

				myBack = new Node(rhs.myBack->data);

				Node* ptr1 = rhs.myBack->next;
				Node* ptr2 = myBack;

				while (ptr1 != rhs.myBack) {
					ptr2->next = new Node(ptr1->data);
					ptr1 = ptr1->next;
					ptr2 = ptr2->next;
				}
				ptr2->next = myBack;

			}

		}
		return *this;
	}
	//***********************************************************************/
	//Name: Queue & operator=(const Queue &rhs); 
	//
	//Pre: RHS is the circular  linked queue to be assigned and is recieved
	//as a const reference parameter;
	//
	//Post: The current CL queue becomes a copy of the RHS (right hand side)
	//and a refertence to it is returned
	//**********************************************************************/

	bool empty() const
	{
		return (myBack == 0);
	}
	/*-----------------------------------------------------------------------
	  Check if queue is empty.

	  Precondition: None.
	  Postcondition: True is returned if the circular linked queue is empty and false is
		  returned otherwise.
	 ----------------------------------------------------------------------*/

	void enqueue(const QueueElement & value)
	{
		Node * t = new Node(value);

		if (myBack == NULL)
		{
			t->next = t;
			myBack = t;

		}
		else {
			t->next = myBack->next;
			myBack->next = t;
			myBack = t;
		}
	}
	/*-----------------------------------------------------------------------
	  Add a value to a queue.

	  Precondition:  value is to be added to this CL queue.
	  Postcondition: value is added to back of CL queue provided there is space;
		  otherwise, a CL queue-full message is displayed and execution is
		  terminated.
	 -----------------------------------------------------------------------*/

	void display(ostream & out) const
	{

		if (myBack != NULL)
		{
			Node * head = myBack->next;

			Node * tmp = head;
			while (tmp->next != head)
			{
				out << tmp->data <<" ";
				tmp = tmp->next;
			}
			out << tmp->data;
		}
	}
	/*-----------------------------------------------------------------------
	  Output the values stored in the queue.

	  Precondition:  ostream out is open.
	  Postcondition: CL Queue's contents, from the circular linked back, have been output
		  to out.
	 -----------------------------------------------------------------------*/

	Queue<QueueElement> front() const
	{
		return (myBack->next->data);
	}
	/*-----------------------------------------------------------------------
	  Retrieve value at front of queue (if any).

	  Precondition:  Queue is nonempty.
	  Postcondition: Value at front of CL queue is returned, unless queue is
		  empty; in that case, an error message that is displayed.
	 ----------------------------------------------------------------------*/
	
	void dequeue()
	{
		Node* t;
		if (myBack == NULL)
			cerr << "*** Queue is empty --- ***\n";

		else {
			t = myBack->next;
			myBack->next = t->next;
			delete t;

		}
	}
	/*-----------------------------------------------------------------------
	  Remove value at front of queue (if any).

	  Precondition:  Queue is nonempty.
	  Postcondition: Value at front of queue has been removed, unless queue
		  is empty; in that case, an error message is displayed.
	 ----------------------------------------------------------------------*/

private:
	/*****Node class******/
	class Node {
	public:
		QueueElement data;
		Node* next;


		Node(QueueElement value, Node* link = 0) : data(value), next(link) {}
	};

	typedef Node* NodePointer;
	/***** Data Members *****/
	NodePointer
		myBack;
}; // end of class declaration


#endif



