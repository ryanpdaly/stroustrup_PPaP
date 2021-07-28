// Chapter 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../HelloWorld/HelloWorld/std_lib_facilities.h"

void convert_currency_for()
{
    constexpr double yen_per_usd = 0.0092;
    constexpr double kr_per_usd = 0.12;
    constexpr double pound_per_usd = 1.39;

    double val_in = 1;
    char unit = ' ';

    std::cout << "Please enter the value followed by the currency (y, k, or p):\n";
    std::cin >> val_in >> unit;

    
    if (unit == 'y')
        std::cout << val_in << "yen == " << val_in * yen_per_usd << "USD\n";
    else if (unit == 'k')
        std::cout << val_in << "kroner == " << val_in * kr_per_usd << "USD\n";
    else if (unit == 'p')
        std::cout << val_in << "GBP == " << val_in * pound_per_usd << "USD\n";
    else
        std::cout << "Sorry, the unit '" << unit << " is invalid.\n";
}

void convert_currency_switch()
{
    constexpr double yen_per_usd = 0.0092;
    constexpr double kr_per_usd = 0.12;
    constexpr double pound_per_usd = 1.39;

    double val_in = 1;
    char unit = ' ';

    std::cout << "Please enter the value followed by the currency (y, k, or p):\n";
    std::cin >> val_in >> unit;

    switch (unit) {
        case 'y':
            std::cout << val_in << "yen == " << val_in * yen_per_usd << "USD\n";
            break;
        case 'k':
            std::cout << val_in << "kroner == " << val_in * kr_per_usd << "USD\n";
            break;
        case 'p':
            std::cout << val_in << "GBP == " << val_in * pound_per_usd << "USD\n";
            break;
        default:
            std::cout << "Sorry, the unit '" << unit << " is invalid.\n";
            break;
    }
}

void char_int_pair_while()
{
    int val_in = 0;
    std::cout << "Enter starting integer:\n";
    std::cin >> val_in;

    int i = 0;
    while (i < 26) {
        std::cout << char('a' + i) << '\t' << val_in+i <<'\n';
        ++i;
    }
}

void char_int_pair_for()
{
    int val_in = 0;
    std::cout << "Enter starting interger:\n";
    std::cin >> val_in;

    for (int i = 0; i < 26; ++i)
        std::cout << char('a' + i) << '\t' << val_in + i << '\n';
    
    for (int i = 0; i < 26; ++i)
        std::cout << char('A' + i) << '\t' << val_in + i << '\n';
    
    for (int i = 0; i < 10; ++i)
        std::cout << char('0' + i) << '\t' << val_in + i << '\n';
}

int square_by_addition(int x)
{
    int sum = x;
    for (int i = 1; i<x; ++i)
        sum += x;

    return sum;
}

void bleep_disliked()
{
    string disliked = "Broccoli";
    vector<string> words;
    for (string temp; cin >> temp;)
        words.push_back(temp);

    for (int i = 0; i < words.size(); ++i)
        if (words[i] == disliked)
            cout << "BLEEP ";
        else
            cout << words[i] << " ";

}

void drill_two_cin() 
{
    double var1 = 0.0;
    double var2 = 0.0;

    while (cin >> var1 >> var2)
    {
        //cout << "\nFirst number: " << var1 << "\nSecond number: " << var2;
        vector<double> nums;
        
        if (var1 != var2)
        {
            nums.push_back(var1);
            nums.push_back(var2);

            sort(nums);
            cout << "\nThe smaller value is: " << nums[0] << "\nThe larger value is: " << nums[1] << "\n";
            
            double perc_diff = (nums[1] - nums[0]) / 100;

            if (perc_diff < 1.0 / 100)
                cout << "\nThe numbers are almost equal\n";

        }
        else
            cout << "\nThe numbers are equal\n";
    }
}

void drill_one_cin()
{
    vector<double> values;
    double var_converted = 0.0;
    
    double var_in = 0.0;
    string unit = " " ; //Valid units: cm, m, in, ft

    constexpr double m_to_cm = 100;
    constexpr double in_to_cm = 2.54;
    constexpr double ft_to_in = 12;


    while (cin >> var_in >> unit)
    {
        // Because unit is a string, we cannot use switch
        if (unit == "cm")
        {
            var_converted = var_in / m_to_cm;
            values.push_back(var_converted);
        }
        else if (unit == "m")
        {
            var_converted = var_in;
            values.push_back(var_converted);
        }
        else if (unit == "in")
        {
            var_converted = var_in * in_to_cm / m_to_cm;
            values.push_back(var_converted);
        }
        else if (unit == "ft")
        {
            var_converted = var_in * ft_to_in * in_to_cm / m_to_cm;
            values.push_back(var_converted);
        }
        else
        {
            cout << "Invalid unit error: " << unit << "\n";
        }

        sort(values);
        
        double sum = 0;
        for (double x : values)
            sum += x;
        int num_values = values.size();

        cout << "Smallest: " << values[0] << "m\n";
        cout << "Largest: " << values[num_values -1] << "m\n";
        cout << "Number of values: " << num_values << "\n";
        cout << "Sum of values: " << sum << "m" << "\n";
        cout << "All values: ";
        for (double x : values)
            cout << x << "m, ";
        cout << "\n\n\n";
    }
}

void ex2()
{
    vector<double> numbers;
    double median;
    for (double temp; cin >> temp;)
        numbers.push_back(temp);
    cout << "Number of values entered: " << numbers.size() << "\n";

    sort(numbers);

    if (numbers.size() % 2 != 0)
        median = numbers[numbers.size() / 2];
    else {
        double num1;
        double num2;

        num1 = numbers[numbers.size() / 2 + 0.5];
        num2 = numbers[numbers.size() / 2 - 0.5];

        median = (num1 + num2) / 2;
    }

    cout << "Median of values: " << median << "\n";
}

void ex3()
{
    vector<double> distances;
    double dist_tot = 0;

    for (double temp; cin >> temp;)
        distances.push_back(temp);

    cout << "Number of distances entered: " << distances.size() << "\n";

    sort(distances);

    for (double x : distances) dist_tot += x;

    cout << "Total distance: " << dist_tot << "\n";
    cout << "Shortest distance: " << distances[0] << "\n";
    cout << "Longest distance: " << distances[distances.size() - 1] << "\n";
}

void ex4()
{
    int user_num = 0;

    cin >> user_num;
}

void ex14()
{

}

int main()
{
    ex3();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
