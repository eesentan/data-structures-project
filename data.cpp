#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

// 
// 
// 	
// 	ELIF NAZ ESENTAN
// 	
//   	
// 



// 
// 
// 
// 
// 
//   ::::CLASS DECLARATION ::::
// 
// 
// 
// 
// 
// 
using namespace std;

class Node
{
public:
    Node* next;
    string data;
};


using namespace std;

class LinkedList
{
public:

    Node* head;
    int size;
    

    LinkedList();
    void add(string data);
    void display();
    void deleteNth();
    void insertNth();
    void openFileName();
    void saveFileName();
    void move();
    void replace();
    //void next();
    //void prev();
   // void undo();
    
};

LinkedList::LinkedList(){
    this->size = 0;
    this->head = NULL;
}
// 
// 
// 
// 
// 
// 
//   ::::ADD FUNCTION ::::
// 
// 
// 
// 
// 
// 
void LinkedList::add(string data){

    Node* node= new Node();
    node->data = data;
    node->next = head;
    head = node;
    
}
// 
// 
// 
// 
// 
// 
//   ::::PRINT FUNCTION ::::
// 
// 
// 
// 
// 
// 
void LinkedList::display() {

    Node* head = this->head;

    int i = 1;
    while(head != NULL){
    
        cout << i << ": " << head -> data <<endl;
        head = head->next;
        i++;
    }
}
// 
// 
// 
// 
// 
// 
//   ::::OPEN FILENAME FUNCTION ::::
// 
// 
// 
// 
// 
// 
void LinkedList::openFileName() {
	string inmyfile;
	
	cout<<"Enter file name:";   //  Please enter your file name here which you have created before
	cin>>inmyfile;
	
	Node* node= new Node();
	
	string line;
	ifstream file;
	file.open(inmyfile.c_str());
	
	while(file.is_open()) {
		while(getline(file,line)){
		
		cout<<line<<endl;
		
		node->data = line;
	    	node->next = head;
	    	head = node;
	    	this->head = node;
	    	this->size++;

		}
	}
}
// 
// 
// 
// 
// 
// 
//   ::::SAVE FILENAME FUNCTION ::::
//   
// 	
// 
// 
// 
// 
void LinkedList::saveFileName() {

	Node* node= new Node();
	Node* current = new Node();
	
	current = head;
	ofstream myFile;
	myFile.open("");    //  Please enter your file name here which you have created before
	if(myFile.is_open()) {
	
		for (current = head; current != NULL;current=current -> next) {
			myFile << current -> data<<endl;
		}
	myFile.close();
	cin.get();
	cout <<"Your list has successfully saved!" <<endl;

	}
}

// 
// 
// 
// 
// 
// 
//   ::::DELETE FUNCTION ::::
// 
// 
// 
// 
// 
// 
void LinkedList::deleteNth() {
	int n; //   delete from position n
	
	cout<<"Enter n:";
	cin>>n;
	
	Node* temp = new Node();
	Node* current = new Node();
	Node* prev = new Node();
	current = head;
	
	if (head == NULL ) {
		cout <<"List is empty!"<<endl;
		return ;
	}
	else {
		for (int i=0 ; i<n-1; i++) {
			prev = current;
			current = current -> next;
		}
		prev -> next = current -> next;
		current = NULL;
		delete current;
	}
	
}
// 
// 
// 
// 
// 
// 
//   ::::MOVE FUNCTION ::::
// 
// 
// 
// 
// 
// 
 
