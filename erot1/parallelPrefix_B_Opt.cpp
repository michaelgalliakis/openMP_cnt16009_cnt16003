/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima A - Prefix
 * Date: 03/05/2017 
 */
#include "OurLib.h"  

void calcPrefixSumNequalsP(int *(&),int) ;  
int main(int argc, char *argv[])
{		
    //cout<<"It has " << std::thread::hardware_concurrency()<<" thread(s) the machine!\n";
    
    int n = 0 ;
    int threads = 0 ;
    double ctime1, ctime2;
    
    if (argc > 1)
        stringstream(argv[1]) >> n; //περνιέται παραμετρικά το n
    if (n==0)
        n = readNum() ; //Δείνει ο χρήστης το n με την βοήθεια της readNum
    
    if (argc > 2)
        stringstream(argv[2]) >> threads; //περνιέται παραμετρικά ο αριθμός των threads			
    if (threads<=0)	
        threads = readNum("threads",0,n) ;  //Δείνει ο χρήστης τον αριθμό των threads
    else if (threads>n) 					//με την βοήθεια της readNum
        threads = n ;	// Αν threads είναι περισσότερα από το n τότε να γίνεται threads=n ;
    
    omp_set_num_threads(threads);// Δηλώνουμε πόσα threads θα έχουμε στο openMP.
    
    int A[n] ;  //Δημιουργείται ο πίνακας Α (Αρχικός).
    fillArrayWithRandNum(A,n) ; //Γεμίζει ο πίνακας Α με τυχαίους αριθμούς από το 1-10.   
    //printArray(A,n) ;		
    
    int tid, prevPrefIndex;       
    int logos = n/threads ;  // υπολογίζεται ο λόγος
    int dr = n % threads ;   // υπολογίζεται το υπόλοιπο της διαίρεσης
    int B[n] ; //Δημιουργείται ο πίνακας Β (Για αποτελέσματα).
    int *lastValues = new int[threads] ; //Δημιουργείται ο πίνακας για τις τελευταίες τιμές από το κάθε thread...      
    int begin[threads],end[threads] ; //Φτιάχνονται 2 πίνακες που θα παίρνουν τους "δείκτες" αρχής και τέλους
    								  //ώστε να μπορεί κάθε thread να υπολογίζει σειριακά το δικό του κομμάτι.
    
    ctime1 = omp_get_wtime(); //Ξεκινάμε να χρονομετράμε τον αλγόριθμο:  
    #pragma omp parallel shared(A,B,n) private(tid)
    {			
        tid = omp_get_thread_num();	 //Κάθε thread παίρνει το id του              
        begin[tid] = tid*logos + ((tid<dr)?tid:dr);  //Υπολογίζεται ο δείκτης αρχής για κάθε thread 
		end[tid] = begin[tid] + logos  + ((tid<dr)?1:0) -1 ; //Υπολογίζεται ο δείκτης τέλους για κάθε thread
                 											//Υπολογίζεται πχ για n=18 & th= 4, θα είναι 5,5,4,4
        B[begin[tid]]=A[begin[tid]] ;   //Ο πρώτος αριθμός δεν χρειάζεται να υπολογιστεί.
        for (int i=begin[tid]+1 ; i <= end[tid]; i++) //Από τον δευτερο αριθμό μέχρι το τελευταίο
            B[i] = B[i-1] + A[i];	                  //για κάθε thread, υπολογίζεται το PrefixSum σειριακά.                          
        lastValues[tid] = B[end[tid]] ; //Ο πίνακας lastValues στην θέση του tid παίρνει τον τελευταίο υπολογισμένο Prefix
    }		//Σταματάει η παραλληλία
    calcPrefixSumNequalsP(lastValues, threads); //Υπολογίζονται τα prefix του lastValues με τον αλγόριθμο για n=p.
    #pragma omp parallel shared(A,B,n) private(tid,prevPrefIndex)
    {	
        tid = omp_get_thread_num();  //Κάθε thread παίρνει το id του πάλι                        
        if (tid>0) //Το 0 thread έχει έτοιμα τα Prefix του, οπότε δεν κάνει κάτι
        {
            prevPrefIndex = tid-1 ; //Υπολογίζεται ο δείκτης για τον lastValues.
            for (int i=begin[tid] ; i <= end[tid]; i++) // Κάθε thread, για το κομμάτι του πίνακα που τον αφορούν
                B[i] += lastValues[prevPrefIndex];      //υπολογίζει τα τελικά prefix με την βοήθεια του lastValues.
        }	       
    }  //Σταματάει η παραλληλία  	
    ctime2 = omp_get_wtime();//Σταματάμε να χρονομετράμε τον αλγόριθμο!
    if (argc <= 3){ //Εμφανίζονται τα μηνύματα αν έχουν δοθεί λιγότεροι από τρεις παραμέτροι. 
        cout<<"******** Final ***********" <<"\n" ;    
        printArray(A,n) ;	
        printArray(B,n) ;	
        cout<<"********  End  ***********" <<"\n" ;
    }
    cout<<fixed<<"[Parallel_B_Opt]time: "<<ctime2-ctime1<<" n= "<<n //Εμφανίζεται μήνυμα με χρόνο, n, threads,φυσικά threads.
            <<" thr= "<<threads<<"(ph:"<<std::thread::hardware_concurrency()<<")\n";
    return 0 ;	
}

