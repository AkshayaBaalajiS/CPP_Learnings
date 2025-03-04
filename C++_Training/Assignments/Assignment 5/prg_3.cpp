class Vehicle 
{ 
 private: 
 int wheels; 	
 protected : 
 int passenger: 
 public : 
 void inputdata(int, int); 
 void outputdata(); 
}; 
class Heavyvehicle : protected Vehicle 
{ 
 int diesel_petrol; 
 protected : 
 int load; 
 public: 
 void readdata(int, int); 
 void writedata(); 
}; 
class Bus : private Heavyvehicle 
{ 
 char make[20]; 
 public : 
 void fetchdata(char); 
 void displaydata(); 
}; 

 /*
(i) Name the base class and derived class of the class Heavyvehicle.  - Vehicle base , Bus is derived class
(ii) Name the data member(s) that can be accessed from function displaydata(). - passanger (Vehicle )
(iii) Name the data member's that can be accessed by an object of Bus class.  - passenger(vehicle)
(iv) Is the member function outputdata() accessible to the objects 
of Heavyvehicle class.  - Yes 
*/
