akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ g++ -c add.cpp -o add.o
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ g++ -c sub.cpp -o sub.o
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ g++ -c mul.cpp -o mul.o
akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ g++ -c divide.cpp -o divide.o



akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ echo "Use the ar (archiver) tool to create a static library by combining the object files into a .a archive."



akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ g++ calculator.cpp -L. calcu.a -o calculator  


akshayabaalaji-s@40475-016661:~/C++_Learning/Library_Static_Dynamic/Static_Library$ ./calculator 
A + B = 30
A - B = -10
A * B = 200
A / B = 0
