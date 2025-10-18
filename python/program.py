import math


def compute_pi(n):
    sign = 1
    pi = 0.0

    for i in range(0, n):
        pi += sign * (1.0/(2 * i + 1))
        sign = -sign

    return 4 * pi

def compute_sqrt(n):
    next = 1.0
    last = 1.0

    for i in range(n):
        last = next;    
        next = 0.5 * (last + n / last)

    return next

def is_prime(n):
    for i in range(2, n):
        if ((n % i) == 0):
            return False
    return True

def display_primes(n):
    for i in range(2, n):
        if is_prime(i):
            print(i)

def process_scores():
    # Initialize variables
    worst_student = ""
    best_student = ""
    best_grade = 0
    worst_grade = 100
    total_students = 0
    sum_grades = 0
    
    while True:
        # Prompt user for input
        user_input = input("Enter student name and score, or q to quit: ")
        
        # Check for quit condition
        if user_input.lower().startswith('q'):
            break
        
        # Parse input - expect "name score" format
        try:
            parts = user_input.split()
            if len(parts) >= 2:
                name_buffer = parts[0]
                grade_input = int(parts[1])
            else:
                print("Please enter both name and score")
                continue
        except ValueError:
            print("Please enter a valid score (integer)")
            continue
        
        # Update min, max, and sum
        if grade_input < worst_grade:
            worst_student = name_buffer
            worst_grade = grade_input
        
        if grade_input > best_grade:
            best_student = name_buffer
            best_grade = grade_input
            
        sum_grades += grade_input
        total_students += 1
    
    # Display results
    if total_students > 0:
        average_score = sum_grades / total_students
        print(f"Avg score: {average_score:.2f}")
        print(f"Best grade: {best_grade}")
        print(f"Worst grade: {worst_grade}")
        print(f"Best student: {best_student}")
        print(f"Worst student: {worst_student} \n")
    else:
        print("No scores entered")


def compute_tax(income, status, state):
    if income < 0:
        return -1

    # Convert status to lowercase
    status = status.lower()

    # Validate status (should be "single" or "married")
    if status not in ["single", "married"]:
        return -1
    
    # Validate state (should be 'i' or 'o')
    if state.lower() not in ['i', 'o']:
        return -1

    tax_rate = 0.0

    if state.lower() == 'i':  # In-state
        if status == "single":  # Single
            if income < 40000:
                tax_rate = 0.30
            else:
                tax_rate = 0.35
        else:  # Married
            if income < 60000:
                tax_rate = 0.20
            else:
                tax_rate = 0.25
    else:  # Out-of-state (3% less)
        if status == "single":  # Single
            if income < 40000:
                tax_rate = 0.27  # 30% - 3%
            else:
                tax_rate = 0.32  # 35% - 3%
        else:  # Married
            if income < 60000:
                tax_rate = 0.17  # 20% - 3%
            else:
                tax_rate = 0.22  # 25% - 3%

    return income * tax_rate

def solve_quadratic(a, b, c):
    
    discriminant = (b * b) - (4 * a * c)
    
    if discriminant < 0:
        # No real solutions (negative discriminant)
        return 0, 0
    
    # Calculate both solutions using quadratic formula
    solution1 = (-b + math.sqrt(discriminant)) / (2 * a)
    solution2 = (-b - math.sqrt(discriminant)) / (2 * a)
    
    return solution1, solution2

def sort(list):
    for i in range(len(list)):
        for j in range(i + 1, len(list)):
            if list[i] > list[j]:
                list[i], list[j] = list[j], list[i]
    return list

def id_password(first, last):
    '''
    The user
    id is the first letter of the first name followed by the last name

    The password is the first
    letter of the first name followed the last letter of the first name followed by the first three
    letters of the last name followed by the length of the first name followed by the length of
    the last name
    '''
    user_id = first[0] + last
    password = first[0] + first[len(first) - 1] + last[0:3] + str(len(first)) + str(len(last))

    return user_id.upper(), password.upper()

