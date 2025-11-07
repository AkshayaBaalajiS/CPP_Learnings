class Drug 
{ 
 char category[10]; 
 char date_of_manufacture[10]; 
 char company[20]; 
 public: 
 Drug(); 
 void enterdrugdetails(); 
 void showdrugdetails(); 
}; 
class Tablet : public Drug 
{ 
 protected: 
 char tablet_name[30]; 
 char volume_label[20]; 
 public: 
 float price; 
 Tablet(); 
 void entertabletdetails(); 
 void showtabletdetails (); 
}; 
class PainReliever : public Tablet 
{ 
 int dosage_units; 
 char side_effects[20]; 
 int use_within_days; 
 public: 
 PainReliever(); 
 void enterdetails(); 
 void showdetails(); 
}; 
/*
(i) How many bytes will be required by an object of class Drug and an object of 
class PainReliever respectively ?  : Drug - 30   , Painreleiver - 122
(ii) Write names of all the data members which are accessible from the object of 
class PainReliever.  -       price ,  
(iii) Write names of all the members accessible from member functions of 
class Tablet.  : char tablet_name[30] , char volume_label[20] , float price 
(iv) Write names of all the member functions which are accessible from objects of 
class PainReliever. : 
	PainReliever(); 
	void enterdetails(); 
	void showdetails(); 
	void entertabletdetails(); 
 	void showtabletdetails (); 
*/
