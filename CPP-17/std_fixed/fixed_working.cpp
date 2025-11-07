#include <iostream>
#include <iomanip>
#include <cstdio>

int main() {
    double num = 12345.6789;

    std::cout << "Default: " << num << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Fixed: " << num << std::endl;



    std::cout<<"-----------------------------------------\n";
    std::cout<<"printf way of precision control \n";
    printf(".3f of the double number is %.3f\n" , num);
    printf("normal f of the  double number is %f\n" , num);

    
    std::cout<<"-----------------------------------------\n";

    return 0;
}
