# Introduction
We will see some basic commands for smooth sailing. Practice these till you remember each of these and their usage.

**pwd** To display the directory/folder you are in. To know where you are.
```sh
pwd
```

**mkdir** To create a new directory/folder.
```sh
mkdir directoryname
mkdir assignment1
```

**ls** To know what files and sub-directories you have in the current directory.
```sh
ls -la
ls
```

**cd** To change your current directory and navigate

```sh
cd directoryname
cd assignment1
```

**gedit** A graphical editor to write your code.

```sh
gedit filename
gedit assignment.c
```

**cp** To copy files. Especially useful for backups and storing partial progress.

```sh
cp source destination
cp assignment1.c assignment1_backup.c
```

Your first program

```c
/*
Name: 
Other details ...
*/
#include <stdio.h>

int main(){
    printf("Hello world!\n");

    return 0;
}

```

Compile it

```sh
gcc assignment0.c
```

You will get a file named `a.out`. How do you check if it exists? Run it.

```sh
./a.out
```

