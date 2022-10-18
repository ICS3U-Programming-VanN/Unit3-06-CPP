// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: October 17, 2022
// This program asks the user to try and guess the randomly generated number
// between 0 - 9 and displays a message depending on if they get it right or not
// This program contains exception handling

#include <iostream>
#include <random>

int main() {
    // Generates a random number from 0-9
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);

    // Declared constant to hold the random number
    const int CORRECT_ANSWER = idist(rgen);

    // Initialize Variable
    int userGuessInt;
    std::string userGuess;

    // Asks user to guess number
    std::cout << "Guess the number (0-9): ";
    std::cin >> userGuess;

    // Tries to convert/assign user input to an integer (different variable)
    try {
        // Assigns userGuessInt as integer version of userGuess
        userGuessInt = std::stoi(userGuess);

        // IF the user guesses the number correctly
        if (userGuessInt == CORRECT_ANSWER) {
            std::cout << "You guessed the number correctly!" << std::endl;

        // IF the user does not guess the number correctly
        } else {
            std::cout << "You guessed the number wrong! The number was: "
            << CORRECT_ANSWER << std::endl;
        }

    // Handles any exceptions raised (user did not enter an integer)
    } catch (std::invalid_argument) {
        std::cout << userGuess << " is not an integer." << std::endl;
    }
}
