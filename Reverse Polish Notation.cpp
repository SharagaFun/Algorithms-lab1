#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>

int getPriority (const char sign)
{
    switch (sign) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

const char *getExp (std::stack <char> &stack)
{
    size_t size = stack.size() * 2;
    char *result = new char[size];
    char sign;
    for (size_t i = 0; i < size; ++i) {
        sign = stack.top();

        if (sign == '(') {
            stack.pop();

            return result;
        }
        result[i] = ' ';
        result[++i] = sign;
        stack.pop();
    }
    return result;
}

std::string convert (std::string input)
{
    std::string exp = "";
    std::stack<char> stack;

    for (auto sign : input)
    {
        switch (sign) {
            case ' ':
            case '\n':
            case '\r':
            case '\t':
                continue;
            case '(':
                stack.push(sign);
                break;
            case ')':
                exp += getExp(stack);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (stack.empty() || getPriority(sign) > getPriority(stack.top()))
                    stack.push(sign);
                else
                {
                    exp += ' ';
                    exp += stack.top();
                    stack.pop();
                    stack.push(sign);
                }
                exp += ' ';
                break;
            default:
                exp += sign;
                break;
        }
    }

    return exp + getExp(stack);
}


double calculate(std::string rpn)
{
    double num, n1, n2, res;
    char *tmp = new char[rpn.size()];
    strcpy (tmp, rpn.c_str());
    std::stack<double> nums;
    for (char *splited = strtok(tmp, " "); splited != NULL; splited = strtok(NULL, " "))
    {
        if (splited[0] >= '0' && splited[0] <='9')
        {
            num = atof(splited);
            nums.push((double) num);
        }
        else
        {
            n2 = nums.top();
            nums.pop();
            n1 = nums.top();
            nums.pop();
            switch (splited[0])
            {
                case '+':
                    res = n1 + n2;
                    break;
                case '-':
                    res = n1 - n2;
                    break;
                case '*':
                    res = n1 * n2;
                    break;
                case '/':
                case ':':
                    res = n1 / n2;
                    break;
                case '^':
                    res = std::pow((double) n1, (double) n2);
                    break;
            }
            nums.push(res);
        }
    }
    delete[] tmp;
    return nums.top();
}

int main()
{
    std::string s;
    std::cin>>s;
    std::cout<<"Expression:\n"<<s<<std::endl;
    std::string rpn = convert(s);
    std::cout <<"Reverse Polish Notation:\n"<<rpn<<" "<<std::endl;
    double result = calculate(rpn);
    std::cout << "Result:\n"<< (int) result;
    return 0;
}

