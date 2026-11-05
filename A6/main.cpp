#include <bits/stdc++.h>
using namespace std;
#include <cmath>
#include <iomanip>
#include <iostream>

int main()
{

  int coin = 0;
  int sumCoin = 0;
  float balance = 0.0;
  const float tea = 0.25;
  const float coffee = 0.25;
  char uc1;
  int amount = 0;
  float total = 0.0;
  float totalBalance = 0.0;

  cout << "Welcome to my Coffee/Tea Vending Machine!" << endl;
  cout << endl;

  bool next = true;
  while (next)
  {

    bool nextCoin = true;
    while (nextCoin)
    {
      cout << "Enter coins - 5, 10, or 25 only: ";
      cin >> coin;

      // TODO validate integer

      switch (coin)
      {
      case 0: // fallthrough
        nextCoin = false;
      case 5:  // fallthrough
      case 10: // fallthrough
      case 25:
        sumCoin = coin + sumCoin;
        break;
      default:
        cout << "Invalid value" << endl;
      }
    }

    balance = static_cast<float>(sumCoin) / 100.0;
    cout << fixed << setprecision(2) << endl;
    cout << "Your balance is $" << balance << endl;
    cout << endl;

    cout << "Please pick an option ($0.25 each):" << endl;
    cout << "    C/c: Coffee" << endl;
    cout << "    T/t: Tea" << endl;
    cout << "    Q/q: Quit" << endl;
    cin >> uc1;
    cout << "    >> " << uc1 << endl;

    if ((uc1 == 'c') or (uc1 == 'C'))
    {
      cout << "How many would you like? ";
      cin >> amount;
      total = (coffee * amount);
      totalBalance = balance - total;
      cout << amount << endl;
    }
    else if ((uc1 == 't') or (uc1 == 'T'))
    {
      cout << "How many would you like? ";
      cin >> amount;
      total = (tea * amount);
      totalBalance = balance - total;
      cout << amount << endl;
      cout << endl;
    }
    else if ((uc1 == 'Q') or (uc1 == 'q'))
    {
      cout << "Your total is $" << total << endl;
      cout << "Your balance is $" << balance << endl;
      cout << endl;
      cout << "Thank you for using my Vending Machine Program!" << endl;
    }
    else
    {
      cout << "Invalid input!!" << endl;
    }

    if (balance > total)
    {
      cout << "Your total is $" << total << endl;
      cout << "Your balance is $" << totalBalance << endl;
      cout << endl;
      cout << "Thank you for using my Vending Machine Program!" << endl;
      next = false;
    }
    else
    {
      cout << "Your total is $" << total << endl;
      cout << "Your balance is $" << balance << endl;
      cout << "Not enough change!! Please add more coins." << endl;
      cout << endl;
    }
  }
}
