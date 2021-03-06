#ifndef BANK_V2_LIST_H
#define BANK_V2_LIST_H

#endif //BANK_V2_LIST_H

#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int acNum;
	int checkBal;
	int savBal;
	int acPin;
	string acName;
	node *next;
};

class list{
private:
public:
	node *head, *tail;
	bool result;

	list(){
		head=NULL;
		tail=NULL;
	}

	void createNode (int num, int bal, int pin, string name, char choice){
		node *temp=new node;
		temp->acNum=num;
		if(choice == 'c') {
			temp->checkBal = bal;
			temp->savBal = 0;
		}
		else if(choice == 's'){
			temp->savBal = bal;
			temp->checkBal = 0;
		}
		else{
			cout << "Invalid input for savings or checking \n";
			cout << "The money was moved to your Checking's account";
			temp->checkBal = bal;
			temp->savBal = 0;
		}
		temp->acPin=pin;
		temp->acName=name;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else{
			tail->next=temp;
			tail=temp;
		}
	}

	void display_account(int num, int pin){
		sort();
		node *temp = binarySearch(head, num);

		if (temp == NULL){
			cout <<"Account does not exist \n";
			return;
		}else if (checkPin(pin, temp->acPin)) {
			cout << "Welcome " << temp->acName << ",\n" << "your account number is ";
			cout << temp->acNum <<" and your current balance is \nChecking Account: $";
			cout << temp->checkBal << "\nSavings Account: $" << temp->savBal << "\n";
		}else{
			cout <<"Incorrect PIN, please try again \n";
			return;
		}
	}

	void Delete(int num, int pin){
		sort();
		node *temp = binarySearch(head, num);
		node *current = head;
		node *previous;
		node *newhead = head->next;
		
		if (temp == head){
			if (checkPin(pin, temp->acPin)){
				delete head;
				head = newhead;
				return;
			}
			else {
				cout <<"Incorrect PIN, please try again \n";
				return;
			}
		}
		
		while (current != temp){
			if (current == NULL || temp == NULL){
				break;
			}
			previous=current;
			current=current->next;
		}

		if (temp == NULL){
			cout << "Account does not exist \n";
			return;
		}
		else if(checkPin(pin, temp->acPin)){
			previous->next = current->next;
			delete current;
		}else{
			cout <<"Incorrect PIN, please try again \n";
			return;
		}
	}

	void withdraw(int num, int wnum, char choice, int pin){

		sort();
		node *temp = binarySearch(head, num);

		if (temp == NULL){
			cout <<"Account does not exist \n";
			return;
		}else {
			if(choice == 'c' && checkPin(pin, temp->acPin) && hasMoney(wnum, num, choice)){
				temp->checkBal = temp->checkBal - wnum;
			}
			else if(choice == 's' && checkPin(pin, temp->acPin) && hasMoney(wnum, num, choice)){
				temp->savBal = temp->savBal - wnum;
			}else if(!checkPin(pin, temp->acPin)){
				cout <<"Incorrect PIN, please try again \n";
				return;
			}else if(!hasMoney(wnum, num, choice)){
				cout << "insufficient funds";
				return;
			}
			else{
				cout << "Invalid input for savings or checking \n";
				cout << "The action was not completed";
				return;
			}
		}
	}

	void deposit(int num, int wnum, char choice, int pin){
		sort();
		node *temp = binarySearch(head, num);

		if (temp == NULL){
			cout <<"Account does not exist \n";
			return;
		}else {
			if(choice == 'c' && checkPin(pin, temp->acPin)){
				temp->checkBal = temp->checkBal + wnum;
			}
			else if(choice == 's' && checkPin(pin, temp->acPin)){
				temp->savBal = temp->savBal + wnum;
			}else if(!checkPin(pin, temp->acPin)){
				cout <<"Incorrect PIN, please try again \n";
				return;
			}
			else{
				cout << "Invalid input for savings or checking \n";
				cout << "The action was not completed";
				return;
			}
		}
	}
	
	void wireTransfer(int num, int snum, char choice, int pin, int amount){
		
		sort();
		node *temp = binarySearch(head, snum);
		node *templ = binarySearch(head, num);
		
		if (accountExists(num) && accountExists(snum) && checkPin(pin, templ->acPin) && hasMoney(amount, num, choice)){
			withdraw(num, amount, choice, pin);
			deposit(snum, amount, 'c', temp->acPin);
		}else if(!checkPin(pin, templ->acPin)){
			cout <<"Incorrect PIN, please try again \n";
			return;
		}else if(!hasMoney(amount, num, choice)){
			cout <<"Insufficient funds \n";
			return;
		}else{
			cout <<"One of those accounts does not exist \n";
			return;
		}
		
	}

	void tempAll (node *headRef){
		if (headRef == NULL) return;
		else{
			cout << headRef->acNum << " " << headRef->acName << " \n";
			tempAll(headRef->next);
		}
	}

	void sort(){
		head = mergeSort(head);
	}

	node *mergeSort(node *headRef){

		node *list2;

		if (headRef == NULL){
			return NULL;
		}

		else if  (headRef->next == NULL){
			return headRef;
		}

		else {
			list2 = split(headRef);
			return merge(mergeSort(headRef), mergeSort(list2));
		}

	}

	node *merge(node *firstNode, node *secondNode){

		if (firstNode == NULL) return secondNode;
		else if (secondNode == NULL) return firstNode;
		else if (firstNode->acNum <= secondNode->acNum){
			firstNode->next = merge(firstNode->next, secondNode);
			return firstNode;
		}

		else {
			secondNode->next = merge(firstNode, secondNode->next);
			return secondNode;
		}

	}

	node *split(node *myNode){
		node *secondNode;

		if (myNode == NULL) return NULL;
		else if (myNode->next == NULL) return NULL;
		else {
			secondNode = myNode->next;
			myNode->next = secondNode->next;
			secondNode->next = split(secondNode->next);
			return secondNode;
		}
	}

	// function to find out middle element
	node *middle(node *start, node *last){
		if (start == NULL){
			return NULL;
		}

		node *slow = start;
		node *fast = start->next;

		while (fast != last){
			fast = fast->next;
			if (fast != last){
				slow = slow->next;
				fast = fast->next;
			}
		}

		return slow;
	}

	node *binarySearch(node *head, int value){
		node *start = head;
		node *last = NULL;

		do{
			node *mid = middle(start, last);


			if (mid == NULL){
				return NULL;
			}

			if (mid->acNum == value){
				return mid;
			}

			else if (mid->acNum < value){
				start = mid->next;
			}
			else{
				last = mid;
			}
		}
		while (last == NULL || last->next != start);

		return NULL;
	}
	
	bool checkPin(int entered, int actual){
		
		if (entered == actual){
			return true;
		}else {
			return false;
		}
		
	}
	
	bool accountExists(int num){
		sort();
		node *temp = binarySearch(head, num);
		if (temp == NULL){
			return false;
		} else{
			return true;
		}
	}
	
	bool hasMoney(int money, int acc, char choice){
		sort();
		node *temp = binarySearch(head, acc);
		
		if ( temp ==NULL){
			return false;
		}else if(choice == 'c'){
			if ((temp->checkBal - money) < 0){
				return false;
			}else{
				return true;
			}
		}else{
			if ((temp->savBal - money) < 0){
				return false;
			}else{
				return true;
			}
		}
	}

};





