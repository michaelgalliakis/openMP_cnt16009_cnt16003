/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima 1 - Prefix
 * Date: 28/04/2017 
 */
#include "OurLib.h"    

#define CHUNKSIZE 1

int main(int argc, char *argv[])
{	
    //cout<<"It has " << std::thread::hardware_concurrency()<<" thread(s) the machine!\n";
    
    int n = 0 ;
    double ctime1, ctime2;
    if (argc > 1)
        stringstream(argv[1]) >> n;			
    if (n==0)
        n = readNum() ;
    
    omp_set_num_threads(n);
    int A[2][n],OriginalA[n] ;
    fillArrayWithRandNum(A[0],n) ;
    copyArray(A[0],OriginalA,n);    
    //printArray(A[0],n) ;		
    
    int tid;
    int chunk = CHUNKSIZE;
    
    int repetitions = ceil(log2(n));		
    int jump = 1;
    
    int index = 0 ;
    //A[!index][0] = A[index][0] ;
    ctime1 = omp_get_wtime();   
    for (int k=1;k<=repetitions;k++){
        //cout<<"## k = " << k << "\n";
        #pragma omp parallel shared(A,n,repetitions,chunk,jump) private(tid)
        {
            //tid = omp_get_thread_num();		
            //jump = pow(2,k-1) ; 
            #pragma omp for schedule(dynamic,chunk) 
            for (int i=jump/2; i < n; i++)
            {    		
                if (i<jump)
                    A[!index][i] = A[index][i];	
                else
                    A[!index][i] = A[index][i] + A[index][i-jump];	
                //printInfo(tid,k,i,A[!index][i]) ;                
            }
        }	
        jump <<= 1 ; 				
        index = !index ;	        
        //printArray(A[index],n) ;	                 
    }	
    ctime2 = omp_get_wtime();
    if (argc <= 2){
        cout<<"******** Final ***********" <<"\n" ;
        printArray(OriginalA,n) ;	
        printArray(A[index],n) ;	
        cout<<"********  End  ***********" <<"\n" ;
    }
    cout<<fixed<<"[Parallel_A_Opt]time: "<<ctime2-ctime1<<" n= "<<n
            <<" thr= "<<n<<"(ph:"<<std::thread::hardware_concurrency()<<")\n";
    return 0 ;	
}

