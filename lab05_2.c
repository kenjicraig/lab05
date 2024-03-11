#include <stdio.h>

void printCombinations(int score, int td, int fg, int safety) { // function to print the combinations of scoring plays
    printf("%d TD + %d FG + %d Safety\n", td, fg, safety);
}

void calculateCombinations(int score, int td, int fg, int safety) { // function to calculate the combinations of scoring plays
    if (score == 0) {
        printCombinations(score, td, fg, safety); // print the combinations of scoring plays
        return;
    }

    if (score >= 6) { // if the score is greater than or equal to 6, we can score a touchdown
        calculateCombinations(score - 6, td + 1, fg, safety);
    }

    if (score >= 3) { // if the score is greater than or equal to 3, we can score a field goal
        calculateCombinations(score - 3, td, fg + 1, safety);
    }

    if (score >= 2) { // if the score is greater than or equal to 2, we can score a safety
        calculateCombinations(score - 2, td, fg, safety + 1);
    }
}

int main() { // main function
    int score;

    while (1) { // loop to input the NFL score
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) { // if the score is less than or equal to 1, we break the loop
            break;
        }

        printf("Possible combinations of scoring plays:\n"); // print the title of the output
        calculateCombinations(score, 0, 0, 0); // calculate the combinations of scoring plays
    }

    return 0;
}
