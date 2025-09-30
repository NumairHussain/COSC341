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
    print("Hello")

def compute_tax(income, status, state):
    print("Hello")

def solve_quadratic(a, b, c):
    print("Hello")

def sort(list):
    print("Hello")

def id_password(first, last):
    print("Hello")

def file_sort(infile, outfile):
    print("Hello")


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
        status = input("Enter status (married) or (single)")
        state = input("Enter (i)nside or (o)utside of state: ")
        compute_tax(int(income), status, state)

    elif choice == "6":
        a = input("Enter a value: ")
        b = input("Enter b value: ")
        c = input("Etner c value: ")
        solve_quadratic(int(a), int(b), int(c))

    elif choice == "7":
        input_list = []
        while True:
            input_integer = input("Enter a value to be added to the list to be sorted, or any non integer to quit: ")
            try:
                input_list.append(int(input_integer))
            except ValueError:
                break

        output_list = sort(input_list)

    elif choice == "8":
        input_first_name = input("Enter your first name")
        input_last_name = input("Enter your last name")
        id_password(input_first_name, input_last_name)

    elif choice == "9":
        file_sort()

    elif choice == "10":
        break
