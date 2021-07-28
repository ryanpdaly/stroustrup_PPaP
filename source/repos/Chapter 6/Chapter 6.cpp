// Chapter 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();
    Token get();            // get a Token
    void putback(Token t);  // put a token back
private:
    bool full;     // is there a Token in the buffer?
    Token buffer;           // store a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;              // note that >> skips whitespace

    switch (ch) {
    case '=':               // for print
    case 'q':               // for quit
    case '(': case ')': case '{': case '}':
    case '!': case '*': case '/': case '+': case '-': 
        return Token{ ch };
    case '.':
    case '0': case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9':
    {   cin.putback(ch);
        double val;
        cin >> val;
        return Token{ '8',val };
    }
    default:
        error("Bad token");
    }
}
//------------------------------------------------------------------------------
Token_stream ts;            // proives get() and putback()

double expression();        // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
        return d;
    }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

int factorial()
{
    double left = primary();
    Token t = ts.get();
    int sum = 1;
    while (true) {
        switch (t.kind) {
        case '!':
            if (left != 0){
                for (int i = left; i > 0; --i)
                    sum *= i;
            }
            return sum;
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double term()
{
    double left = factorial();
    Token t = ts.get();     // get the next token

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

//------------------------------------------------------------------------------

double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------


int main()
try {
    cout << "Enter expressions grouped using () or {}.\n" <<
             "Valid operatators are: +, -, *, /, and !.\n";
    double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'q') break;
        if (t.kind == '=')
            cout << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}






//------------------------------------------------------------------------------
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
