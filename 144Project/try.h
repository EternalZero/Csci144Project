#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include<vector>
#include <windows.h>
#include <ctime>
using namespace std;

//Declaration of Global variables that will be used
//throughout program
vector<string>Google;
vector<string>Apple;
vector<string>ATT;
vector<string>HP;
vector<string>Samsung;
vector<string>Tesla;
int rando; //used for random numbers
string stck1;




//Function that picks out random stock
string rand_stock()
{
   string arr[] = {"Google", "Apple", "AT&T", "Tesla","HP","Samsung"};
   rando = rand();
   //cout<<"Rando: "<<rando<<endl;
   int x = (rando % 6);
  return (arr[x]);
}


//Initialize Price list by reading price list from
//corresponding text file.
void initialize_prices()
{
string word;
  ifstream myfile ("google.txt");
if (myfile.is_open())
  {
    while (!myfile.eof())
    {
       myfile>>word;
       Google.push_back(word);
    }
    myfile.close();
  }

ifstream myfile1("apple.txt");
if (myfile1.is_open())
  {
    while (!myfile1.eof())
    {
       myfile1>>word;
        Apple.push_back(word);
    }
    myfile1.close();
  }

ifstream myfile2 ("att.txt");
if (myfile2.is_open())
  {
    while (!myfile2.eof())
    {
       myfile2>>word;
        ATT.push_back(word);
    }
    myfile2.close();
  }

ifstream myfile3 ("hp.txt");
if (myfile3.is_open())
  {
    while (!myfile3.eof())
    {
       myfile3>>word;
        HP.push_back(word);
    }
    myfile3.close();
  }

ifstream myfile4 ("samsung.txt");
if (myfile4.is_open())
  {
    while (!myfile4.eof())
    {
       myfile4>>word;
        Samsung.push_back(word );
    }
    myfile4.close();
  }

ifstream myfile5 ("tesla.txt");
if (myfile5.is_open())
  {
    while (!myfile5.eof())
    {
       myfile5>>word;
        Tesla.push_back(word);
    }
    myfile5.close();
  }
}


//Give initial buying stock price for corresponding company
string buyprice(string x)
{
    if (x=="Google")
        return(Google[0]);
    else if(x=="Apple")
        return(Apple[0]);
    else if(x=="AT&T")
        return(ATT[0]);
    else if(x=="Tesla")
        return(Tesla[0]);
    else if(x=="Samsung")
        return(Samsung[0]);
    else if (x=="HP")
        return(HP[0]);
}


//When Buy case, this function will give you how many shares to buy.
//To prevent program from using all funds to buy stock in one company, a
//20% allowance was given, so that only 20% of current available funds can be used.
int How_Many_Stocks_toBuy(int total, string bprice)
{
    double ppstock = atof(bprice.c_str()); //price per stock
    double allowance = total*.20; //amount of money allowed to spend
    int num_of_shares = allowance/ppstock;
    return (num_of_shares);
}

//the stocks class as suggested by instructor.
class stocks
{
public:
    string name; // symbol of stock
    int shares;   //# of shares
    double cps;  //cost per shares, initial buying price
    vector<string>price_list; //price list
    int current_price; //where in the price list is current price located
    void stock_info();
};
//This function gives you stock info on a particular stock
void stocks::stock_info()
{
    cout<<"Stock Name: "<<name<<endl;
    cout<<"Number of shares: "<<shares<<endl;
    cout<<"Initial stock price "<<cps<<endl;
    cout<<"current price: "<<price_list[current_price]<<endl;
}

//Globally Creates instances of class Stock
 stocks GOOGLE;
    stocks APPLE;
    stocks att;
    stocks hp;
    stocks TESLA;
    stocks SAMSUNG;
    stocks TRAP;

