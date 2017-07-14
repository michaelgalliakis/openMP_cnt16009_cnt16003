/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima A - Prefix
 * Date: 28/04/2017 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime> 
#include <math.h>  
#include <omp.h>
#include <thread>
using namespace std ;

void printInfo(int thread,int k, int i, int res)
{
    cout<<"[thread: "<<thread ;
    cout<<" k: "<<k ;
    cout<<" i: "<<i ;
    cout<<" res: "<<res<<"]\n" ;
}

void copyArray(int arr1[],int arr2[],int n)
{
    for (int i = 0 ;i<n;i++)
        arr2[i] = arr1[i] ;	
}

int readNum(string messageParam = "n",int min = 0,int max = 100000)
{
    string input = "";
    int n=0;
    do {
        cout<< "Give a number ("<<min+1<<"-"<<max<<") "<< messageParam<< " : " ;
        getline(cin, input);
        stringstream(input) >> n;	
    } while (n<=min || n>max) ;
    
    return n ;	
}

void fillArrayWithRandNum(int array[],int n)
{		
    srand((unsigned)time(0));      
    for(int i=0; i<n; i++){ 
        array[i] = (rand()%10)+1;                  
    } 		
}

void printArray(int array[], int n)
{
    for (int i = 0;i < n ; i++)
        cout<<"[" << array[i] << "]" ;
    cout<<"\n" ;	 
}
