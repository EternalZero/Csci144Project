
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include<vector>
using namespace std;

void initialize_prices();
string rand_stock();


vector<int>goo;
vector<int>appl;
vector<int>att;
vector<int>hp;
vector<int>sam;



int main () {


 string stock = rand_stock();

 vector<vector<int>> vec;

    for(int i = 0; i < 5; i++)
    {
         vector<int> row;
         vec.push_back(row);
    }

    vec[0].push_back(5);
    cout << vec[0][0] << endl;


 /*

 string line;
 string word;


  ifstream myfile ("data1.txt");
  if (myfile.is_open())
  {
    while (! myfile.eof())
    {


        cout<<word<<endl;
      getline(myfile, line);
      istringstream iss(line);
      iss>>word;
    /* if (word == "Google")
      {
        myfile>>word;
        cout<<word<<endl;
      }}
    myfile.close();
  }

  else cout << "Unable to open file";*/
  return 0;
}










string rand_stock()
{
    srand(time(NULL));
   string arr[] = {"Google", "Apple", "AT&T", "Tesla","HP","Samsung"};
   int x = rand() % 6;
 //  cout<<arr[x]<<endl;
   return (arr[x]);
}
