// Lab 1: Singly Linked List for Username/Password storage

// Goal: Implement a simple credential store using a singly linked list

// Instructions:
// 1) Search for "TODO" and implement each function.
// 2) Build & run:   g++ -std=c++17 -O2 -Wall linked_lists.cpp -o lab && ./lab
// 3) Do not change function signatures
#include <iostream>
#include <string>
using namespace std;


struct User {
    string username;
    string password;
    User* next;

    User(string u, string p) {
        username = u;
        password = p;
        next = nullptr;
    }
};

// Inserts a new (username, password) at the END of the list.
// If username already exists, do NOT insert a duplicate; return false.
// Otherwise insert and return true.
bool insertUser(User*& head, const string& username, const string& password) {
   User* current = head;

	while (current != nullptr) {
	if (current->username == username){
	    return false;
	}
	current = current->next;
     }
	User* newUser = new User(username, password);
	if(head == nullptr) {
	    head = newUser;
	    return true;
	}

	current = head;
	while (current->next != nullptr){
	    current = current->next;
	}
	current->next = newUser;

    return true;
}

// Returns pointer to the node with matching username; otherwise nullptr.
User* findUser(User* head, const string& username) {

    User* current = head;
	while (current != nullptr) {
	    if(current->username == username){
		return current;
	    }
	current = current->next;
	}

    return nullptr;
}

// Returns true if (username, password) matches an existing node; false otherwise.
bool authenticate(User* head, const string& username, const string& password) {
   User* current = head;
	while(current != nullptr){
	    if(current->username == username && current->password == password){
		return true;
	    }
	current = current->next;
	}
    return false;
}

// Deletes the FIRST node (head) and updates head. No-op if list is empty.
// Return true if a node was deleted, false otherwise.
bool removeFront(User*& head) {
    // List is emply no operation
    if(head == nullptr){
        return false;
    }

    User* temp = head;
    head = head->next;
    delete temp;
    return true;
}

// Deletes the node with matching username (first match only).
// Return true if a node was found & deleted; false if not found.
bool removeByUsername(User*& head, const string& username) {
    // If the node to delete is the head
       if (head->username == username){
	User* temp = head;
	head = head->next;
	delete temp;
	return true;
	}

	User* current = head;
	   while(current->next != nullptr){
		if(current->next->username == username){
		    User* temp = current->next;
		    current->next = current->next->next;
		    delete temp;
		    return true;
		}
		    current = current->next;
	    }
	    return false;
}

// Deletes ALL nodes and sets head=nullptr. 
void clearList(User*& head) {
    User* current = head;
	while(current != nullptr){
	    User* temp = current;
	    current = current->next;
	    delete temp;
	}
	head = nullptr;
}

// Returns number of nodes.
size_t size(User* head) {
    size_t count = 0;

	User* current = head;
	  while(current != nullptr){
	      count++;
	      current = current->next;
	  }
    return count;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
	cout << "User List: ";
	User* current = head;
	while (current != nullptr){
	    cout << "(" << current->username << ", " << current->password << ") -> ";
	    current = current->next;
	}
	cout << "NULL\n";
}

int main() {
    // Write code here to test your implementation
	User* head = nullptr;
	cout << (removeFront(head) ? "User Removed\n" : "Could not remove User since list is empty\n");

	cout << (insertUser(head, "alice", "1234") ? "Inserted\n" : "Duplicate\n");
	printUsers(head);

	cout << (insertUser(head, "bob", "abcd") ? "Inserted\n" : "Duplicate\n");
	printUsers(head);

	cout << (insertUser(head, "alice", "xxxx") ? "Inserted\n" : "Duplicate\n");
	printUsers(head);

	cout << (insertUser(head, "charlie", "pass") ? "Inserted\n" : "Duplicate\n");
	printUsers(head);

	cout << (insertUser(head, "david", "password123") ? "Inserted\n" : "Duplicate\n");
	printUsers(head);
	// Size of the list initially
	cout << "The size of the list is: " << size(head) << endl;

	if(findUser(head, "charlie") != nullptr){
	cout << "User found: " << findUser(head, "charlie")->username << endl;
	}
	else
	cout << "User Not Found\n";
	//Authenticating
	cout << (authenticate(head, "bob", "password") ? "Login Accepted\n" : "Password or Username is Incorrect\n");
	cout << (authenticate(head, "bob", "abcd") ? "Login Accepted\n" : "Password or Username is Incorrect\n");
	//Removing from front
	cout << "Now removing user front fromt\n";
	cout << (removeFront(head) ? "User Removed\n" : "Could not remove User since list is empty\n");
	printUsers(head);

	cout << "Removing User 'david'\n";
	cout << (removeByUsername(head, "david") ? "Removed User\n" : "User not Found\n");
	cout << "Removing User 'frank'\n";
	cout << (removeByUsername(head, "frank") ? "Removed User\n" : "User not Found\n");
	printUsers(head);
	//Size of the List after Deletions
	cout << "The size of the list is: " << size(head) << endl;

	cout << "Clearing List!\n";
	clearList(head);
	//Size of the list after clearing
	cout << "The size of the list is: " << size(head) << endl;
	printUsers(head);
    return 0;
}
