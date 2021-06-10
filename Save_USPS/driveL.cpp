#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include "hashL.hpp"

using namespace std; 
int main(int argc, char *argv[])
{
    string line; 
    int nums; 
    int count =0;
    HashTable Table = HashTable(40009);
    ifstream inFile;
    ofstream oFile;
    int arr[40000];
    double insertime[400];
    inFile.open(argv[1]);
    oFile.open("oFile.txt");
    if(!inFile)
    {
        cout << "FILE NOT FOUND" << endl;
    }
    while(getline(inFile, line, ','))
    {
        nums = stoi(line);
        arr[count] = nums; 
        count++;
    }

    //Block A.
   for(int i =0; i<100; i++)
   {
       Table.insertItem(arr[i]);
   }
   // End of Block A
   for(int i =0; i < 400; i++)
   {
       //Star time;
    std::chrono::time_point<std::chrono::system_clock> start, end; 
    start = std::chrono::system_clock::now(); 
       for(int  j = i * 100 ; j <  (i * 100) + 100; j++)
       {
           Table.insertItem(arr[j]);
       }
     end = std::chrono::system_clock::now(); 
     std::chrono::duration<double> elapsed_seconds = (end - start)/100;
     insertime[i]= elapsed_seconds.count(); 
    //End time;
   }
   for(int q=0; q < 400; q++)
   {
       if(oFile.is_open())
       {
           oFile << insertime[q];
           oFile << endl;
       }
   }
    oFile.close();
    Table.printTable();
    Table.searchItem(34787);

}