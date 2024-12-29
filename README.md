# Numerical Thingy _from book to code_, Calculus, Physics and allthat - (mainly) written in C, Python and other language i locked my eyes into.

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

## How to, idk, use it?

all of the code that are written in C and Zig are located in `source/` directory. per 28/12/2014, i've wrote these:

```raw
  Dec 27 21:55 area_within_interval.c
  Dec 27 21:54 area_within_interval.h
  Dec 28 04:05 area_within_interval.zig
  Dec 27 22:59 example_area_within_interval.c
  Dec 28 02:00 function_as_parameter.zig
  Dec 27 20:51 problem_set_4_1.c
  Dec 27 21:36 problemsetA_13_21.c
```
most of c codes above were my initial attempt on learning C throught calculus material i learned in Uni.

The zig code [area_within_interval.zig](source/area_within_interval.zig) is my first attempt to re-write the [area_within_interval.c](source/area_within_interval.c) and [area_within_interval.h] in Zig.

### To run it?.. (im sorry im just a rookie)

i'm on Windows, here's the prereqs.:

- im using gcc from [StrawberryPerl 5.40](https://strawberryperl.com/) but i'm pretty sure y'all can use gcc from MINGW or Cygwin or clang too.

- im using [ Zig version 0.14.0-dev.2293+6d781e095 ](https://ziglang.org/download/)

- im using [python 3.10](https://www.python.org/downloads/release/python-3100/)

    - python dependency, install it using y'all fav package manager.

        - [cffi==1.17.0](https://cffi.readthedocs.io/en/latest/whatsnew.html#v1-17-0)

The python code are wrapped by the `cffi` from either directly from c scripts and headers, or from the
shared objects.


#### The C scripts

The `build_source.sh` will compile the C scripts to executables located in `bins/` sub-dir
and shared objects (later for python usage) located in `shared_objects/` sub-dir

The script also empties the `bins/` and `shared_objects` before produces new executables and shared objects.

from root directory, make the bash script `build_source.sh` executable.

```bash
chmod u+x build_source.sh
```

>NOTE: for now, i just use script instead of make/cmake, but let see where it will get me to

then, just run the `build_source.sh` by run one of the following command on y'all shell

```
$ ./build_source.sh
$ .\build_source.sh
bash build_source.sh
```

#### The Zig scripts

from root directory just `zig run source/zig_script.zig`

#### The Python scripts

All of python codes are wrapped by the `cffi` and separated in modules based on the problem
from specified materials located in `materials/non_codings/` sub-dir

see `main.py` for example. y'all can play with it.

run the main.py as a regular python script:

```
python main.py # if you on Windows
python3 main.py # if you on MacOS or Linux
```
