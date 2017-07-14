/*
 * Athanasios Rokopoulos (cnt16009)
 * Michael Galliakis (cnt16003)
 * OpenMP - Erotima B - Prefix
 * Date: 2/05/2017 
 */
#include "OurLib.h"

#define DEFAULTLIMIT 10000

int Limit = DEFAULTLIMIT ;

void multisort(int*, long, int*) ;

int main(int argc, char *argv[])
{
    int n = 0;
    int threads = 0 ;
    double ctime1, ctime2;
    //cout<<"It has " << std::thread::hardware_concurrency()<<" thread(s) the machine!\n";
    
    if (argc > 1)
        stringstream(argv[1]) >> n;	//περνιέται παραμετρικά το n	 	
    if (n<=0)
        n = readNum() ; //Δείνει ο χρήστης το n με την βοήθεια της readNum
    
    if (argc > 2)
        stringstream(argv[2]) >> threads; //περνιέται παραμετρικά ο αριθμός των threads		
    if (threads==0)
        threads = readNum("threads",0,n) ; //Δείνει ο χρήστης τον αριθμό των threads
    else if (threads<0)					   //με την βοήθεια της readNum
        threads = std::thread::hardware_concurrency() ; // Αν η μεταβλητή threads είναι αρνητική (έχει περαστεί παραμετρικά) 
    												// τότε τα threads θα είναι όσα έχει το μηχάνημα που τρέχει το πρόγραμμα.
    if (argc > 3)
        stringstream(argv[3]) >> Limit;	 //περνιέται παραμετρικά το Limit		
    if (Limit<=0)
        Limit = DEFAULTLIMIT ;	//Αν το limit είναι είναι μικρότερο του 1, τότε το limit είναι το default.
    
    int data[n], tmp[n]; 
    
    omp_set_num_threads(threads);  // Δηλώνουμε πόσα threads θα έχουμε στο openMP.
    generate_list(data, n); //υπολογίζονται 0-n αριθμοί και διασκορπίζονται στον πίνακα data.
    if (argc <= 4){ //Δεν εμφανίζεται ο αρχικός, μη ταξινομημένος πίνακας, αν έχουμε 4 ή περισσότερους παραμέτρους.
        cout<<"******** Final ***********" <<"\n" ;
        printArray(data, n);
    }
    ctime1 = omp_get_wtime();  //Ξεκινάμε να χρονομετράμε τον αλγόριθμο:  
    #pragma omp parallel
    {
    #pragma omp single        
        multisort(data, n, tmp);
    }
    ctime2 = omp_get_wtime(); //Σταματάμε να χρονομετράμε τον αλγόριθμο!
    if (argc <= 4){	 //Δεν εμφανίζεται ο τελικός, ταξινομημένος πίνακας, αν έχουμε 4 ή περισσότερους παραμέτρους.	
        printArray(data, n);
        cout<<"********  End  ***********" <<"\n" ;  
    }
    
    cout<<fixed<<"[Multisort]time: "<<ctime2-ctime1<<" n= "<<n //Εμφανίζεται μήνυμα με χρόνο, n, threads,φυσικά threads, limit.
            <<" thr= "<<threads<<"(ph:"<<std::thread::hardware_concurrency()<<") ";
    cout<<"Limit="<<Limit<<endl ;
    return 0 ;
}
/*
	Συνάρτηση που κάνει merge ένα πίνακα Χ (n θέσεων) με την βοήθεια ενός προσωρινού πίνακα (tmp[n θέσεων]).
	Θα πρέπει τα δύο μισά του πίνακα να είναι ταξινομημένα, ώστε να μπορέσει να πραγματοποιηθεί
	η συγχώνευση. πχ αν n=10 πρέπει στον Χ οι αριθμοί στις θέσεις 0..4 & 5..9 να είναι ταξινομημένοι.
	Είναι ακριβώς η ίδια που μας δώσατε.
*/
void merge(int * X, long n, int * tmp) { 
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

/*	
	Είναι ακριβώς η ίδια που μας δώσατε, με διαφορά ότι είναι ακολουθιακή και όχι παράλληλη. Χρησιμοποιείται 
	στην περίπτωση που το n στην multisort είναι μικρότερο από ένα καθορισμένο όριο. Οπότε πρακτικά 
	ταξινομεί ένα πίνακα X, n στοιχείων.
*/
void mergesort(int * X, int n, int * tmp)
{
    if (n < 2) return;
    
    mergesort(X, n/2, tmp);
    mergesort(X+(n/2), n-(n/2), tmp);  
    
    /* merge sorted halves into sorted list */
    merge(X, n, tmp);
}

void multisort(int *X, long n, int * tmp)
{
    if (n < Limit)  //Το limit είναι Global μεταβλητή.
    {				//Αν το n είναι μικρότερο από ένα καθορισμένο όριο τότε
    				//εκτελείτε η σειριακή mergesort για τα n(<limit) στοιχεία. 
        mergesort(X, n, tmp);   		
        /*
        Αντί για την quicksort, χρησιμοποιήσαμε την mergesort (σειριακή) όταν το n, 
        μετά τις αναδρομικές κλήσεις, είναι μικρότερο από κάποιο όριο (limit). 
        Επειδή την είχαμε έτοιμη (mergesort) από το παράδειγμα σας στο eclass (msort.c).
        */
        return ;
    } 
    
    int qua = (n/4) ; //Ένα τέταρτο του n
    int dr = n%4 ; //Υπόλοιπο διαίρεσης
    int partA = qua ; //Πρώτο κομμάτι
    int partB = qua + ((dr>1)?1:0); //Δεύτερο κομμάτι
    int partC = qua + ((dr>2)?1:0) ; //Τρίτο κομμάτι
    int partD = qua + ((dr>0)?1:0); //Τέταρτο κομμάτι    
    
    //Για να γίνει το merge πρέπει τα δύο μισά του πίνακα να είναι ταξινομημένα.
    //Οπότε, αν το υπόλοιπο της διαίρεσης (1,2,3) το πάρει ένα οποιοδήποτε από τα 3 μέρη (πχ partΒ)
    //υπάρχει πρόβλημα! Στην merge αν είναι ζυγός το n, πχ n=12, καταλαβαίνει 6 & 6 ταξινομημένα και
    //αν είναι περιττός το n, πχ n=13 καταλαβαίνει 6 & 7 (Μια μονάδα το πολύ μεγαλύτερο το 2ο από το 1ο).
    //Οπότε δεν μπορείς πχ να έχεις 5 και 7 ταξινομημένα στοιχεία...
    //Ο παραπάνω τρόπος που μοιράζει το υπόλοιπο της διαίρεσης λύνει το πρόβλημα, γιατί:
    // Αν πχ n = 1001 τότε [pa=250, pb=250], [pc=250, pd=251] -> 500 , 501 (Τελικό merge)
    // Αν πχ n = 1002 τότε [pa=250, pb=251], [pc=250, pd=251] -> 501 , 501 (Τελικό merge)
    // Αν πχ n = 1003 τότε [pa=250, pb=251], [pc=251, pd=251] -> 501 , 502 (Τελικό merge)
    // Αν πχ n = 1004 τότε [pa=251, pb=251], [pc=251, pd=251] -> 502 , 502 (Τελικό merge)

    //Πρακτικά υπολογίζονται οι 4 υποπίνακες του Χ, ώστε να κληθούν στις 4 αναδρομικές κλήσεις.
    int *XA = X ; 
    int *XB = XA+partA; 
    int *XC = XB+partB ;
    int *XD = XC+partC ;
    //Πρακτικά υπολογίζονται οι 4 υποπίνακες του tmp, ώστε να κληθούν στις 4 αναδρομικές κλήσεις.
    int *tmpA = tmp ;
    int *tmpB = tmpA+partA; 
    int *tmpC = tmpB+partB ;
    int *tmpD = tmpC+partC ;
   
    //cout<< omp_get_thread_num()<<endl ;
 
    //Εκτελούνται παράλληλα (σε tasks) οι 4 αναδρομικές κλήσεις, για κάθε τέταρτο του X.
    #pragma omp task firstprivate (XA, partA, tmpA)
    multisort(XA, partA, tmpA);   
    
    #pragma omp task firstprivate (XB, partB, tmpB) 
    multisort(XB,partB, tmpB);
    
    #pragma omp task firstprivate (XC, partC, tmpC) 
    multisort(XC, partC, tmpC);
    
    #pragma omp task firstprivate (XD, partD, tmpD) 
    multisort(XD, partD , tmpD);
    
    //Περιμένουμε να τελειώσουν όλα τα tasks.
    #pragma omp taskwait
    
    //Εκτελούνται παράλληλα (σε tasks) τα 2 πρώτα merge, για τα δύο μισά του X.
    #pragma omp task 
    merge(XA, partA + partB, tmpA);
    
    #pragma omp task 
    merge(XC, partC + partD, tmpC);   
    
    //Περιμένουμε να τελειώσουν όλα τα tasks.
    #pragma omp taskwait
    //Εκτελείτε σειριακά το καθολικό-τελικό merge για όλον τον X.
    merge(X, n, tmp);     
}
