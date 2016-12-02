//Jairo Reyes Csci144 Proj

//Cygwin64 Terminal used
//Try.h header file is needed, which I have provided in folder
//TO RUN PROGRAM:
////////////////////////////
// g++ -o proj1 proj1.cpp -lpthread
//
// ./proj1 .03 .10 60
/////////////////////////////
//First parameter represents X% (price increase)
//Second Parameter represents Y% (price decrease)
//Third Parameter represents Z% (buying percentage)

///////////////////////////////////////////////////////////////
//NOTE: IT IS EXTREMELY IMPORTANT TO KEEP X & Y UNDER 15%    //
//THIS IS FURTHER EXPLAINED IN REPORT                        //..................... if you actually read it ...(^_^)...................................................................unlike my email lol
///////////////////////////////////////////////////////////////

////
//This Program, using Pthreads is suppose to simulate "automated stock trading".
//Threads will be generated based on some probabilities, and then select the appropriate action
//for chosen stock.
//A server thread will be periodically keeping you updated with Balance and Yield.
//Stocks are chosen from a 6 possible companies: Google, Apple, HP, Tesla, SamSung, AT&T
//along with their corresponding price list   *info regarding price is in Report*

//OUTPUT:
//After 10,000 legal transactions, A list of information should print detailing current stock info for all companies
//Including number of shares in company currently owned,
//Initial Price of stock
//Current Price of stock

//For better results, Try making X% to be lower than 10% and more closer to 5%
//while Y% to be higher than 10%
//BUT REMEMBER KEEP EM BOTH UNDER 15%     *as stated in report*

#include<iomanip>
#include"try.h"
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex1, mutex2; // declaring mutex
double Total_Balance;   //Global variable that will keep track of
double Profit;
double Cost;

double selling_P_INC;
double selling_P_DEC;


int num_trans; //Global variable keeping track of total num of valid transactions


//ProcessTransact function is a function that takes in the
//transaction string and will parse through the string
//in order to see if its a buy or sell action, and retrieve
//the rest of information needed to perform said action
void ProcessTransact(string transact)
{
    string word;
    string word2;
    string word3;
    int share;
   // cout<<"This is current Total Balance: "<<Total_Balance<<endl;
    istringstream iss(transact);
    iss>>word; //action to take Buy or sell
    if (word == "Buy"){ //Buying Case
        iss>>word; //name of stock
        iss>>word2; //number of stocks
        iss>>word3; //price at which stocks will be sold at
        int num_shares = atoi(word2.c_str());
        if( num_shares > 0) //If number of shares to buy is 0, do nothing, else proceed
        {
            share = num_shares;
            double buying =atof(word3.c_str()); //converts buying price to double
            double price = (share*buying);
            Total_Balance -= price;// Update total balance
            Cost += price;
            which_stock_buy(word, share);//.stock_info();
            num_trans +=1; //increase number of Total transaction
        //    cout<<transact<<endl;
        }

    }

    else{ //Sell case
            iss>>word; //name of stock
            iss>>word2; //number of stocks
            iss>>word3; //price at which stocks will be sold at
            share =  atoi(word2.c_str());
            double selling = atof(word3.c_str());
            double price = (share*selling);
            Total_Balance += price; //update Total
            Profit +=price;
            which_stock_sell(word);//sets number of shares for stock to zero
            update_buying_price(word,0); //when sold, reset buying price for stock
            num_trans +=1; //update # of transactions
          //  cout<<transact<<endl;
        }
    sleep(2);
}

//The buy function puts a string together
//that consists of action, company name,
//number of stocks, and buying price

