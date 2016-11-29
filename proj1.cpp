#include<iomanip>
#include"try.h"
#include <pthread.h>
#include <unistd.h>


using namespace std;

pthread_mutex_t mutex1, mutex2, mutex3, mutex4;

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
    if (word == "Buy"){
            iss>>word;
            iss>>word2;
            iss>> word3;

            share = atoi(word2.c_str());
            double buying =atof(word3.c_str());
            Total_Balance -= (share*buying);
            which_stock_buy(word, share);//.stock_info();
    }

    else{
            iss>>word; //name of stock
            iss>>word2; //number of stocks
            iss>>word3; //price at which stocks will be sold at
            share =  atoi(word2.c_str());
            double selling = atof(word3.c_str());
            Total_Balance += (share*selling);
            which_stock_sell(word);//.stock_info();
            update_buying_price(word,0);




    }
  //  sleep(2);
}



void *buy(void*)
{
    cout<<fixed;
    cout <<setprecision(2);

  // string stck = rand_stock();

    string bprice = buyprice(stck1);

    stringstream ss;
    ss<<How_Many_Stocks_toBuy(Total_Balance,bprice);
    string num_of_shares = ss.str();
   string trans = "Buy "+stck1+" "+num_of_shares+" "+bprice;//string vectors not ints
   pthread_mutex_lock(&mutex2);
  cout<<trans<<endl<<endl;
   pthread_mutex_unlock(&mutex2);
   ProcessTransact(trans);
//cout<<"check2"<<endl;
  // sleep(1);
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

    stocks temp = choose_from_bought();

    if(temp.name == "trap"){
        return(0);}

    double initial_price = atof(buyprice(temp.name).c_str());
    double sell_price1 = initial_price+(initial_price *.10);
    double sell_price2 = initial_price-(initial_price*.15);

        double current_price = atof(temp.price_list[temp.current_price].c_str());
        cout<<"This is current price: "<<current_price<<" and should not be greater than "<<sell_price1<<" and not less than "<<sell_price2<<endl;
        if(current_price > sell_price1 || current_price < sell_price2)
        {
            stringstream ss;
    ss<<current_price;
    string str = ss.str();

    stringstream dd;
    dd<<temp.shares;
    string sh = dd.str();

    string trans="Sell "+temp.name+" "+sh+" "+str;
 pthread_mutex_lock(&mutex2);
    cout<<trans<<endl<<endl;
     pthread_mutex_unlock(&mutex2);
    ProcessTransact(trans);
    return NULL;

        }
    else{
        update_buying_price(temp.name, temp.current_price+1);
        return NULL;
    }


    //sleep(2);
    return NULL;


}








int main () {
srand(time(NULL));

Total_Balance = 100000;
initialize_prices();
create_stocks();


pthread_t cThreads;
pthread_mutex_init(&mutex1, NULL);
pthread_mutex_init(&mutex2, NULL);


int num_trans = 0;
bool isBuy = 1;
while(num_trans<100)
{
    if(isBuy == 1){
        stck1 = rand_stock();
    pthread_create(&cThreads,NULL,buy,NULL);
        ++num_trans;
        isBuy = 0;
    }
    else{
       pthread_create(&cThreads,NULL,sell,NULL);
        ++num_trans;
        isBuy = 1;
    }
 pthread_mutex_lock(&mutex1);
 cout<<"Transaction#: "<<num_trans<<endl;
 pthread_mutex_unlock(&mutex1);
}

pthread_join(cThreads, NULL);

  cout<<endl<<"New Total Balance: "<<Total_Balance<<endl<<endl;






//check_all_stocks();

  return 0;
}


