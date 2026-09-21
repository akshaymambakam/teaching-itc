# Recursion
Recursion is a programming pattern in which a function calls itself. The purpose is to solve smaller versions of the same problem and combine the results. A recursive function contains a call to itself either directly or indirectly. Let us discuss three common types of recursion which are direct recursion, indirect recursion, and tail recursion.

## Direct recursion
In direct recursion the function has a call to itself contained right inside its body.

**Linear recursion**
```c
// Function definition
int factorial(int n) {
    // 1. Base case to stop the loop
    if (n <= 1) {
        return 1;
    }
    // 2. Direct recursive call
    return n * factorial(n - 1);
}
```

**Tree recursion**
```c
int fibonacci(int n) {
    // 1. Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // 2. Multiple direct recursive calls
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```


**Important note: The base cases need to carefully written to prevent never-ending calls. Use your mathematical intuition.**


## Tail recursion
Tail recursion is a special case of direct recursion where the recursive call is the last operation performed.

```c
// A tail recursive function to calculate factorial
unsigned factTR(unsigned int n, unsigned int a)
{
    if (n <= 1)
        return a;

    return factTR(n - 1, n * a);
}

// A wrapper over factTR
unsigned int fact(unsigned int n) { 
    return factTR(n, 1); 
}
```
- Can you convert this and find an iterative approach?
- Why is this important? The compiler can optimize and reduce the memory space required for the program to execute.
- No need to keep a trace of function calls for the compiler if it acts cleverly.

## Indirect recursion
In indirect recursion a function does not call itself directly. It calls another function, which in turn calls calls the first function. We can create such chain with two or more functions.

```c
void funcA(int);
void funcB(int);

void funcA(int n) {
    if (n > 0) {
        printf("%d ", n);
        funcB(n - 1);
    }
}

void funcB(int n) {
    if (n > 0) {
        printf("%d ", n);
        funcA(n / 2);
    }
}
```

**Note: The function prototypes are absolutely required here for proper compilation because of the circular dependency.**


