#include <iostream>
#include <chrono>
#include <vector>

// Define a simple struct representing a particle with x, y, z coordinates
struct Particle {
    float x;
    float y;
    float z;

    float size;
    float color;

    float directionX;
    float directionY;
    float directionZ;
    float speed;
};

// Improve the cache efficiency of the particle struct
//TODO
struct CacheFriendlyParticle {

};

// Function to process an array of particles in a space-inefficient manner
void processArray(std::vector<Particle>& particles, int iterations) {
    for (int iter = 0; iter < iterations; ++iter) {
        for (std::size_t i = 0; i < particles.size(); ++i) {
            const float particleSpeed = particles[i].speed;
            particles[i].x += particles[i].directionX * particleSpeed;
            particles[i].y += particles[i].directionY * particleSpeed;
            particles[i].z += particles[i].directionZ * particleSpeed;
        }
    }
}

// Function to process an array of particles in a space-inefficient manner
void processArrayFriendly(std::vector<CacheFriendlyParticle>& particles, int iterations) {
    //TODO
}

// Function to process a struct of arrays representing particles
void processStructOfArrays(std::vector<float>& x, std::vector<float>& y, std::vector<float>& z, std::vector<float>& vx, std::vector<float>& vy, std::vector<float>& vz, int iterations) {
    for (int iter = 0; iter < iterations; ++iter) {
        for (std::size_t i = 0; i < x.size(); ++i) {
            x[i] += vx[i];
            y[i] += vy[i];
            z[i] += vz[i];
        }
    }
}

void RunExercise2() {
    const int numParticles = 1000000;
    const int iterations = 1000;

    // Create an array of structs
    std::vector<Particle> particleArray(numParticles, { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
    //std::vector<CacheFriendlyParticle> ...

    // Create struct of arrays

    // Measure time for processing array of structs
    auto startArray = std::chrono::high_resolution_clock::now();
    processArray(particleArray, iterations);
    auto endArray = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationArray = endArray - startArray;
    std::cout << "Time for processing array of structs: " << durationArray.count() << " seconds" << std::endl;

    // Measure time for processing array of structs (cache friendlier)
    auto startArray2 = std::chrono::high_resolution_clock::now();
    //processArrayFriendly(particleArrayFriendly, iterations);
    auto endArray2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationArray2 = endArray2 - startArray2;
    std::cout << "Time for processing array of structs (cache friendlier): " << durationArray2.count() << " seconds" << std::endl;

    // Measure time for processing struct of arrays
    auto startStructOfArrays = std::chrono::high_resolution_clock::now();
    //processStructOfArrays(...)
    auto endStructOfArrays = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationStructOfArrays = endStructOfArrays - startStructOfArrays;
    std::cout << "Time for processing struct of arrays: " << durationStructOfArrays.count() << " seconds" << std::endl;
}
