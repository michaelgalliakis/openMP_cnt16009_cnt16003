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
    int threads = 0 ;
    double ctime1, ctime2;
    
    if (argc > 1)
        stringstream(argv[1]) >> n;			
    if (n==0)
        n = readNum() ;
    
    if (argc > 2)
        stringstream(argv[2]) >> threads;			
    if (threads<=0)	
        threads = readNum("threads",0,n) ;
    else if (threads>n) 
        threads = n ;	
    
    omp_set_num_threads(threads);
    
    int A[n] ;
    fillArrayWithRandNum(A,n) ;        
    //printArray(A,n) ;		
    
    int tid;       
    int logos = n/threads ;        
    int B[n] ;
    int lastValues[threads] ;
    int sum = 0 ;   
    ctime1 = omp_get_wtime();   
    #pragma omp parallel shared(A,B,n) private(tid,sum)
    {			
        tid = omp_get_thread_num();		            
        int begin = tid*logos ;
        int end = begin + logos - 1 + (tid==omp_get_num_threads()-1?n%threads:0) ;   
        B[begin]=A[begin] ;        
        
        for (int i=begin+1 ; i <= end; i++)
        {    			            
            B[i] = B[i-1] + A[i];	
            //printInfo(tid,0,i,B[i]) ;                            
        }         
        lastValues[tid] = B[end] ;
        
        sum = 0;        
        #pragma omp barrier
        for (int i=0 ; i <tid; i++)            					
            sum +=lastValues[i];				
        
        if (tid>0)			
            for (int i=begin ; i <= end; i++)
            {    								                                
                B[i] += sum;	
                //printInfo(tid,0,i,B[i]) ;                				                    
            }         		
    }	
    ctime2 = omp_get_wtime();	
    if (argc <= 3){
        cout<<"******** Final ***********" <<"\n" ;    
        printArray(A,n) ;	
        printArray(B,n) ;	
        cout<<"********  End  ***********" <<"\n" ;
    }
    cout<<fixed<<"[Parallel_B]time: "<<ctime2-ctime1<<" n= "<<n
            <<" thr= "<<threads<<"(ph:"<<std::thread::hardware_concurrency()<<")\n";
    return 0 ;	
}
