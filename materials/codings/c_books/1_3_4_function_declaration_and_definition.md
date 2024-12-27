---
id: 1.3.4.1.declaration
aliases: []
tags:
  - book
  - reading
  - codings
created: "27-12-2024"
related to:
  - 02 Computer Science
reviewed: false
source: "[The C Book]( https://publications.gbdirect.co.uk/c_book/chapter1/description_of_example.html#:~:text=1.3.4.%C2%A0Function%20declaration%20and%20definition )"
---

parent:: 

# [[1.3.4.1.declaration|1.3.4.Function declaration and definition]]

- Declaration
- Definition

Summary:

_Declarations_ are used to _introduce_ the name of a function, its return type and the type (if any) of its arguments.

A funciton _definition_ is a declaration wiht the body of the function given too.

A function returnin no valkue should have its type declared as `void`.

A funciton taking no arguments should be declared with `void` as its arguments list, for example

```c
void func(void); { ... }
```

## Contents

### Declaration

it's basically something like `funtion prototype`

It is now strongly recommended that you do declare them (the functions) in advance

the distinction between a _declaration_ and _definition_ is that the former simply describe the type of the function and any arguments that it might take the later is where the body of a funciton is provided.

by advance declaration before the function being used, the compiler is able to check tat it is used _correctly_

The declaration describe three important things:

 - its name
 - its type
 - and the number of and tupe of its arguments.

### Definition

FORTRAN uses _subroutines_, Pascal and Algol, (and Odin) call them _procedures_.

C simply uses _function_

The body of the function is a _compound statement_, which is a sequence of other statments sorrounded by curly brackets `{}`.

