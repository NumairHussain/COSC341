#include <iostream>
#include <string>
#include <iomanip>

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

// Process student scores and find min, max, and average
void scores()
{
    // Initialize variables
    std::string name_buffer;
    std::string worst_student, best_student;
    int best_grade = 0, worst_grade = 100;
    int total_students = 0;
    int grade_input;
    double sum_grades = 0;
    
    while (true)
    {
        // Prompt user for input
        std::cout << "Enter student name and score, or -1 to quit: ";
        std::cin >> name_buffer;

        // Check for quit condition
        if (name_buffer == "-1" || name_buffer == "-1")
        {
            break;
        }
        std::cin >> grade_input;

        // Update min, max, and sum
        if (grade_input < worst_grade)
        {
            worst_student = name_buffer;
            worst_grade = grade_input;
        }
        if (grade_input > best_grade)
        {
            best_student = name_buffer;
            best_grade = grade_input;
        }
        sum_grades += grade_input;
        total_students++;
    }
    
    // Display results
    if (total_students > 0)
    {
        double average_score = sum_grades / total_students;
        std::cout << "Avg score: " << std::fixed << std::setprecision(2) << average_score << std::endl;
        std::cout << "Max score: " << best_grade << std::endl;
        std::cout << "Min score: " << worst_grade << std::endl;
    }
    else
    {
        std::cout << "No scores entered" << std::endl;
    }
}

void file_sort(char *infile, char *outfile)
{

}


int main()
{
    std::cout << compute_pi(3) << "\n"
    scores();
    return 0;
}