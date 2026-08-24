# Assignment: Distance, Triangle Area, and Triangle Inequality

## GCC Compilation

Compile using:

```bash
gcc program.c -o program -lm
```

The `-lm` flag links the math library required by `sqrt()` and `fabs()` which are the functions for computing square root and absolute value of floating point numbers respectively.

---

## Question 1: Manhattan Distance

Given two points $P_1(x_1,y_1)$ and $P_2(x_2,y_2)$, compute their **Manhattan distance**.

### Formula

$$
d=|x_1-x_2|+|y_1-y_2|
$$

### Code

Complete the expression for `distance`:

```c
#include <stdio.h>
#include <math.h>

int main() {
    float x1,y1,x2,y2;

    printf("First point: ");
    scanf("%f%f",&x1,&y1);

    printf("Second point: ");
    scanf("%f%f",&x2,&y2);

    float distance = __________________________;

    printf("Manhattan distance: %f\n",distance);

    return 0;
}
```

---

## Question 2: Euclidean Distance

Given two points $P_1(x_1,y_1)$ and $P_2(x_2,y_2)$, compute their **Euclidean distance**.

### Formula

$$
d=\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}
$$

### Code

Complete the expression for `distance`:

```c
#include <stdio.h>
#include <math.h>

int main() {
    float x1,y1,x2,y2;

    printf("First point: ");
    scanf("%f%f",&x1,&y1);

    printf("Second point: ");
    scanf("%f%f",&x2,&y2);

    float distance = __________________________;

    printf("Euclidean distance: %f\n",distance);

    return 0;
}
```

---

## Question 3: Area of a Triangle and Triangle Inequality

Given three points $P_1(x_1,y_1)$, $P_2(x_2,y_2)$, and $P_3(x_3,y_3)$:

1. Compute the area of the triangle.
2. Determine whether the three points form a valid triangle.
3. Compute the three side lengths using Euclidean distance.
4. Check whether the triangle inequality is violated.
5. Use negation to obtain the final `valid_triangle` result.

### Formulae

Twice the signed area is:

$$
A_2=x_1(y_2-y_3)+x_2(y_3-y_1)+x_3(y_1-y_2)
$$

The actual area is:

$$
A=\frac{|A_2|}{2}
$$

The three side lengths are:

$$
a=\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}
$$

$$
b=\sqrt{(x_2-x_3)^2+(y_2-y_3)^2}
$$

$$
c=\sqrt{(x_1-x_3)^2+(y_1-y_3)^2}
$$

The triangle inequality requires $a+b>c$, $b+c>a$, and $c+a>b$.

### Negated Triangle Inequalities

The corresponding conditions for an **invalid triangle** are:

$$
a+b\leq c
$$

$$
b+c\leq a
$$

$$
c+a\leq b
$$

Since any one of these conditions is sufficient to make the side lengths invalid, they are combined using logical OR, $||$.

### Code

Complete the missing expressions:

```c
#include <stdio.h>
#include <math.h>

int main() {
    int x1,y1;
    int x2,y2;
    int x3,y3;

    printf("Point 1: ");
    scanf("%d%d",&x1,&y1);

    printf("Point 2: ");
    scanf("%d%d",&x2,&y2);

    printf("Point 3: ");
    scanf("%d%d",&x3,&y3);

    // Use the area formula to check if the triangle is valid
    int valid_by_area;
    // First calculate the area correctly
    // Check if the area is zero
    ___ area;
    ___ twice_area;
    // Which one will you use? area or twice the area? Why?

    valid_by_area = ________________________________;

    print("Valid triangle: %d\n", valid_by_area);

    float side1 = __________________________;
    float side2 = __________________________;
    float side3 = __________________________;

    int sides_invalid =
        __________________________ ||
        __________________________ ||
        __________________________;

    int valid_triangle = !__________________________;

    printf("Valid triangle: %d\n",valid_triangle);

    return 0;
}
```

### Requirements

* Use `fabs()` to obtain the absolute value when calculating the area.
* Use `sqrt()` to calculate the Euclidean side lengths.
* Use `||` to combine the three invalid triangle conditions.
* Use `<=` to detect a violation of the triangle inequality.
* Use `!` to obtain `valid_triangle` from the invalid-side condition.
* Ensure that the three points are not collinear.
* Compile using:

```bash
gcc program.c -o program -lm
```
