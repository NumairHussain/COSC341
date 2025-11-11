#include <iostream>

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



int main()
{
    std::cout << compute_pi(3);
    return 0;
}