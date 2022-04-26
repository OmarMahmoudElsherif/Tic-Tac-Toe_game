// Tic-Tac-Toe__game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;


struct node           // we implemented this game using linked list and arrays *FROM SCRATCH*
{
	char data;
	node* next;
};

//function to insert a node in a linked list at a given position

void insert_at_position(node** head, char data, int pos)
{
	node* newnode = new node();
	node* prev;
	node* after;
	if (newnode == NULL)
	{
		std::cout << "Heap is full !!!" << endl;
		return;
	}
	newnode->data = data;
	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
	}
	else if (pos == 0)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{
		prev = *head;
		int i = 0;
		for (i; i < pos - 1; i++)
			prev = prev->next;
		after = prev->next;
		newnode->next = after;
		prev->next = newnode;
	}

}

//displaying the 3x3 tic-tac-toe board

void display(node* head)
{
	system("CLS");    // to clear screen

	cout << "\n";
	cout << "                ___________________\n";
	cout << "                |     |     |     |  " << endl;
	cout << "                |  " << head->data << "  |  " << head->next->data << "  |  " << head->next->next->data << "  |  " << endl;
	head = head->next->next->next;
	cout << "                |_____|_____|_____|" << endl;
	cout << "                |     |     |     |  " << endl;
	cout << "                |  " << head->data << "  |  " << head->next->data << "  |  " << head->next->next->data << "  |  " << endl;
	head = head->next->next->next;
	cout << "                |_____|_____|_____|" << endl;
	cout << "                |     |     |     |  " << endl;
	cout << "                |  " << head->data << "  |  " << head->next->data << "  |  " << head->next->next->data << "  |  " << endl;
	head = head->next->next->next;
	cout << "                |_____|_____|_____|" << endl << endl;
}


//function to put either 'X' or 'O' in board
bool change_value(node* head, char data, int index)
{
	for (int i = 0; i < index; i++)
		head = head->next;
	if (head->data == 'X' || head->data == 'O')
	{
		return false;
	}
	head->data = data;
	return true;
}

//this function is used to check if either 'X' or 'O' won or draw

void iscompleted(node* head)
{
	// check if any row is matched with same type
	node* tmphead = head;
	int Xcounter = 0;
	int Ocounter = 0;
	for (int j = 0; j < 3; j++)
	{
		Xcounter = 0;
		Ocounter = 0;
		for (int i = 0; i < 3; i++)
		{
			if (tmphead->data == 'X')
				Xcounter++;
			else if (tmphead->data == 'O')
				Ocounter++;
			tmphead = tmphead->next;

		}
		if (Xcounter == 3)
		{
			display(head);
			std::cout << "\n---------------X Won...-------------\n";

			exit(0);
		}
		else if (Ocounter == 3)
		{
			display(head);
			std::cout << "\n---------------O Won...-------------\n";

			exit(0);
		}

	}

	//check if Left diagonal X is completed
	tmphead = head;
	Xcounter = Ocounter = 0;
	if (tmphead->data == 'X')
	{
		Xcounter++;
		//	for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;

		if (tmphead->data == 'X')
			Xcounter++;

		//for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;
		if (tmphead->data == 'X')
			Xcounter++;

	}

	//check if Left diagonal O is completed
	tmphead = head;
	if (tmphead->data == 'O')
	{
		Ocounter++;
		//for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;
		if (tmphead->data == 'O')
			Ocounter++;

		//for (int j = 0; j < 4; j++)
		tmphead = tmphead->next->next->next->next;
		if (tmphead->data == 'O')
			Ocounter++;

	}
	if (Xcounter == 3)
	{
		display(head);
		std::cout << "\n---------------X Won...-------------\n";

		exit(0);
	}
	if (Ocounter == 3)
	{
		display(head);
		std::cout << "\n---------------O Won...-------------\n";

		exit(0);
	}

	//check if Right diagonal X is completed
	tmphead = head->next->next;
	Xcounter = Ocounter = 0;
	if (tmphead->data == 'X')
	{
		Xcounter++;
		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'X')
			Xcounter++;

		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'X')
			Xcounter++;

	}


	//check if Right diagonal O is completed
	tmphead = head->next->next;
	if (tmphead->data == 'O')
	{
		Ocounter++;
		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'O')
			Ocounter++;

		//for (int j = 0; j < 2; j++)
		tmphead = tmphead->next->next;

		if (tmphead->data == 'O')
			Ocounter++;

	}
	if (Xcounter == 3)
	{
		display(head);
		std::cout << "\n---------------X Won...-------------\n";

		exit(0);
	}
	if (Ocounter == 3)
	{
		display(head);
		std::cout << "\n---------------O Won...-------------\n";

		exit(0);
	}


	tmphead = head;
	// check if any column is matched with same type
	for (int j = 0; j < 3; j++)
	{
		//tmphead = head;
		Xcounter = Ocounter = 0;
		if (tmphead->data == 'X')
		{
			Xcounter++;
			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'X')
				Xcounter++;

			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'X')
				Xcounter++;

		}
		else if (tmphead->data == 'O')
		{

			Ocounter++;
			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'O')
				Ocounter++;

			//for (int j = 0; j < 3; j++)
			tmphead = tmphead->next->next->next;

			if (tmphead->data == 'O')
				Ocounter++;

		}
		for (int k = 0; k <= j; k++)
		{
			tmphead = head;
			tmphead = tmphead->next;
		}
		if (Xcounter == 3)
		{
			display(head);
			std::cout << "\n---------------X Won...-------------\n";

			exit(0);
		}
		tmphead = head;
		for (int k = 0; k <= j; k++)
			tmphead = tmphead->next;
		if (Ocounter == 3)
		{
			display(head);
			std::cout << "\n---------------O Won...-------------\n";

			exit(0);
		}
	}

}
