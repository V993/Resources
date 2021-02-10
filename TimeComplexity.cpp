/** @author: Leonardo Matone
 *  @file: simple script with interactive programs demonstrating
 *  different runtimes for different algorithms.
 *  @version C++ 11
 * 
 *      @resources used:
 * 
 *      iostream:   for input and output
 *      string:     for the useage of strings
 *      chrono:     runtime tracking
 *      math.h:     exponential function
 *      iomanip:    for nice outputs
 */

#include <iostream>
#include <string>
#include <chrono>
#include <math.h>
#include <iomanip>
#include <vector>

/** use of the chrono library is intended to demonstrate different 
 *  runtimes for different algorithms efficiently. For information
 *  on chrono, consult:
 *  https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
 */

using namespace std::chrono;
using namespace std;

//  script paths (what the script will do on user specification): 
void singleAlgorithm(long int N);
void algorithmComparison(long int N);
void compareAll(long int N);

//  function declarations (actual algorithms):
int constant(long int n); 
int linear(long int n);
int logarithmic(long int n);
int quadratic(long int n);
int cubic(long int n);

vector<string> algorithms = {"constant", "linear", "logarithmic", "quadratic", "cubic"};

/**  The main function in this script is responsible for two things:   
 *      1. the size of input for algorithms (determined from user input)
 *      2. what the script will do:
 *          a. runtime for a specific algorithm
 *          b. runtime for two algorithms, compared against each other
 *          c. runtime for all defined algorithms, compared agaisnt each other
 *   both paths for the script are determined with switches.  */
int main() {

    int integer;    // we use this to determine the size of our input in the switch.
    int test;       // we use this to determine what our script will do based off of user needs. 
    long int N;     // finally, the actual size of our input. We use 'long int' as some inputs are quite large in these tests.

        // prompt user for input size specification:
    cout << "input size for test:\n\t1. small\n\t2. large\n\t3. ridiculously large\n\t4. you want to make your machine groan\n\t5. you want to break your machine\n";
    cout << "enter size of input (number): ";
    cin >> integer;
    cout << endl;

        // switch used to attribute a handy input size based off of user specification.
    switch(integer) {
        case 1:
            N = 8; 
            break;
        case 2:
            N = 512;
            break;
        case 3:
            N = 4096;
            break;
        case 4:
            N = 65536;
            break;
        case 5:
            N = 4294967296;
            break;
        default:
            cout << "no acceptable input" << endl;
            break;
    }

    cout << "choice of test: \n\t1. single algorithm runtime\n\t2. side-by-side comparison of two algorithms\n\t3. test all algorithms on same input and compare time\n";
    cout << "enter choice of test (number): ";
    cin >> test;
    cout << endl;

        //  switch used to determine what the script will do based off of user choice of test.
    switch (test) {
        case 1:
            singleAlgorithm(N);
            break;
        case 2:
            algorithmComparison(N); 
            break;
        case 3:
            compareAll(N);
            break;
        default:
            cout << "no acceptable input" << endl;
            break;
    }

}

/** @brief prompts user for a single algorithm, runs it on input N, and gives the runtime.
    @param N long int, size dependent on user input in main() */ 
