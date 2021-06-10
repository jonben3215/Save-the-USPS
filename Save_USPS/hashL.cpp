#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include "hashL.hpp"

using namespace std;

HashTable::HashTable(int bsize)
{
  /*
  Defining everything that I will need later on in the code.
  */
  tableSize = bsize;
  numOfcolision =0;
  table = new int [tableSize];
  for(int i =0; i < tableSize; i++)
  {
    table[i]=-1;
  }
}
/*
This function should just read in the data from readFile function
and insert each number into the hastable and insert the numbers that have been passed to
the insertItem function;
*/
void HashTable::insertItem(int key)
{
    if(table[hashFunction(key)] == -1)
    {
      table[hashFunction(key)] = key;
    }
    else
    {
        //temp = table[hashFunction(key)];
        int index = hashFunction(key);
        while(table[index] != -1 && index < tableSize&&table[index] != key)
        {
            index = (index +1)%tableSize;
            numOfcolision++;
        }
        if(index < tableSize)
        {
            table[index] = key;
        }
        cout << "INSERTING: "<< key  << " AT " << hashFunction(key) << " INDEX"  << endl;
    }
}

unsigned int  HashTable::hashFunction(int key)
{
    return (key % tableSize);
}
/*
This part of the function should print the has table. 
*/
void HashTable::printTable()
{
  cout << "DISPLAYING TABLE: " << endl;
  for(int i =0; i < tableSize; i++)
  {
    cout << "[Index: "<<i << " ]" << " ";
    cout << table[i] << endl;
  }
  cout << endl;
  cout << "There was "<<getNumOfCollision() << " Collision." << endl;
}
int HashTable::getNumOfCollision()
{
   return numOfcolision;
}
bool HashTable::searchItem(int key)
{
    if(table[hashFunction(key)] == -1)
    {
      return false;
    }
    else
    {
        int index = hashFunction(key);
        while(table[index] != -1 && index < tableSize && table[index] != key)
        {
            index = (index +1)%tableSize;
        }
        if(index < tableSize )
        {
            if(table[index] == key)
            {
              return true;
            }
        }
    }
    return false;
}