akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ g++ -fPIC -c sub.cpp -o sub.o
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ g++ -fPIC -c mul.cpp -o mul.o
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ g++ -fPIC -c divide.cpp -o divide.o
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ g++ -shared -o libdynamic_cal.so add.o sub.o mul.o divide.o 


akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ g++ calculator.cpp -L. -ldynamic_cal -o calculator 


akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ ./calculator 
./calculator: error while loading shared libraries: libdynamic_cal.so: cannot open shared object file: No such file or directory


akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ export LD_LIBRARY_PATH=`pwd`


akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ echo $LD_LIBRARY_PATH
/home/akshayabaalaji-s/C++_Learning/Library_Static_Dynamic/Dynamic_Library


akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ ./calculator 
A + B = 30
A - B = -10
A * B = 200
A / B = 0
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Dynamic_Library$ 