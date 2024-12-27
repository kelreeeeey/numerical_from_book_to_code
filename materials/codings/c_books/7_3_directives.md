---
id: 7.3. Directives
aliases: []
tags:
  - book
  - reading
  - codings
created: "27-12-2024"
related to:
  - 02 Computer Science
reviewed: false
source: "[The C Book]( https://publications.gbdirect.co.uk/c_book/chapter7/directives.html )"
---

parent:: 

# [[7.3. Directives]]

Directives r always introduced by a line that starts with `#` char.

Optionally preceded by white space character, although it is not common practice to indent the `#`.

| Directive | Meaning |
| --------- | --------------------- |
| `#include` | include a source file |
| `#define` | define a macro        |
| `#undef` | undefine a macro        |
| `#if`     | conditional compilation        |
| `#ifdef` |  conditional compilation       |
| `#ifndef` |  conditional compilation       |
| `#elif` |  conditional compilation       |
| `#else` |  conditional compilation       |
| `#endif` |  conditional compilation       |
| `#line` |  control error reporting       |
| `error` |  force an error massage       |
| `#pargam` | used for implementation dependent controll       |
| `#` | null directive; no effect |
    _Table 7.1. Preprocessor directives_

## Contents

### `# define`

there are two (2) ways of defining _macros_

```c
#define FMAC(a, b) // a here, then b

#define NONFMAC // some text here
```

after those definitions, they can be used as follows, with the effect of the macro replacement shown in comments:

```c
NONFMAC // stands for non function macros
    /* some text here */

FMAC(first_text, some_more)
    /* frist_text here, then some_more here */
```

The scope of the names of the formal parameters is limited to the body of the `#define` directive.

for both forms of macro, leadind or trailing with whitespace around the replacement text is discarded.

A corious ambiguity arises with macros:

- How do u define a non-funciton macro whose replacement text happens to start with the opening paranthesis characters?
    if the definition of the macro but a simple replacement macro instead.
- When u use function-like macros, there's no equivalent restriction.

The standard allows either type of macro to be redefined at any time, using another `#define`, 

```c
# define XXX abc /* comment */ def hij
# define XXX abc def hij

```
because comment is a form of white space. the token sequence for both cases (w-s stands for a white-space token) is:

```c
# w-s define w-s XXX w-s abc w-s def w-s hij w-s
```




