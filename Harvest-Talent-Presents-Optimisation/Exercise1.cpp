#include <iostream>
#include <chrono>
#include <cmath>
#include "xorshift.h"

using namespace std;
// 1a; use chrono::high_resolution clock to time your application and cout to console in seconds
// https://cplusplus.com/reference/chrono/
// 
// 1b; blink and you miss it; cast the duration to nanoseconds
// Run a single iteration, restart your application, how predictable is the duration?
// 
// 1c; Run the statement for millions of iterations, make sure the total execution time > 1 second
//
// 1d; Explore, what is the cost of the math expression? What is the cost of the branching?
//
// 1e; Optimise! Finda way to remove the branching without changing the result
// Run your changes in Debug mode and Release mode, how does it change?
//
// 1f; Extra; given we are iterating a ton now, could we use loop unrolling?
void RunExercise1() {
    const int iterations = 500000000;  // Number of iterations for the benchmark
    float result = 0.0f;

    //Original version
    float number = 0;
    //auto t1 = chrono::high_resolution_clock::now();
    result = 0.0f;
    for (int i = 0; i < iterations; i++) {
        uint32_t x = xorshift_0_64();
        if (x > 32) {
            result += result * result;
        }
        else {
            result -= result * 0.5;
        }
    }
    
    cout << "Time using if statement: " << "duration.count() - todo" << " seconds" << endl;
}