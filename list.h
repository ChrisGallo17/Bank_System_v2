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
public:
	node *head, *tail, *newhead, *newtail;
    bool result;

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
        sort();
    	node *temp = binarySearch(head, num);
    	
    	if (temp == NULL){
    		cout <<"Account does not exist \n";
    		return;
		}else {
			cout << "welcome " << temp->acName << " your account balance is " << temp->acBal << "\n";
		}
    }

    void Delete(int num){
        sort();
        node *temp = binarySearch(head, num);
        node *current = head;
        node *previous;
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
		else{
			previous->next = current->next;
			delete current;
		}
    }

    void withdraw(int num, int wnum){ 
	
		sort();
		node *temp = binarySearch(head, num);
		
		if (temp == NULL){
			cout <<"Account does not exist \n";
			return;
		}else {
			temp->acBal = temp->acBal - wnum;
			display_account(num);
		}      
    }

    void deposit(int num, int wnum){   
		sort();
		node *temp = binarySearch(head, num);
		
		if (temp == NULL){
			cout <<"Account does not exist \n";
			return;
		}else {
			temp->acBal = temp->acBal + wnum;
			display_account(num);
		}     
    }

    void allAccounts(){
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
	
	


    /*void searchAccount(int num){
        node *temp;
        temp = head;
        while (temp->acNum != num){
            temp = temp->next;
            if (temp == tail && temp->acNum != num){
                cout<<"Sorry this account number does not exit, please try again \n";
                break;
            }
        }

        if (temp->acNum==num){
            cout << "hello " << temp->acName << "\n" << "your account number is ";
            cout << temp->acNum << "\n" << "your balance is $" << temp->acBal << "\n";
        }
    }*/

    // uses recursion to search for an account number in the linked list
    /*void searchRecursive(node *ptr, int searchNum){

        if (ptr == NULL){ // The number is NOT in the list
            result = false;
        }
        else if(ptr->acNum == searchNum){ // The number IS in the list
            result = true;
        }
        else{
            searchRecursive(ptr->next, searchNum);
        }
    }

    // checks if account exists
    // created a function for this because you can only pass *head
    // inside of this list file because head is private
    int accountExists(int num){
        searchRecursive(head, num);
    }*/

    /*
    node* Merge(node* h1, node* h2)
    {
        node *t1;
        node *t2;
        node *temp;

        // Return if the first list is empty.
        if(h1 == NULL)
            return h2;

        // Return if the Second list is empty.
        if(h2 == NULL)
            return h1;

        t1 = h1;

        // A loop to traverse the second list, to merge the nodes to h1 in sorted way.
        while (h2 != NULL)
        {
            // Taking head node of second list as t2.
            t2 = h2;

            // Shifting second list head to the next.
            h2 = h2->next;
            t2->next = NULL;

            // If the data value is lesser than the head of first list add that node at the beginning.
            if(h1->acNum > t2->acNum)
            {
                t2->next = h1;
                h1 = t2;
                t1 = h1;
                continue;
            }

            // Traverse the first list.
            flag:
            if(t1->next == NULL)
            {
                t1->next = t2;
                t1 = t1->next;
            }
                // Traverse first list until t2->data more than node's data.
            else if((t1->next)->acNum <= t2->acNum)
            {
                t1 = t1->next;
                goto flag;
            }
            else
            {
                // Insert the node as t2->data is lesser than the next node.
                temp = t1->next;
                t1->next = t2;
                t2->next = temp;
            }
        }

        // Return the head of new sorted list.
        return h1;
    }


// A function implementing Merge Sort on linked list using reference.
    void MergeSort(node **mHead)
    {
        node *first;
        node *second;
        node *temp;
        first = *mHead;
        temp = *mHead;

        // Return if list have less than two nodes.
        if(first == NULL || first->next == NULL)
        {
            return;
        }
        else
        {
            // Break the list into two half as first and second as head of list.
            while(first->next != NULL)
            {
                first = first->next;
                if(first->next != NULL)
                {
                    temp = temp->next;
                    first = first->next;
                }
            }
            second = temp->next;
            temp->next = NULL;
            first = *mHead;
        }

        // Implementing divide and conquer approach.
        MergeSort(&first);
        MergeSort(&second);

        // Merge the two part of the list into a sorted one.
        *mHead = Merge(first, second);
    }

    void sortAccounts(){
        // Send reference of head into MergeSort().
        MergeSort(&head);

        // Printing the sorted data.
        cout<<"\nSorted Data \n";

        newhead = NULL;
        newtail = NULL;

        while(head != NULL)
        {
            cout << head->acNum << "\t" << head->acName << "\t";
            cout << head->acPin << "\t$" << head->acBal << "\n";

            createNode(head->acNum, head->acBal, head->acPin, head->acName);
            if(newhead == NULL) {
                newhead = newtail;
            }

            head=head->next;
        }
    }
*/
};