def file_sort(infile, outfile):
    infile = open(infile, 'r')
    length = (int) (infile.readline().strip())

    student_ids = []
    student_names = []
    student_gpas = []

    for i in range(length):
        line = infile.readline()
        id_num, name, gpa = line.split()
        student_ids.append(id_num)
        student_names.append(name)
        student_gpas.append(gpa)

    for i in range(len(student_ids)):
        for j in range(i + 1, len(student_ids)):
            if student_ids[i] > student_ids[j]:
                student_ids[i], student_ids[j] = student_ids[j], student_ids[i]
                student_names[i], student_names[j] = student_names[j], student_names[i]
                student_gpas[i], student_gpas[j] = student_gpas[j], student_gpas[i]
    

    outfile = open(outfile, 'w')
    outfile.write((str) (length) + "\n")
    for i in range(length):
        outfile.write(student_ids[i] + " " + student_names[i] + " " + student_gpas[i] + "\n")


class Rectangle:
    def __init__(self, length, width):
        self.length = length
        self.width = width

    def set_length(self, new_length):
        self.length = new_length

    def set_width(self, new_width):
        self.width = new_width

    def get_length(self):
        return self.length
    
    def get_width(self):
        return self.width
    
    def a(self):
        return self.length * self.width
    
    def __str__(self):
        return "Length of Rectangle: " + str(self.length) + " | Width of Rectangle: " + str(self.width)

while True:
    print("Menu Options:")
    print("1. Compute Pi")
    print("2. Compute Square Root")
    print("3. Display Primes")
    print("4. Process Scores")
    print("5. Compute Tax")
    print("6. Solve Quadratic")
    print("7. Sort")
    print("8. ID and Password")
    print("9. File Sort")
    print("10. Quit")

    choice = input("Enter option 1-9 (or 10 to quit): ")

    if choice == "1":
        compute_pi_input = input("Enter a number to compute pi using that many terms: ")
        print("The value of pi: ", compute_pi(int(compute_pi_input)))

    elif choice == "2":
        compute_sqrt_input = input("Enter a number to compute its square root:")
        print("Square root of", compute_sqrt_input, "is", compute_sqrt(int(compute_sqrt_input)))
    
    elif choice == "3":
        display_primes_input = input("Display primes up to: ")
        display_primes(int(display_primes_input))

    elif choice == "4":
        process_scores()

    elif choice == "5":
        income = input("Enter income: ")
        status = input("Enter status (married) or (single): ")
        state = input("Enter (i)nside or (o)utside of state: ")
        tax_amount = compute_tax(int(income), status, state)
        if tax_amount == -1:
            print("Invalid input provided")
        else:
            print(f"Your tax amount: {tax_amount:.2f}")

    elif choice == "6":
        a = input("Enter a value: ")
        b = input("Enter b value: ")
        c = input("Enter c value: ")
        solution1, solution2 = solve_quadratic(int(a), int(b), int(c))
        print(f"The answer for the quadratic formula is: {solution1} and {solution2}")

    elif choice == "7":
        input_list = []
        while True:
            input_integer = input("Enter a value to be added to the list to be sorted, or any non integer to quit: ")
            try:
                input_list.append(int(input_integer))
            except ValueError:
                break

        print("The sorted list is ", sort(input_list))

    elif choice == "8":
        input_first_name = input("Enter your first name: ")
        input_last_name = input("Enter your last name: ")
        output_user_id, output_password = id_password(input_first_name, input_last_name)
        print("User id: " + output_user_id + " | Password: " + output_password)

    elif choice == "9":
        input_file_name = input("Enter the name of the file to be sorted: ")
        output_file_name = input("Enter the name of the file to put the results in: ")
        file_sort(input_file_name, output_file_name)

    elif choice == "10":
        rect = Rectangle(5, 10)
        print("get_length:", rect.get_length())
        print("get_width:", rect.get_width())
        rect.set_length(15)
        rect.set_width(20)
        print(rect)
        print("Area of rectangle:", rect.a())
        break