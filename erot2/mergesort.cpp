/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima B - Prefix
 * Date: 2/05/2017 
 */
#include "OurLib.h"

#define MAX_SIZE 1000

void mergesort(int *, int, int *);

int main(int argc, char *argv[])
{
    int n = 0;  
    double ctime1, ctime2;
    
    if (argc > 1)
        stringstream(argv[1]) >> n;     
    if (n==0)
        n = readNum() ;      
    
    int data[n], tmp[n];
    
    generate_list(data, n);
    if (argc <= 2){
        cout<<"******** Final ***********" <<"\n" ;
        printArray(data, n);
    }
    ctime1 = omp_get_wtime(); 
    mergesort(data, n, tmp);
    ctime2 = omp_get_wtime(); 
    if (argc <= 2){    
        printArray(data, n);
        cout<<"********  End  ***********" <<"\n" ;  
    }
    
    cout<<fixed<<"[Mergesort]time: "<<ctime2-ctime1<<" n= "<<n
            <<" thr= 1(ph:"<<std::thread::hardware_concurrency()<<")\n";
}

void merge(int * X, int n, int * tmp) {
    int i = 0;
    int j = n/2;
    int ti = 0;
    
    while (i<n/2 && j<n) {
        if (X[i] < X[j]) {
            tmp[ti] = X[i];
            ti++; i++;
        } else {
            tmp[ti] = X[j];
            ti++; j++;
        }
    }
    while (i<n/2) { /* finish up lower half */
        tmp[ti] = X[i];
        ti++; i++;
    }
    while (j<n) { /* finish up upper half */
        tmp[ti] = X[j];
        ti++; j++;
    }
    memcpy(X, tmp, n*sizeof(int));
    
} // end of merge()

void mergesort(int * X, int n, int * tmp)
{
    if (n < 2) return;
    
    mergesort(X, n/2, tmp);
    mergesort(X+(n/2), n-(n/2), tmp);  
    
    /* merge sorted halves into sorted list */
    merge(X, n, tmp);
}
