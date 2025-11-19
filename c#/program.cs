// Process student scores to find average, max, and min
class program
{
    void scores()
    {
        // Initialize variables
        int bestGrade = 0, worstGrade = 100;
        int totalStudents = 0;
        int gradeInput;
        double sumGrades = 0;
        
        // Input loop
        while (true)
        {
            // Prompt for score
            Console.Write("Enter score or -1 to quit: ");
            gradeInput = Convert.ToInt32(Console.ReadLine());
            
            // Check for quit condition
            if (gradeInput == -1)
            {
                break;
            }
            
            // Update min, max, and sum
            if (gradeInput < worstGrade)
            {
                worstGrade = gradeInput;
            }
            if (gradeInput > bestGrade)
            {
                bestGrade = gradeInput;
            }
            sumGrades += gradeInput;
            totalStudents++;
        }
        
        // Display results
        if (totalStudents > 0)
        {
            double averageScore = sumGrades / totalStudents;
            Console.WriteLine("Avg score: " + averageScore);
            Console.WriteLine("Max score: " + bestGrade);
            Console.WriteLine("Min score: " + worstGrade);
        }
        else
        {
            Console.WriteLine("No scores entered");
        }
    }

    // Generate ID and password based on name
    void createIdPassword(string last, string first)
    {
        // Create ID and password
        id = first[0] + last;
        password = first[0] + first[first.Length - 1] + last.Substring(0, 3) + first.Length + "" + last.Length;

        // Display ID and password
        Console.WriteLine("ID: " + id.ToUpper());
        Console.WriteLine("Password: " + password.ToUpper());
    }

    void fileSort(string infile, string outfile)
    {
        // Read student data from input file
        StreamReader fin = new StreamReader(infile);
        int numStudents = 0;
        numStudents = Convert.ToInt32(fin.ReadLine());

        // Arrays to hold student data
        int[] studentIds = new int[numStudents];
        char[] studentGrades = new char[numStudents];
        double[] studentGpas = new double[numStudents];

        // Read student data from file
        for (int i = 0; i < numStudents; i++)
        {
            string line = fin.ReadLine();
            string[] parts = line.Split(' ');
            studentIds[i] = Convert.ToInt32(parts[0]);
            studentGrades[i] = Convert.ToChar(parts[1]);
            studentGpas[i] = Convert.ToDouble(parts[2]);
        }

        // Close input file
        fin.Close();

        // Sort students by ID using bubble sort
        for (int i = 0; i < numStudents; i++)
        {
            for (int j = 0; j < numStudents - i - 1; j++)
            {
                if (studentIds[j] > studentIds[j + 1])
                {
                    // Swap student data
                    int tempId = studentIds[j];
                    studentIds[j] = studentIds[j + 1];
                    studentIds[j + 1] = tempId;

                    // Swap grades
                    char tempGrade = studentGrades[j];
                    studentGrades[j] = studentGrades[j + 1];
                    studentGrades[j + 1] = tempGrade;

                    // Swap gpas
                    double tempGpa = studentGpas[j];
                    studentGpas[j] = studentGpas[j + 1];
                    studentGpas[j + 1] = tempGpa;
                }
            }
        }

        // Write sorted data to output file
        StreamWriter fout = new StreamWriter(outfile);
        fout.WriteLine(numStudents);
        for (int i = 0; i < numStudents; i++)
        {
            fout.WriteLine(studentIds[i] + " " + studentGrades[i] + " " + studentGpas[i]);
        }
        fout.Close();
    }

    // Rectangle class
    class Rectangle
    {
        // Attributes
        private int width;
        private int height;

        // Constructors
        public Rectangle()
        {
            this.width = 0;
            this.height = 0;
        }

        public Rectangle(int size)
        {
            this.width = size;
            this.height = size;
        }

        public Rectangle(int width, int height)
        {
            this.width = width;
            this.height = height;
        }

        // Setters and Getters
        public void SetWidth(int width)
        {
            this.width = width;
        }

        public int GetWidth()
        {
            return this.width;
        }

        public void SetHeight(int height)
        {
            this.height = height;
        }

        public int GetHeight()
        {
            return this.height;
        }

        // Calculate area
        public int Area()
        {
            return this.width * this.height;
        }

        // Display dimensions
        public void Display()
        {
            Console.WriteLine("Width: " + this.width + ", Height: " + this.height);
        }
    }

    // Person class
    class Person
    {
        // Attributes
        private int age;
        private string name;

        // Constructor
        public Person(int age, string name)
        {
            this.age = age;
            this.name = name;
        }

        // Setters and Getters
        public void SetAge(int age)
        {
            this.age = age;
        }

        public int GetAge()
        {
            return this.age;
        }

        public void SetName(string name)
        {
            this.name = name;
        }

        public string GetName()
        {
            return this.name;
        }
    }

    // Student class inheriting from Person
    class Student : Person
    {
        // Attributes
        private int id;
        private double gpa;

        // Constructor
        public Student(string name, int age, int id, double gpa) : base(age, name)
        {
            this.id = id;
            this.gpa = gpa;
        }

        // Setters and Getters
        public void SetId(int id)
        {
            this.id = id;
        }

        public int GetId()
        {
            return this.id;
        }

        public void SetGpa(double gpa)
        {
            this.gpa = gpa;
        }

        public double GetGpa()
        {
            return this.gpa;
        }

        // Display student information
        public void Show()
        {
            Console.WriteLine("Name: " + this.GetName() + ", Age: " + this.GetAge() + ", ID: " + this.GetId() + ", GPA: " + this.GetGpa());
        }
    }
}