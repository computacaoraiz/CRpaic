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
  - [x] ✔️ `crpaic_get_string`
  - [x] ✔️ `crpaic_vget_string`
  - [x] ✔️ `crpaic_get_char`
  - [ ] ⏹️ unit tests
  - [ ] 🔁 comments in headers and implementations
  - [ ] 🔁 man pages
  - [ ] ⏹️ read the docs
- [ ] 🔁 numbers
  - [ ] ⏹️ `crpaic_get_short`
  - [x] ✔️ `crpaic_get_int`
  - [x] ✔️ `crpaic_get_long`
  - [x] ✔️ `crpaic_get_long_long`
  - [x] ✔️ `crpaic_get_float`
  - [x] ✔️ `crpaic_get_double`
  - [x] ✔️ `crpaic_get_long_double`
  - [ ] ⏹️ unit tests
  - [ ] 🔁 comments in headers and implementations
  - [ ] 🔁 man pages
  - [ ] ⏹️ read the docs
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
- [x] ✔️ mathematical constants
- [ ] 🔁 arithmetic utilities
  - [x] ✔️ `crpaic_is_even`
  - [x] ✔️ `crpaic_is_odd`
  - [ ] ⏹️ `crpaic_gcd`
  - [ ] ⏹️ `crpaic_lcm`
  - [ ] ⏹️ `crpaic_clamp`
  - [x] ✔️ `crpaic_max`
  - [x] ✔️ `crpaic_min`
  - [ ] ⏹️ unit tests
  - [ ] 🔁 comments in headers and implementations
  - [ ] 🔁 man pages
  - [ ] ⏹️ read the docs
- [ ] 🔁 prime number utilities
  - [x] ✔️ `crpaic_is_prime`
  - [x] ✔️ `crpaic_next_prime`
  - [ ] ⏹️ `crpaic_prev_prime`
  - [ ] ⏹️ unit tests
  - [ ] 🔁 comments in headers and implementations
  - [x] 🔁 man pages
  - [ ] ⏹️ read the docs

## Code Review and Test Overhaul (2026-11-12)
Full review of the v2 code base (details, evidence and proposals in
`historico/20261112_revisao_codigo.txt`). Decisions on the proposals are
pending. ([go back to CRpaic Modules list](#crpaic-modules))

- [ ] ⏹️ confirmed bugs (write a regression test first, then fix)
  - [ ] ⏹️ B1: `crpaic_is_prime_ulli` overflow in `i * i <= n` (hangs on
        64-bit primes; use `i <= n / i`)
  - [ ] ⏹️ B2: `signed char`/`int8_t` and `bool` not handled by the `_Generic`
        macros (`crpaic_max` silently returns `long double`)
  - [ ] ⏹️ B3: Makefile does not include `*.pic.d` (stale shared library)
  - [ ] ⏹️ B4: `install` with `DESTDIR` (absolute symlinks, no `man3` dir,
        `ldconfig`)
  - [ ] ⏹️ B5: v1 man pages installed; no man pages for `crpaic_get_*`
  - [ ] ⏹️ B6: SONAME should be `libCRpaic.so.2`, not `libCRpaic.so.2.0.0`
  - [ ] ⏹️ B7: NaN semantics of `crpaic_max`/`crpaic_min`
  - [ ] ⏹️ B8: macro hygiene (`__x`/`__y` names)
  - [ ] ⏹️ B9: remove unused `-lX11 -lcrypt` from `LDLIBS`
- [ ] ⏸️ I/O design decisions (D1-D8: `NOPROMPT`, unbuffered stdout, memory
      retained by `get_*`, `free()` on `get_string` results, scientific
      notation/locale, sentinels)
- [ ] ⏸️ new test infrastructure (proposal: cmocka, one binary per
      submodule, `make check`, sanitizers, coverage, fault injection,
      compile-fail tests, fuzzing, install tests, `make release-check`)
  - [ ] ⏹️ Phase 0: Makefile fixes + test infrastructure
  - [ ] ⏹️ Phase 1: math tests (reproduce B1, B2, B7 first)
  - [ ] ⏹️ Phase 2: I/O refactor (`FILE *` core) + I/O tests
  - [ ] ⏹️ Phase 3: sanitizers, coverage, CI
  - [ ] ⏹️ Phase 4: fuzzing, install tests, `make release-check`
