#ifndef BANK_V2_LIST_H
#define BANK_V2_LIST_H

#endif //BANK_V2_LIST_H

#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
    int acNum;
    int acBal;
    int acPin;
    string acName;
    node *next;
};

class list{
private:
    node *head, *tail;
public:
    list(){
        head=NULL;
        tail=NULL;
    }
    void createNode (int num, int bal, int pin, string name){
        node *temp=new node;
        temp->acNum=num;
        temp->acBal=bal;
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

    void display_account(int num){
        node *temp;
        temp=head;
        while (temp->acNum!=num){
            temp=temp->next;
            if (temp==tail && temp->acNum!=num){
                cout<<"Sorry this account number does not exit, please try again \n";
                break;
            }
        }

        if (temp->acNum==num){
            cout<<"hello "<<temp->acName<<"\n"<<"your account number is "<<temp->acNum<<"\n"<<"your balance is "<<temp->acBal<<"$"<<"\n";
        }
    }

    void Delete(int num){
        node *current;
        node *previous=new node;
        current=head;
        while(current->acNum!=num){
            previous=current;
            current=current->next;
            if (current==tail){
                cout<<"could not find this account \n";
                break;
            }
        }
        if (current->acNum==num){
            previous->next=current->next;
            delete current;
        }
    }

    void withdraw(int num, int wnum){
        node *temp;
        temp=head;
        while (temp->acNum!=num){
            temp=temp->next;
            if (temp==tail && temp->acNum!=num){
                cout<<"Sorry this account number does not exit, please try again \n";
                break;
            }
        }

        if (temp->acNum==num){
            temp->acBal = temp->acBal - wnum;
            display_account(num);
        }
    }

    void deposit(int num, int wnum){
        node *temp=new node;
        temp=head;
        while (temp->acNum!=num){
            temp=temp->next;
            if (temp==tail && temp->acNum!=num){
                cout<<"Sorry this account number does not exit, please try again \n";
                break;
            }
        }

        if (temp->acNum==num){
            temp->acBal = temp->acBal + wnum;
            display_account(num);
        }
    }

    void allAccounts(){

        node *temp;
        temp=head;
        while (temp != NULL){
            cout << temp->acNum << " " << temp->acName << " " << temp->acPin << " $" << temp->acBal << endl;
            temp=temp->next;
        }
    }

    void searchAccount(int num){
        node *temp;
        temp=head;
        while (temp->acNum!=num){
            temp=temp->next;
            if (temp==tail && temp->acNum!=num){
                cout<<"Sorry this account number does not exit, please try again \n";
                break;
            }
        }

        if (temp->acNum==num){
            cout<<"hello "<<temp->acName<<"\n"<<"your account number is "<<temp->acNum<<"\n"<<"your balance is $"<<temp->acBal<<"\n";
        }
    }

    void checkValidAccount(){

    }

};





