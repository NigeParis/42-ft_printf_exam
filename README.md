# 42-ft_printf
This project is pretty straight forward. It's about recoding the printf function in C, using my own library of re-coded functions, and learning how to manipulate variadic functions and it's arguments.<br>

The prototype of ft_printf() is:<br>
int ft_printf(const char *, ...);<br>

Here are the requirements:<br>
• Don’t implement the buffer management of the original printf().<br>
• Your function has to handle the following conversions: cspdiuxX%<br>
• Your function will be compared against the original printf().<br>
• You must use the command ar to create your library.<br>
Using the libtool command is forbidden.<br>
• Your libftprintf.a has to be created at the root of your repository.<br>
<br>
You have to implement the following conversions:<br>
• %c Prints a single character.<br>
• %s Prints a string (as defined by the common C convention).<br>
• %p The void * pointer argument has to be printed in hexadecimal format.<br>
• %d Prints a decimal (base 10) number.<br>
• %i Prints an integer in base 10.<br>
• %u Prints an unsigned decimal (base 10) number.<br>
• %x Prints a number in hexadecimal (base 16) lowercase format.<br>
• %X Prints a number in hexadecimal (base 16) uppercase format.<br>
• %% Prints a percent sign.<br>

#ft_printf_exam
