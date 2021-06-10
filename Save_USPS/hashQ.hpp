#ifndef HASHQ_HPP
#define HASHQ_HPP

#include <string>


using namespace std;

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int* table;
    int numOfcolision =0;
public:
    HashTable(int bsize);  // Constructor

    // inserts a key into hash table
    void insertItem(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    bool searchItem(int key);
};

#endif
