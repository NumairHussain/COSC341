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


class Rectangle
{
    private:
        int height;
        int width;

    public:
        Rectangle() {this->height = 0; this->width = 0;};
        Rectangle(int size) {this->height = size; this->width = size;};
        Rectangle(int height, int width) {this->height = height; this->width = width;};
};

class Scores
{
    private:
        int num_students;
        double* scores;

    public:
        Scores(int num_students, double scores[]);
        ~Scores();  // Destructor
        double average();
        void display();
};

Scores::Scores(int num_students, double scores[])
{
    this->num_students = num_students;
    this->scores = new double[num_students];  // Create new array
    
    // Copy scores from parameter array to class array
    for (int i = 0; i < num_students; i++)
    {
        this->scores[i] = scores[i];
    }
}

Scores::~Scores()
{
    delete[] scores;  // Delete the dynamically allocated array
}

double Scores::average()
{
    if (num_students == 0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < num_students; i++)
    {
        sum += scores[i];
    }
    return sum / num_students;
}

void Scores::display()
{
    std::cout << "Scores: ";
    for (int i = 0; i < num_students; i++)
    {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Average: " << std::fixed << std::setprecision(2) << average() << std::endl;
}

class Person
{
    private:
        std::string name;
        int age;

    public:
        Person(std::string name, int age) {this->name = name; this->age = age;};
        int get_age() {return this->age;};
        std::string get_name() {return this->name;};
};

class Student : public Person
{
    private:
        int id;
        double gpa;

    public:
        Student(std::string name, int age, int id, double gpa) : Person(name, age)
        {
            this->id = id;
            this->gpa = gpa;
        }
        
        int get_id() {return this->id;};
        double get_gpa() {return this->gpa;};
        void set_id(int id) {this->id = id;};
        void set_gpa(double gpa) {this->gpa = gpa;};
        void show();
};

void Student::show()
{
    std::cout << "Name: " << get_name() << ", Age: " << get_age() << ", ID: " << get_id() << ", GPA: " << get_gpa() << std::endl;
}

int main()
{
    std::cout << "=== Testing Rectangle Class ===" << std::endl;
    Rectangle rect1;  // Default constructor
    Rectangle rect2(5);  // Square constructor
    Rectangle rect3(3, 7);  // Rectangle constructor
    
    std::cout << "Three rectangles created successfully" << std::endl;
    
    std::cout << "\n=== Testing Scores Class ===" << std::endl;
    double test_scores[] = {85.5, 92.0, 78.5, 95.0, 88.5};
    int num_students = 5;
    
    Scores class_scores(num_students, test_scores);
    class_scores.display();
    std::cout << "Class average: " << std::fixed << std::setprecision(2) 
              << class_scores.average() << std::endl;
    
    std::cout << "\n=== Testing Person Class ===" << std::endl;
    Person person1("Alice Johnson", 25);
    std::cout << "Person created: " << person1.get_name() 
              << ", Age: " << person1.get_age() << std::endl;
    
    std::cout << "\n=== Testing Student Class ===" << std::endl;
    // Note: Student class needs a constructor that calls Person constructor
    // For now, we'll create a basic test
    
    std::cout << "Student class testing requires constructor fix" << std::endl;
    
    std::cout << "\n=== Testing file_sort function ===" << std::endl;
    // Create a test input file
    std::ofstream test_file("test_input.txt");
    test_file << "3" << std::endl;
    test_file << "103 B 3.2" << std::endl;
    test_file << "101 A 3.8" << std::endl;
    test_file << "102 C 2.9" << std::endl;
    test_file.close();
    
    std::cout << "Created test file with unsorted student data" << std::endl;
    std::cout << "Calling file_sort..." << std::endl;
    
    char input[] = "test_input.txt";
    char output[] = "sorted_output.txt";
    file_sort(input, output);
    
    std::cout << "Sorted data written to sorted_output.txt" << std::endl;
    
    return 0;
}