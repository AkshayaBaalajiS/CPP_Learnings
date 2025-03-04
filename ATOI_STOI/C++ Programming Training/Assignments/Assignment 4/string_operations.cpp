#include<iostream>
#include<cstring>
#include<string>
using namespace std ;

string global_variable ;
class String 
{
    public :
        String () {}
        string concatination (string s1 , string s2 )
        {
            // string temp  = s1 + s2 ;

            // string temp =s1.concat(s2); there is no concat option in c++
            
            s1.append(s2);
            return s1;
        }
        int length_finding (string str )
        {
            // const char * ptr = str.c_str();
            // int length =  strlen(ptr);
            // return length ;

            int length = str.length();
            return length;
        }
        
        void copy_string(string str )
        {
            global_variable = str ;  // how the global variale accessible inside the class above it 
            cout<<"The string copied to global variable   : " << global_variable << " \n";

			int length = str.length();
            char * ptr = new char [length+1];
            strcpy(ptr , str.c_str()); // strcpy for copying the char *  from const char * 
            

            global_variable.assign(str);  // assign for copying a string to another 
        } 

        void compare_String(string s1, string  s2)
        {
            //int result = strcmp(s1.c_str() , s2.c_str()); // this wont work why ?
          	
//			this wont work
//			int result = s1.compare(s2);
//            if (result == 0) {
//                cout << "Strings are equal" << endl;
//            } 
//            else if (result < 0) {
//                cout << "str1 is less than str2" << endl;
//            } 
//            else {
//                cout << "str1 is greater than str2" << endl;
//            }
			cout<<"void compare_String(string s1, string  s2)     : \n"; 
            if (s1 == s2 ) {
                cout << "Strings are equal" << endl;
            } 
            else if (s1 < s2) {
                cout << "str1 is less than str2" << endl;
            } 
            else {
                cout << "str1 is greater than str2" << endl;
            }
            
        }
        string reverse_string(string s1)
        {
        	int length = s1.length();
            char * ptr = new char [length+1];
            for (int i=length-1,j=0;i>=0;j++,i--)
            {
            	ptr[j] = s1[i];
			}
			
        	//below auto type cast done from char * to string 
			string temp  = ptr ;
        	return temp;
		}
		string convert_string(string s1 , char c1 , char c2 )
        {
        	int length = s1.length();
           	for(int i=0;i<(s1.length());i++ )
           	{
           		if(s1[i] == c1)
				{
				 	s1[i] = c2 ;  	
				}
			}
			return s1;
		}

		int find_string(string s1 , string s2 )
		{
			int index = s1.find(s2);
			cout<<"Found at index  : " << index <<"\n";
			return index ;
		}

};
int main()
{
    string s1 = "Akshaya Baalaji " ;
    string s2 = "Senthilraj " ;

    String object;
    
    cout<<"-------------------------------------------------\n";
    string full_name = object.concatination(s1 , s2)  ;
    cout<<"The concatenated string is  : " << full_name << " \n";

    cout<<"-------------------------------------------------\n";
    int length = object.length_finding(full_name);
    cout<<"Length is :  "<<length << "\n";
    cout<<"-------------------------------------------------\n";
    
    object.copy_string(full_name);
    cout<<"-------------------------------------------------\n";

    cout<<"-------------------------------------------------\n";
    object.compare_String(full_name, s1);
    cout<<"-------------------------------------------------\n";

    object.compare_String(full_name, full_name);
    cout<<"-------------------------------------------------\n";
    
    full_name = object.reverse_string(full_name);
    cout<<"Reverse is : " << full_name<<"\n";
	cout<<"-------------------------------------------------\n";
    
    full_name = object.convert_string(full_name,'a' , 'i');
    cout<<"Convert 'a' to 'i' is : " << full_name<<"\n";
	cout<<"-------------------------------------------------\n";
    
    string temp = "ijiliiB";
    int index = object.find_string(full_name,temp );
    if(index >= 0 )
     {
     	cout<<"Found inside the string \n"  ;
	 }
	 else 
	 {
	 	cout<<"Not found \n";
	 }
    
}

