/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima B - Prefix
 * Date: 2/05/2017 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime> 
#include <math.h>  
#include <omp.h>
#include <thread>
#include <cstring>
using namespace std ;

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

void printArray(int array[], int n)
{
    for (int i = 0;i < n ; i++)
        cout<<"[" << array[i] << "]" ;
    cout<<"\n" ;	 
}

void generate_list(int * x, int n) {
    int i,j,t;
    for (i = 0; i < n; i++)
        x[i] = i;
    for (i = 0; i < n; i++) {
        j = rand() % n;
        t = x[i];
        x[i] = x[j];
        x[j] = t;
    }
}
