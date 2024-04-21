<div align="center">
<h1 align="center">
    <img src="./ft_printf.tiff" width= "200px">
    <br>ft_prinf</br>
</h1>
<p align="center">
    <img src="https://img.shields.io/badge/Barcelona-100000?style=flat-square&logo=42&logoColor=white&labelColor=000000&color=000000" alt="42 Barcelona"/>
</p>
</div>

## Table of Contents
- [Summary](#-summary)
- [Installation](#-installation)


# Summary

### Que es ft_printf?
ft_printf es un proyecto de 42 donde recreamos el funcionamiento de `printf`.
En nuestro ft_printf puedes usar las siguientes conversiones:

| Conversión  | Descripción|
|-------|-----------------------------------------------------------------------------------|
| **%c** | Imprime un solo carácter.   |
| **%s** | Imprime una string (como se define por defecto en C).  	|
| **%p** | El puntero void * dado como argumento se imprime en formato hexadecimal.         |
| **%d** | Imprime un número decimal (base 10).		|  
| **%i** | Imprime un entero en base 10.  	|
| **%u** | Imprime un número decimal (base 10) sin signo.      |
| **%x** | Imprime un número hexadecimal (base 16) en minúsculas.                				|
| **%X** | Imprime un número hexadecimal (base 16) en mayúsculas.                				|
| **%%** | Imprime el símbolo del porcentaje.                 			      |				
---
## Installation

1. Clone the Libft repository:
```sh
git clone
```

2. Change to the project directory:
```sh
cd ft_printf
```

3. Compile the library:

    Using Makefile you can create library file libftprintf.a<br/>
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
