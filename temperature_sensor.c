#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void checkThreshold(float tempC) {
    if (tempC > 45.0)
        printf("⚠️  Alert: High Temperature!\n");
    else if (tempC < 0.0)
        printf("⚠️  Alert: Low Temperature!\n");
}

int main() {
    int choice, inputType;
    float tempInput;

    srand(time(NULL)); // Seed for random number generation

    while (1) {
        printf("\n--- Temperature Sensor Simulation ---\n");
        printf("1. Enter temperature manually\n");
        printf("2. Generate random temperature\n");
        printf("3. Exit\n");
        printf("Select input type: ");
        scanf("%d", &inputType);

        if (inputType == 3) {
            printf("Exiting program.\n");
            break;
        }

        if (inputType == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &tempInput);
        } else if (inputType == 2) {
            tempInput = (rand() % 8001 - 3000) / 100.0; // Range: -30.00 to 50.00
            printf("Randomly Generated Temperature: %.2f °C\n", tempInput);
        } else {
            printf("Invalid input choice.\n");
            continue;
        }

        printf("\nChoose Output Format:\n");
        printf("1. Celsius\n2. Fahrenheit\n3. Both\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Temperature: %.2f °C\n", tempInput);
                break;
            case 2:
                printf("Temperature: %.2f °F\n", celsiusToFahrenheit(tempInput));
                break;
            case 3:
                printf("Temperature: %.2f °C | %.2f °F\n", tempInput, celsiusToFahrenheit(tempInput));
                break;
            default:
                printf("Invalid format choice.\n");
        }

        checkThreshold(tempInput);
    }

    return 0;
}
