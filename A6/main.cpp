
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// Configure
const float TEA_USD = 0.25;
const float COFFEE_USD = 0.25;

// Function declarations
string string_cents(float usd);
void display_beverage_menu();
void display_order_summary(float balance_usd, float total_usd);
void display_data(string label, string value, string SEPARATOR = " ");
bool check_next();
int add_coins();
float choice_to_usd();

// Strings
const string MESSAGE_WELCOME = "Welcome to my Coffee/Tea Vending Machine!";
const string MESSAGE_GOODBYE = "Thank you for using my Vending Machine Program!";
const string PROMPT_COIN = "Enter coin - [0 to continue], 5, 10, or 25 only: ";
const string PROMPT_COUNT = "How many would you like? ";
const string ERROR_INVALID_VALUE = "Invalid value";
const string ERROR_BAD_INT = "ERROR, NOT AN INTEGER: ";
const string ERROR_BAD_CHOICE = "Choice not available";
const string LABEL_BALANCE_USD = "Your balance is $";
const string LABEL_TOTAL_USD = "Your total is $";
const string LABEL_CHANGE_USD = "Your change is $";
const string OPTIONS_MENU =
    "Please pick an option ($0.25 each):\n"
    "    C/c: Coffee\n"
    "    T/t: Tea\n"
    "    Q/q: Quit";

int main()
{
  float balance_usd = 0.0;
  float total_usd = 0.0;

  cout << MESSAGE_WELCOME << endl;
  cout << endl;

  bool next = true;
  while (next)
  {
    int coins = add_coins();
    balance_usd = static_cast<float>(coins) / 100.0;

    display_data(LABEL_BALANCE_USD, string_cents(balance_usd));

    char choice;
    display_beverage_menu();
    cin >> choice;
    choice = toupper(choice);
    cout << "    >> " << choice << endl;
    
    float item_usd = choice_to_usd(choice);
    bool item_selected = item_usd > 0;

    if (item_selected)
    {
      int item_count = 0;
      cout << PROMPT_COUNT;
      cin >> item_count;
      cout << item_count << endl;
      total_usd = item_usd * item_count;
      cout << endl;
    } else {
      next = false;
    }

    display_order_summary(balance_usd, total_usd);
    next = total_usd > balance_usd;
  }

  cout << MESSAGE_GOODBYE << endl;
}

// Function implementations

string string_cents(float usd)
{
  stringstream ss;
  ss << fixed << setprecision(2) << usd;
  return ss.str();
}

void display_beverage_menu()
{
  cout << OPTIONS_MENU << endl;
}

void display_data(string label, string value, string SEPARATOR = " ")
{
  cout << label << SEPARATOR << value << endl;
}

int add_coins()
{
  int cents = 0;
  int coin = 0;
  bool nextCoin = true;
  while (nextCoin)
  {
    cout << PROMPT_COIN;
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
        cents = coin + cents;
        break;
      default:
        cout << ERROR_INVALID_VALUE << endl;
      }
    }
    else
    {
      cin.clear();
      // to ignore all to end of line needs #include <limits>
      // cin.ignore(numeric_limits<streamsize>::max(), '\n');

      char c = cin.get();
      cout << ERROR_BAD_INT << c << endl;
    }
  }
  return cents;
}

float choice_to_usd(char choice)
{
  const char CHOICE_COFFEE = 'C';
  const char CHOICE_TEA = 'T';
  const char CHOICE_QUIT = 'Q';

  float usd = 0.00;

  switch (choice)
  {
  case CHOICE_COFFEE:
    usd = COFFEE_USD;
    break;
  case CHOICE_TEA:
    usd = TEA_USD;
    break;
  case CHOICE_QUIT:
    usd = 0.00;
    break;
  default:
    cout << ERROR_BAD_CHOICE << endl;
  }
  return usd;
}

void display_order_summary(float balance_usd, float total_usd) {
    display_data(LABEL_TOTAL_USD, string_cents(total_usd));
    if (balance_usd >= total_usd)
    {
      balance_usd = balance_usd - total_usd;
      display_data(LABEL_CHANGE_USD, string_cents(balance_usd));
    }
    else
    {
      display_data(LABEL_BALANCE_USD, string_cents(balance_usd));
      cout << "Not enough change!! Please add more coins." << endl;
    }

    cout << endl;
}