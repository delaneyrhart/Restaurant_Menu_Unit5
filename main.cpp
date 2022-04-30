//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
//Delaney Hart - COSC 1437
//4/29/2022


#include "includes.h"


//I moved the classes and functions because I was getting confused with so many lines

int main() 
{
  int loopMenu;
  do{
    cout << "Would you like to order? Type 1 to order or 2 to exit." << endl;
     loopMenu = validateInt(loopMenu);
    if(loopMenu == 1)
    {
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 
      }
    else if(loopMenu == 2)
    {
      cout << "Bye" << endl;
      system("clear");
    }
    else
    {cout << "Invalid input" << endl;}
    }while(loopMenu != 2);
  return 0; 
}