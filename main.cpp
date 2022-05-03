/*A  Delaney Hart 
COSC 1437 Tarrant County College
Dr. McMillan
4/29/2022
A program meant to simulate ordering at a restaurant.
This program was practice for classes and vectors.
*/

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