// Multi-function C program with mathematical and file processing capabilities

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

// Compute pi
double compute_pi(int n)
{
    int sign = 1;
    double pi = 0.0;

    for (int i = 0; i < n; i++)
    {
        pi += sign * (1.0/(2 * i + 1));
        sign = -sign;
    }

    return 4 * pi;
}

// Compute square root using Newton's method
double compute_sqrt(double x)
{
    double next = 1.0;
    double last = 1.0;

    for (int i = 0; i < 10; i++)
    {
        last = next;    
        next = 0.5 * (last + x / last);
    }
    return next;
}

// Check if a number is prime
int is_prime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if ((n % i) == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Display all prime numbers up to n
void display_primes(int n)
{
    for (int i = 2; i < n; i++)
    {
        int prime_checker = is_prime(i);
        if (prime_checker == 1)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Generate user ID and password from name and year
void id_password(char first[], char last[], int year)
{
    // Create user ID
    char userid[50] = "";
    char first_letter[2] = {first[0], '\0'};
    strcat(userid, first_letter);
    strcat(userid, last);
    printf("Your user id: %s\n", userid);

    // Create password
    char first_three_letters[4] = {first[0], first[1], first[2], '\0'};
    char year_as_string[5] = "";
    sprintf(year_as_string, "%04d", year);
    char password[6] = {first[0], first[1], first[2], year_as_string[2], year_as_string[3], '\0'};
    printf("Your Password is  %s\n", password);
}

// Process student scores and find min, max, and average
void process_scores()
{
    // Initialize variables
    char name_buffer[50];
    char worst_student[50], best_student[50];
    int best_grade = 0, worst_grade = 100;
    int total_students = 0;
    int grade_input;
    double sum_grades = 0;
    
    while (1)
    {
        // Prompt user for input
        printf("Enter student name and score, or q to quit: ");
        scanf("%s", name_buffer);

        // Check for quit condition
        if (tolower(name_buffer[0]) == 'q')
        {
            break;
        }
        scanf("%d", &grade_input);

        // Update min, max, and sum
        if (grade_input < worst_grade)
        {
            strcpy(worst_student, name_buffer);
            worst_grade = grade_input;
        }
        if (grade_input > best_grade)
        {
            strcpy(best_student, name_buffer);
            best_grade = grade_input;
        }
        sum_grades += grade_input;
        total_students++;
    }
    
    // Display results
    if (total_students > 0)
    {
        double average_score = sum_grades / total_students;
        printf("Avg score: %.02f\n", average_score);
        printf("Best grade: %d\n", best_grade);
        printf("Worst grade: %d\n", worst_grade);
        printf("Best student: %s\n", best_student);
        printf("Worst student: %s\n", worst_student);
    }
    else
    {
        printf("No scores entered\n");
    }
}

// Calculate tax based on income, marital status, and state residence
double compute_tax(int income, char *status, char state)
{
    if (income < 0)
    {
        return -1;
    }

    // Convert status to lowercase
    for (int i = 0; i < strlen(status); i++) {
        status[i] = tolower(status[i]);
    }

    // Validate status (should be "single" or "married")
    if (strcmp(status, "single") != 0 && strcmp(status, "married") != 0)
    {
        return -1;
    }
    
    // Validate state (should be 'i' or 'o')
    if (tolower(state) != 'i' && tolower(state) != 'o')
    {
        return -1;
    }

    double tax_rate = 0.0;

    if (tolower(state) == 'i')  // In-state
    {
        if (strcmp(status, "single") == 0)  // Single
        {
            if (income < 40000)
                tax_rate = 0.30;
            else
                tax_rate = 0.35;
        }
        else  // Married
        {
            if (income < 60000)
                tax_rate = 0.20;
            else
                tax_rate = 0.25;
        }
    }
    else  // Out-of-state (3% less)
    {
        if (strcmp(status, "single") == 0)  // Single
        {
            if (income < 40000)
                tax_rate = 0.27;  // 30% - 3%
            else
                tax_rate = 0.32;  // 35% - 3%
        }
        else  // Married
        {
            if (income < 60000)
                tax_rate = 0.17;  // 20% - 3%
            else
                tax_rate = 0.22;  // 25% - 3%
        }
    }

    return income * tax_rate;
}

// Solve quadratic equation using quadratic formula
int quadratic(double a, double b, double c, double *solution1, double *solution2)
{
    if (((b * b) - (4 * a * c)) < 0 )
    {
        // No real solutions (negative discriminant)
        *solution1 = -1;
        *solution2 = -1;
        return 0;
    }
    // Calculate both solutions using quadratic formula
    *solution1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    *solution2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
    return 1;
}

// Count characters, blank spaces, and lines in a file
void file_count(char *file, int *characters, int *blanks, int *lines)
{
    FILE *fp = fopen(file, "r");

    int ch;
    int last_char = '\n';
    *characters = 0;
    *blanks = 0;
    *lines = 0;

    // Read file character by character
    while ((ch = fgetc(fp)) != EOF) {
        (*characters)++;

        if (ch == ' ')
            (*blanks)++;

        if (ch == '\n')
            (*lines)++;

        last_char = ch;
    }

    // Count last line if file doesn't end with newline
    if ((*characters) > 0 && last_char != '\n')
    {
        (*lines)++;
    }
    
    fclose(fp);
}

// Read student data from file, sort by ID, and write to output file
void file_sort(char *infile, char *outfile)
{
    FILE *fp = fopen(infile, "r");
    int num_students = 0;
    fscanf(fp, "%d", &num_students);

    fgetc(fp);  // Consume newline after number

    // Allocate memory for student data arrays
    int *ids = (int *)malloc(num_students * sizeof(int));
    char *grades = (char *)malloc(num_students * sizeof(char));
    double *gpas = (double *)malloc(num_students * sizeof(double));

    // Read student data from file
    for (int i = 0; i < num_students; i++)
    {
        fscanf(fp, "%d %s %lf", &ids[i], &grades[i], &gpas[i]);
    }

    fclose(fp);

    // Sort students by ID using selection sort
    for (int i = 0; i < num_students - 1; i++) 
    {
        for (int j = i + 1; j < num_students; j++) 
        {
            if (ids[j] < ids[i]) 
            {
                // Swap ids
                int tempId = ids[i];
                ids[i] = ids[j];
                ids[j] = tempId;

                // Swap grades
                char tempGrade = grades[i];
                grades[i] = grades[j];
                grades[j] = tempGrade;

                // Swap gpas
                double tempGpa = gpas[i];
                gpas[i] = gpas[j];
                gpas[j] = tempGpa;
            }
        }
    }

    // Write sorted data to output file
    FILE *fout = fopen(outfile, "w");
    fprintf(fout, "%d \n", num_students);
    for (int i = 0; i < num_students; i++)
    {
        fprintf(fout, "%d %c %.2f\n", ids[i], grades[i], gpas[i]);
    }
    fclose(fout);

    // Free allocated memory
    free(ids);
    free(grades);
    free(gpas);
    
}

// Student structure definition
typedef struct {
    char name[50];   // Student name
    int id;          // Student ID
    int age;         // Student age
    double gpa;      // Student GPA
} Student;

// Read student file, calculate statistics, and display sorted results
void file_student(char *infile)
{
    // Initialize file pointer and read number of students
    FILE *fp = fopen(infile, "r");
    int num_students;
    fscanf(fp, "%d", &num_students);

    // Allocate memory for student array
    Student *students = (Student *)malloc(num_students * sizeof(Student));

    // Read student data from file
    for (int i = 0; i < num_students; i++)
    {
        fscanf(fp, "%s %d %d %lf", students[i].name, &students[i].id, &students[i].age, &students[i].gpa);
    }

    fclose(fp);

    // Calculate average GPA
    double total_gpa = 0;
    for (int i = 0; i < num_students; i++)
    {
        total_gpa += students[i].gpa;
    }
    double avgGpa = total_gpa / num_students;
    printf("Average GPA: %.2f\n", avgGpa);
    
    // Display students with good GPAs (3.0 or higher)
    printf("\nStudents with GPA at least 3.0:\n");
    for (int i = 0; i < num_students; i++) 
    {
        if (students[i].gpa >= 3.0) 
        {
            printf("%s\n", students[i].name);
        }
    }

    // Sort students by ID using bubble sort
    for (int i = 0; i < num_students - 1; i++) 
    {
        for (int j = 0; j < num_students - i - 1; j++) 
        {
            if (students[j].id > students[j + 1].id) 
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Display sorted student list
    printf("\nStudents sorted by ID:\n");
    for (int i = 0; i < num_students; i++) 
    {
        printf("%s %d %d %.2f\n",
            students[i].name,
            students[i].id,
            students[i].age,
            students[i].gpa);
    }

    // Free allocated memory
    free(students);
    
}

// Main function - displays menu and handles user choices
int main()
{

    // typedef struct {
    //     int year;
    //     char make[20];
    // } car;

    // car my_car;
    // my_car.year = 2022;
    // strcpy(my_car.make, "Honda");
    // car *my_car_ptr = &my_car;
    // my_car_ptr->year = 2023;

    // Main program loop - continues until user chooses to quit
    while(1)
    {
        int option;
        
        // Display menu options
        printf("\nMenu Options:\n");
        printf("1. Compute Pi\n");
        printf("2. Compute Square Root\n");
        printf("3. Display Primes\n");
        printf("4. ID and Password\n");
        printf("5. Process Grades\n");
        printf("6. Compute Tax\n");
        printf("7. Solve Quadratic\n");
        printf("8. Count File\n");
        printf("9. Sort File\n");
        printf("10. Student File\n");
        printf("11. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        // Process user's menu choice
        switch (option)
        {
            case 1:  // Pi calculation
            {
                // Getting User Input
                int n_terms;
                printf("Enter a number to compute pi using that many terms: ");
                scanf("%d", &n_terms);

                // Calling function and displaying results
                printf("Pi value using %d terms: %f\n", n_terms, compute_pi(n_terms));
                break;
            }
            case 2:  // Square root calculation
            {
                // Getting User Input
                double x;
                printf("Enter a number to compute its square root: ");
                scanf("%lf", &x);

                // Calling function and displaying results
                printf("Square root of %f is %f\n", x, compute_sqrt(x));
                break;
            }
            case 3:  // Display prime numbers up to a given limit
            {
                // Getting User Input
                int n;
                printf("Display primes up to: ");
                scanf("%d", &n);

                // Calling function
                display_primes(n);
                break;
            }
            case 4:  // Generate user ID and password from personal info
            {
                // Getting User Input
                char first[50], last[50];
                int year;
                printf("Enter first name: ");
                scanf("%s", first);
                printf("Enter last name: ");
                scanf("%s", last);
                printf("Enter year: ");
                scanf("%d", &year);

                // Calling function
                id_password(first, last, year);
                break;
            }
            case 5:  // Process and analyze student scores
            {
                // Calling function
                process_scores();
                break;
            }
            case 6:  // Calculate tax based on income and status
            {
                //Getting User Input
                int income;
                char status[20];
                char state;
                printf("Enter income: ");
                scanf("%d", &income);
                printf("Enter whether (married) or (single): ");
                scanf("%s", status);
                printf("Enter (i)nside or (o)utside of state: ");
                scanf(" %c", &state);

                //Calling function and displaying results
                printf("Your tax amount: %.2f\n", compute_tax(income, status, state));
                break;
            }
            case 7:  // Solve quadratic equation
            {
                //Getting User Input
                int a, b, c;
                double solution1, solution2;
                printf("Enter a: ");
                scanf("%d", &a);
                printf("Enter b: ");
                scanf("%d", &b);
                printf("Enter c: ");
                scanf("%d", &c);

                //Calling function
                quadratic(a, b, c, &solution1, &solution2);

                //Displaying results
                printf("The answer for the quadratic forumla is: %f and %f\n", solution1, solution2);
                break;
            }
            case 8:  // Count characters, blanks, and lines in a file
            {
                //Getting User Input
                int characters, blanks, lines;
                char file_name[100];
                printf("Enter the filename: ");
                scanf("%s", file_name);

                //Calling function
                file_count(file_name, &characters, &blanks, &lines);

                //Displaying results
                printf("Characters: %d\n", characters);
                printf("Blanks: %d\n", blanks);
                printf("Lines: %d\n", lines);
                break;
            }
            case 9:  // Sort student data from input file to output file
            {
                char infile_name[100];
                char outfile_name[100];
                printf("Enter the infile: ");
                scanf("%s", infile_name);
                printf("Enter the outfile: ");
                scanf("%s", outfile_name);

                file_sort(infile_name, outfile_name);
                break;
            }
            case 10:  // Process student file and display statistics
            {
                //Getting user input
                char infile_name[100];
                printf("Enter the infile: ");
                scanf("%s", infile_name);

                //Calling function
                file_student(infile_name);
                break;
            }
            case 11:  // Exit the program
            {
                printf("Quitting program.\n");
                return 0;
            }
            default:  // Handle invalid menu choices
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