void *buy(void*)
{
  // string stck = rand_stock();

    string bprice = buyprice(stck1); //gets buying price for stock

    stringstream ss;
    ss<<How_Many_Stocks_toBuy(Total_Balance,bprice); //retrieve number of stocks allowed to buy

    string num_of_shares = ss.str();
   string trans = "Buy "+stck1+" "+num_of_shares+" "+bprice;//string vectors not ints
  // pthread_mutex_lock(&mutex2);
  //cout<<trans<<endl<<endl;
  // pthread_mutex_unlock(&mutex2);
   ProcessTransact(trans); //send string to be parsed by ProcessTransact function
//cout<<"check2"<<endl;
   return NULL;
}





//This function is used to by the sell function in order
//to be able to pick a random stock from a company that you
//own shares of.




//When sell function is called, it will check if current price
//meets the criteria in order to sell, if not, then update current price
//to be next in price list, if it does meet criteria, then send transaction string to
//ProcessTransact function.
void *sell(void*)
{
    cout<<fixed;
    cout <<setprecision(2);

    stocks temp = choose_from_bought();

    if(temp.name == "trap"){
        return(0);}

    double initial_price = atof(buyprice(temp.name).c_str());
    double sell_price1 = initial_price+(initial_price *selling_P_INC);
    double sell_price2 = initial_price-(initial_price*selling_P_DEC);
    double current_price = atof(temp.price_list[temp.current_price].c_str());
    if(current_price >= sell_price1 || current_price <= sell_price2)
    {
        stringstream ss;
        ss<<current_price;
        string str = ss.str();
        stringstream dd;
        dd<<temp.shares;
        string sh = dd.str();
        string trans="Sell "+temp.name+" "+sh+" "+str;
 //pthread_mutex_lock(&mutex2);
   // cout<<trans<<endl<<endl;
    // pthread_mutex_unlock(&mutex2);
        ProcessTransact(trans);
        return NULL;
        }
    else{
        update_buying_price(temp.name, temp.current_price+1);
        return NULL;
        }
}



//Server function will print out current balance
//and yield , every 10 secs
void* server(void*)
{
while(num_trans<10000)
{
    cout<<"Current Blanace: "<<Total_Balance<<endl;
    double yield = (Profit/Cost)*100;
    cout<<"Yield: "<<yield<<"%"<<endl<<endl;
    sleep(10);
}
}




int main (int argc, char* argv[]) {
srand(time(NULL));
double init_bal = 100000;

selling_P_INC = atof(argv[1]);
selling_P_DEC = atof(argv[2]);
int Z = atof(argv[3]);

Total_Balance = init_bal; //initialize balance
initialize_prices();  //initialize price list
create_stocks();    //create stock classes needed

pthread_t cThreads; //declaring threads
pthread_t sThreads;

pthread_mutex_init(&mutex1, NULL); //initializing mutex
pthread_mutex_init(&mutex2, NULL);

pthread_create(&sThreads,NULL,server,NULL); //creating sThread
//int num_trans = 0;
bool isBuy = 1;
while(num_trans<10000)
{

    if(isBuy == 1){
        stck1 = rand_stock(); //picking random stock to work with
       // if((rando%100)<= Z) //<-Z Part, while I didnt see anything logically wrong, this step just never worked on my poor old Pc.
            pthread_create(&cThreads,NULL,buy,NULL);
        isBuy = 0;
    }
    else{ //The price checking is found in the  sell function!!!
       pthread_create(&cThreads,NULL,sell,NULL);
        isBuy = 1;
    }
// pthread_mutex_lock(&mutex1);
// cout<<"Transaction#: "<<num_trans<<endl;
 //pthread_mutex_unlock(&mutex1);
}

pthread_join(cThreads, NULL);
pthread_join(sThreads,NULL);
cout<<"Number of transactions: "<<num_trans<<endl<<endl;
cout<<"Initial Total Balance: "<<init_bal<<endl;
cout<<endl<<"Current Total Balance: "<<Total_Balance<<endl<<endl;

cout<<"CURRENT STATUS OF ALL STOCKS: "<<endl<<endl;
check_all_stocks(); //Function that lets you know the current
                    //status of your stocks at the end of program.

  return 0;
}


