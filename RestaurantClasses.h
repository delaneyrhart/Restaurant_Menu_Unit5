#include<string>
using namespace std;

class MenuItem
{
  private:
    string name;
    double itemCost; 
    string desc; 
    char addLetter; 
    char removeLetter;
    int count;
  public:
    void setName(string n) { name = n;}
    void setItemCost(double i) { itemCost = i; }
    void setDesc(string d) { desc = d; }
    void setAddLetter(char l) { addLetter = l; }
    void setRemoveLetter(char r) { removeLetter = r; }
    void setCount(int c) { count = c; }
    string getName() {return name;}
    double getItemCost() { return itemCost; }
    string getDesc() { return desc; }
    char getAddLetter() { return addLetter; }
    char getRemoveLetter() { return removeLetter; }
    int getCount() { return count; }
    MenuItem()
    {
      count = 0;
    }
};

class Receipt
{
  private:
    double totalDue;
    double change;
    double tip;
    string payment;
    double tender;
  public:
    void setTotalDue(double tD) { totalDue = tD; }
    void setChange(double ch) { change = ch; }
    void setTip(double ti) { tip = ti; }
    void setPayment(string p) { payment = p; }
    void setTender(double td) { tender = td; }
    double getTotalDue() { return totalDue; }
    double getChange() { return change; }
    double getTip() { return tip; }

    Receipt()
      {
        tip = (.20);
      }
    
};