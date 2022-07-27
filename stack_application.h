#include "stack.h"

// REVERSE A STRING
void reverseString(std ::string s)
{
    // push character of string to the stack
    Stack<char> stack(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        stack.push(s[i]);
    }

    // pop all elements and during each pop set new values at indices
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = stack.top();
        stack.pop();
    }

    std ::printf("%s\n", s.c_str());
}

// CHECK PARANTHESES
bool checkParan(std ::string s)
{
    // push character of string to the stack
    Stack<char> stack(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
        }
        else
        {
            if (stack.isEmpty())
            {
                return false;
            }
            switch (s[i])
            {
            case ']':
                if (stack.top() == '[')
                {
                    stack.pop();
                    break;
                }
                return false;
            case ')':
                if (stack.top() == '(')
                {
                    stack.pop();
                    break;
                }
                return false;
            case '}':
                if (stack.top() == '{')
                {
                    stack.pop();
                    break;
                }
                return false;
            }
        }
    }

    return stack.isEmpty();
}

// EVALUATE POSTFIX
void evalPostfix(std ::string s)
{
    /*
        repeat till the whole string is parsed
        {
            1. Push all the Operands onto the Stack
            2. When encounter a Operator do
                2.1 Pop two elements from Stack
                2.2 Perform the Operation specified by the Operator
                2.3 Push the result back to Stack
        }
    */

    Stack<int> stack(s.length());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {

            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();

            int result = 0;

            switch (s[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }
            stack.push(result);
        }
        else
        {
            if (s[i] != ' ')
            {
                int curr = 0;
                float decimal = 1;
                while (s[i] != ' ')
                {
                    curr = curr * decimal + (int)(s[i] - '0');
                    decimal *= 10;
                    i++;
                }
                stack.push(curr);
            }
        }
    }

    std ::cout << stack.top() << "\n";
}

// INFIX TO POSTFIX
int precedence(char op)
{
    switch (op)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        break;
    }
    return -1;
}
void infixToPostfix(std ::string s)
{

    std ::string postfix = "";
    Stack<char> stack(s.length());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (stack.isEmpty())
            {
                stack.push(s[i]);
                continue;
            }

            char top = stack.top();
            if (precedence(top) < precedence(s[i]))
            {
                stack.push(s[i]);
            }
            else
            {
                while ((precedence(s[i]) <= precedence(top)) && !stack.isEmpty())
                {
                    top = stack.top();
                    postfix += " ";
                    postfix += top;
                    postfix += " ";
                    stack.pop();
                }
                stack.push(s[i]);
            }
        }
        else
        {
            postfix += s[i];
        }
    }

    while (!stack.isEmpty())
    {
        postfix += " ";
        postfix += stack.top();
        postfix += " ";
        stack.pop();
    }

    std ::cout << postfix << " = ";
    evalPostfix(postfix);
}