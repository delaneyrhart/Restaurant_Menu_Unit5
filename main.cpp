//A  Restaurant Project Struct style Dr_T Dr. Tyson McMillan 10-2-2019
//Delaney Hart - COSC 1437
//4/29/2022

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "InputValidationExtended.h"
#include "RestaurantClasses.h"
#include "RestaurantFunctions.h"
using namespace std; 

//I moved the classes and functions because I was getting confused with so many lines

int main() 
{
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 
  
  return 0; 
}