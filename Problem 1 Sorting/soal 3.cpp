#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    //cout << "INPUT : Numerical Array" << endl;
    int array[6] = {1, 4, 5, 6, 8, 2};
    int size = sizeof(array)/sizeof(array[0]);
    
    sort(array, array + size, greater<int>());
    /*cout << "[";
    for (int i = 0; i < size; i++) {
        if(i == size-1)
        {
            cout << array[i];
        }
        else
        {
            cout << array[i] << ',';
        }
        
    }
    cout << "]" << endl;
    cout << endl;
    cout << "OUTPUT: Vertical Barcharts" << endl;*/
    
    int highest = array[0];
    for(int check = 0; check<=size-1; check++)
    {
        if(array[check]>highest)
        {
            highest = array[check];
        }
    }
    for(int rows = highest; rows>=1; rows--)
    {
        for(int cols=0; cols<=size-1; cols++)
        {
            if(array[cols]>=rows)
            {
                cout << "| ";
            }
            else
            {
                cout << "  ";
            }
            
        }
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
}