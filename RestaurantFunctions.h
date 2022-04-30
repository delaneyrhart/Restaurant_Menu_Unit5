#ifndef RESTAURANT_FUNCTIONS_H
#define RESTAURANT_FUNCTIONS_H

//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Hotdog", "Chips", "Dr. Pepper", "Donut", "Coffee"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 
  vector<double> defaultItemCost = {3.00, 4.00, 2.00, 1.00, 3.00, 2.00, 3.50 };

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].setName(defaultMenuNames[i]); 
    entireMenu[i].setAddLetter(defaultAddLetters[i]); 
    entireMenu[i].setRemoveLetter(defaultRemoveLetters[i]); 
    entireMenu[i].setItemCost(defaultItemCost[i]);
    //entireMenu[i].setItemCost(3.00 + i); //set a random starter cost for each item
    entireMenu[i].setCount(0); //initialze all counts to 0
    entireMenu[i].setDesc("delicious"); //set all default desc to "delicous"
  }
}



void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].getAddLetter() << ")" << setw(10) << m[i].getName() 
    << setw(5) << "$" << m[i].getItemCost() << setw(5) << "(" << m[i].getRemoveLetter()
    << ")" << setw(7) << m[i].getCount() << setw(13) << m[i].getDesc() 
    <<endl; 
  }
}


void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 
  double tip = 0.0;
  string tipQ;
  string payment;
  double tender = 0.0;
  int c = 0;
  
  double change;

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].getAddLetter())
      {
        cout << "\nMenu Item " << m[i].getAddLetter() << " selected."; 
       m[i].setCount(c++); //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].getName() << endl;
        subtotal += m[i].getItemCost(); //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].getRemoveLetter())
      {
        cout << "\nRemove Item " << m[i].getRemoveLetter() << " selected."; 
        if(m[i].getCount() > 0) //subtract if and only if the count is > 0
        {
         m[i].setCount(c--); //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].getName() << endl;
          subtotal -= m[i].getItemCost(); //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].getName() << endl;
        }
      }
      else if(
                option != m[i].getAddLetter() && 
                option != m[i].getRemoveLetter() &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here

do{
cout << "\nWould you like to leave a tip? Type Y for YES or N for NO: " << endl;
tipQ = validateString(tipQ);  
  if(tipQ == "Y" || tipQ == "y")
    {cout << "Suggested gratuity (20%): " << (.20 * subtotal) << endl;
    cout << "Please enter the tip amount below: " << endl;
    cout << "> $";
    tip = validateDouble(tip);
      break;
      }
  else if(tipQ == "N" || tipQ == "n")
    {cout << " :( okay " << endl;
      break;}
  else
    {cout << "Invalid input";};
  }while(tipQ != "N" || tipQ != "n");

double tax = .0625 * subtotal;
double totalTax = tax + subtotal;
double totalDue = subtotal + tip + tax;
  
cout << "Your final total will be: $" << totalDue << endl;

do{
cout << "Would you like to pay with cash or credit? Type CREDIT for credit or CASH for cash: " << endl;
payment = validateString(payment);
  if(payment == "CREDIT" || payment == "credit")
  {
    cout << "Please follow the instructions on the payment terminal..." << endl;
    cout << "Payment processed" << endl;
    break;
  }
  else if(payment == "CASH" || payment == "cash")
  {
    cout << "Please enter the cash amount below so that we can calculate your change: " << endl;
    cout << "> $";
    tender = validateDouble(tender);
      if(tender >= totalDue)
      {
        change = tender - totalDue;
        cout << "Your change is $" << change << endl;
        break;
      }
      else if(tender < totalDue)
      {
        cout << "You still owe $" << (totalDue - tender) << endl; //figure out some way to loop back around with only the owed amount...
      }
      else
      {
        cout << "Invalid input " << endl;
      }
  }
  }while(tender < totalDue);
  //handle reciept generation here

    cout << "\nRECEIPT" << endl;
    cout << "Total before tax: " << subtotal << endl;
    cout << "Tax: " << tax << endl;
    cout << "Total after tax: " << totalTax << endl;
    cout << "Tip: " << tip << endl;
    cout << "Total Due: " << totalDue << endl;
    cout << "Change: " << change << endl;
  
  ofstream outfile;
  outfile.open("Receipt.txt");
  outfile << fixed << setprecision(2);//set doubles to 2 decimal places
    outfile << "\nRECEIPT" << endl;
    outfile << "Total before tax: " << subtotal << endl;
    outfile << "Tax: " << tax << endl;
    outfile << "Total after tax: " << totalTax << endl;
    outfile << "Tip: " << tip << endl;
    outfile << "Total Due: " << totalDue << endl;
    outfile << "Change: " << change << endl;
  outfile.close();
  system("Receipt.txt");

}

 
#endif