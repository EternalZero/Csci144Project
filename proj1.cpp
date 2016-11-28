
#include"try.h"


using namespace std;













double Total_Balance;





stocks which_stock(string stk)
{
    //cout<<"This is stk being checked: "<<stk<<endl;
    if (stk == GOOGLE.name)
        return GOOGLE;
    else if (stk == APPLE.name)
        return APPLE;
    else if(stk == att.name)
        return att;
    else if(stk== TESLA.name)
        return TESLA;
    else if (stk == SAMSUNG.name)
        return SAMSUNG;
    else if (stk == hp.name)
        return hp;
}





void ProcessTransact(string transact)
{
    istringstream iss(transact);
    string word;
    iss>>word;
    //cout<<"1st word"<<word<<endl;
    if (word == "Buy"){
            iss>>word;
            stocks temp = ;
            which_stock(word).stock_info();



//
//    }
//
//    else
//    {
//
//    }

}
}



void *buy(void)
{
   string stck = rand_stock();
    string bprice = buyprice(stck);

    stringstream ss;
    ss<<How_Many_Stocks_toBuy(Total_Balance,bprice);
    string num_of_shares = ss.str();
   string trans = "Buy "+stck+" "+bprice+" "+num_of_shares;//string vectors not ints
   ProcessTransact(trans);


//cout<<trans<<endl;


}

int main () {
Total_Balance = 10000;
initialize_prices();
create_stocks();
buy();

//check_all_stocks();






  return 0;
}


