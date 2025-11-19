#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

// Compute an approximation of pi
double compute_pi(int n)
{
    // Initialize variables
    int sign = 1;
    double pi = 0.0;

    // Calculate pi
    for (int i = 0; i < n; i++)
    {
        pi += sign * (1.0/(2 * i + 1));
        sign = -sign;
    }

    // Return the pi * 4
    return 4 * pi;
}

// Process student scores and find min, max, and average
void scores()
{
    // Initialize variables
    int best_grade = 0, worst_grade = 100;
    int total_students = 0;
    int grade_input;
    double sum_grades = 0;
    
    // Loop to get scores from user
    while (true)
    {
        // Prompt user for input
        std::cout << "Enter score or -1 to quit: ";
        std::cin >> grade_input;

        // Check for quit condition
        if (grade_input == -1)
        {
            break;
        }

        // Update min, max, and sum
        if (grade_input < worst_grade)
        {
            worst_grade = grade_input;
        }
        if (grade_input > best_grade)
        {
            best_grade = grade_input;
        }
        sum_grades += grade_input;
        total_students++;
    }
    
    // Display results
    if (total_students > 0)
    {
        double average_score = sum_grades / total_students;
        std::cout << "Avg score: " << std::fixed << std::setprecision(2) << average_score << "\n";
        std::cout << "Max score: " << best_grade << "\n";
        std::cout << "Min score: " << worst_grade << "\n";
    }
    else
    {
        std::cout << "No scores entered" << "\n";
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
    int *student_ids = new int[num_students];
    char *student_grades = new char[num_students];
    double *student_gpas = new double[num_students];

    // Read student data from file
    for (int i = 0; i < num_students; i++)
    {
        fin >> student_ids[i] >> student_grades[i] >> student_gpas[i];
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
    fout << num_students << "\n";
    for (int i = 0; i < num_students; i++)
    {
        fout << student_ids[i] << " " << student_grades[i] << " " << student_gpas[i] << "\n";
    }
    fout.close();

    // Free dynamically allocated memory
    delete[] student_ids;
    delete[] student_grades;
    delete[] student_gpas;
}


class Rectangle
{
    // Private member variables
    private:
        int height;
        int width;

    // Public member functions
    public:
        // Constructors
        Rectangle() {this->height = 0; this->width = 0;};
        Rectangle(int size) {this->height = size; this->width = size;};
        Rectangle(int height, int width) {this->height = height; this->width = width;};

        // Setters and Getters
        void set_height(int height) {this->height = height;};
        void set_width(int width) {this->width = width;};
        int get_height() {return this->height;};
        int get_width() {return this->width;};

        // Calculate area
        int area() {return this->height * this->width;};
        void display(){std::cout << "Height: " << this->height << ", Width: " << this->width << ", Area: " << area() << "\n";};
};

// Class to manage student scores
class Score
{
    // Private member variables
    private:
        int num_students;
        double* scores;

    // Public member functions
    public:
        // Constructors
        Score(int num_students, double scores[]);

        // Destructor
        ~Score();  

        // Calculate average score
        double average();

        // Display scores and average
        void display();
};

// Constructor
Score::Score(int num_students, double scores[])
{
    // Initialize member variables
    this->num_students = num_students;

    // Create new array
    this->scores = new double[num_students];  
    
    // Copy scores from parameter array to class array
    for (int i = 0; i < num_students; i++)
    {
        this->scores[i] = scores[i];
    }
}

// Destructor
Score::~Score()
{
    // Free dynamically allocated memory
    delete[] scores;  
}

// Calculate average score
double Score::average()
{
    // Check for zero students
    if (num_students == 0) return 0.0;
    
    // Calculate sum of scores
    double sum = 0.0;
    for (int i = 0; i < num_students; i++)
    {
        sum += scores[i];
    }

    // Return average
    return sum / num_students;
}

// Display scores and average
void Score::display()
{
    // Display individual scores
    std::cout << "Scores: ";
    for (int i = 0; i < num_students; i++)
    {
        std::cout << scores[i] << " ";
    }
    std::cout << "\n";

    // Display average score
    std::cout << "Average: " << average() << "\n";
}

// Person class
class Person
{
    // Private member variables
    private:
        std::string name;
        int age;

    // Public member functions
    public:
    // Constructors
        Person(std::string name, int age) {this->name = name; this->age = age;};

        // Setters and Getters
        void set_name(std::string name) {this->name = name;};
        void set_age(int age) {this->age = age;};
        int get_age() {return this->age;};
        std::string get_name() {return this->name;};
};

// Student class inheriting from Person
class Student : public Person
{
    // Private member variables
    private:
        int id;
        double gpa;

    // Public member functions
    public:

        // Constructor
        Student(std::string name, int age, int id, double gpa) : Person(name, age)
        {
            this->id = id;
            this->gpa = gpa;
        }

        // Setters and Getters
        int get_id() {return this->id;};
        double get_gpa() {return this->gpa;};
        void set_id(int id) {this->id = id;};
        void set_gpa(double gpa) {this->gpa = gpa;};

        // Display student information
        void show();
};

// Display student information
void Student::show()
{
    std::cout << "Name: " << get_name() << ", Age: " << get_age() << ", ID: " << get_id() << ", GPA: " << get_gpa() << "\n";
}
