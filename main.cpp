#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
	struct Node {
		int data;
		Node* prev;
		Node* next;
		Node(int val, Node* p = nullptr, Node* n = nullptr) {
			data = val;
			prev = p;
			next = n;
		}
	};
	Node* head;
	Node* tail;
public:
	// constructor
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	void push_back(int value) {
		Node* newNode = new Node(value);
		if (!tail) // if there's no tail, the list is empty
			head = tail = newNode;
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
	void push_front(int value) {
		Node* newNode = new Node(value);
		if (!head) // if there's no head, the list is empty
			head = tail = newNode;
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void insert_after(int value, int position) {
		if (position < 0) {
			cout << "Position must be >= 0." << endl;
			return;
		}
		Node* newNode = new Node(value);
		if (!head) {
			head = tail = newNode;
			return;
		}
		Node* temp = head;
		for (int i = 0; i < position && temp; ++i)
			temp = temp->next;
		if (!temp) {
			cout << "Position exceeds list size. Node not inserted.\n";
			delete newNode;
			return;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if (temp->next)
			temp->next->prev = newNode;
		else
			tail = newNode; // Inserting at the end
		temp->next = newNode;
	}
	void delete_val(int value) {
		if (!head) return; // Empty list
		Node* temp = head;
		while (temp && temp->data != value)
			temp = temp->next;
		if (!temp) return; // Value not found
		if (temp->prev) {
			temp->prev->next = temp->next;
		} else {
			head = temp->next; // Deleting the head
		}
		if (temp->next) {
			temp->next->prev = temp->prev;
		} else {
			tail = temp->prev; // Deleting the tail
		}
		delete temp;
	}
    // delete node based on position
    void delete_pos(int position) {
        if (!head) return;
        if (position < 0) return;

        Node* temp = head;

        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) return;

        if (temp->prev) {
			temp->prev->next = temp->next;
		} else {
			head = temp->next; // Deleting the head
		}
		if (temp->next) {
			temp->next->prev = temp->prev;
		} else {
			tail = temp->prev; // Deleting the tail
		}
		delete temp;
    }
    // pop the head node
    void pop_front() {
        if (!head) return;

        Node* temp = head;
        head = temp->next;

        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    //pop back node
    void pop_back() {
        if (!tail) return;

        Node* temp = tail;
        tail = temp->prev;

        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }
	void print() {
		Node* current = head;
		if (!current) {
            cout << "List is empty" << endl;
            return;
        }
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void print_reverse() {
		Node* current = tail;
		if (!current) {
            cout << "List is empty" << endl;
            return;
        }
		while (current) {
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
	~DoublyLinkedList() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};

// Driver program to test the required deletion methods
int main() {
	DoublyLinkedList list;

    // Use predetermined list to better demonstrate methods
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    cout << "Original List: ";
    list.print();

    list.delete_pos(2);

    cout << "List after deleting pos 2: ";
    list.print();

    list.delete_pos(0);

    cout << "List after deleting head: ";
    list.print();

    list.delete_pos(2);

    cout << "List after deleting tail: ";
    list.print();

    list.pop_front();

    cout << "List after pop_front: ";
    list.print();

    list.pop_back();

    cout << "List after pop_back: ";
    list.print();

    list.push_back(60);
    list.push_back(70);
    list.push_back(80);

    cout << "List before delete_val: ";
    list.print();

    list.delete_val(60);

    cout << "List after delete_val(60): ";
    list.print();

    list.delete_val(80);

    cout << "List after delete_val(80): ";
    list.print();

    list.pop_front();

    cout << "List after pop_front (single node): ";
    list.print();

    list.pop_back();

    cout << "List after pop_back (empty list): ";
    list.print();
		
	
	return 0;
}