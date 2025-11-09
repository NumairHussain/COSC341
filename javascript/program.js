// Find all factors of a given number
function factors(num)
{
    let all_factors = "1"; // Start with 1 as first factor
    
    // Check each number from 2 to num for factors
    for (let i = 2; i <= num; i++)
    {
        if (num % i === 0) // If i divides num evenly, it's a factor
        {
            all_factors += ", " + i;
        }
    }
    
    return all_factors;
}

// Calculate tax amount
function tax(income, status)
{
    let taxed_amount;
    
    // Check if single
    if (status.toLowerCase() == "single")
    {
        // Check Income
        if (income < 30000)
        {
            taxed_amount = income * .2; // 20%
        }
        else
        {
            taxed_amount = income * .25; // 25%
        }
    }
    // Check if married
    else if (status.toLowerCase() == "married")
    {
        // Check Income
        if (income < 50000)
        {
            taxed_amount = income * .1; // 10% 
        }
        else
        {
            taxed_amount = income * .15; // 15% 
        }
    }
    return taxed_amount;
}

// Calculate standard deviation
function stdDev(arr)
{
    // Calculate sum of all elements
    let sum = 0;
    for (let i = 0; i < arr.length; i++)
    {
        sum += arr[i];
    }
    let average = sum / arr.length; // Calculate mean

    // Calculate sum of squared differences from mean
    let standard_deviation = 0;
    for (let i = 0; i < arr.length; i++)
    {
        standard_deviation += (arr[i] - average) * (arr[i] - average);
    }
    return standard_deviation / arr.length; // Return standard deviation
}

// Create user ID
function createIDPassword(lastName, firstName)
{
    var id = firstName[0] + lastName;
    var password = firstName[0] + firstName[firstName.length - 1]  + lastName.substring(0, 3) + firstName.length + "" + lastName.length
    return [id.toUpperCase(), password.toUpperCase()]
}

// Remove duplicates
function removeDuplicates(arr)
{
    var newArray = [];
    
    // Check each element
    for (var i = 0; i < arr.length; i++)
    {
        var isDuplicate = false; // Reset flag for each element
        
        // Check if current element already exists in newArray
        for (var j = 0; j < newArray.length; j++)
        {
            if (arr[i] == newArray[j])
            {
                isDuplicate = true;
                break; // Exit inner loop if duplicate found
            }
        }
        
        // Add element only if it's not a duplicate
        if (!isDuplicate)
        {
            newArray[newArray.length] = arr[i];
        }
    }
    return newArray;
}

// Student class
class Student
{
    // Constructor to initialize student with name and GPA
    constructor(name, gpa)
    {
        this.name = name;
        this.gpa = gpa;
    }

    // Get student's name
    getName()
    {
        return this.name;
    }

    // Get student's GPA
    getGpa()
    {
        return this.gpa;
    }

    // Set student's name
    setName(name)
    {
        this.name = name;
    }

    // Set student's GPA
    setGpa(gpa)
    {
        this.gpa = gpa;
    }

    // Check if student qualifies for honors
    isHonors()
    {
        if (this.gpa > 3)
        {
            return true;
        }
        return false;
    }
}
