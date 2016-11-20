
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
 initialize_prices();

  return 0;
}



void initialize_prices()
{
  vector<string>goo1;
  vector<string>appl1;
  vector<string>att1;
  vector<string>hp1;
  vector<string>sam1;

  string word;
  string line;
  ifstream myfile ("google.txt");
if (myfile.is_open())
  {
    while (!myfile.eof())
    {
       myfile>>word;
        goo1.push_back(word);
    }
    myfile.close();
  }
else cout << "Unable to open file";

for(int i; i<goo1.size();i++)
{
    cout<<goo1[i]<<endl;
}

ifstream myfile1("apple.txt");
if (myfile1.is_open())
  {
    while (!myfile1.eof())
    {
       myfile1>>word;
        appl1.push_back(word);
    }
    myfile1.close();
  }
else cout << "Unable to open file";


ifstream myfile2 ("att.txt");
if (myfile2.is_open())
  {
    while (!myfile2.eof())
    {
       myfile2>>word;
        att1.push_back(word);
    }
    myfile2.close();
  }
else cout << "Unable to open file";


ifstream myfile3 ("hp.txt");
if (myfile3.is_open())
  {
    while (!myfile3.eof())
    {
       myfile3>>word;
        hp1.push_back(word);
    }
    myfile3.close();
  }
else cout << "Unable to open file";

ifstream myfile4 ("sam.txt");
if (myfile4.is_open())
  {
    while (!myfile4.eof())
    {
       myfile4>>word;
        sam1.push_back(word);
    }
    myfile4.close();
  }
else cout << "Unable to open file";



}












string rand_stock()
{
    srand(time(NULL));
   string arr[] = {"Google", "Apple", "AT&T", "Tesla","HP","Samsung"};
   int x = rand() % 6;
 //  cout<<arr[x]<<endl;
   return (arr[x]);
}
