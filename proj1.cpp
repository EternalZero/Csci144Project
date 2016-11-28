#include<iomanip>
#include"try.h"
#include <pthread.h>
#include <unistd.h>


using namespace std;

pthread_mutex_t mutex1, mutex2;





double Total_Balance;









void ProcessTransact(string transact)
{

    cout<<fixed;
    cout <<setprecision(2);


    string word;
    string word2;
    string word3;
    int share;
   // cout<<"This is current Total Balance: "<<Total_Balance<<endl;
    istringstream iss(transact);
    iss>>word;
    //cout<<"1st word"<<word<<endl;
    if (word == "Buy"){
            iss>>word;
            iss>>word2;
            iss>> word3;

            share = atoi(word2.c_str());
            double buying =atof(word3.c_str());
            //mutex lock
            Total_Balance -= (share*buying);
          //  cout<<"New Total Balance: "<<Total_Balance<<endl<<endl;
            //mutex unlock
            which_stock_buy(word, share);//.stock_info();
    }

    else{
            iss>>word; //name of stock
            iss>>word2; //number of stocks
            iss>>word3; //price at which stocks will be sold at
            //put mutex here lock
            share =  atoi(word2.c_str());
            double selling = atof(word3.c_str());
            Total_Balance += (share*selling);
          //  cout<<"New Total Balance: "<<Total_Balance<<endl<<endl;
            //unlock
            which_stock_sell(word);//.stock_info();




    }
}



void *buy(void*)
{
    cout<<fixed;
    cout <<setprecision(2);


   string stck = rand_stock();
    string bprice = buyprice(stck);

    stringstream ss;
    ss<<How_Many_Stocks_toBuy(Total_Balance,bprice);
    string num_of_shares = ss.str();
   string trans = "Buy "+stck+" "+num_of_shares+" "+bprice;//string vectors not ints
   //cout<<trans<<endl<<endl;
    cout<<"Thread is here buy";
   ProcessTransact(trans);
   sleep(2);
   return NULL;

}


stocks choose_from_bought()
{
    vector<stocks>bought;
    if (GOOGLE.shares != 0)
    {
        bought.push_back(GOOGLE);
    }
    if (APPLE.shares != 0)
    {
        bought.push_back(APPLE);
    }
    if (TESLA.shares != 0)
    {
        bought.push_back(TESLA);
    }
    if (hp.shares != 0)
    {
        bought.push_back(hp);
    }
    if (att.shares != 0)
    {
        bought.push_back(att);
    }
    if(SAMSUNG.shares != 0)
    {
        bought.push_back(SAMSUNG);
    }
   //cout<<bought.size()<<endl;
   if(bought.size() != 0){
    int x = rand() % bought.size();
    return (bought[x]);}
    else
        //cout<<"Nothing to sell"<<endl;
        return (TRAP);

}



void *sell(void*)
{
    cout<<fixed;
    cout <<setprecision(2);


   // cout<<"Chosen to sell"<<endl;

    stocks temp = choose_from_bought();

    if(temp.name == "trap"){
        return(0);}
    double sell_price1 = temp.cps+(temp.cps *.10);
    double sell_price2 = temp.cps-(temp.cps*.15);
    double current_price = temp.cps;

        for(int x = 0; x<temp.price_list.size(); x++)
        {
        current_price = atof(temp.price_list[x].c_str());
        if(current_price > sell_price1 || current_price < sell_price2)
        {break;}
        }
    stringstream ss;
    ss<<current_price;
    string str = ss.str();

    stringstream dd;
    dd<<temp.shares;
    string sh = dd.str();

    string trans="Sell "+temp.name+" "+sh+" "+str;
   // cout<<trans<<endl<<endl;
   cout<<"Thread is here: sell"<<endl;
    ProcessTransact(trans);

    sleep(2);
    return NULL;


}








int main () {
srand(time(0));

Total_Balance = 100000;
initialize_prices();
create_stocks();

pthread_mutex_init(&mutex1,NULL);
pthread_mutex_init(&mutex2,NULL);
pthread_t cThreads;

int num_trans = 0;
bool isBuy = 1;
while(num_trans<10000)
{
    if(isBuy == 1){
       pthread_create(&cThreads,NULL,buy,NULL);
        ++num_trans;
        isBuy = 0;
    }
    else{
       // cout<<num_trans<<endl;
        pthread_create(&cThreads,NULL,sell,NULL);
        ++num_trans;

        isBuy = 1;
    }
    //cout<<endl<<"New Total Balance: "<<Total_Balance<<endl<<endl;

}

   cout<<endl<<"New Total Balance: "<<Total_Balance<<endl<<endl;

//cout<<endl;

//sell();


//check_all_stocks();
  return 0;
}


