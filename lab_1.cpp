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
	   while(current != nullptr){
		if(current->next != nullptr && current->username == username){
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
    // TODO: implement
    
}

// Returns number of nodes.
size_t size(User* head) {
    // TODO: implement
    
    return 0;
}

// Prints usernames in order, separated by " -> " then " -> NULL".
// Example: alice -> bob -> charlie -> NULL
void printUsers(User* head) {
    // TODO: implement
    
}

int main() {
    // Write code here to test your implementation
	User* head = nullptr;
	cout << (removeFront(head) ? "User Removed\n" : "Could not remove User since list is empty\n");


	cout << (insertUser(head, "alice", "1234") ? "Inserted\n" : "Duplicate\n");

	cout << (insertUser(head, "bob", "abcd") ? "Inserted\n" : "Duplicate\n");

	cout << (insertUser(head, "alice", "xxxx") ? "Inserted\n" : "Duplicate\n");

	cout << (insertUser(head, "charlie", "pass") ? "Inserted\n" : "Duplicate\n");

	cout << (insertUser(head, "david", "password123") ? "Inserted\n" : "Duplicate\n");

	if(findUser(head, "charlie") != nullptr){
	cout << "User found: " << findUser(head, "charlie")->username << endl;
	}
	else
	cout << "User Not Found\n";

	cout << (authenticate(head, "bob", "password") ? "Login Accepted\n" : "Password or Username is Incorrect\n");
	cout << (authenticate(head, "bob", "abcd") ? "Login Accepted\n" : "Password or Username is Incorrect\n");

	cout << (removeFront(head) ? "User Removed\n" : "Could not remove User since list is empty\n");
	
	cout << (removeByUsername(head, "bob") ? "Removed User\n" : "User not Found\n");
	cout << (removeByUsername(head, "frank") ? "Removed User\n" : "User not Found\n");

    return 0;
}
