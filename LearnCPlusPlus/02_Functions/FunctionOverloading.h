#ifndef CPP_LEARNING_FUNCTION_OVERLOADING_H
#define CPP_LEARNING_FUNCTION_OVERLOADING_H

class FunctionOverloadingExample
{
public:
    void run();

private:
    int area(int side) const;
    int area(int width, int height) const;
};

#endif