  #!/bin/bash
if [ $# -eq 1 ]
then
 echo "Compiling..."
 g++ mergesort.cpp -o mergesort -fopenmp -std=c++11
 g++ msort.cpp -o msort -fopenmp -std=c++11
 g++ multisort.cpp -o multisort -fopenmp -std=c++11 
fi
echo "RUN:"

N="300" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="3000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="30000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="300000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="600000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="1000000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./mergesort $N OnlyTime
./msort $N $TH OnlyTime
./multisort $N $TH DefaultLimit OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo
echo

# Try some limits
echo "Try some limits:"
N="1000000" 
TH="-1" # machine threads
LIMIT="100"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="1000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="10000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="15000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="25000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="50000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="75000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo

LIMIT="100000"
echo "*** BEGIN: n :" $N " th : (machine threads) ***"
./mergesort $N OnlyTime
./multisort $N $TH $LIMIT OnlyTime
echo "*** END: n :" $N " th : (machine threads) ***"
echo
