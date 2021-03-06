#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

std::vector<int> get_numbers_from_file(std::ifstream& s)
{
    std::vector<int> v;
    int i;

    while (s >> i)
    {
        v.push_back(i);
        s.ignore();
    }

    return v;
}

unsigned long part(const std::vector<int>& numbers, unsigned int iterations)
{
    unsigned long int a[9]{};
    std::memset(a, 0, sizeof(a));
    for(auto n : numbers)
        a[n] += 1;

    for(unsigned int i = 0; i < iterations; i++)
    {
        auto num_pregnant = a[0];

        // shift numbers
        for(int i = 1; i < 9; i++)
            a[i - 1] = a[i];

        a[6] += num_pregnant;
        a[8] = num_pregnant;
    }

    unsigned long sum = 0;

    for (unsigned int i = 0; i < 9; i++)
        sum += a[i];


    return sum;
}

int main()
{
    std::ifstream s{"days/day06/input.txt"};
    auto numbers = get_numbers_from_file(s);
    auto p1 = part(numbers, 80);
    auto p2 = part(numbers, 256);
    std::cout << "Part1: " << p1 << std::endl;
    std::cout << "Part2: " << p2 << std::endl;
    return 0;
}