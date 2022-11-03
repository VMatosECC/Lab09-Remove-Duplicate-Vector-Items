// Lab09-Remove-Duplicate-Vector-Items.cpp 
// Author:  V. Matos
// Goal:    Create a reduced version of a vector where duplicate entries are eliminated.
// -------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

// Prototypes --------------------------------------------------------------------------
int  countOccurrences(vector<int> v, int item);
void showVector(vector<int> v, string msg = "");
void removeDuplicatesVersion1(vector<int>& v);
void removeDuplicatesVersion2(vector<int>& v);

// -------------------------------------------------------------------------------------
int main()
{
    vector<int> v{ 11, 33, 22, 11, 44, 77, 66, 33, 55 };
    showVector(v, "Main. Original Vector (including duplicates)");

    removeDuplicatesVersion1(v);
    //removeDuplicatesVersion2(v);

    showVector(v, "Main. Modified vector (no duplicates)");

}


// -------------------------------------------------------------------------------------
// User-defined methods

int countOccurrences(vector<int> v, int item)
{
    int counter = 0;
    for (int num : v)
    {
        if (num == item)  counter++;
    }
    return counter;
}
//------------------------------------------------------------------------------
void showVector(vector<int> v, string msg)
{
    cout << msg << endl;
    for (int num : v) cout << num << endl;
}

// -----------------------------------------------------------------------------
void removeDuplicatesVersion1(vector<int>& v)
{
    //Version1. Removing duplicates (temporary new vector is created, then destroyed)
    vector<int> vNew;
    for (int num : v)
    {
        if (countOccurrences(v, num) == 1) vNew.push_back(num);
    }
    showVector(vNew, "Version1. vNew (no dups)");
    v = vNew;
    showVector(v, "Version1. v after copying vNew data in it");
    vNew.clear();
    showVector(v, "Version1. v after clearing vNew");
}

//------------------------------------------------------------------------
void removeDuplicatesVersion2(vector<int>& v)
{
    //Version2. Removing duplicates 'in place'

    vector<int> vDup;       //make a collection of duplicate values
    for (int num : v)
    {
        if ((countOccurrences(v, num) > 1) && (countOccurrences(vDup, num) == 0))
        {
            vDup.push_back(num);
        }
    }
    showVector(vDup, "Version2. Duplicate entries occurring in v");

    int i = 0;
    while (i < v.size())
    {
        if (countOccurrences(vDup, v[i]) == 1)
        {
            v.erase(v.begin() + i);
            i = 0;
        }
        else
        {
            i++;
        }
    }
    showVector(v, "Version2. v after Version2");
}