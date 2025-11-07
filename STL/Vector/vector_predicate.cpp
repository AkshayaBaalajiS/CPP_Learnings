#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Unary predicate function
bool isEven(int value)
{
    return value % 2 == 0;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    // Using std::find_if with a unary predicate
    auto it = find_if(numbers.begin(), numbers.end(), isEven);

    if (it != numbers.end())
    {
        cout << "First even number: " << *it << endl;
    }
    else
    {
        cout << "No even number found" << endl;
    }

    return 0;
}
