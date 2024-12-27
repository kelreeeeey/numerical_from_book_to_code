---
source: me_brain
note_type: brain_log
---

# Me Brain Log

This file is my brain dump. i will put everything i learned in in here.

The contents of this file will be separated per day as a level 1 heading of markdown.


## 27-12-2024

i learn about what the hell is header file, why it bother exists, and how propely make use of it.

I've watched 2 YouTube videos about c header file, and C book (online book about C).

notes:

 - [About C Headers and Libraries](../materials/codings/about_c_headers_and_libraries.md)

 - [c_books - Directives](../materials/codings/c_books/7.3. Directives.md)

     >NOTE: `c_books/` are copied from my obsidian_vaults, they're might be not as updated as the other notes

Key Points:

 - header file basically is just a encapsulation of privacy related to declaration and implementation.
 - header file, by recommendation and conventionality, expected to be having declaration of something like `typedef` or a `function` that later will, the correspondence(s) will be implemented in the .c file
 - header file should contains `include guards`.
 - `include guards` basically is a way that we tell our program to not declare certain thing twice, cz that is illegal due to C law.
