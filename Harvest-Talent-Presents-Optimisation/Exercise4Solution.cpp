#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

const int numParticles = 3000;
const int iterations = 100;

struct Particle {
    float x, y, z, r, g, b;
};

void updateParticleInteractions(std::vector<Particle>& particles, float interactionRadius) {
    const int numParticles = particles.size();

    for (int iter = 0; iter < iterations; ++iter) {
        for (int i = 0; i < numParticles; ++i) {
            Particle& currentParticle = particles[i];

            for (int j = 0; j < numParticles; ++j) {
                Particle& otherParticle = particles[j];

                float distance = std::sqrt((currentParticle.x - otherParticle.x) * (currentParticle.x - otherParticle.x) +
                    (currentParticle.y - otherParticle.y) * (currentParticle.y - otherParticle.y) +
                    (currentParticle.z - otherParticle.z) * (currentParticle.z - otherParticle.z));

                if (distance < interactionRadius) {
                    currentParticle.r += otherParticle.g;
                    currentParticle.g += otherParticle.b;
                    currentParticle.b += otherParticle.r;
                }
            }
        }
    }
}

void RunExercise4Solution() {
    // Vector of particles
    std::vector<Particle> particles(numParticles);

    // Initialize particle data with random positions
    for (int i = 0; i < numParticles; ++i) {
        particles[i].x = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        particles[i].y = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        particles[i].z = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        particles[i].r = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        particles[i].g = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        particles[i].b = static_cast<float>(rand()) / RAND_MAX * 100.0f;
    }

    // Measure time for updating particle interactions with spatial locality
    auto start = std::chrono::high_resolution_clock::now();
    updateParticleInteractions(particles, 5.0f);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time for updating particle interactions with spatial locality: " << duration.count() << " seconds" << std::endl;
}