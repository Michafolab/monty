**0x19. C - Stacks, Queues - LIFO, FIFO**



**monty is an interpreter of Monty ByteCodes files, which is a scripting language just like Python**

![image](https://github.com/Michafolab/monty/assets/117805721/b941001b-184d-435f-b21b-bfd01bb91a9c)

![image](https://github.com/Michafolab/monty/assets/117805721/aa0cd01d-17ca-4d7c-8d33-f8757c638201)
![image](https://github.com/Michafolab/monty/assets/117805721/c1e2593e-253f-429d-a65e-13a7f8a5a96d)




monty is an interpreter of Monty ByteCodes files, which is a scripting language just like Python.

********************************************************************************************************************************************

**About the Monty language**
This is a language that contains specific instructions to manipulate data information (stacks or queues), where each instruction (called opcode) is sended per line. Files which contains Monty byte codes usually have the .m extension.

********************************************************************************************************************************************
Example (file.m):

$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
Technologies
Interpreter was written with C language
C files are compiled using gcc 4.8.4
C files are written according to the C89 standard
Tested on Ubuntu 20.04 LTS
Usage
To compile all files:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
The synopsis of the interpreter is the following:

$ ./monty [filename]
$
To run the interpreter:

$ ./monty file.m
2
1
0
0
3
2
1
$

*********************************************************************************************************************************
**Features**
Opcodes
monty executes the following opcodes:




**Opcode**	            ****************************                           ** Description**


1)     push	                                                                      Pushes an element to the stack




2)     pall**	                                                                      Prints all the values on the stack




3)     pint	**                                                                      Prints the value at the top of the stack





4)    pop                                                                          Removes the top element of the stack






5)   swap	**                                                                      Swaps the top two elements of the stack






6) queue	 **                                                                     Sets the format of the data to a queue (FIFO)






7) stack**	                                                                      Sets the format of the data to a stack (LIFO)






8) nop   **                                                                      Doesn't do anything







9) add**	                                                                        Adds the top two elements of the stack






10)  sub**	                                                                       Subtracts the top element of the stack from the second top element of the stack







11) mul	 **                                                                      Multiplies the second top element of the stack with the top element of the stack






12)  div	**                                                                       Divides the second top element of the stack by the top element of the stack





13)  mod	   **                                                                    Computes the rest of the division of the second top element of the stack by the top element of the stack






14)  pchar	  **                                                                   Prints the char at the top of the stack






15)  pstr **                                                                   	Prints the string starting at the top of the stack







16)  rotl**	                                                                    Rotates the stack to the top








17)  rotr**	                                                                    Rotates the stack to the bottom


*******************************************************************************************************************************
**Comments,**

indicated with #, are not executed by the interpreter.

When a nonextistent opcode is passed, the interpreter prints an error message and stops:

$ cat errorfile.m
push 1
pint
pcx
$ ./monty errorfile.m
1
L3: unknown instruction pcx
Return value
When there is no errors, monty returns 0. Otherwise, returns 1

****************************************************************************************************************************
Authors


ABU MOSES - GitHub


MICHAEL AFOLABI - GitHub
