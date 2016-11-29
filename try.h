#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include<vector>
// #include <conio.h>
 #include <windows.h>
 #include <ctime>
using namespace std;





vector<string>Google;
vector<string>Apple;
vector<string>ATT;
vector<string>HP;
vector<string>Samsung;
vector<string>Tesla;


string stck1;



string rand_stock()
{
   string arr[] = {"Google", "Apple", "AT&T", "Tesla","HP","Samsung"};
   int x = (rand() % 6);
   //cout<<"This is choosen stock: "<<arr[x]<<endl;
  return (arr[x]);

}





void initialize_prices()
{


string word;
  ifstream myfile ("google.txt");
if (myfile.is_open())
  {
    while (!myfile.eof())
    {
       myfile>>word;
      // cout<<word<<endl;
      // double num = atof(word.c_str());
        Google.push_back(word);
    }
    myfile.close();
  }
else cout << "Unable to open file";

//for(int i=0; i<Google.size();i++)
//{
//    cout<<Google[i]<<endl;
//}

ifstream myfile1("apple.txt");
if (myfile1.is_open())
  {
    while (!myfile1.eof())
    {
       myfile1>>word;
      // double num = atof(word.c_str());
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
     //  double num = atof(word.c_str());
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
     //  double num = atof(word.c_str());
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
     //  double num = atof(word.c_str());
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
      // double num = atof(word.c_str());
        Tesla.push_back(word);
    }
    myfile5.close();
  }

}





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




int How_Many_Stocks_toBuy(int total, string bprice)
{

    double ppstock = atof(bprice.c_str());

    double allowance = total*.15; //amount of money allowed to spend

    int num_of_shares = allowance/ppstock;
   // if(num_of_shares < 1)
        //cout<<"Not enough to buy stock"<<endl<<endl;

    return (num_of_shares);
}

class stocks
{
public:
    string name; // symbol of stock
    int shares;   //# of shares
    double cps;  //cost per shares
    vector<string>price_list;
    int current_price;
    void stock_info();
};

void stocks::stock_info()
{
    cout<<"Stock Name: "<<name<<endl;
    cout<<"Number of shares: "<<shares<<endl;
    cout<<"Cost per share: "<<cps<<endl;
    cout<<"current price: "<<current_price<<endl;
}

 stocks GOOGLE;
    stocks APPLE;
    stocks att;
    stocks hp;
    stocks TESLA;
    stocks SAMSUNG;
    stocks TRAP;

void create_stocks()// stocks* g, stocks* a, stocks* attt, stocks* hpp, stocks* tesla, stocks* samsung)
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

   // stocks TESLA;
    TESLA.name="Tesla";
    price = Tesla[0];
    TESLA.cps = atof(price.c_str());
    TESLA.price_list = Tesla;
    TESLA.shares = 0;
    TESLA.current_price = 0;

   // stocks SAMSUNG;
    SAMSUNG.name="Samsung";
    price = Samsung[0];
    SAMSUNG.cps = atof(price.c_str());
    SAMSUNG.price_list = Samsung;
    SAMSUNG.shares = 0;
    SAMSUNG.current_price = 0;

    TRAP.name = "trap";

}


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



stocks which_stock_buy(string stk, int share)
{
    //cout<<"This is stk being checked: "<<stk<<endl;
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

stocks which_stock_sell(string stk)
{
    //cout<<"This is stk being checked: "<<stk<<endl;
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
