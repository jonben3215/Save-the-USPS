#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include "hash.hpp"

using namespace std; 

HashTable::HashTable(int bsize)
{
  /*
  Defining everything that I will need later on in the code. 
  */
  tableSize = bsize;
  numOfcolision =0;
  table = new node* [tableSize]; 
}
/*
This function should just read in the data from readFile function 
and insert each number into the hastable and insert the numbers that have been passed to
the insertItem function; 
*/
void HashTable::insertItem(int key)
{
    node *value = new node;
    node *temp;
    value -> key = key; 
    value -> next = NULL;
    if(table[hashFunction(key)] == NULL)
    {
      table[hashFunction(key)] = value;
    }
    else 
    {
        temp = table[hashFunction(key)];
        while(temp->next !=NULL)
        {
            temp = temp -> next; 
            numOfcolision +=1;
        }
        temp -> next = value;
        cout << "INSERTING: "<< key  << " AT " << hashFunction(key) << " INDEX"  << endl;
    }
} 
//This function should return the 
unsigned int  HashTable::hashFunction(int key)
{
    return (key % tableSize);
}
void HashTable::printTable()
{
  node *curr;
  cout << "DISPLAYING TABLE: " << endl;
  for(int i =0; i < tableSize; i++)
  {
    curr = table[i]; 
    cout << "[Index: "<<i << " ]" << " ";
    while(curr !=NULL)
    {
      cout << curr ->key << " --> ";
      curr = curr -> next;
    }
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
  node *temp = table[hashFunction(key)];
    while(temp !=NULL)
    {
        if (temp->key == key) 
        {
            cout << "True" << endl;
            return true;
        } 
        temp = temp -> next;
    }
    cout << "False"<<endl;
    return false; 
}