//
//
//  Assignment 2
//  group Members : Amiira Al Husnaa, 001202000157
//                  Niken Ayuning Tyas, 001202000139
//                  Raykhana Nabilla, 001202000182
//

#include <iostream>
#include <stack>
#include <string>
// Note : Add more operator (^, %), and give a space between the operand in suffix
//There are some mistake when compare the operator

using namespace std;
// Simply determine if expression is one of the five standard operators.
bool isOperator(char expression) {

    if (expression == '+' || expression == '-' || expression == '*' || expression == '/' || expression == '^' || expression == '%') {
        return true;
    }
    return false;
}
// If the expression is not an operator or a parenthesis, then it is assumed to be an operand.
bool isOperand(char expression) {
    if (!isOperator(expression) && expression != '(' && expression != ')') {
        return true;
    }
    return false;
}
// Compare operator precedence of main operators.
int compare(char s1, char s2)
{
    int pr1,pr2;
    switch(s1)
    {
        case '^' :
            pr1 = 3;
            break;
        case '*' :
        case '/':
            pr1 = 2;
            break;
        case '+' :
        case '-' :
        case '%' :
            pr1 = 1;
            break;
        default:
            pr1 = 0;
            break;
    }

    switch(s2)
    {
        case '(':
            pr2 = 4;
            break;
        case '^':
            pr2 = 3;
            break;
        case '*':
        case '/':
        pr2 = 2;
            break;
        case '+':
        case '-':
        case '%':
            pr2 = 1;
            break;
        default:
            pr2 = 0;
            break;
    }

    return (pr1 >= pr2) ? 1:0;
}

int main()
{
    // Empty expression stack and blank postfix string.
    stack<char> mystack;
    string postFix = "";

    string input; //calvary
    // Collect input
    cout << "Enter an expression: ";
    getline(cin, input); //calvary
    // Get a pointer to our expression array.
    char *cPtr = &input[0]; //calvary
    while (*cPtr != '\0') {
        if (isOperand(*cPtr) && *cPtr != ' ')
            {
            postFix += *cPtr;
            postFix += ' ';
            }
        else if (isOperator(*cPtr)) {
            while (!mystack.empty() && mystack.top() != '(' && compare(mystack.top(),*cPtr) == true) {
                postFix += mystack.top();
                postFix += ' ';
                mystack.pop();
            }
            mystack.push(*cPtr);
        }
        else if (*cPtr == '(')
                 { mystack.push(*cPtr); }
        else if (*cPtr == ')') {
            while (!mystack.empty()) {
                if (mystack.top() == '(')
                    {   mystack.pop();
                        break;
                    }
                postFix += mystack.top();
                postFix += ' ';
                mystack.pop();
            }
        }
        // Advance our pointer to next expression in string.
        cPtr++;
    }
    while (!mystack.empty()) {
        postFix += mystack.top();
        postFix += ' ';
        mystack.pop();
    }
// Show the postfix string at the end.

    cout << "Postfix is: " << postFix << endl;
    return 0;
}

