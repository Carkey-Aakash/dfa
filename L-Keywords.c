#include <stdio.h>
// Define states using an enum (enumeration)
enum States {
    q0 = 0,
    q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,qReject
};

// Global variable for the current state
enum States currentState;

// Function to initialize the DFA
void initializeDFA() {
    // Set the initial state
    currentState = q0;
}

// Function to simulate the DFA and check if the input is accepted
int simulateDFA(const char *input) {
    int i = 0;

    // Iterate through the input string
    while (input[i] != '\0') { 
        char symbol = input[i];

        // Perform state transitions based on the symbol
        switch (currentState) {
            case q0:
                if (symbol == 'i') {
                    currentState = q1;
                } else if (symbol == 'o') {
                    currentState = q5;
                } 
                else if (symbol == 'f') {
                    currentState = q3;
                } 
                else if (symbol == 'd') {
                    currentState = q7;
                } 
                else if (symbol == 'a') {
                    currentState = q9;
                } 
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
            case q1:
                if (symbol == 'f') {
                   currentState = q2;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
            case q2:
                if (input[i] != '\0') {
                    currentState = qReject;
                }
                break;
               case q3:
                 if (symbol == 'o') {
                   currentState = q4;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
             case q4:
                 if (symbol == 'r') {
                   currentState = q6;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
            case q5:
                 if (symbol == 'r') {
                   currentState = q6;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
             case q6:
                if (input[i] != '\0') {
                    currentState = qReject;
                }
                break;
        
             case q7:
                 if (symbol == 'o') {
                   currentState = q8;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
             case q8:
                if (input[i] != '\0') {
                    currentState = qReject;
                }
                break;
             case q9:
                 if (symbol == 'n') {
                   currentState = q10;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
             case q10:
                 if (symbol == 'd') {
                   currentState = q11;
                }
                else {
                    // Invalid symbol
                    currentState = qReject;
                }
                break;
             case q11:
                if (input[i] != '\0') {
                    currentState = qReject;
                }
                break;
           
            case qReject:
                // Stay in the reject state for any symbol
                break;
        }
        i++; // Move to the next symbol
    }

    // Check if the final state is the accepting state
    return (currentState == q2 ||currentState == q6 ||currentState == q8 ||currentState == q11);
}
int main() {
    initializeDFA();

    // Get input from the user
    char input[20];
    printf("Enter a keyword to check if it is recognized by the 'L' language: ");
    scanf("%s", input);

    // Simulate DFA and check if the input is a keyword or not
    if (simulateDFA(input)) {
        printf("The string \"%s\" is a Keyword.\n", input);
    } else {
        printf("The string \"%s\" is not a Keyword.\n", input);
    }
    return 0;
}
