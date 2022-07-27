#include <iostream>
#include "stack_application.h"
int main()
{
    try
    {
        infixToPostfix("10 + 20 * 30 - 40 * 50");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
