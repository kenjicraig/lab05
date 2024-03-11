#include <stdio.h>

#define MONTHS 12

// we can use a function to read the sales data from the input file
void read_sales(double sales[]); // function prototypes
void generate_sales_report(double sales[]); 
void generate_summary_report(double sales[]);
void generate_moving_average_report(double sales[]);
void generate_sorted_sales_report(double sales[]);

int main() { // main function
    double sales[MONTHS]; // declare an array of 12 elements to store the sales data

    read_sales(sales); // call the function to read the sales data from the input file
    generate_sales_report(sales); // call the function to generate the sales report
    generate_summary_report(sales); // call the function to generate the sales summary report
    generate_moving_average_report(sales); // call the function to generate the six-month moving average report
    generate_sorted_sales_report(sales); // call the function to generate the sales report sorted from highest to lowest
 
    return 0;
}

// Read the sales data from the input file
void read_sales(double sales[]) {
    FILE *file = fopen("monthly_sales.txt", "r"); // open the input file for reading
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < MONTHS; i++) { // read the sales data from the input file
        fscanf(file, "%lf", &sales[i]); 
    }

    fclose(file);
}

// generate sales report
void generate_sales_report(double sales[]) { // function to generate the sales report
    const char *months[] = { // array of strings to store the names of the months
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("Monthly sales report for 2022:\n"); // print the title of the report
    printf("Month    Sales\n"); //  print the column headers
    for (int i = 0; i < MONTHS; i++) { // print the sales data for each month
        printf("%s $%.2f\n", months[i], sales[i]);
    }
}

// Generate the sales summary report
void generate_summary_report(double sales[]) { 
    const char *months[] = { // array of strings to store the names of the months
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    double min = sales[0], max = sales[0], sum = 0; // declare variables to store the minimum, maximum, and sum of the sales
    for (int i = 0; i < MONTHS; i++) { // calculate the minimum, maximum, and sum of the sales
        if (sales[i] < min) { // check if the current sales value is less than the minimum
            min = sales[i]; // update the minimum sales value
        }
        if (sales[i] > max) { // check if the current sales value is greater than the maximum
            max = sales[i]; // update the maximum sales value
        }
        sum += sales[i]; // add the current sales value to the sum
    }

    // print the sales summary report
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[11]);
    printf("Average sales: $%.2f\n", sum / MONTHS);
}

// Generate six-month moving average report
void generate_moving_average_report(double sales[]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) { // calculate the moving average for each six-month period
        double sum = 0; // declare a variable to store the sum of the sales for the six-month period
        for (int j = i; j < i + 6; j++) { // calculate the sum of the sales for the six-month period
            sum += sales[j]; // add the current sales value to the sum
        }
        printf("%s - %s $%.2f\n", months[i], months[i + 5], sum / 6); // print the moving average for the six-month period
    }
}

// Generate the sales report sorted from highest to lowest
void generate_sorted_sales_report(double sales[]) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month    Sales\n");
    double temp; // declare a temporary variable to store the sales value during sorting
    const char *temp_month; // declare a temporary variable to store the month name during sorting
    for (int i = 0; i < MONTHS; i++) { // sort the sales data from highest to lowest
        for (int j = i + 1; j < MONTHS; j++) { // compare each pair of sales values
            if (sales[i] < sales[j]) { // check if the current sales value is less than the next sales value
                temp = sales[i]; // swap the sales values
                sales[i] = sales[j]; 
                sales[j] = temp; 

                temp_month = months[i]; // swap the month names
                months[i] = months[j]; 
                months[j] = temp_month;
            }
        }
        printf("%s $%.2f\n", months[i], sales[i]); // print the sorted sales data
    }
}
