# Numerical Thingy _from book to code_, Calculus, Physics and allthat - written in C and Python


I decide to learn C by solving Calculus and Physics problem
found in any book, mainly from what i got in class(es) as undergrad.
Geophysics student

So please bare with the _MeEsSy_ C code. Also a disclaimer, i will make a
bunch of typo, it is just me bad at typing, i'm working on it.

source: 
- [2020 - Calculus II - After Mid Term]( https://drive.google.com/drive/folders/1mBOdVSwoBwY-C8VFbK0Sj1ZoNFnRjppd?usp=drive_link )
>**NOTE**: The source currently in private mode, i'll make the public one ASAP

## How i approach this thing.

### Background
1. i need to:
- Learn C
- Being able to integrate C and my mother language Python as she's being so slow for some reason.
- it is just fun to learn new language, especially when you was so traumatized by C++ back then.
- also some bash scripting to make life more easy.

2. As i implicityly said before, i'm coming from python, so the c codes written would be smelled like a snake :)

### Now get to my point

here's how i write the code
1. Read some book
2. look up for the problems
3. try to solve it using pencil and papers
4. code the problem and solution in C
5. ofc compile and check the results
6. write a wrapper for python


# Logs

## 26/12/2024

Add more subdirectories for the sake of better separation

additons:

- bins/
    will be holdin any final program sourced directly from `source/*.c`

- material/
    will be containing any source material, planned to be in markdown formats but pdfs or even pptx would ok too

- python_libs/
    will be containing by the mid representation of shared-object loaded in python class so the `./main.py` could read it.

- shared_objects/
    the compiled shared object for python from `source/*.c`

## 27/12/2024

- i think i wrote the zig version of problem: `area within interval`

- tried to messing up with shared objects in python for problem `area within interval`, and i coudln't not get things run as i expected.
