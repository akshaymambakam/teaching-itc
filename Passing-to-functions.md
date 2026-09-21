# Passing Variables to Functions in C
When a function needs data from another part of the program, we **pass arguments** to it.

Example:

```c
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int result = add(10, 20);
    printf("%d", result);
}
```

Here,

- `a` and `b` are **parameters**
- `10` and `20` are **arguments**

---

# Pass by Value

In C, **all function arguments are passed by value**.

This means the function receives a **copy** of the variable.

Changing the copy does **not** change the original variable.

Example

```c
#include <stdio.h>

void change(int x)
{
    x = 100;
}

int main()
{
    int a = 10;

    change(a);

    printf("%d", a);
}
```

Output

```
10
```

Explanation

```
main()

a = 10
      |
      | send a copy
change()

x = 10

x becomes 100

Original variable is unchanged.
```

---

# Passing Basic Data Types

Basic (primitive) data types include:

- `char`
- `int`
- `float`
- `double`
- `long`
- `short`

Example

```c
#include <stdio.h>

void printSquare(int n)
{
    printf("%d\n", n * n);
}

int main()
{
    int x = 5;

    printSquare(x);

    return 0;
}
```

Output

```
25
```

---

# Passing Multiple Variables

```c
#include <stdio.h>

void display(int age, float salary)
{
    printf("Age: %d\n", age);
    printf("Salary: %.2f\n", salary);
}

int main()
{
    display(21, 45000.50);
}
```

---

# Passing Arrays

Arrays behave differently.

When an array is passed to a function, the array **goes as a pointer to its first element**.

The function can modify the original array.

Example

```c
#include <stdio.h>

void doubleValues(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        arr[i] *= 2;
}

int main()
{
    int numbers[] = {1,2,3,4,5};

    doubleValues(numbers, 5);

    for(int i = 0; i < 5; i++)
        printf("%d ", numbers[i]);
}
```

Output

```
2 4 6 8 10
```

Memory

```
main()

numbers

+---+---+---+---+---+
|1|2|3|4|5|
+---+---+---+---+---+
 ^
 |
 Function receives pointer here
```

---

# Passing Character Arrays (Strings)

Strings are simply character arrays.

```c
#include <stdio.h>

void printString(char str[])
{
    printf("%s\n", str);
}

int main()
{
    char name[] = "Alice";

    printString(name);
}
```

Output

```
Alice
```

---

# Passing Two-Dimensional Arrays

For multidimensional arrays, all dimensions except the first must be specified.

Example

```c
#include <stdio.h>

void printMatrix(int mat[][3], int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%d ", mat[i][j]);

        printf("\n");
    }
}

int main()
{
    int matrix[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    printMatrix(matrix, 2);
}
```

Output

```
1 2 3
4 5 6
```

**Note:**
Why specify the number of columns?

The compiler must know how many elements are in each row so it can correctly calculate the address of `mat[i][j]`.

---

# Passing Three-Dimensional Arrays

The same rule applies.

```c
void process(int cube[][4][5], int layers)
{
    ...
}
```

Only the first dimension can be omitted.

---

# Passing Pointers

Pointers store memory addresses.

A pointer can be passed like any other variable.

Example

```c
#include <stdio.h>

void change(int *p)
{
    *p = 100;
}

int main()
{
    int a = 10;

    change(&a);

    printf("%d", a);
}
```

Output

```
100
```

Memory

```
a = 10

&a
 |
 |
 |
 V
+------+
|  10  |
+------+

p -----> a

*p = 100
```

---

# Why Use Pointers?

Pointers allow a function to:

- Modify the original variable
- Avoid copying large amounts of data
- Work with dynamic memory
---

# Passing Multiple Pointers

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5;
    int y = 10;

    swap(&x, &y);

    printf("%d %d", x, y);
}
```

Output

```
10 5
```

---

# Passing a Pointer to a Pointer

A pointer can itself have an address.

```
value

↓

variable

↓

pointer

↓

pointer to pointer
```

Example

```c
#include <stdio.h>

void update(int **pp)
{
    **pp = 500;
}

int main()
{
    int value = 10;

    int *p = &value;

    update(&p);

    printf("%d", value);
}
```

Output

```
500
```

Memory

```
value = 10

   ^
   |
   p
   ^
   |
  pp
```

---

# Why Use Pointer to Pointer?

They are commonly used for:

- Dynamic memory allocation
- Arrays of pointers
- Linked data structures
- Functions that need to modify a pointer itself

Example

```c
void allocate(int **ptr)
{
    *ptr = malloc(5 * sizeof(int));
}
```

The function changes the caller's pointer so it points to newly allocated memory.

---

# Passing Structures

Structures can be passed by value.

```c
struct Student
{
    int id;
    float marks;
};

void printStudent(struct Student s)
{
    printf("%d %.2f\n", s.id, s.marks);
}
```

This copies the entire structure.

For large structures, passing a pointer is usually more efficient.

```c
void printStudent(struct Student *s)
{
    printf("%d %.2f\n", s->id, s->marks);
}
```

---

# Passing Functions as Arguments

C allows passing function pointers.

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

void calculate(int (*operation)(int, int))
{
    printf("%d\n", operation(5, 3));
}

int main()
{
    calculate(add);
}
```

Output

```
8
```

---

# Summary Table

| Data Type | Function Parameter |
|------------|--------------------|
| `int` | `int x` |
| `char` | `char c` |
| `float` | `float x` |
| `double` | `double x` |
| `long` | `long x` |
| `short` | `short x` |
| Array | `int arr[]` or `int *arr` |
| Character Array | `char str[]` |
| 2D Array | `int arr[][COLS]` |
| Pointer | `int *p` |
| Pointer to Pointer | `int **pp` |
| Structure | `struct Student s` |
| Structure Pointer | `struct Student *s` |
| Function Pointer | `int (*func)(int,int)` |

---

# Common Mistakes

## 1. Expecting pass-by-value to modify the original variable

❌ Wrong

```c
void change(int x)
{
    x = 100;
}
```

✔ Correct

```c
void change(int *x)
{
    *x = 100;
}
```

---

## 2. Forgetting array size information

❌ Wrong

```c
void printArray(int arr[])
{
    // Size of the array is not available here.
}
```

✔ Correct

```c
void printArray(int arr[], int size)
{
    ...
}
```

---

## 3. Omitting column sizes for multidimensional arrays

❌ Wrong

```c
void print(int mat[][], ...)
{
}
```

✔ Correct

```c
void print(int mat[][3], ...)
{
}
```

---

# Key Takeaways

- C uses **pass by value** for all function arguments.
- Arrays go as pointers to their first element when passed to functions.
- Pass the array size separately because the function cannot determine it automatically.
- For multidimensional arrays, all dimensions except the first must be specified in the parameter.
- Use pointers when a function needs to modify the caller's data or avoid copying large objects.
- Use pointer-to-pointer parameters when a function needs to modify a pointer itself (for example, allocating memory).
- Passing structures by pointer is usually more efficient than copying large structures.
