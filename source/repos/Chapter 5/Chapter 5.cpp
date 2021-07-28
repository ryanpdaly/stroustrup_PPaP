// Chapter 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../HelloWorld/HelloWorld/std_lib_facilities.h"

int drill()
try
{
    // Code segment
    
    //Cout << "Success!\n"; // Cout -> cout
    //cout << "Sucess!\n; // String literal unterminated
    //cout << "Success\n" << !\n"; // Second string literal not intiated
    //cout << success << '/n'; // success is undefined
    //string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; // Incorrect type for res
    //vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n"; // Vector item given by v[x], != -> ==
    //if (cond) cout << "Success!\n"; else cout << "Fail!\n"; //cond is undefined
    //bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n"; //c set incorrectly
    //string s = "ape"; boo c = "fool" < s; if (c) cout << "Success!\n"; // boo -> bool, < -> >
    //string s = "ape"; if (s == "fool") cout << "Success!\n"; // Success condition incorrect
    
    // End code segment
    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}

double ctok(double c)
{
    double k = c + 273.15;      // Errors: Originally declared as integer, needs to be a double to prevent data loss
    return k;                   // Errors: Missing ; at end of statement, returning int (should return k)

    /*Call using:
    double c = 0;
    cin >> c;                   // Errors: inputting undeclared indentifier d, need to input c
    double k = ctok(c);         // Errors: passing "c" instead of c
    cout << k << '\n';          // Errors: Cout instead of cout, /n instead of \n
    */
}

double ktoc(double k)
{
    double c = k - 273.15;
    return c;
}

double ctof(double c)
{
    double f = 9.0 / 5 * c + 32;
    return f;
}

int ctof_exact(double c)
{
    int f = 9.0 / 5 * c + 32;
    return f;
}

double ftoc(double f)
{
    double c = 5.0 / 9 * (f - 32);
    return c;
}

int ftoc_exact(double f)
{
    int c = 5.0 / 9 * (f - 32);
    return c;
}

int convert_temp()
{
    /*
        This function does multiple things, should probably be broken up into read_temp() and convert_temp().
        In order to do this I need to return multiple values, which I'm not sure how to do.
    */
    try {
        double val_in = 0;
        char unit = 'e';

        cout << "Enter temperature: ";
        cin >> val_in;
        cout << "Enter units (c, k, or f): ";
        cin >> unit;

        switch (unit) {
        case 'c': {
            if (val_in >= -273.15) {
                double k = ctok(val_in);
                double f = ctof(val_in);
                int f_exact = ctof_exact(val_in);
                // if (f != f_exact) error("Result cannot be represented by int.");
                cout << val_in << " C\n==" << k << " K\n==" << f << " F\n";
            }
            else
                error("Invalid temperature. Minimum input = 0K / -273.15C / -951.34F");
            break;
        }
        case 'k': {
            if (val_in >= 0) {
                double c = ktoc(val_in);
                double f = ctof(c);
                cout << val_in << " K\n== " << c << " C\n== " << f << " F\n";
            }
            else
                error("Invalid temperature. Minimum input = 0K / -273.15C / -951.34F");
            break;
        }
        case 'f': {
            if (val_in >= -951.34) {
                double c = ftoc(val_in);
                int c_exact = ftoc_exact(val_in);
                // if (c != c_exact) error("Result cannot be represented by int.");
                double k = ctok(c);
                cout << val_in << " F\n== " << k << " K\n== " << c << " C\n";
            }
            else
                error("Invalid temperature. Minimum input = 0K / -273.15C / -951.34F");
            break;
        }
        }
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;   // 1 indicates failure
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;   // 2 indicates failure
    }
}

bool test_root(vector<double> coeffs, double root)
{
    const double precision = 0.00001;
    double test = coeffs[0] * pow(root, 2.0) + coeffs[1] * root + coeffs[2];
    
    if (test < precision)
        return true;
    else
        return false;
}

void quadratic_roots() 
{
    double a = 0;
    double b = 0;
    double c = 0;

    cout << "Input coefficients (a, b, c) separated by spaces.\n";
    cin >> a >> b >> c;

    double test_real = pow(b, 2.0) - 4 * a * c;

    if (test_real >= 0) {
        double x_plus = (-b + sqrt(test_real)) / (2*a);
        double x_minus = (-b - sqrt(test_real)) / (2*a);
        cout << "Roots: " << x_plus << " & " << x_minus << "\n";

        vector<double> coeffs = { a, b, c };

        if (test_root(coeffs, x_plus) && test_root(coeffs, x_minus))
            cout << "Tests: pass\n";
        else
            cout << "Tests: fail\n";
    }
    else {
        cout << "This quadratic has no real roots.";
        return;
    }
}

int print_n_integers()
{
    try {

        int N = 0;
        vector<double> nums;
        vector<double> differences;

        cout << "Please enter the number of values you want to sum: ";
        cin >> N;

        cout << "Please enter some integers (press '|' to stop): ";
        for (double i; cin >> i;)
            nums.push_back(i);

        if (N < 0)
            error("Negative value entered for N");
        else if (N == 0)
            error("It's a bit pointless to run the damned thing and then not request a sum, now innit?");
        else if (N > nums.size())
            error("Error: Cannot sum more numbers that are entered.");
        else
        {
            cout << "\nThe sum of the first " << N << " numbers ( ";

            double sum = 0;
            for (int i = 0; i < N; i++) {
                sum += nums[i];
                cout << nums[i] << " ";
            }

            cout << ") is " << sum << "\n";

            for (int i = 1; i < nums.size(); i++) {
                double temp = nums[i] - nums[i - 1];
                differences.push_back(temp);
            }

            cout << "Our adjacent differences are given by: ";
            for (int i = 0; i < differences.size(); i++) {
                cout << differences[i] << " ";
            }
            cout << "\n";
        }
        return 0;   // 0 indicates failure
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;   // 1 indicates failure
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;   // 2 indicates failure
    }
}

int print_n_fibonacci()
{
    try {
        int N = 0;
        vector<int> seq{ 1, 1 };

        cout << "Desired number of values in the sequence? ";
        cin >> N;
        cout << "\n";

        for (int i = 0; i < (N - 2); i++) {
            int length = seq.size();

            int n = seq[length - 1] + seq[length - 2];

            if (n < 0)
                error("Integer overflow"); // This doesn't work. Need to check for unexpected behavior by hand?

            if (n - seq[length - 1] == seq[length - 2])
                seq.push_back(n);
        }

        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << " ";
        }
        cout <<"\n\n" << INT_MAX;

        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;   // 1 indicates failure
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;   // 2 indicates failure
    }
}

int main()
{
    print_n_fibonacci();
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
