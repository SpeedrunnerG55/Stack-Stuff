// Stacks.cpp : Defines the entry point for the console application.
//

/*
Julio Rojas, Adam Blakeslee, Douglas Loughmiller, and Beomsoo Kim
Prof. F. Aljamal
CIS 277
14 II 2017
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Stack
{
	int record[30];
	int i = -1;
};
//"toolkit functions" not really
void create_stack(Stack &s);
void push(Stack &s);
void pop(Stack &s);
void purge(Stack &s);
void tops(Stack s);
void empty(Stack s);

void showStack(Stack s)

int main()
{
	bool invalid;
	bool running  = true;
	
	Stack Que;
	int x = 0;
	char c;
	do
	{
		
		

		do {
			showStack(Que);
			invalid = false;
			cout << "Type 1 to create stack." << endl;
			cout << "Type 2 to push." << endl;
			cout << "Type 3 to pop." << endl;
			cout << "Type 4 to top." << endl;
			cout << "Type 5 to empty." << endl;
			cout << "Type 6 to purge." << endl;
			cout << "Type 9 to quit." << endl;

			cin >> c;

			switch (c){
				case '1': create_stack(Que);
					break;
				case '2': push(Que);
					break;
				case '3': pop(Que);
					break;
				case '4':	tops(Que);
					break;
				case '5': empty(*&Que);
					break;
				case '6': purge(*&Que);
					break;
				case '9': running = false;
				default: cout << "invalid input" << endl;
					invalid = true;
					break;
			}
		} while (invalid);
	} while (running);
	return 0;
}

void showStack(Stack s) {
	if (s.i > -1) {
		cout << "Here is the que from bottom to top left to right" << endl;
		cout << "[";
		for (int i = 0; i < s.i; i++) {
			cout << s.record[i];
			if (i != s.i - 1) {
				cout << ",";
			}
		}

		cout << "]" << endl;
	}
}

void create_stack(Stack &s){	
	s.i = 0;
	cout << "Stack created!" << endl;
}

void push(Stack &s){	
	system("cls");
	if (s.i == -1){
		cout << "stack does not exist" << endl;
		getchar();
	}

	else if (s.i == 29) {
		cout << "The stack is full!" << endl;
		getchar();
	}

	else{	
		cout << "enter a number to push " << endl;
		cin >> s.record[s.i];
		s.i++;
	}
}

void pop(Stack &s){

	if (s.i == -1){
		cout << "Stack does not exist" << endl;
		getchar();
	}

	else if (s.i == 0){
		cout << "stack is empty" << endl;
		getchar();
	}

	else{
		s.i--;
	}
}

void tops(Stack s){

	if (s.i == -1){
		cout << "Stack does not exist" << endl;
		getchar();
	}

	else if (s.i == 0){
		cout << "stack empty" << endl;
		getchar();
	}

	else{
		cout << "top item is: " << s.record[s.i - 1] << endl;
		getchar();
	}
}

void empty(Stack s){
	

	if (s.i == -1){
		cout << "stack does not exist" << endl;
		getchar();
	}
	else if (s.i == 0){
		cout << "stack empty" << endl;
		getchar();
	}
	else{
		cout << "stack not empty" << endl;
		getchar();
	}
}

void purge(Stack &s){

	if (s.i == -1){
		cout << "stack does not exist" << endl;
		getchar();
	}

	else if (s.i == 0){
		cout << "stack already empty" << endl;
		getchar();
	}

	else{
		s.i = 0;
	}
}