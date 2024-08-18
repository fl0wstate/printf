# Printf Project 🖨️
Hello world welcome to our personal peer project of creating a replica of the `printf` function in c.<br>
The project will entail all the process used to make a custom `_printf`, that has the same behaviour as the C standard libray `printf`.<br>
Starting point, will be using this prototype as our starting point.<br>
```int _printf(const char *format, ...);```

# Run the program 👣
* Below are some of the functionality and use cases of our custom `_printf()`
All right lets dive in and have fun while at it..
* Have included a `run.sh` file on the repo under the test folder to run the program and also use the `_printf` functionality.
* For Window users you will have to use the following command to compile the code to have an executable file.
       ```
       gcc -g -Wall -Wextra -Werror -pedantic -std=gnu89 -o _printf
       ```
There you go you have a new replica of the `printf` c library function.

# Use Cases & Examples ☕
Basic usage: `_printf("Format String", arg1, arg2, arg3, ...);`

`...` means indefinite number of arguments.

**Examples:**
- Basic String: `_printf("%s World\n", "Hello");`<br>
- Output `Hello World`<br>

- Print Integers: `_printf("Hey i am an integer [%i]\n", 34);`<br>
- Output: `Hey i am an integer [34]`<br>

There is more than this two options more will be described below, some include something like `b, S, p, x and X`. Not to worry will discuss this later.

### Return Value ✔️
Return value of the `_printf()` number of bytes written on the standard output upon success, `-1` failure of during program execution.<br>

### Format Specifiers ⚙️
Syntax for format specifiers almost the same as the one for `printf`, just added a few new custom format specifiers.<br>
```
_printf("%[specifier]\n", data);
...
```
A _specifier_ will be used to invoke the builtin function to execute the exepected result. The format specifier is used to signal the `_printf` function what to do with the data passed to it for processing and formating.<br>

# Specifiers 📌
Now the fun part begins<br>
|Specifier[letters]|Example|Output|
|------------------|-------|------|
|`d`|Signed integer -23| `23`|
|`i`|Signed integer 45| `45`|
|`u`|Usigned integer 344| `344`|
|`b`|Binary representation of 98| `1100010`|
|`x`|Hexadecimal representation of 62| `3e`|
|`X`|Hexadecimal_Caps representation of 62| `3E`|
|`o`|Octal representation 45| `55`|
|`s`|String of characters| `Hello world`|
|`c`|Characters| `c`|
|`S`|Non-printable chars `\n`| `\0xA`|
|`r`|Reverse string| `dlrow elloh`|
|`R`|Rot13 String translation| `xabj`|
|`p`|Memory addresses| `0x34323`|

Dont forget that all the format specifiers should be prefixed with the `%` sign in order for them to work.

Here is a walk through of all the files and their functionality in the making of the printf project.

# Directories && Files 📁
|Name|Information|Relavant Functions|
|----|-----------|--------------|
|`./test`|Directory with all the `main.c` files to test the whole program|`adv_main.c`|
|`main.h`|Header files contiaining all the standard library files, structers and all the files prototypes|`*.c`|
|`_printf.c`|Starting point for the whole project which will be used to check and call all the relevant function|`_prntf`, `_reverse_arg`, `digit_counter`, `_abs`, `_percent_arg`|
|`_printf_spec_func.c`|Has some more specifier functions which will be called according to the format specifier passed by the user|`_digit_arg`, `_pointer_hex_arg`, `_unsigned_arg`, `_string_arg`, `_char_arg`|
|`_more_printf_spec_func.c`|Again some more list of all the specifier functions which are pretty self explanatory when you read them through|`_low_hex_arg`, `_upper_hex_arg`, `_octal_arg`, `_binary_arg`, `_rot13_arg`|
|`_helper_func.c`|Include some shortened functions which can later be called multiple times in other files and functions|`get_val_ULINT`, `get_val_UINT`, `write_buffer`, `create_heap_mem`, `_isUINT`|
|`more_helper_func.c`|Some more helper functions to be used all over the program files|`get_converters_val`, `create_special_heap`, `digit_long_counter`, `_puts`, `_strlen`|
|`get_hex_val.c`|An extension of the `_custom_spec_func.c` which includes functions which are in relation with it|`get_hex_val`, `_get_base`, `base_len`|
|`_custom_spec_func.c`|Contains all the files which make it possible for all to work with the `%S` function|`_no_printable_arg`, `fill_no_printable_buff`, `_is_printable`, `_swap_func`|

All functions mentioned above are well desciribed inside where they are defined and what they do.<br>

List of all the c libray used to make the project.
`write (man 2 write)`, `malloc (man 3 malloc)`, `free (man 3 free)`, `va_start (man 3 va_start)`, `va_end (man 3 va_end)`, `va_copy (man 3 va_copy)`, `va_arg (man 3 va_arg)`.<br>
Thanks for reading upto here have fun while at it.👋 <br>
***
AUTHORS: [Mk-0-wan](https://github.com/Mk-0-wan)
       : [SplugS](https://github.com/SPlugS)
