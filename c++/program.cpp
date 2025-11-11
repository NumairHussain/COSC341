#include <iostream>
#include <string>

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

void scores()
{
    while(true)
    {
        std::string input;
        std::string exit_case = "-1";
        std::cin >> input;
        if (input == exit_case)
        {
            break;
        }
        
    }
}


int main()
{
    std::cout << compute_pi(3);
    return 0;
}