function factors(num)
{
    let all_factors = "1";
    
    for (let i = 2; i <= num; i++)
    {
        if (num % i === 0)
        {
            all_factors += ", " + i;
        }
    }
    
    return all_factors;
}

console.log(factors(10));

function tax(income, status)
{
    let taxed_amount;
    if (status.toLowerCase() == "single")
    {
        if (income < 30000)
        {
            taxed_amount = income * .2;
        }
        else
        {
            taxed_amount = income * .25;
        }
    }
    else
    {
        if (income < 50000)
        {
            taxed_amount = income * .1;
        }
        else
        {
            taxed_amount = income * .15
        }
    }
    return taxed_amount;
}

console.log(tax(60000, "married"))

function stdDev(arr)
{
    let sum = 0;
    for (let i = 0; i < arr.length; i++)
    {
        sum += arr[i]
    }
    let average = sum / arr.length;

    let standard_deviation = 0;
    for (let i = 0; i < arr.length; i++)
    {
        standard_deviation += (arr[i] - average) * (arr[i] - average)
    }
    return standard_deviation / arr.length;
}

arr = [1, 2, 3, 4, 5, 6]
console.log(stdDev(arr))

function createIDPassword(lastName, firstName)
{
    var id = firstName[0] + lastName;
    var password = firstName[0] + firstName[firstName.length - 1]  + lastName.substring(0, 3) + firstName.length + "" + lastName.length
    return [id.toUpperCase(), password.toUpperCase()]
}

firstName = "John"
lastName = "Maxwell"
console.log(createIDPassword(lastName, firstName))

function removeDuplicates(arr)
{
    var newArray = [];
    for (var i = 0; i < arr.length; i++)
    {
        var isDuplicate = false;
        for (var j = 0; j < newArray.length; j++)
        {
            if (arr[i] == newArray[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            newArray[newArray.length] = arr[i];
        }
    }
    return newArray;
}

var arr = ["tree", "cat", "box", "cat", "dog", "tree", "tree", "box"];
console.log(removeDuplicates(arr))


class Student
{
    constructor(name, gpa)
    {
        this.name = name;
        this.gpa = gpa;
    }

    getName()
    {
        return this.name;
    }

    getGpa()
    {
        return this.gpa;
    }

    setName(name)
    {
        this.name = name
    }

    setGpa(gpa)
    {
        this.gpa = gpa
    }

    isHonors()
    {
        if (gpa > 3)
        {
            return true;
        }
        return false;
    }
}
