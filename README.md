# CRpaic: a library for *"Programming Abstractions in C"*

The **`CRpaic`** library is a C library specifically designed for studying the
book **"Programming Abstractions in C: A Second Course in Computer Science"**
(**PAIC**). This book was written by [Eric S.
Roberts](https://cs.stanford.edu/people/eroberts) in 1997, and I consider it to
be, even today, one of the best books for beginner students to learn important
concepts in algorithms and data structures, using the C language as the
implementation tool. Here is an image of the book cover:

![Foto da cada do
PAIC](https://raw.githubusercontent.com/computacaoraiz/CRpaic/master/imgs/paic.jpg)

The need for **CRpaic** arose from an introductory course on Data Structures and
Algorithms for computer science students at Universidade Vila Velha. I adopted
*PAIC* as the reference textbook for the students, but many of them struggled to
obtain, compile, and use the original PAIC library, the **`cslib`**.


# About `cslib` and `CRpaic`

In 1995, Eric S. Roberts published an introductory computer science book aimed
at complete beginners with no prior experience in C, titled **"The Art and
Science of C: A Library-Based Introduction to Computer Science"**:

![Foto da cada do
TAASOC](https://raw.githubusercontent.com/computacaoraiz/CRpaic/master/imgs/taasoc.jpg)

To facilitate student learning, Roberts created a special C library to accompany
the book, the **`cslib`**. This library provides various data types and
subprograms to make learning easier for students. In 1997, when publishing
**"Programming Abstractions in C,"** Roberts reused the same library.

The **`cslib`** is a comprehensive library offering facilities for input and
output, graphical windows, memory allocation, and many other features designed
to help students. Unfortunately, its nearly 30 years of age have rendered some
parts of it less functional today (particularly the library’s graphical
features, which can sometimes cause serious issues, including completely
freezing your computer). Nonetheless, Roberts' idea was influential, and several
courses have used the **`cslib`** as inspiration to create more modern libraries
for students. For example, Harvard University's course [CS50: Introduction to
Computer Science](https://cs50.harvard.edu/x/) developed the
[**`libcs50`**](https://github.com/cs50/libcs50), which is based on and inspired
by Roberts' **`cslib`**.

The **`CRpaic`** library was created with the same spirit: to provide a C
library that facilitates student learning. However, it is specifically designed
for studying PAIC. This focus is reflected in the library’s name: “CR” clearly
stands for "Computação Raiz", and "paic" is an acronym formed from the first
letters of the words in the book’s title. However, the **`CRpaic`** library is,
in many ways, different from the **`cslib`**. Here are some differences and
assumptions:

* It was based on both, Eric S. Roberts' **`cslib`** and Harvard University's
  **`libcs50`**;
* Most of the input functions (e.g., `get_string`, `get_char`, etc.) were based
  on **`libcs50`**;
* It is simpler than **`cslib`**: several subprograms that "made things too
  easy" for students were removed, such as the dynamic memory allocation
  subprograms. The motivation behind this is that PAIC is not an introductory
  course, and in this case, students are expected to already know or learn more
  advanced C functionalities; and
* Some functions from **`cslib`** that were merely wrappers for functions in the
  Standard C Library were removed (again, it is expected that students know or
  learn how to use the functions from the Standard C Library).

Currently, **`CRpaic`** is focused solely on studying *PAIC*, but like
**`libcs50`**, it has the potential to become a general-purpose library for C
courses, including introductory courses for students with no experience in
computing and/or C programming.


# Installation

You must have a Linux computer with development tools, particularly **make**,
the **gcc** compiler, the standard C library **glibc**, and some common C header
files. You also need access as a `root` user (usually via the **sudo** command).

## How to install?

0. Download the latest release from
   [CRpaic releases](https://github.com/computacaoraiz/CRpaic/releases);
0. Extract the file `CRpaic-*.*`
0. `cd CRpaic-*`
0. `make all`
0. `sudo make install`

By default, we install to `/usr/local` (and this is the recommend default
install directory). If you'd like to change the installation
location (and if you know what you are doing), you can run
`sudo DESTDIR=/path/to/install make install` as desired.

## How to uninstall?
Using the downloaded release (from installation):

0. `cd CRpaic-*`
0. `sudo make uninstall`

If you have installed on a non default directory, you can run
`sudo DESTDIR=/path/to/install make uninstall`.

## Troubleshooting

0. If, when compiling a program, you see `/usr/bin/ld: cannot find -lCRpaic`:
    Add `export LIBRARY_PATH=/usr/local/lib:$LIBRARY_PATH` to your
    `.bashrc`.
0. If, when compiling a program, you see `fatal error: 'CRpaic.h' file not
    found`: Add `export C_INCLUDE_PATH=/usr/local/include` to your `.bashrc`.
0. If, when executing a program, you see `error while loading shared libraries:
   libCRpaic.so.1: cannot open shared object file: No such file or directory`:
   Add `export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH` to your
   `.bashrc`.


# Usage

Link with `-lCRpaic`. See `man get_*` manual pages after installation.


# Status of development

The list below shows the development status of **`CRpaic`**, based on the
reimplementation of the `libcs50` and `cslib` libraries. The list should be
interpreted as follows:

1. If a functionality is **described as necessary**, a completion checkmark
   indicates that the functionality has already been implemented in **`CRpaic`**
   (otherwise, it is yet to be implemented);
2. If a functionality is **described as not necessary**, a completion checkmark
   indicates that the functionality **will not be implemented** in **CRpaic**;
   and
3. If a functionality is marked as uncertain, it is unclear whether it will be
   implemented in **CRpaic**.

- [x] From **`libcs50`**: Necessary.
  - [x] `string` type
  - [x] `get_char` function
  - [x] `get_string` function
  - [x] `get_int` function
  - [x] `get_long` function
  - [x] `get_long_long` function
  - [x] `get_float` function
  - [x] `get_double` function
- [ ] From **`cslib`**:
  - [ ] **`exception.h`** and **`exception.c`**: Uncertain if necessary at the
        moment.
    - [ ] `exception` type
    - [ ] `ctx_block` type
    - [ ] `RaiseException` procedure
    - [ ] `HandlerExists` predicate
  - [ ] **`extgraph.h`**: Uncertain if necessary at the moment.
    - [ ] `DrawEllipticalArc` procedure
    - [ ] `StartFilledRegion` procedure
    - [ ] `EndFilledRegion` procedure
    - [ ] `DrawTextString` procedure
    - [ ] `TextStringWidth` function
    - [ ] `SetFont` procedure
    - [ ] `GetFont` function
    - [ ] `SetPointSize` procedure
    - [ ] `GetPointSize` function
    - [ ] `SetStyle` procedure
    - [ ] `GetStyle` function
    - [ ] `GetFontAscent` function
    - [ ] `GetFontDescent` function
    - [ ] `GetFontHeight` function
    - [ ] `GetMouseX` function
    - [ ] `GetMouseY` function
    - [ ] `MouseButtonIsDown` predicate
    - [ ] `WaitForMouseDown` procedure
    - [ ] `WaitForMouseUp` procedure
    - [ ] `HasColor` predicate
    - [ ] `SetPenColor` procedure
    - [ ] `GetPenColor` function
    - [ ] `DefineColor` predicate
    - [ ] `SetEraseMode` procedure
    - [ ] `GetEraseMode` function
    - [ ] `SetWindowTitle` procedure
    - [ ] `GetWindowTitle` function
    - [ ] `UpdateDisplay` procedure
    - [ ] `Pause` procedure
    - [ ] `ExitGraphics` procedure
    - [ ] `SaveGraphicsState` procedure
    - [ ] `RestoreGraphicsState` procedure
    - [ ] `GetFullScreenWidth` function
    - [ ] `GetFullScreenHeight` function
    - [ ] `SetWindowSize` procedure
    - [ ] `GetXResolution` function
    - [ ] `GetYResolution` function
  - [ ] **`galloc.h`**: Probably not necessary.
    - [ ] `ProtectVariable` macro
    - [ ] `ProtectBlock` procedure
    - [ ] `_GCControlBlock` type
  - [x] **`gccx`**: not necessary in CRpaic
  - [ ] **`genlib.h`** and **`genlib.c`**: Mostly not necessary.
    - [x] `bool` type: unnecessary (students use <stdbool.h>)
    - [x] `string` type: necessary
    - [x] `stream` type: unnecessary at moment
    - [ ] `UNDEFINED` constant: necessary
    - [x] `GetBlock`: unnecessary (students use malloc, calloc or realloc)
    - [x] `FreeBlock`: unnecessary (students use free)
    - [x] `New`: unnecessary (students use malloc, calloc or realloc)
    - [x] `NewArray`: unnecessary (students use malloc, calloc or realloc)
    - [ ] `Error` procedure
    - [x] `repeat` macro: unnecessary (students use while)
  - [ ] **`glibrary.h`** and **`glibrary.c`**: Uncertain if necessary at the
        moment.
    - [ ] `GLRadians` function
    - [ ] `GLDegrees` function
    - [ ] `GLRound` function
    - [ ] `GLMin` function
    - [ ] `GLMax` function
    - [ ] `GLMinF` function
    - [ ] `GLMaxF` function
  - [ ] **`graphics.h`** and **`graphics.c`**: Uncertain if necessary at the
        moment.
    - [ ] `InitGraphics` procedure
    - [ ] `MovePen` procedure
    - [ ] `DrawLine` procedure
    - [ ] `DrawArc` procedure
    - [ ] `GetWindowWidth` function
    - [ ] `GetWindowHeight` function
    - [ ] `GetCurrentX` function
    - [ ] `GetCurrentY` function
  - [ ] **`random.h`** and **`random.c`**: Probably not necessary.
    - [ ] `Randomize` procedure
    - [ ] `RandomInteger` function
    - [ ] `RandomReal` function
    - [ ] `RandomChance` predicate
  - [ ] **`simpio.h`** and **`simpio.c`**: Necessary
    - [x] `GetInteger` function: implemented as `get_int`
    - [x] `GetLong` function: implemented as `get_long` and `get_long_long`
    - [x] `GetReal` function: implemented as `get_float`, `get_double` and `get_long_double`
    - [x] `GetLine` function: implemented as `get_string`
    - [ ] `ReadLine` function
  - [ ] **`strlib.h`** and **`strlib.c`**: Some functions necessary.
    - [ ] `Concat` function
    - [ ] `IthChar` function
    - [x] `SubString` function: implemented as `substring`
    - [ ] `CharToString` function
    - [ ] `StringLenght` function
    - [ ] `CopyString` function
    - [ ] `StringEqual` predicate
    - [ ] `StringCompare` predicate
    - [ ] `FindChar` function
    - [ ] `FindString` function
    - [ ] `ConvertToLowerCase` function
    - [ ] `ConvertToUpperCase` function
    - [ ] `IntegerToString` function
    - [ ] `StringToInteger` function
    - [ ] `RealToString` function
    - [ ] `StringToReal` function
  - [x] **`xcompat.h`** and **`xcompat.c`**: Not necessary
  - [ ] **`xdisplay.h`** and **`xdisplay.c`**: Uncertain if necessary at the
        moment.
    - [ ] `XDOpenDisplay` procedure
    - [ ] `XDCloseDisplay` procedure
    - [ ] `XDDisplayFD` function
    - [ ] `XDProcessXEvent` predicate
    - [ ] `XDCheckForRedraw` procedure
    - [ ] `XDSetRedrawFlag` procedure
    - [ ] `XDClearDisplay` procedure
    - [ ] `XDDrawLine` procedure
    - [ ] `XDDrawArc` procedure
    - [ ] `XDDrawText` procedure
    - [ ] `XDTextWidth` function
    - [ ] `XDSetFont` function
    - [ ] `XDSetTitle` procedure
    - [ ] `XDSetEraseMode` procedure
    - [ ] `XDStartRegion` procedure
    - [ ] `XDEndRegion` procedure
    - [ ] `XDGetMouse` procedure
    - [ ] `XDWaitForMouse` procedure
    - [ ] `XDSetWindowSize` procedure
    - [ ] `XDGetScreenSize` procedure
    - [ ] `XDGetResolution` procedure
    - [ ] `XDGetNColors` function
    - [ ] `XDSetColor` procedure
  - [ ] **`xmanager.h`** and **`xmanager.c`**: Uncertain if necessary at the
        moment.
    - [ ] `XMInitialize` procedure
    - [ ] `XMSendCommand` procedure
    - [ ] `XMGetResponse` procedure
    - [ ] `XMReleaseClient` procedure
