/* Assignment C++: 1
   Author: Roee Shahmoon, ID: 206564759
   Author: Noam Klainer,  ID: 316015411
*/

#include "Menu.h"
#include "Set.h"
#include "myQueue.h"

#include <iostream>
using namespace std;

Menu::Menu() {} // Constructor of menu

void Menu::setMenu() {
    static int choose;
    static int add_num;
    int flag_set_one = 0, flag_set_two = 0;
    Set set_one, set_two;
    do {
        cout << "*** Welcome to Set Menu ***" << endl;
        cout << "To select an item, enter" << endl;
        cout << "1 Show set 1" << endl;
        cout << "2 Show set 2" << endl;
        cout << "3 add element to set 1" << endl;
        cout << "4 add element tp set 2" << endl;
        cout << "5 Show set1 U set 2 (union)" << endl;
        cout << "6 to exit" << endl;

        cin >> choose;
        if (choose == 1) { //user choose show set 1
            if (flag_set_one) {
                cout << set_one << endl;
            }
            else {
                cout << "Set 1 is empty" << endl;
            }
        }
        if (choose == 2) { //user choose show set 2
            if (flag_set_two) {
                cout << set_two << endl;
            }
            else {
                cout << "Set 2 is empty" << endl;
            }
        }
        if (choose == 3) { //user choose add element to set 1
            flag_set_one = 1;
            cout << "Give a number: ";
            cin >> add_num;
            set_one += add_num;
        }
        if (choose == 4) { //user choose add element to set 2
            flag_set_two = 1;
            cout << "Give a number: ";
            cin >> add_num;
            set_two += add_num;
        }
        if (choose == 5) {
            if (flag_set_one || flag_set_two) { //user choose add element to set 1
                cout << set_one + set_two << endl;
            }
            else {
                cout << "The union is empty" << endl;
            }
        }
        if (choose == 6) {
            //            cout << "Thank you!" << endl;
        }
        if (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5 &&
            choose != 6) {//the user insert Invalid selection
            cout << "Invalid selection." << endl;
        }
    } while (choose != 6);

}
void Menu::queueMenu(){
    static int choose;
    static int Q_size;
    cout << "Enter the size of the queue: ";
    cin >> Q_size;
    myQueue Q(Q_size);
    do{
        cout << "*** Welcome to Queue Menu ***" << endl;
        cout << "To select an item, enter" << endl;
        cout << "1 Show Queue" << endl;
        cout << "2 Insert new element" << endl;
        cout << "3 Remove element" << endl;
        cout << "4 Check the first element" << endl;
        cout << "5 to exit" << endl;

        cin >> choose;
        if (choose == 1) {        //the use
            if (!Q.isEmpty()) {
                cout << Q;
            }
            else {
                cout << "The queue is empty" << endl;
            }
        }

        if (choose == 2) {        //the user choose to insert a new element
            int newelement;
            cout << "insert new element: ";
            cin >> newelement;
            if (Q.getSize() >= Q_size) {
                cout << "Queue is full" << endl;
            }
            else {
                Q.enQueue(newelement);
                cout << "The new queue:" << endl << Q;
            }
        }
        if (choose == 3) {            //the user choose to remove element
            Q.deQueue();
            if (!Q.isEmpty()) {
                cout << "The new queue:" << endl<<Q;
            }
            else {
                cout << "Queue is empty" << endl;
            }
        }
        if (choose == 4) {          //the user choose to check the first element
            if (Q.isEmpty()) {
                cout << "The queue is empty" << endl;
            }
            if (!Q.isEmpty()) {
                cout <<Q.peek() << endl;
            }
        }
        
        if (choose != 1 && choose != 2 && choose != 3 && choose != 4 && choose != 5){//the user insert Invalid selection
            cout<<"Invalid selection."<< endl;
        }
    }
    while (choose != 5);
}

void Menu::mainMenu() {
    static int option;
    do {
        cout << "(1) Set Menu" << endl;
        cout << "(2) Integer Queue Menu" << endl;
        cout << "(3) Exit" << endl;

        cin >> option; //input from the user
        if (option == 1) {
            this->setMenu(); // get into Set Menu
        }
        if (option == 2) {
            this->queueMenu(); // get Into Queue Menu
        }
        if (option != 1 && option != 2 && option != 3) {//the user insert Invalid selection
            cout << "Invalid selection." << endl;
        }

    } while (option != 3); //while input is 1 or 2
     cout << "Goodbye!" << endl;
}

Menu::~Menu() { //destructor
    //cout<<"Deleting a Menu Type...\n";
}


