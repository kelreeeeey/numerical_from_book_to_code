---
source: 
    - "[ YouTube Video - Header files and Libraries - Kevin Lynch ](https://www.youtube.com/watch?v=5UMHbzZGQuE)"
    - "[ YouTube Video - C Modules - Tutorial on .h Header Files, Include Guards, .o Object Code, and Incremental Compilation ](https://www.youtube.com/watch?v=8KyZedtkEhk)"
material_type: c
---

# About C Headers and Libraries (by Kevin Lynch)

source: [ YouTube Video - Header files and Libraries - Kevin Lynch ](https://www.youtube.com/watch?v=5UMHbzZGQuE)
## Not in a library header file:

>Time:: 6.55

1. _private_ function prototype, constant, and macros
2. `int Global;`

_Why?_

- _private_ function prototype, constant, and macros

    Just so the _privates_ would not avaliable to external program.

- `int Global;`

    collision, duh?. it's tricky when other c files have variable called `Global`

## In a library header file:

>Time:: 8.07

 - include guard
 - other include files
 - new data types
 - public function prototypes, constants, and macros
 - `extern int global;`

_Why?_

- include guards

    make sure the include directive only runs once for each call

- other include files, 

    makes sense

- new data types

    yeahh, its pretty helpful

- public function protoypes, constants, and macros

- `extern int Global;`

# YouTube Video - C Modules - Tutorial on .h Header Files, Include Guards, .o Object Code, and Incremental Compilation

source: [ YouTube Video - C Modules - Tutorial on .h Header Files, Include Guards, .o Object Code, and Incremental Compilation ](https://www.youtube.com/watch?v=8KyZedtkEhk)

The problems:

    There a big ass functionalites that are in ONE .c file

## Modularizing Programs

### Downsides to single file programs

>Time:: 0.25-3.22

1. Single namespcae for static global identifiers

    static global identifiers have file-level namaspaces

2. Recompiling large projects can be slow, even though changes are small

    incremental compilation on a per-file basis should avoid this downside

3. Sharing code between multiple programs requires duplication of code.

    Duplication of code is generally best avoided!

4. Long files are more difficult to reason through separate of concerns.

### "Modules" in C

>Time:: 3.30-6.10


- There are not _formal modules in the C language, but the combination of a header and source file offer benefits of a module

- Header file .h contains funciton and type declarations

- Source file .c contains concrete implementations

- _Header file_ provides the interface to a module. 

    The contents of a well-defined module should treat the source file as a black box

