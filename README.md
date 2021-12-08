![Now Showing](https://user-images.githubusercontent.com/85719559/144750851-607c0b76-eda0-44b9-a188-9bcbe22741cf.jpg)

## SIMPLE SHELL


![GitHub repo size](https://img.shields.io/github/repo-size/sahinmeric/simple_shell)
![Lines of code](https://img.shields.io/tokei/lines/github/sahinmeric/simple_shell)
![Code language](https://img.shields.io/badge/c-language-yellowgreen)

## Description

Welcome to our `simple_shell` project for the end of the first tremeter at Holberton School!!

In a few words we can say that a Shell is a command interpreter that uses funtions and system calls to execute programs stored in the O.S.


## Learning Objectives

- [x] How does a shell work
- [x] What is a pid and a ppid
- [x] How to manipulate the environment of the current process
- [x] What is the difference between a function and a system call
- [x] How to create processes
- [x] What are the three prototypes of main
- [x] How does the shell use the PATH to find the programs
- [x] How to execute another program with the execve system call
- [x] How to suspend the execution of a process until one of its children terminates
- [x] What is EOF / “end-of-file”?


## Project Requirements
-   Allowed editors:  _vi_,  _vim_,  _emacs_
-   All your files will be compiled on Ubuntu 14.04 LTS.
-   Your programs and functions will be compiled with  _gcc 4.8.4_  using the flags  _-Wall -Werror -Wextra_  and  _-pedantic_
-   All your files should end with a new line
-   A  _README.md_  file, at the root of the folder of the project is mandatory
-   Your code should use the  _Betty_  style. It will be checked using  _betty-style.pl_  and  _betty-doc.pl_
-   No more than 5 functions per file.
-   Your shell should not have any memory leaks.
-   All your header files should be include guarded.
-   Use system calls only when you need to.
## Contents


| **Filename**  | **Description**          |
| ------------- | ----------- |
| `simple_sh.c` | Skeleton of our shell |
| `main.h` | Libreries used, main.h definition and prototypes of our functions |
| `main.c` | Entry point of the shell |
| `parse.c` |  Other functions |
| `execute.c` | Process id and execution files |
| `read.c` | Other functions |

## Compilation
Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Testing modes

Interactive :

![carbon (2) copy](https://user-images.githubusercontent.com/85719559/144756444-9dc4cd20-e0a5-4d32-86f2-7fb7338b07a3.png)

Non-interactive :

![carbon (2) non-intv copy](https://user-images.githubusercontent.com/85719559/144756628-ce5a0918-6359-440f-980d-fee6af4fbe2c.png)

## Installation

-   ` git clone://https://github.com/sahinmeric/simple_shell.git`
-   `cd simple_shell`
-   `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
-   `./hsh`

## Examples

Exercise 2. Simple shell 0.1

_Display a prompt and wait for the user to type a command. A command line always ends with a new line._

![#cisfun$ julien@ubuntu:~/shell$mands](https://user-images.githubusercontent.com/85719559/144759801-03d4a0ea-8747-4521-bb2a-a60613eea2e1.png)

Exercise  4. Simple shell 0.3

_Handle the PATH and fork must not be called if the command doesn’t exist_

![carbon (4) path and fork](https://user-images.githubusercontent.com/85719559/144760608-62fb9fe4-917f-427e-a343-1c59c556e4f9.png)

## Authors

[Sahin](https://www.linkedin.com/in/sahinmeric/)

[Lucila](https://www.linkedin.com/in/lucila-m-2b1518201/ )

## License
This simple_shell is under Apache license.