void calcPrefixSumNequalsP(int *(&Array),int n) //Συνάρτηση που υπολογίζει τα prefixSum για n=p
{	         
    int **A = new int*[2] ;
    A[0] = Array ; 
    A[1] = new int[n];    
    
    int chunk = 1 ; // Θέλουμε chunk = 1, γιατί έχουμε n=p όποτε σε κάθε επανάληψη  
    				// του for να κάνει κάθε thread από μόνο μια πράξη.
    
    int repetitions = ceil(log2(n)); // Βρίσκονται οι επαναλήψεις-βήματα		
    int jump = 1; //Στην αρχή το jump είναι 1
    int tid;        
    int index = 0 ;  //Δείκτης για να γίνονται εναλλαγές μεταξύ των 2 πινάκων πρακτικά.
    for (int k=1;k<=repetitions;k++){ // Για όσα είναι τα βήματα
        #pragma omp parallel shared(A,n,repetitions,chunk,jump) //Τρέχουμε παράλληλα
        {                                     
            #pragma omp for schedule(static,chunk) 
            for (int i=jump/2; i < n; i++) //Το jump είναι δια 2, γιατί υπάρχουν ήδη τα 
            {							   //τα υπολογισμένα prefix μέχρι εκεί...
                //tid = omp_get_thread_num();                         
                if (i<jump)
                    A[!index][i] = A[index][i];	//Αντιγράφονται απλά(με παράλληλο τρόπο), γιατί γνωρίζουμε το Prefix
                else
                    A[!index][i] = A[index][i] + A[index][i-jump];	//Υπολογίζεται το Prefix παράλληλα
                //printInfo(tid,k,i,A[!index][i]) ;                
            }            
        }			
        jump <<= 1 ; //Γίνεται shift κατά μια θέση στο δυαδικό, οπότε το jump παίρνει την αμέσως 
        			 //επόμενη δύναμη του 2 από αυτό που ήταν (πχ από 100 [4] -> 1000 [8]).			
        index = !index ;	//Ο δείκτης πρακτικά αλλάζει (0->1,1->0) ώστε μετά από κάθε βήμα, ο πίνακας
        					//των αποτελεσμάτων, να γίνεται αρχικός για την επόμενη επανάληψη.                	                
    }
    Array = A[index]; //Επιστρέφεται πρακτικά ο πίνακας με τα αποτελέσματα...
}
