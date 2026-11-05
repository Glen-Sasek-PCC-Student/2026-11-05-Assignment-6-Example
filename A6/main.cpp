
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

string string_cents(float usd)
{
  stringstream ss;
  ss << fixed << setprecision(2) << usd;
  return ss.str();
}

void display_beverage_menu()
{
  cout << "Please pick an option ($0.25 each):" << endl;
  cout << "    C/c: Coffee" << endl;
  cout << "    T/t: Tea" << endl;
  cout << "    Q/q: Quit" << endl;
}

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
      const int END_SENTINEL = 0;

      enum
      {
        NICKEL = 5,
        DIME = 10,
        QUARTER = 25
      };

      if (cin)
      {
        switch (coin)
        {
        case END_SENTINEL: // fallthrough
          nextCoin = false;
          break;
        case NICKEL: // fallthrough
        case DIME:   // fallthrough
        case QUARTER:
          sumCoin = coin + sumCoin;
          break;
        default:
          cout << "Invalid value" << endl;
        }
      }
      else
      {
        cin.clear();
        // to ignore all to end of line needs #include <limits>
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');

        char c = cin.get();
        cout << "ERROR, NOT AN INTEGER: " << c << endl;
      }
    }

    balance = static_cast<float>(sumCoin) / 100.0;

    // Display balance
    cout << "Your balance is $ " << string_cents(balance) << endl;
    
    
    display_beverage_menu();
    cin >> uc1;
    cout << "    >> " << uc1 << endl;

    if ((uc1 == 'c') or (uc1 == 'C'))
    {
      cout << "How many would you like? ";
      cin >> amount;
      total = (coffee * amount);
      cout << amount << endl;
    }
    else if ((uc1 == 't') or (uc1 == 'T'))
    {
      cout << "How many would you like? ";
      cin >> amount;
      total = (tea * amount);
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

    cout << "Your total is $" << total << endl;
    if (balance >= total)
    {
      balance = balance - total;
      next = false;
      cout << "Your change is $" << string_cents(balance) << endl;
    }
    else
    {
      cout << "Your balance is $" << string_cents(balance) << endl;
      cout << "Not enough change!! Please add more coins." << endl;
    }
    cout << endl;
  }

  cout << "Thank you for using my Vending Machine Program!" << endl;
}
