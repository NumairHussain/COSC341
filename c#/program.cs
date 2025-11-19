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