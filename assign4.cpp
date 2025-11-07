 /* 
 Name - Hansal Kumar
 Roll no - 23308
 Problem Statement:Implement a program to convert an infixexpression to prefix and postfix
 notation.
 •Evaluate both prefix and postfix expressions. Use STL for implementation.
*/
#include <bits/stdc++.h>
using namespace std;

class ExpressionConverter
{
public:
    string infixExpression;

    // Function to define operator priority
    int getPriority(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    // Input function
    void takeInput()
    {
        cout << "ENTER THE INFIX EXPRESSION: ";
        getline(cin, infixExpression);
    }

    // INFIX → POSTFIX conversion and evaluation
    int convertToPostfix()
    {
        string postfix = "";
        stack<char> opStack;

        for (char c : infixExpression)
        {
            if (isalnum(c))
            {
                postfix += c;
            }
            else if (c == '(')
            {
                opStack.push(c);
            }
            else if (c == ')')
            {
                while (!opStack.empty() && opStack.top() != '(')
                {
                    postfix += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty())
                    opStack.pop();
            }
            else // operator
            {
                while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(c))
                {
                    postfix += opStack.top();
                    opStack.pop();
                }
                opStack.push(c);
            }
        }

        // Pop remaining operators
        while (!opStack.empty())
        {
            postfix += opStack.top();
            opStack.pop();
        }

        cout << "\nINFIX TO POSTFIX: " << postfix << endl;
        cout << "Do you want to evaluate it? (yes/no): ";
        string choice;
        cin >> choice;

        if (choice == "yes")
        {
            stack<int> evalStack;

            for (char c : postfix)
            {
                if (isdigit(c))
                {
                    evalStack.push(c - '0');
                }
                else
                {
                    int val2 = evalStack.top(); evalStack.pop();
                    int val1 = evalStack.top(); evalStack.pop();

                    switch (c)
                    {
                    case '+': evalStack.push(val1 + val2); break;
                    case '-': evalStack.push(val1 - val2); break;
                    case '*': evalStack.push(val1 * val2); break;
                    case '/': evalStack.push(val1 / val2); break;
                    case '^': evalStack.push(pow(val1, val2)); break;
                    }
                }
            }

            cout << "EVALUATION RESULT (POSTFIX): " << evalStack.top() << endl;
            return evalStack.top();
        }
        else
        {
            cout << "Skipping evaluation." << endl;
            return 0;
        }
    }

    // INFIX → PREFIX conversion and evaluation
    int convertToPrefix()
    {
        string infix = infixExpression;
        reverse(infix.begin(), infix.end());

        for (char &c : infix)
        {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }

        string prefix = "";
        stack<char> opStack;

        for (char c : infix)
        {
            if (isalnum(c))
            {
                prefix += c;
            }
            else if (c == '(')
            {
                opStack.push(c);
            }
            else if (c == ')')
            {
                while (!opStack.empty() && opStack.top() != '(')
                {
                    prefix += opStack.top();
                    opStack.pop();
                }
                if (!opStack.empty())
                    opStack.pop();
            }
            else
            {
                while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(c))
                {
                    prefix += opStack.top();
                    opStack.pop();
                }
                opStack.push(c);
            }
        }

        while (!opStack.empty())
        {
            prefix += opStack.top();
            opStack.pop();
        }

        reverse(prefix.begin(), prefix.end());

        cout << "\nINFIX TO PREFIX: " << prefix << endl;
        cout << "Do you want to evaluate it? (yes/no): ";
        string choice;
        cin >> choice;

        if (choice == "yes")
        {
            stack<int> evalStack;

            for (int i = prefix.size() - 1; i >= 0; i--)
            {
                char c = prefix[i];

                if (isdigit(c))
                {
                    evalStack.push(c - '0');
                }
                else
                {
                    int val1 = evalStack.top(); evalStack.pop();
                    int val2 = evalStack.top(); evalStack.pop();

                    switch (c)
                    {
                    case '+': evalStack.push(val1 + val2); break;
                    case '-': evalStack.push(val1 - val2); break;
                    case '*': evalStack.push(val1 * val2); break;
                    case '/': evalStack.push(val1 / val2); break;
                    case '^': evalStack.push(pow(val1, val2)); break;
                    }
                }
            }

            cout << "EVALUATION RESULT (PREFIX): " << evalStack.top() << endl;
            return evalStack.top();
        }
        else
        {
            cout << "Skipping evaluation." << endl;
            return 0;
        }
    }
};

int main()
{
    ExpressionConverter converter;
    converter.takeInput();
    converter.convertToPostfix();
    converter.convertToPrefix();
    return 0;
}
