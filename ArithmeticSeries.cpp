/** @author: Leonardo Matone
 *  @file: Simple script to simulate an arithmetic series.
 *  @version C++ 11   */

#include <iostream>
using namespace std;

int sum(int n);

int main() {

    int input; 
    cout << "enter an integer: ";
    cin >> input;
    cout << endl; 

    int resultantSum = sum(input);

    cout << "resultant partialSum: " << resultantSum << endl;
}

/** @param n integer
 *  @return partialSum, the resultant summation 
 *  of the arithmetic series where i is cubed. */
int sum(int n) {
    int partialSum = 0; // 1
    
    for (int i = 1; i <= n; ++i) // N
        partialSum += i*i*i; // 1
    return partialSum; // 1
}
// time complexity: O(N)