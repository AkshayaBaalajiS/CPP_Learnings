// proof that the int arr[] [] cant be called as arr ** 
#include <iostream>

using namespace std;

void func_to_print(int ** arr )
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j] << "  ";    
        }
        cout<<endl;
        
    }
}

int main()
{
    std::cout<<"Hello World";
    int arr[2][3] = {1,2,3,4,5,6};
    func_to_print(arr);
    return 0;
}


/*
#include <iostream>

using namespace std;

void func_to_print(int **arr)  // Accept pointer to pointer
{
    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            cout << arr[i][j] << "  ";    
        }
        cout << endl;
    }
}

int main()
{
    std::cout << "Hello World" << endl;
    
    // Dynamically allocate memory for the 2D array
    int rows = 2, cols = 3;
    int** arr = new int*[rows]; // Allocate memory for rows
    
    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // Allocate memory for columns
    }

    // Initialize the 2D array
    int count = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr[i][j] = count++;  // Assign values to the array
        }
    }

    // Pass the dynamically allocated array to the function
    func_to_print(arr);

    // Free the allocated memory
    for(int i = 0; i < rows; i++) {
        delete[] arr[i];  // Delete each row
    }
    delete[] arr;  // Delete the main array

    return 0;
}

*/