//initialized the Stocks I will be working with.
void create_stocks()
{
   // stocks GOOGLE;
   GOOGLE.name="Google";
    string price = Google[0];
    GOOGLE.cps = atof(price.c_str());
    GOOGLE.price_list = Google;
    GOOGLE.shares = 0;
    GOOGLE.current_price = 0;
   // stocks APPLE;
    APPLE.name="Apple";
    price = Apple[0];
    APPLE.cps = atof(price.c_str());
    APPLE.price_list = Apple;
    APPLE.shares = 0;
    APPLE.current_price = 0;
   // stocks att;
    att.name="AT&T";
    price = ATT[0];
    att.cps = atof(price.c_str());
    att.price_list = ATT;
    att.shares = 0;
    att.current_price = 0;
    //stocks hp;
    hp.name="HP";
    price = HP[0];
    hp.cps = atof(price.c_str());
    hp.price_list = HP;
    hp.shares = 0;
    hp.current_price = 0;
    //stock Tesla
    TESLA.name="Tesla";
    price = Tesla[0];
    TESLA.cps = atof(price.c_str());
    TESLA.price_list = Tesla;
    TESLA.shares = 0;
    TESLA.current_price = 0;
    //stock Samsung
    SAMSUNG.name="Samsung";
    price = Samsung[0];
    SAMSUNG.cps = atof(price.c_str());
    SAMSUNG.price_list = Samsung;
    SAMSUNG.shares = 0;
    SAMSUNG.current_price = 0;

    TRAP.name = "trap";

}

//In sell function, if current price did not meet criteria to sell
//then update current price, this is what this function does.
void update_buying_price(string stk, int x)
{
    if (stk == GOOGLE.name)
        {GOOGLE.current_price=x;}
    else if (stk == APPLE.name)
        {APPLE.current_price=x;}
    else if(stk == att.name)
        {att.current_price=x;}
    else if(stk== TESLA.name)
        {TESLA.current_price=x;}
    else if (stk == SAMSUNG.name)
        {SAMSUNG.current_price=x;}
    else if (stk == hp.name)
        {hp.current_price=x;}
}


//Function that gives stock info on all companies
void check_all_stocks()
{
    GOOGLE.stock_info();
    cout<<endl<<endl;
    APPLE.stock_info();
    cout<<endl<<endl;
    att.stock_info();
    cout<<endl<<endl;
    hp.stock_info();
    cout<<endl<<endl;
    TESLA.stock_info();
    cout<<endl<<endl;
    SAMSUNG.stock_info();
}

//Used in ProcessTransact function in the Buy case.
//Adds the number of shares bought to the amount
//of shares already bought in corresponding company
stocks which_stock_buy(string stk, int share)
{
    if (stk == GOOGLE.name)
    {GOOGLE.shares+=share;
        return GOOGLE;}
    else if (stk == APPLE.name)
        {APPLE.shares+=share;
        return APPLE;}
    else if(stk == att.name)
        {att.shares+=share;
        return att;}
    else if(stk== TESLA.name)
        {TESLA.shares+=share;
        return TESLA;}
    else if (stk == SAMSUNG.name)
        {SAMSUNG.shares += share;
        return SAMSUNG;}
    else if (stk == hp.name)
        {hp.shares+=share;
        return hp;}
}

//This function is used by ProcessTransact function in
//the Sell case.  This function Sets the # of shares in company
//back to zero, signifying it was sold.
stocks which_stock_sell(string stk)
{
    if (stk == GOOGLE.name)
    {GOOGLE.shares= 0;
        return GOOGLE;}
    else if (stk == APPLE.name)
        {APPLE.shares=0;
        return APPLE;}
    else if(stk == att.name)
        {att.shares=0;
        return att;}
    else if(stk== TESLA.name)
        {TESLA.shares=0;
        return TESLA;}
    else if (stk == SAMSUNG.name)
        {SAMSUNG.shares= 0;
        return SAMSUNG;}
    else if (stk == hp.name)
        {hp.shares=0;
        return hp;}
}

//This function is used to by the sell function in order
//to be able to pick a random stock from a company that you
//own shares of.

stocks choose_from_bought()
{
    vector<stocks>bought;
    if (GOOGLE.shares != 0)
        bought.push_back(GOOGLE);
    if (APPLE.shares != 0)
        bought.push_back(APPLE);
    if (TESLA.shares != 0)
        bought.push_back(TESLA);
    if (hp.shares != 0)
        bought.push_back(hp);
    if (att.shares != 0)
        bought.push_back(att);
    if(SAMSUNG.shares != 0)
        bought.push_back(SAMSUNG);
   if(bought.size() != 0){
        int x;
        if(rando != 0)
            {x = rando % bought.size();}
        else
            {x = rand() % bought.size();}
    return (bought[x]);}
    else
        return (TRAP);

}
