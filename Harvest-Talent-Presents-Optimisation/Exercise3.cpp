#include <iostream>
#include <immintrin.h>
#include <chrono>

// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
// Use SIMD to accelerate the loop below
// Run your code in Debug then in Release, what do you see?
void vectorAddition(float* a, float* b, float* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = a[i] + b[i];
    }
}

void RunExercise3() {
    const int size = 100000000;

    float* arrayA = new float[size];
    float* arrayB = new float[size];
    float* result = new float[size];

    // Initialize input arrays with some values
    for (int i = 0; i < size; i++) {
        arrayA[i] = static_cast<float>(i);
        arrayB[i] = static_cast<float>(size - i);
    }

    // Measure regular vector addition time
    auto start = std::chrono::high_resolution_clock::now();
    vectorAddition(arrayA, arrayB, result, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Regular Vector Addition Time: " << duration.count() << " seconds" << std::endl;

    // Measure AVX2 vector addition time
    start = std::chrono::high_resolution_clock::now();
    //avx2VectorAddition(arrayA, arrayB, avx2Result, size);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "AVX2 Vector Addition Time: " << duration.count() << " seconds" << std::endl;

    // Clean up
    delete[] arrayA;
    delete[] arrayB;
    delete[] result;
}