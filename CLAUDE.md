# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

CRpaic is a C teaching library (Linux only) for studying Eric Roberts' *Programming Abstractions in C* (PAIC). It is inspired by Roberts' `cslib` and Harvard's `libcs50` (the `get_*` input functions derive from `libcs50`). The `v2` branch is a restructuring into modules with a `crpaic_` prefix on all public symbols (e.g. `crpaic_get_int`, `crpaic_max`); `master` holds the older flat v1 API (`get_int`, `concat`, ...). Progress per module is tracked in `TODO.md`; the README status list refers to v1-era names.

## Build

```sh
make                 # static lib/libCRpaic.a + shared lib/libCRpaic.so.<VERSION> + gzipped man pages
make static | shared | mans
make MODE=DEBUG      # -ggdb -O0 -DDEBUG (default MODE=PRODUCTION, -O3)
make CSTD=gnu17      # C standard (default gnu17; GNU extensions are required, see below)
make version
make clean
sudo make install    # PREFIX=/usr/local by default; DESTDIR supported; runs ldconfig
sudo make uninstall
```

- Compiler flags include `-Wall -Wextra -Werror -Wconversion -Wunused-result`: any warning, including implicit narrowing conversions, breaks the build.
- Sources are discovered recursively (`find src -name '*.c'`); new `.c` files under `src/` are built automatically, with objects mirrored into `build/` (`*.o` and `*.pic.o`).
- **Version must match in two places**: `CRPAIC_VERSION_STRING` in `include/CRpaic/CRpaic_version.h` (parsed by the Makefile with awk) and `src/VERSION.TXT`. The Makefile aborts if they differ. Bump both together (also the MAJOR/MINOR/PATCH macros).
- Linked libs: `-lm -lX11 -lcrypt`.

## Tests

`tests/` uses CUnit (`-lcunit`) and links against the **installed** library (`-lCRpaic`), not the in-tree build — run `sudo make install` (or point `LIBRARY_PATH`/`LD_LIBRARY_PATH`/`C_INCLUDE_PATH` at a local install; `tests/env.sh` is an example) first.

```sh
cd tests && make     # builds and runs ./tests, then cleans
```

Note: the test suite is still from v1 (tests target old names like `get_int`) and has not been ported to the v2 `crpaic_*` API. There is no single-test runner — tests are CUnit cases registered in `tests/tests.c`. A full rewrite is planned (proposal: cmocka, one binary per submodule, in-tree linking, sanitizers, coverage, fault injection, compile-fail tests) but awaiting the maintainer's decisions — see the "Code Review and Test Overhaul" section of `TODO.md` and `historico/20261112_revisao_codigo.txt`, which also lists known bugs (B1–B9) and open I/O design questions (D1–D8).

## Workflow

- Two repositories: this one (code) and `~/CRpaic_docs` (user documentation, Sphinx/Read the Docs). API changes need updates in both (man pages here, guides there).
- Propose changes and wait for the maintainer's review and approval before editing either repository. The maintainer commits and pushes manually — suggest a commit message instead of committing.
- `historico/AAAAMMDD.txt` are the maintainer's hand-written session logs (edited in Emacs); don't edit them. Write session summaries to separate files in `historico/` only when asked.
- When presenting tables, use plain ASCII tables (max. 80 columns), never Markdown tables. The maintainer writes in Brazilian Portuguese.

## Architecture

- `include/CRpaic.h` is the single umbrella header clients use. It includes `CRpaic/CRpaic_version.h`, `CRpaic/CRpaic_globals.h` (the `string` typedef and `NOPROMPT`), and one aggregate header per module (`CRpaic/io/CRpaic_io.h`, `CRpaic/math/CRpaic_math.h`).
- Each module is a directory under both `include/CRpaic/<module>/` and `src/CRpaic/<module>/`, split into submodules named `CRpaic_<module>_<submodule>.{h,c}` (e.g. `io/CRpaic_io_charstr`, `math/CRpaic_math_prime`). The module aggregate header just includes its submodule headers. A new submodule needs: header, implementation, an `#include` in the module aggregate header, and (for a new module) an `#include` in `CRpaic.h`.
- Headers are included with angle brackets relative to `include/` (`#include <CRpaic/math/CRpaic_math_minmax.h>`), since the build uses `-Iinclude` and installed headers keep the same tree.
- Type-generic APIs (e.g. `crpaic_max`, `crpaic_min`) are a family of per-type functions with suffixes (`_c`, `_uc`, `_si`, `_usi`, `_i`, `_ui`, `_li`, `_uli`, `_lli`, `_ulli`, `_f`, `_d`, `_ld`) plus a dispatch macro using `_Generic`, GCC statement expressions, `__auto_type` and `__builtin_types_compatible_p` with a `_Static_assert` that both arguments have the same type. This is why the build requires GNU C (`gnu17`).
- `todo/` holds planned/draft modules (string, char, db, algorithms, errors) not yet part of the build. `experimental/` and `gpt/` are scratch/reference material, not built.

## Conventions

- Every file starts with a header comment block (`File`, `Date`, `GitHub`, description). Use the skeletons in `templates/` for new headers/implementations. `src/sections.txt` defines the section order used inside interfaces and implementations (feature macros/includes → constants/globals → types → declarations → definitions → misc, each split private/exported).
- Public subprograms are documented in headers with a `Function: / Usage: / ----` comment block; implementations repeat a shorter version.
- Function definition style: return type on its own line, then `name (args)`, braces on their own lines, 4-space indentation, 80-column lines.
- Each public function gets a man page in `docs/<name>.3` (groff, section 3; see `docs/crpaic_TEMPLATE`). Example programs live in `docs/examples/`; to embed one in a man page, escape it with `sed -e 's/\\/\\\\/g' -e 's/"/\\(dq/g' FILE.c`. `make mans` regenerates the `.3.gz` files, which are what `make install` installs.
- `build/` and `lib/` contents are generated; don't store files there.
- CRpaic's `get_string` interface is intentionally incompatible with libcs50's; don't align it.
