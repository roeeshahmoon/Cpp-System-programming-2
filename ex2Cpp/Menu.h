/* Assignment C++: 1
   Author: Roee Shahmoon, ID: 206564759
   Author: Noam Klainer,  ID: 316015411
*/
#ifndef EX2CPP_MENU_H
#define EX2CPP_MENU_H

#include <iostream>
using namespace std;

class Menu {// Menu has no fields only public methods
public:
    Menu();
    void mainMenu();
    void setMenu();
    void queueMenu();
    ~Menu();
};


#endif //EX2CPP_MENU_H
