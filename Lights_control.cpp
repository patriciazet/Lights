#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

// Function to simulate turning on/off lights
void displayLights(const vector<string>& lights) {
    for (const string& row : lights) {
        std::cout << row << std::endl;
    }
    std::cout << string(20, '-') << std::endl;
}

// Function to create different light patterns
vector<string> generatePattern(int patternNumber, int size) {
    vector<string> lights(size, string(size, ' '));

    switch (patternNumber) {
        case 1: // Diagonal lights
            for (int i = 0; i < size; ++i) {
                lights[i][i] = '*';
            }
            break;
        case 2: // Border lights
            for (int i = 0; i < size; ++i) {
                lights[0][i] = lights[size - 1][i] = '*';
                lights[i][0] = lights[i][size - 1] = '*';
            }
            break;
        case 3: // Checkerboard pattern
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if ((i + j) % 2 == 0) {
                        lights[i][j] = '*';
                    }
                }
            }
            break;
        default:
            std::cout << "Invalid pattern number!\n";
    }

    return lights;
}

int main() {
    int size = 8; // Size of the light grid
    bool running = true;

    std::cout << "Welcome to the Christmas Lights Controller!\n";
    std::cout << "Choose an option:\n";

    while (running) {
        std::cout << "1. Turn lights ON\n";
        std::cout << "2. Display pattern 1 (Diagonal)\n";
        std::cout << "3. Display pattern 2 (Border)\n";
        std::cout << "4. Display pattern 3 (Checkerboard)\n";
        std::cout << "5. Turn lights OFF\n";
        std::cout << "6. Exit\n";
        
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            vector<string> lights(size, string(size, '*'));
            displayLights(lights);
        } else if (choice >= 2 && choice <= 4) {
            vector<string> lights = generatePattern(choice - 1, size);
            displayLights(lights);
        } else if (choice == 5) {
            vector<string> lights(size, string(size, ' '));
            displayLights(lights);
        } else if (choice == 6) {
            running = false;
            std::cout << "Goodbye!\n";
        } else {
            std::cout << "Invalid choice, please try again.\n";
        }

        // Pause before clearing screen for next action
        this_thread::sleep_for(chrono::seconds(1));
        system("clear"); // Use "cls" on Windows
    }

    return 0;
}
