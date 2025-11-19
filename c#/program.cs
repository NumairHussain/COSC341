void scores()
{
    string nameBuffer;
    string worstStudent = "", bestStudent = "";
    int bestGrade = 0, worstGrade = 100;
    int totalStudents = 0;
    int gradeInput;
    double sumGrades = 0;
    
    while (true)
    {
        Console.Write("Enter student name and score, or -1 to quit: ");
        nameBuffer = Console.ReadLine();
        
        // Check for quit condition
        if (nameBuffer == "-1")
        {
            break;
        }
        
        gradeInput = Convert.ToInt32(Console.ReadLine());
        
        // Update min, max, and sum
        if (gradeInput < worstGrade)
        {
            worstStudent = nameBuffer;
            worstGrade = gradeInput;
        }
        if (gradeInput > bestGrade)
        {
            bestStudent = nameBuffer;
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

void createIDPassword(string last, string first)
{
    id = first[0] + last;
    password = first[0] + first[first.Length - 1] + last.Substring(0, 3) + first.Length + "" + last.Length;
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
        Console.WriteLine(studentIds[i] + " " + studentGrades[i] + " " + studentGpas[i]);
    }

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
        fout.WriteLine(studentIds[i] + " " + studentGrades[i] + " " + studentGpas[i].ToString("F2"));
    }
    fout.Close();
}

class program
{
    public static void Main(string[] args)
    {
        // Call the scores function
        scores();
        
        // Create ID and password
        Console.Write("Enter last name: ");
        string lastName = Console.ReadLine();
        Console.Write("Enter first name: ");
        string firstName = Console.ReadLine();
        createIDPassword(lastName, firstName);
    }
}