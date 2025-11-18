#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

//To Run, do g++ program.c -o program

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

// Sort student data from input file to output file
void file_sort(char *infile, char *outfile)
{
    // Read student data from input file
    std::ifstream fin(infile);
    int num_students = 0;
    fin >> num_students;

    // Arrays to hold student data
    int student_ids[num_students];
    char student_grades[num_students];
    double student_gpas[num_students];

    // Read student data from file
    for (int i = 0; i < num_students; i++)
    {
        fin >> student_ids[i] >> student_grades[i] >> student_gpas[i];
        std::cout << student_ids[i] << " " << student_grades[i] << " " << student_gpas[i] << std::endl;
    }

    fin.close();

    // Sort students by ID using bubble sort
    for (int i = 0; i < num_students; i++)
    {
        for (int j = 0; j < num_students - i - 1; j++)
        {
            if (student_ids[j] > student_ids[j + 1])
            {
                // Swap student data
                int temp_id = student_ids[j];
                student_ids[j] = student_ids[j + 1];
                student_ids[j + 1] = temp_id;

                // Swap grades
                char temp_grade = student_grades[j];
                student_grades[j] = student_grades[j + 1];
                student_grades[j + 1] = temp_grade;

                // Swap gpas
                double temp_gpa = student_gpas[j];
                student_gpas[j] = student_gpas[j + 1];
                student_gpas[j + 1] = temp_gpa;
            }
        }
    }

    // Write sorted data to output file
    std::ofstream fout(outfile);
    fout << num_students << std::endl;
    for (int i = 0; i < num_students; i++)
    {
        fout << student_ids[i] << " " << student_grades[i] << " "<< std::fixed << std::setprecision(2) << student_gpas[i] << std::endl;
    }
    fout.close();
}


int main()
{
    std::string infile = "case3in.txt";
    std::string outfile = "case3out.txt";
    file_sort(&infile[0], &outfile[0]);
    return 0;
}