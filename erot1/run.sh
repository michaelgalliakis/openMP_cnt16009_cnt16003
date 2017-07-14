  #!/bin/bash
if [ $# -eq 1 ]
then
 echo "Compiling..."
 g++ serialPrefix.cpp -o serialPrefix -fopenmp -std=c++11
 g++ parallelPrefix_A.cpp -o parallelPrefix_A -fopenmp -std=c++11
 g++ parallelPrefix_A_Opt.cpp -o parallelPrefix_A_Opt -fopenmp -std=c++11
 g++ parallelPrefix_B.cpp -o parallelPrefix_B -fopenmp -std=c++11
 g++ parallelPrefix_B_Opt.cpp -o parallelPrefix_B_Opt -fopenmp -std=c++11 
fi
echo "RUN:"

N="300" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="700" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="1000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_A $N OnlyTime
./parallelPrefix_A_Opt $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***"
echo

N="20000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo

N="100000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo

N="200000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo

N="400000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo

N="600000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo

N="800000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo

N="1000000" 
TH="1"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="2"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="4"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
TH="8"
echo "*** BEGIN: n :" $N " th : " $TH "***"
./serialPrefix $N OnlyTime
./parallelPrefix_B $N $TH OnlyTime
./parallelPrefix_B_Opt $N $TH OnlyTime
echo "*** END: n :" $N " th : " $TH "***\n"
echo