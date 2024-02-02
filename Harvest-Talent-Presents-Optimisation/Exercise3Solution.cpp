//// // Uncomment to run, comment out original
////
//#include <iostream>
//#include <immintrin.h>
//#include <chrono>
//
//// https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
//// Use SIMD to accelerate the loop below
//// Run your code in Debug then in Release, what do you see?
//void vectorAddition(float* a, float* b, float* result, int size) {
//    for (int i = 0; i < size; i++) {
//        result[i] = a[i] + b[i];
//    }
//}
//
//void avx2VectorAddition(float* a, float* b, float* result, int size) {
//    if (size % 8 != 0) {
//        std::cerr << "Array size must be divisible by 8 for AVX2 optimization." << std::endl;
//        return;
//    }
//
//    for (int i = 0; i < size; i += 8) {
//        __m256 vectorA = _mm256_loadu_ps(&a[i]);
//        __m256 vectorB = _mm256_loadu_ps(&b[i]);
//        __m256 resultVector = _mm256_add_ps(vectorA, vectorB);
//        _mm256_storeu_ps(&result[i], resultVector);
//    }
//}
//
//void avx2VectorAdditionUnrolled(float* a, float* b, float* result, int size) {
//    if (size % 8 != 0) {
//        std::cerr << "Array size must be divisible by 8 for AVX2 optimization." << std::endl;
//        return;
//    }
//
//    for (int i = 0; i < size; i += 32) {
//        // Load 512 bits of data from aligned memory into AVX2 registers
//        __m256 vectorA1 = _mm256_load_ps(&a[i]);
//        __m256 vectorB1 = _mm256_load_ps(&b[i]);
//        __m256 vectorA2 = _mm256_load_ps(&a[i + 8]);
//        __m256 vectorB2 = _mm256_load_ps(&b[i + 8]);
//        __m256 vectorA3 = _mm256_load_ps(&a[i + 16]);
//        __m256 vectorB3 = _mm256_load_ps(&b[i + 16]);
//        __m256 vectorA4 = _mm256_load_ps(&a[i + 24]);
//        __m256 vectorB4 = _mm256_load_ps(&b[i + 24]);
//
//        // Perform vector addition
//        __m256 resultVector1 = _mm256_add_ps(vectorA1, vectorB1);
//        __m256 resultVector2 = _mm256_add_ps(vectorA2, vectorB2);
//        __m256 resultVector3 = _mm256_add_ps(vectorA3, vectorB3);
//        __m256 resultVector4 = _mm256_add_ps(vectorA4, vectorB4);
//
//        // Store the result back to aligned memory
//        _mm256_store_ps(&result[i], resultVector1);
//        _mm256_store_ps(&result[i + 8], resultVector2);
//    }
//}
//
//void RunExercise3Solution() {
//    const int size = 100000000;
//
//    alignas(32) float* arrayA = new float[size];
//    alignas(32) float* arrayB = new float[size];
//    alignas(32) float* result = new float[size];
//    alignas(32) float* avx2Result = new float[size];
//    alignas(32) float* avx2ResultUnrolled = new float[size];
//
//    // Initialize input arrays with some values
//    for (int i = 0; i < size; i++) {
//        arrayA[i] = static_cast<float>(i);
//        arrayB[i] = static_cast<float>(size - i);
//    }
//
//    // Measure regular vector addition time
//    auto start = std::chrono::high_resolution_clock::now();
//    vectorAddition(arrayA, arrayB, result, size);
//    auto end = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> duration = end - start;
//    std::cout << "Regular Vector Addition Time: " << duration.count() << " seconds" << std::endl;
//
//    // Measure AVX2 vector addition time
//    start = std::chrono::high_resolution_clock::now();
//    avx2VectorAddition(arrayA, arrayB, avx2Result, size);
//    end = std::chrono::high_resolution_clock::now();
//    duration = end - start;
//    std::cout << "AVX2 Vector Addition Time: " << duration.count() << " seconds" << std::endl;
//
//    // Measure AVX2 vector addition time unrolled
//    start = std::chrono::high_resolution_clock::now();
//    avx2VectorAdditionUnrolled(arrayA, arrayB, avx2ResultUnrolled, size);
//    end = std::chrono::high_resolution_clock::now();
//    duration = end - start;
//    std::cout << "AVX2 unrolled Vector Addition Time: " << duration.count() << " seconds" << std::endl;
//
//    // Clean up
//    delete[] arrayA;
//    delete[] arrayB;
//    delete[] result;
//    delete[] avx2Result;
//    delete[] avx2ResultUnrolled;
//}