void singleAlgorithm(long int N) {

    int algorithm;
    string chosenAlgorithm;

    cout << "algorithms:\n\t1. constant\n\t2. linear\n\t3. logarithmic\n\t4. quadratic\n\t5. cubic\n";
    cout << "enter algorithm choice (number): ";
    cin >> algorithm;

    // with this line, we now have the string value for the algorithm the user chooses.
    chosenAlgorithm = algorithms[algorithm];

    int result;

    auto start = high_resolution_clock::now();
    switch(algorithm) {
        case 1:
            result = constant(N);  
            break;
        case 2:
            result = linear(N);
            break;
        case 3:
            result = logarithmic(N);
            break;
        case 4:
            result = quadratic(N);
            break;
        case 5:
            result = cubic(N); 
            break;
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "result for " << chosenAlgorithm << ": " << endl;
    cout << "time to compute: " << duration.count() << " microseconds."<<  endl;
}

/** @brief prompts user two algorithms, runs both on the same input N, and gives the runtime for each.
    @param N long int, size dependent on user input in main() */ 
void algorithmComparison(long int N) {
    int algorithm1;
    int algorithm2;
    int result;

    string firstAlgorithm;
    string secondAlgorithm;

    //  here the user designates which algoritms will be compared. We save the number of their choice for our switch below.
    cout << "algorithms:\n\t1. constant\n\t2. linear\n\t3. logarithmic\n\t4. quadratic\n\t5. cubic\n";
    cout << "enter first algorithm choice (number): ";
    cin >> algorithm1;
    cout << endl << "enter second algorithm choice (number): ";
    cin >> algorithm2;
    cout << endl;

    //  With these lines, we now have the string values of each algorithm for output use later.
    firstAlgorithm = algorithms[algorithm1];
    secondAlgorithm = algorithms[algorithm2];

    auto start1 = high_resolution_clock::now();
    switch(algorithm1) {
        case 1:
            result = constant(N);  
            break;
        case 2:
            result = linear(N);
            break;
        case 3:
            result = logarithmic(N);
            break;
        case 4:
            result = quadratic(N);
            break;
        case 5:
            result = cubic(N); 
            break;
    }
    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    switch(algorithm2) {
        case 1:
            result = constant(N);  
            break;
        case 2:
            result = linear(N);
            break;
        case 3:
            result = logarithmic(N);
            break;
        case 4:
            result = quadratic(N);
            break;
        case 5:
            result = cubic(N); 
            break;
    }
    auto stop2 = high_resolution_clock::now();
    
    auto duration1 = duration_cast<microseconds>(stop1 - start1); 
    auto duration2 = duration_cast<microseconds>(stop2 - start2); 

    cout << "\talgorithm:     |      compute time:  \n";
    cout << "\t" << firstAlgorithm << setw(5) << "|" << setw(10) << duration1.count() << " microseconds" << endl;
    cout << "\t" << secondAlgorithm << setw(5) << "|" << setw(10) << duration2.count() << " microseconds" << endl;
}

/** @brief runs all algorithms on the same input N, and gives the runtime for each algorithm.
    @param N long int, size dependent on user input in main() */ 
void compareAll(long int N) {
    cout << "hello";
}

/** performs an operation on an integer in constant time:
 *  @brief Multiplies n by a constant and returns the result
 *  @param n integer input
 *  @return the result of algorithm in O(1) time */
int constant(long int n) {
    return 0;
}

/** performs an operation on an integer in linear time:
 *  @brief Takes 2 to the power of i for i=0; i<n
 *  @param n integer input
 *  @return the result of algorithm in O(N) time */
int linear(long int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += pow(2,i);
    }
    return 0;
}

/** performs an operation on an integer in logarithmic time:
 *  @brief Divides input by 2 until the result is less than or 
 *  equal to one. Returns the number of divisions necessary.
 *  @param n integer input. To best demonstrate this algorithm,
 *         it is best to use numbers which can be described by
 *         2^k for some integer k>0. (2, 4, 8, 16, 32, 64 ..)
 *  @return the result of algorithm in O(log(N)) time */
int logarithmic(long int n) {
    if (n % 2 != 0) 
        n++;
    int count = 0;
    while (n > 1) {
        n = n/2;
        count++;
    }
    return count;
}

/** performs an operation on an integer in quadratic time:
 *  @brief This algorithm uses a nested for loop to perform 
 *  n^2 calculations, tabulating the number of inner and 
 *  outer counts, and returning their product.
 *  @param n integer input
 *  @return the result of algorithm in O(N^2) time */
int quadratic(long int n) {
    int outerLoop = 0;
    int innerLoop = 0;
    for (int i = 0; i < n; i++) {
        innerLoop++;
        for (int j = 0; j < n; j++) {
            outerLoop++;
        }
    }
    return 0;
}

/** performs an operation on an integer in cubic time:
 *  @brief This algorithm uses a triply-nested for loop to 
 *  perform n^3 calculations, tabulating the number of 
 *  inner and outer counts, and returning their product.
 *  @param n integer input
 *  @return the result of algorithm in O(N^3) time */
int cubic(long int n) {
    int outerLoop = 0;
    int innerLoop = 0;
    int outerMostLoop = 0;
    for (int i = 0; i < n; i++) {
        innerLoop++;
        for (int j = 0; j < n; j++) {
            outerLoop++;
            for (int k = 0; k < n; k++) {
                outerMostLoop++;
            }
        }
    }
    return 0;
}