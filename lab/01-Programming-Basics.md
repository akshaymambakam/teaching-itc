# Instructions to write and run your programs
## 1. Open the terminal.
## 2. Create the assignment directory
```sh
mkdir assignment1
```
## 3. Go into the directory
```sh
cd assignment1
```
## 4. Create and edit your assignment file using `gedit`
```sh
gedit assignment1.c
```
This will open gedit in a separate window
## Write your code and DO NOT forget to SAVE
## Close the file
## Compile your code
```sh
gcc assignment1.c
```
## Run your code
```sh
./a.out
```

## To calculate the area and perimeter of a rectangle
```c
#include <stdio.h>

int main() {
    float a=1, b=1;

    printf("Enter the length (a) and the width (b) of the rectangle:");
    scanf("%f%f", &a, &b);
    
    float area = a*b;

    printf("The area of the rectangle is: %f\n", area);

    float perimeter = 2*(a+b);

    printf("The perimeter of the rectangle is: %f\n", perimeter);

    return 0;
}

```

## Dot product
- **Formula:** $x_1\times x_2+y_1\times y_2+z_1\times z_2$

```c
#include <stdio.h>

int main() {
    float x1,y1,z1;
    float x2,y2,z2;

    printf("Enter the x,y, and z co-ordinates of the first point:");
    scanf("%f%f%f", &x1, &y1, &z1);
    
    printf("Enter the x,y, and z co-ordinates of the second point:");
    scanf("%f%f%f", &x2, &y2, &z2);
    
    float dot_product = // fill here

    printf("The dot product of the two points is: %f \n", dot_product);

    return 0;
}
```

## Manhattan distance
- **Formula:** $|x_1-x_2|+|y_1-y_2|$
- Use `fabs` for absolute value
```c
#include <stdio.h>
#include <math.h>

int main() {
    float x1=1, y1=1, x2=1, y2=1;

    printf("Enter the x and y co-ordinates of the first point:");
    scanf("%f%f", &x1, &y1);

    printf("Enter the x and y co-ordinates of the second point:");
    scanf("%f%f", &x2, &y2);

    printf("Manhattan distance is:%f", fabs(x1-x2)+??);

    return 0;
}
```

## To get the digits of a number
```c
#include <stdio.h>

int main() {
    int n=0;

    printf("Enter the four-digit integer n:");
    scanf("%d", &n);
    
    int remaining = n;
    
    int fourth_digit = remaining%10;
    remaining = remaining/10;
    
    int third_digit = remaining%10;
    remaining = remaining/10;
    
    // Fill below to get the first and second digits
    
    printf("The digits are: %d-%d-%d-%d\n", first_digit,
        second_digit, third_digit, fourth_digit);

    return 0;
}
```
