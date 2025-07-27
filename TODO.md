# TODO list
The lists below show the status of the work being done in the project and some
short and medium term goals. The content is roughly organized by CRpaic module.

Legend for the tasks:
* ⏹️ Not started
* 🔁 Started
* ⏸️ Paused
* ✔️ Finished

## CRpaic Modules
The list below contains the proposed modules for CRpaic. Some are already in
development, while others are still in the planning stages.

- [ ] 🔁 [I/O Module](#io-module)
- [ ] 🔁 [Math Module](#math-module)
- [ ] ⏹️ Char Module
- [ ] ⏹️ String Module
- [ ] ⏹️ Date/Time Module
- [ ] ⏹️ Data Structure Module
- [ ] ⏹️ Algorithms Module
- [ ] ⏹️ Database (SQLite) Module
- [ ] ⏹️ ICU (Unicode) Module
- [ ] ⏹️ Graphic (Raylib) Module

## I/O Module
The I/O module aims to provide functions that allow obtaining different types of
user input (char, string, integer, real numbers, dates, etc.) in a friendly way
for the beginning student. ([go back to CRpaic Modules list](#crpaic-modules))

- [ ] 🔁 char and strings
  - [x] `crpaic_get_string`
  - [x] `crpaic_vget_string`
  - [x] `crpaic_get_char`
  - [ ] ⏹️ unit tests
  - [ ] ⏹️ comments in headers and implementations
  - [ ] ⏹️ man pages
  - [ ] ⏹️ read the docs
- [ ] numbers
  - [ ] ⏹️ `crpaic_get_short`
  - [x] `crpaic_get_int`
  - [x] `crpaic_get_long`
  - [x] `crpaic_get_long_long`
  - [x] `crpaic_get_float`
  - [x] `crpaic_get_double`
  - [x] `crpaic_get_long_double`
  - [ ] unit tests
  - [ ] 🔁 comments in headers and implementations
  - [ ] 🔁 man pages
  - [ ] read the docs
- [ ] ⏹️ dates
  - [ ] ⏹️ `crpaic_get_date`
  - [ ] ⏹️ `crpaic_get_time`
  - [ ] ⏹️ `crpaic_get_datetime`
  - [ ] ⏹️ `crpaic_get_datetimetz`
  - [ ] ⏹️ `crpaic_get_sys_date`
  - [ ] ⏹️ `crpaic_get_sys_time`
  - [ ] ⏹️ `crpaic_get_sys_datetime`
  - [ ] ⏹️ `crpaic_get_sys_datetimetz`
  - [ ] ⏹️ unit tests
  - [ ] ⏹️ comments in headers and implementations
  - [ ] ⏹️ man pages
  - [ ] ⏹️ read the docs

## Math Module
The math module aims to provide common functions and utilities for handling
various basic mathematical operations. It also provides various mathematical and
physical constants. ([go back to CRpaic Modules list](#crpaic-modules))
- [x] mathematical constants
- [ ] 🔁 arithmetic utilities
  - [x] `crpaic_is_even`
  - [x] `crpaic_is_odd`
  - [ ] `crpaic_gcd`
  - [ ] `crpaic_lcm`
  - [ ] `crpaic_clamp`
  - [x] `crpaic_max`
  - [x] `crpaic_min`
  - [ ] unit tests
  - [ ] 🔁 comments in headers and implementations
  - [ ] 🔁 man pages
  - [ ] read the docs
- [x] prime number utilities
  - [x] `crpaic_is_prime`
  - [x] `crpaic_next_prime`
  - [ ] unit tests
  - [ ] 🔁 comments in headers and implementations
  - [x] 🔁 man pages
  - [ ] read the docs
