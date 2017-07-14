/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima A - Prefix
 * Date: 28/04/2017 
 */
#include "OurLib.h"    

int main(int argc, char *argv[])
{
    //cout<<"It has " << std::thread::hardware_concurrency()<<" thread(s) the machine!\n";
    
    int n = 0 ;
    double ctime1, ctime2;
    
    if (argc > 1)
        stringstream(argv[1]) >> n;			
    if (n==0)
        n = readNum() ;
    
    int A[n] ;
    fillArrayWithRandNum(A,n) ;
    if (argc <= 2)	
        printArray(A,n) ;	
    
    int B[n] ;
    //Serial algorithm:    
    ctime1 = omp_get_wtime();  
    B[0] = A[0] ;
    for (int i=1;i<n;i++)
        B[i] = B[i-1]+A[i] ;
    ctime2 = omp_get_wtime();
    
    if (argc <= 2)	
        printArray(B,n) ;
    
    cout<<fixed<<"[Serial]time: "<<ctime2-ctime1<<" n= "<<n
            <<" thr= 1(ph:"<<std::thread::hardware_concurrency()<<")\n";		
    return 0 ;	
}
