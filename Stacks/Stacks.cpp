// Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
Julio Rojas, Adam Blakeslee, Douglas Loughmiller, and Beomsoo Kim 
Prof. F. Aljamal
CIS 277
14 II 2017
*/
#include <iostream>
#include <cstdlib>

using namespace std;

struct stack
{
    int num;
    stack*next;
};

void create_stack(stack*&, stack*&, int&);
void empty(stack*,int);
void push(stack*&, stack*&, int, int&);
void pop(stack*&, stack*&, int, int&);
void tops(stack*, stack*, int);
void purge (stack*&, stack*&, int, int&);

int main()
{
  stack*startptr;
  stack*top;
  int c;
  int b = 0;
  int x=0;
    do
    {
      cout << "Type 1 to create stack." << endl;
      cout << "Type 2 to push." << endl;
      cout << "Type 3 to pop." << endl;
      cout << "Type 4 to top." << endl;
      cout << "Type 5 to empty." << endl;
      cout << "Type 6 to purge." << endl;
      cin >> c;

      switch(c)
      {
        case 1: create_stack(startptr, top, b);
          break;
        case 2:push(startptr, top, b, x);
          break;
        case 3: pop(startptr, top, b, x);
          break;
        case 4: tops(startptr, top, b);
          break;
        case 5: empty (startptr,b);
          break;
        case 6: purge (startptr, top, b, x);
          break;
        default: "invalid input";
          break;
      }
    }
	while(c>0 && c<7);
    return 0;
}

    void create_stack(stack*&startptr, stack*&top, int &i)
    {
      system("cls");
      startptr = NULL;
      top = NULL;
      i = 1;
    }
    
    void push(stack*&startptr, stack*&top, int i, int&x)
    {
      system("cls");
      if(i==0)
        {
          cout << "stack does not exist" << endl;
        }
      else
      {
        stack*temp;
        temp = new stack;
        cout << "enter a number to push ";
        cin >> temp ->num;
        if(startptr == NULL)
        {
          startptr = temp;
          top = temp;
          temp -> next = NULL;
          x++;
        }
        else
        {
        top -> next = temp;
        top = temp;
        x++;
        }
      }
    }
      void pop (stack*&startptr, stack*&top, int i, int&x)
      {
        system("cls");
        stack*nuke;

        if(i==0)
        {
          cout << "Stack does not exist" << endl;
        }
        else if (startptr == NULL)
        {
          cout << "stack is empty" << endl;
        }
        else if (startptr -> next == NULL)
        {
          nuke=top;
          delete nuke;
          top=NULL;
          x--;
        }
        else
          {
            nuke = top;
            stack * search = startptr;
            while(search->next!=top)
              {
                search = search->next;
              }
            top = search;
            top ->next= NULL;
            delete nuke;
          }
      }
      void tops(stack * startptr, stack * top, int i)
      {
        system("cls");
        if(i == 0)
        {
          cout << "Stack does not exist" << endl;
        }
        else if(startptr == NULL)
        {
          cout << "stack empty" << endl;
        }
        else
        {
          cout << "top item is: " << top->num << endl;
        }
      }
      void empty (stack*startptr, int i)
      {
	  	system("cls");
	  	if (i==0)
	  	{
	  		cout << "stack does not exist" << endl;
	  	}
	  else if(startptr == NULL)
	  {
	  	cout << "stack empty" << endl;
	  }
	  else
		{ 
	  		cout << "stack not empty" << endl;	
		}
	  }
	  void purge(stack*&startptr, stack*&top, int i, int&x)
	  {
	  	system ("cls");
	  	if( i == 0)
	  	{
	  		cout << "stack does not exist" << endl;
		}
		else if(startptr == NULL)
		{
			cout << "stack already empty" << endl;
		}
		else
		{
			stack * purge = startptr;
			stack * purge2;
			for (int z =0; z<x; z++)
			{
				purge2=purge;
				purge=purge->next;
				delete purge2;
			}
		startptr = NULL;
		top = NULL;
		x = 0;
		x = 0;
		cout << "stack purge" << endl;
		}
	  }