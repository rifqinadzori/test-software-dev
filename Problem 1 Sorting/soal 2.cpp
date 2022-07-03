#include<iostream>  
using namespace std;  
int main ()  
{    
    int myarray[4] = { 5,4,6,1};   
    int size = sizeof(myarray)/sizeof(myarray[0]);
    //cout<<"\nInput list is \n";
    
    int highest = myarray[0];
    for(int check = 0; check<=size-1; check++)
    {
        if(myarray[check]>highest)
        {
            highest = myarray[check];
        }
    }
    for(int rows = highest; rows>=1; rows--)
    {
        for(int cols=0; cols<=size-1; cols++)
        {
            if(myarray[cols]>=rows)
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
    
    for(int i=0;i<size;i++)  
    {  
        cout <<myarray[i]<<" ";  
    }   
    for(int k=1; k<size; k++)   
    {  
        int temp = myarray[k];  
        int j= k-1; 
        
        
        //cout <<"\n";
        
        for(int m=0;m<size;m++)  
        { 
            while(j>=0 && temp <= myarray[j])  
            {  
                myarray[j+1] = myarray[j];   
                j = j-1;  
            }  
            myarray[j+1] = temp;
            
            //cout <<myarray[m]<<" ";  
        } 
    }  
    
    //int highest = myarray[0];
    cout <<"\n";
    for(int check = 0; check<=size-1; check++)
    {
        if(myarray[check]>highest)
        {
            highest = myarray[check];
        }
    }
    for(int rows = highest; rows>=1; rows--)
    {
        for(int cols=0; cols<=size-1; cols++)
        {
            if(myarray[cols]>=rows)
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
    
    //cout<<"\nSorted list is \n";
    for(int i=0;i<4;i++)  
    {  
        cout <<myarray[i]<<" ";  
    }  
}