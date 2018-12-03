#include <iostream>
#include "list.h"
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
list List;
int cursor;


class bank{
public:
	void menu();
	void addAccount();
	void viewAccount();
	void removeAccount();
	void withdraw();
	void deposit();
	void allAccounts();
};

int main() {
	bank bk;

	List.createNode(5, 1, 123, "Colten", 's');
	List.createNode(3, 100, 123, "Paul", 'c');
	List.createNode(4, 555, 123, "Sean", 's');
	List.createNode(2, 1700, 123, "Coocoo", 'c');
	List.createNode(1, 14, 123, "Batman", 's');
	List.createNode(6, 14, 123, "Chris", 's');
	List.createNode(8, 14, 123, "Jose", 's');
	List.createNode(23, 14, 123, "Mondo", 's');

	cout << "Welcome to your Banking System,\n";
	bk.menu();
	return 0;
}

void bank::menu(){

	cout << "\n1: Create an account \n";
	cout << "2: View account balance \n";
	cout << "3: Withdraw or deposit from account \n";
	cout << "4: Remove account \n";
	cout << "5: View all accounts \n";
	cout << "6: Transfer Money \n";
	cout << "7: Search existing account \n";
	cout << "8: Sort Accounts \n";
	cout << "9: Exit \n";

	cursor = 0;

	cin >> cursor;

	// Create Account
	if (cursor == 1)
	{
		addAccount();
		menu();
	}

		// View Account
	else if (cursor == 2){
		viewAccount();
		menu();
	}

		// Withdraw or Deposit
	else if (cursor ==3){
		char input;

		cout <<"Please press w to withdraw, and d to deposit \n";
		cin >>input;

		if (input == 'w'){
			withdraw();
		}
		else if (input == 'd'){
			deposit();
		}
		else {
			cout <<"Please enter a valid option \n";
		}
		menu();
	}

		// Remove Account
	else if(cursor == 4){
		removeAccount();
		menu();
	}

		// View all accounts
	else if(cursor == 5){
		allAccounts();
		menu();
	}

		// Transfer Money
	else if(cursor == 6){
		cout << "transfer money feature: work in progress\n";
		menu();
	}

		// Search For Account
	else if(cursor == 7){
		int num;
		cout << "What account number were you looking for? \n";
		cin >> num;
		//List.accountExists(num);
		if(List.result == true){
			cout << "This Account Exists! \n";
		}
		else if(List.result == false){
			cout << "This account DOESN'T exist! \n";
		}
		else{ //if this is displayed then there's a bug
			cout << "There is a bug here \n";
		}
		menu();
	}

		// Sort List
	else if(cursor == 8){
		List.sort();

		cout << "Merge Sort Complete. \n";
		allAccounts();
		menu();
	}

	else if(cursor == 9){
		exit(9);
	}

	else{
		cout << "Invalid input, try again \n";
		menu();
	}

}

// == Needs to check if account number is already taken before creating ==
void bank::addAccount(){
	int accNumber, pin, balance;
	string name;
	char choice;

	cout <<"Please enter an account number you would like to use \n";
	cin >>accNumber;

	cout <<"Enter a pin number you would like to use for your account \n";
	cin >>pin;

	cout <<"Enter your name: \n";
	cin >>name;

	cout << "Would you like to start with money in your Savings or Checking account? \n";
	cout << "Type c for Checking / s for Savings \n";
	cin >> choice;

	cout <<"How much money you would like for your starting balance? \n";
	cin >>balance;

	List.createNode(accNumber, balance, pin, name, choice);
}

void bank::viewAccount(){
	int accNumber;

	cout <<"Please enter your account number \n";
	cin >>accNumber;

	List.display_account(accNumber);
}

void bank::withdraw(){
	int accNumber, wnum;
	char choice;

	cout <<"please enter your account number \n";
	cin >>accNumber;

	cout << "Would you like to take from your checking or savings account?\n";
	cout << "Type c for checking and s for saving\n";
	cin >> choice;

	cout <<"please enter how much money you would like to take out \n";
	cin >>wnum;

	List.withdraw(accNumber, wnum, choice);
}

void bank::deposit(){
	int accNumber, wnum;
	char choice;

	cout <<"please enter your account number \n";
	cin >>accNumber;

	cout << "Would you like to add to your checking or savings account?\n";
	cout << "Type c for checking and s for saving\n";
	cin >> choice;

	cout <<"please enter how much money you would like to add \n";
	cin >>wnum;

	List.deposit(accNumber, wnum, choice);
}

// fix bug that removes account
void bank::removeAccount(){
	int accNumber;

	cout <<"Please enter account number \n";
	cin >>accNumber;

	List.Delete(accNumber);
}

void bank::allAccounts() {

	cout << "The accounts are as follows: " << endl;
	List.tempAll(List.head);
}
