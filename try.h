#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include<vector>
using namespace std;





vector<string>Google;
vector<string>Apple;
vector<string>ATT;
vector<string>HP;
vector<string>Samsung;
vector<string>Tesla;






string rand_stock()
{
    srand(time(NULL));
   string arr[] = {"Google", "Apple", "AT&T", "Tesla","HP","Samsung"};
   int x = rand() % 6;
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
    return (num_of_shares);
}

class stocks
{
public:
    string name; // symbol of stock
    int shares;   //# of shares
    double cps;  //cost per shares
    vector<string>price_list;
    void stock_info();
};

void stocks::stock_info()
{
    cout<<"Stock Name: "<<name<<endl;
    cout<<"Number of shares: "<<shares<<endl;
    cout<<"Cost per share: "<<cps<<endl;
}

 stocks GOOGLE;
    stocks APPLE;
    stocks att;
    stocks hp;
    stocks TESLA;
    stocks SAMSUNG;

void create_stocks()// stocks* g, stocks* a, stocks* attt, stocks* hpp, stocks* tesla, stocks* samsung)
{
   // stocks GOOGLE;
   GOOGLE.name="Google";
    string price = Google[0];
    GOOGLE.cps = atof(price.c_str());
    GOOGLE.price_list = Google;
    GOOGLE.shares = 0;

   // stocks APPLE;
    APPLE.name="Apple";
    price = Apple[0];
    APPLE.cps = atof(price.c_str());
    APPLE.price_list = Apple;
    APPLE.shares = 0;

   // stocks att;
    att.name="AT&T";
    price = ATT[0];
    att.cps = atof(price.c_str());
    att.price_list = ATT;
    att.shares = 0;

    //stocks hp;
    hp.name="HP";
    price = HP[0];
    hp.cps = atof(price.c_str());
    hp.price_list = HP;
    hp.shares = 0;

   // stocks TESLA;
    TESLA.name="Tesla";
    price = Tesla[0];
    TESLA.cps = atof(price.c_str());
    TESLA.price_list = Tesla;
    TESLA.shares = 0;

   // stocks SAMSUNG;
    SAMSUNG.name="Samsung";
    price = Samsung[0];
    SAMSUNG.cps = atof(price.c_str());
    SAMSUNG.price_list = Samsung;
    SAMSUNG.shares = 0;

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


