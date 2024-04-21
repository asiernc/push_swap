<div align="center">
<h1 align="center">
    <img src="./img.png" width= "200px">
    <br>Push swap</br>
</h1>
<p align="center">
    <img src="https://img.shields.io/badge/Barcelona-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000" alt="42 Barcelona"/>
</p>
</div>

## Table of Contents
- [Summary](#-summary)
- [Qualification](#-qualification)
- [Average results](#-averageresults)
- [Usage](#-usage)
- [Installation](#-installation)


# Summary

### What is "push swap"?
"Push swap" is a simple algorithmic project where you need to sort data. You have access to two stacks and a set of allowed movements. The goal is to create a program that sorts the data in the fewest number of movements. It's evaluated based on a scoring table. I implemented an algorithm based on the Turkish algorithm, which basically consists of finding which number is cheapest for me to place on its site. I used a double-linked structure that allowed me to perform the movements much more easily. The movements are: 

| Conversión  | Descripción|
|-------|-----------------------------------------------------------------------------------|
| **sa** | swap a - exchanges the first two elements on top of stack a.   |
| **sb** | swap b - exchanges the first two elements on top of stack b.  	|
| **ss** | swap a and swap b simultaneously.        |
| **pa** | push a - takes the first element from stack b and puts it on top of stack a.		|  
| **pb** | push b - takes the first element from stack a and puts it on top of stack b.  	|
| **ra** | rotate a - shifts all elements of stack a up by one position, the first element becomes the last.      |
| **rb** | rotate b - shifts all elements of stack b up by one position, the first element becomes the last.               				|
| **rr** | ra and rb simultaneously.               				|
| **rra** | reverse rotate a - shifts all elements of stack a down by one position, the last element becomes the first.                				|
| **rrb** | reverse rotate b - shifts all elements of stack b down by one position, the last element becomes the first.                				|
| **rrr** | rra and rrb simultaneously.               				|

### Qualification

For three (3) numbers: 
    - Maximum 3 movements.

For five (5) numbers:
    - Maximum 13 movements.

For one hundred (100) numbers:

    | Movements  | Points  |
    |-------|-----------------------------------------------------------------------------------|
    | **less than 700** | 5   |
    | **less than 900** | 4  	|
    | **less than 1100** | 3      |
    | **less than 1300** | 2	|  
    | **less than 1500** | 1 	|

For five hundred (500) numbers:

    | Movements  | Points  |
    |-------|-----------------------------------------------------------------------------------|
    | **less than 5500** | 5   |
    | **less than 7000** | 4  	|
    | **less than 8500** | 3      |
    | **less than 10000** | 2	|  
    | **less than 11500** | 1 	|

### Average results

For 3 numbers: 1-2 movements.
for 5 numbers: ~8 movements.
For 100 numbers: ~545 movements.
For 500 numbers: ~4913 movements.

### Usage

```sh
./push_swap [numbers]
```

Example: 

```sh
./push_swap 66 581 841 488 627 547 758 471 31 107 118 227 701 605 300 405 464 830 115 624
```
💡 Tip: for a quick count of movements use "wc -l"


---
## Installation

1. Clone the Libft repository:
```sh
git clone
```

2. Change to the project directory:
```sh
cd push_swap
```

3. Compile the library:

    Using Makefile you can create the file push_swap.a<br/>
    Makefile has 4 main options:<br/>
    ```sh
    make
    ```
    to compile C files - create object files and library libft.a
    ```sh
    make clean
    ```
    to remove object files.
    ```sh
    make fclean
    ```
    remove libft.a file.
    ```sh
    make re
    ```
    recompile the library.



[**Return**](#Top)
