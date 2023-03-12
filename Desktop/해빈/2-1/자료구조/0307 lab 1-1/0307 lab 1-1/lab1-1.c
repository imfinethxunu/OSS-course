#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

//Check if it is a full stack
int stack_full() {
	if (top >= MAX_SIZE - 1)
		return 1;
	return 0;
}

//Check if it is an empty stack
int stack_empty() {
	if (top == -1)
		return 1;
	return 0;
}

//insert value in stack 
void push(int x) {
	top++;
	stack[top] = x;
}

//delete value from stack
int pop() {
	int temp = stack[top];
	top--;
	return temp;
}

//helper function : print the current stack
void print_stack() {
	printf("stack = ");
	for (int i = 0; i <= top; i++)
		printf(" %d", stack[i]);
	printf(" (top = %d)\n", top);
}

//check if stack is a full stack using 'if'
//copy value from arr[] to stack[]
void run_pushes(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		printf("push(%d) , ", arr[i]);
		if (!stack_full()) {
			push(arr[i]);
		}
		else
			printf("stack full! ");
		print_stack();
	}
	
}

//check if stack is an empty stack using 'if'
//shows the process of deleting data
void run_pops(int num) {
	int value; //Specify the value to be deleted as a variable
	for (int i = 0; i < num; i++) {
		printf("pop() ");
		if (!stack_empty()) {
			value = pop(); 
			//gets the return value temp
			// temp is stack[top]
			printf("-> %d, ", value);
		}
		else
			printf("stack empty!");
		print_stack();
	}
	
}

int main() {
	//Specify Value
	int numbers[] = { 3,9,4,5,2,1,6,8,7,5,8 };

	//print the current stack
	print_stack();

	//insert value in stack
	run_pushes(numbers, 5);
	//ex) copy value from numbers array to stack 
	//이때 num은 numbers라는 array에서 stack에 넣을 값의 수

	//delete value from stack
	run_pops(3);

	run_pushes(numbers, 10);

	run_pops(11);

}