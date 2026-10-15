# Why do we need dynamic memory?

Normally, variables are created with a fixed size.

```c
int numbers[5];
```

This creates space for exactly **5 integers**.

But what if the user wants to enter **100 numbers**?
Or maybe only **3 numbers**?

We don't always know the required memory size while writing the program.

That's where **dynamic memory allocation** comes in.

Dynamic memory is allocated while the program is running (runtime).

The C Standard Library provides three important functions:

- `malloc()`
- `calloc()`
- `realloc()`

These functions are declared in:

```c
#include <stdlib.h>
```

---

# 1. malloc()

`malloc()` stands for **Memory Allocation**.

It allocates a block of memory of the requested size.

## Syntax

```c
pointer = (type *) malloc(size_in_bytes);
```

Example:

```c
int *arr;

arr = (int *)malloc(5 * sizeof(int));
```

This allocates memory for **5 integers**.

### Memory layout

```
+----+----+----+----+----+
| ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+
```

Notice the values are **garbage values** (unknown data).

`malloc()` **does NOT initialize memory**.

---

## Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
    }

    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
```

Output

```
10 20 30 40 50
```

---

# 2. calloc()
It allocates memory for multiple elements **and initializes all bytes to zero**.

## Syntax

```c
pointer = (type *) calloc(number_of_elements, size_of_each_element);
```

Example

```c
int *arr = calloc(5, sizeof(int));
```

This allocates memory for **5 integers**.

Initial memory:

```
+---+---+---+---+---+
| 0 | 0 | 0 | 0 | 0 |
+---+---+---+---+---+
```

Unlike `malloc()`, the memory is initialized.

---

## Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = calloc(5, sizeof(int));

    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
```

Output

```
0 0 0 0 0
```

---

# malloc() vs calloc()

| Feature | malloc() | calloc() |
|----------|----------|-----------|
| Initialization | No | Yes (zeros) |
| Arguments | 1 | 2 |
| Speed | Usually slightly faster | Slightly slower because it initializes memory |

---

# 3. realloc()

Sometimes the allocated memory is not enough.

Suppose we allocated memory for 5 integers, but later we need space for 10 integers.

Instead of creating a new array manually, we can resize the existing memory using `realloc()`.

## Syntax

```c
pointer = realloc(pointer, new_size);
```

---

## Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr = malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++)
        arr[i] = i + 1;

    arr = realloc(arr, 10 * sizeof(int));

    for(int i = 5; i < 10; i++)
        arr[i] = i + 1;

    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
```

Output

```
1 2 3 4 5 6 7 8 9 10
```

---

# How realloc() works

Suppose we have:

```
Before

+----+----+----+----+----+
| 1  | 2  | 3  | 4  | 5  |
+----+----+----+----+----+
```

After:

```c
arr = realloc(arr, 10 * sizeof(int));
```

Possible result:

```
+----+----+----+----+----+----+----+----+----+----+
| 1  | 2  | 3  | 4  | 5  | ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+----+----+----+----+----+
```

The first five values remain unchanged.

The new memory is **not initialized**.

> `realloc()` may move the memory to a different location if needed. Always assign its return value back to a pointer (or, in production code, to a temporary pointer after checking for `NULL`).

---

# Always free allocated memory

Memory allocated using

- `malloc()`
- `calloc()`
- `realloc()`

must be released using:

```c
free(pointer);
```

Example

```c
int *arr = malloc(100 * sizeof(int));

...

free(arr);
```

Failing to call `free()` can lead to **memory leaks**, where allocated memory remains unavailable until the program ends.

---

# Checking for allocation failure

Memory allocation can fail (for example, if the system cannot provide enough memory).

Always check the returned pointer before using it.

```c
int *arr = malloc(5 * sizeof(int));

if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}
```

---

# Summary

| Function | Purpose | Initial Values |
|----------|---------|----------------|
| `malloc()` | Allocate memory | Garbage/indeterminate values |
| `calloc()` | Allocate memory and initialize | All bytes set to zero |
| `realloc()` | Resize previously allocated memory | Existing data preserved up to the smaller of the old and new sizes; new bytes are uninitialized |

---

# Quick Example

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *arr = malloc(3 * sizeof(int));

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    arr = realloc(arr, 5 * sizeof(int));

    arr[3] = 40;
    arr[4] = 50;

    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
```

Output

```
10 20 30 40 50
```

---

# Key Takeaways

- Use `malloc()` when you need dynamically allocated memory with an unknown initial value.
- Use `calloc()` when you want dynamically allocated memory that starts with all bytes set to zero.
- Use `realloc()` to increase or decrease the size of previously allocated memory.
- Always check whether allocation succeeded by comparing the returned pointer to `NULL`.
- Always release dynamically allocated memory using `free()` to avoid memory leaks.
