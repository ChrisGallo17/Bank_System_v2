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

	bk.menu();
	return 0;
}

void bank::menu(){

	cout << "\nEnter 1 to create an account \n";
    cout << "Enter 2 to view account balance \n";
    cout << "Enter 3 to withdraw or deposit from account \n";
    cout << "Enter 4 to remove account \n";
    cout << "Enter 5 to view all accounts \n";
    cout << "Enter 6 to exit \n";

    cursor = 0;

    cin >> cursor;

    if (cursor == 1)
    {
        // Create account function
        addAccount();
        menu();
    }

    else if (cursor == 2){
    	viewAccount();
    	menu();
	}

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
			cout <<"PLease enter a valid option \n";
		}
		menu();
	}

	else if(cursor == 4){
		removeAccount();
		menu();
	}

    else if(cursor == 5){
        allAccounts();
        menu();
    }

}

void bank::addAccount(){
	int accNumber, pin, balance;
	string name;

	cout <<"Please enter an account number you would like to use \n";
	cin >>accNumber;

	cout <<"please enter a pin number you would like to use for your account \n";
	cin >>pin;

	cout <<"please enter your name: \n";
	cin >>name;

	cout <<"please enter how much money you would like for your starting balance \n";
	cin >>balance;

	List.createNode(accNumber, balance, pin, name);
	List.display_account(accNumber);
}

void bank::viewAccount(){
	int accNumber;

	cout <<"Please enter your account number \n";
	cin >>accNumber;

	List.display_account(accNumber);

}

void bank::withdraw(){
	int accNumber, wnum;

	cout <<"please enter your account number \n";
	cin >>accNumber;

	cout <<"please enter how much money you would like to take out \n";
	cin >>wnum;

	List.withdraw(accNumber, wnum);
}

void bank::deposit(){
	int accNumber, wnum;

	cout <<"please enter your account number \n";
	cin >>accNumber;

	cout <<"please enter how much money you would like to add \n";
	cin >>wnum;

	List.deposit(accNumber, wnum);
}

void bank::removeAccount(){
	int accNumber;

	cout <<"please enter account number \n";
	cin >>accNumber;

	List.Delete(accNumber);
}

void bank::allAccounts() {

    cout << "The accounts are as follows: " << endl;
    List.allAccounts();
}
