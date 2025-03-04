all : compile
compile : shared_library libdynamic_prg.so
  g++ -o output application.o  -L. -ldynamic_prg
shared_library :library headers.h
  g++ -shared -o libdynamic_prg.so functions.o
  g++ -c application.cpp 
library:
  g++ -c -fPIC functions.cpp 
remove:
  rm -r *.o *.so output *.gch