void LinkedList::move() {

	int n,m;   // move from line n to line m
	Node* temp = new Node();
	Node* current = new Node();
	Node* prev = new Node();
	current = head;
	cout << "Enter line to move from:";
	cin >> n;
	
	cout << "Enter line to move to:";
	cin >> m;
	
	if ( n > 0 && m >0 ){
		for (int i=0; i<n-1 ; i++) { 

			current = current -> next;    
		}
		temp = current ->next;
		current ->next = temp -> next;
		current = head;
	
		for (int j=0; j<(m-n)+1; j++) { 
	
			current = current -> next; 
	
		}
		temp -> next = current ->next;
		current -> next = temp;
	}
	
}
// 
// 
// 
// 
// 
// 
//   ::::REPLACE FUNCTION ::::
// 
// 
// 
// 
// 
// 
void LinkedList::replace() {
	
	int n;
	string newLine;
	
	Node* current = new Node();
	current = head;
	
	if (head == NULL ) {
		cout << "List is empty!" <<endl;
	}
	else {
		cout << "Enter the line to update:" ;
		cin >> n;
		
		if ( n > 0) {
			cout << "Enter the new line:";
			cin >> newLine;
			
			for (int i=0; i<n-1; i++) {
				current = current -> next;
			}
			current -> data = newLine;
		}
	}
}
// 
// 
// 
// 
// 
// 
//   ::::INSERT FUNCTION ::::
// 
// 
// 
// 
// 
// 
void LinkedList::insertNth() {
	int n=0;  //   insert n to linked list
	string x;
	
	cout<<"Enter n:";
	cin>>n;
	
	cout<<"Enter text:";
	cin>>x;
	
	Node *temp = new Node();
	Node *current = new Node();
	Node *prev = new Node();
	current = head;
	
	for (int i=0 ; i<n-1; i++) {
		prev = current;
		current = current -> next;
	}
        temp -> data = x;
        prev -> next = temp;
        temp -> next =current;
}
// 
// 
// 
// 
// 
// 
//   ::::MAIN FUNCTION ::::
// 
// 
// 
// 
// 
// 
int main()
{
	LinkedList* linkedlist = new LinkedList();
    	int select;

	linkedlist->add("My 10th line");
	linkedlist->add("My 9th line");
	linkedlist->add("My 8th line");
	linkedlist->add("My 7th line");
	linkedlist->add("My 6th line");
	linkedlist->add("My 5th line");
	linkedlist->add("My 4th line");
	linkedlist->add("My 3rd line");
	linkedlist->add("My 2nd line");
	linkedlist->add("My 1st line");
	linkedlist->display();

	
	
	
    while (true) {
    
	    cout << "1.Open filename." <<endl;
	    cout << "2.Save filename." << endl;
	    cout << "3.Insert n text." << endl;
	    cout << "4.Delete n." << endl;
	    cout << "5.Move n m" << endl;
	    cout << "6.Replace n text." << endl;
	    cout << "7.Next." << endl;
	    cout << "8.Prev." << endl;
	    cout << "9.Undo." << endl;
	    cout << "10.Enter -1 to exit the menu." << endl;
	    
	    cout << "Please enter your selection:";
	    cin >> select;
	   
	    if (select == 1) {   // open filename
	    	
	    	linkedlist -> openFileName();
	    	linkedlist-> display();
	    }
	    if (select == 2) {   // save filename
	    	linkedlist -> saveFileName();
	    	linkedlist->display();
	    }
	    if (select == 3) {   // insert
	    	linkedlist -> insertNth();
	    	linkedlist->display();
	    }
	    if (select == 4) {   //delete
	    	linkedlist->deleteNth();
	    	linkedlist -> display();
	    	
	    }
	    if (select == 5) {   // move
	    	linkedlist -> move();
	    	linkedlist -> display();
	    }
	    if (select == 6) {   // replace
	   	linkedlist -> replace();
	   	linkedlist -> display();
	    }
	    if (select == 7) {   //next
	    	//linkedlist -> next();
	    	//linkedlist -> display();
	    }
	    if (select == 8) {   // prev
	    	//linkedlist -> prev();
	    	//linkedlist -> display();
	    }
	    if (select == 9) {   // undo 
	    	//linkedlist -> undo();
	    	//linkedlist -> display();
	    	
	    }
	    if (select == -1) { 
	    	break;
	    }
    
    }
}   
