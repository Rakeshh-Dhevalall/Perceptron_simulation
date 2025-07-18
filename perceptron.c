#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define sigmoid activation function
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// Define sigmoid derivative
double sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

int main() {
    // Initialize input, weights, and bias
    double input[] = {0.5, 0.8}; // Example input features
    double weights[] = {0.2, -0.4}; // Initial weights
    double bias = 0.3; // Initial bias
    
    // Learning rate
    double learning_rate = 0.01;

    // Forward pass
    double weighted_sum = (input[0] * weights[0]) + (input[1] * weights[1]) + bias;
    double output = sigmoid(weighted_sum);

    // Assume target output is 1
    double target = 1.0;
    
    // Calculate error
    double error = target - output;

    // Backpropagation: Adjust weights using gradient descent
    double gradient = error * sigmoid_derivative(output);
    weights[0] += learning_rate * gradient * input[0];
    weights[1] += learning_rate * gradient * input[1];
    bias += learning_rate * gradient;

    // Print updated values
    printf("Updated weights: %f, %f\n", weights[0], weights[1]);
    printf("Updated bias: %f\n", bias);
    printf("Final output: %f\n", output);
    return 0;
}


