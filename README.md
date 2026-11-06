# Lab 01 — Voltage Toolkit

Build and test a small C++17 utility library for electrical measurements.

## Learning outcomes

- Inspect a cloned Git repository and navigate its structure.
- Configure and build a CMake project; distinguish compilation from test execution.
- Understand function declarations, implementations, namespaces, and library targets.
- Diagnose failing GoogleTests and fix production code without changing the provided tests.
- Use `git status`, `git diff`, `git add`, `git commit`, and `git log`.

## Project layout

```text
CMakeLists.txt
include/sda/VoltageUtils.hpp
src/VoltageUtils.cpp
app/main.cpp
tests/test_voltage_utils.cpp   # Provided core tests: do not edit
TODO.md
```

## Build and run

```bash
cmake -S . -B build
cmake --build build
./build/voltage_demo
ctest --test-dir build --output-on-failure
```

GoogleTest is fetched on first configuration via CMake FetchContent, so internet access may be required.

## Assignment

Follow [TODO.md](TODO.md) in order. At each **STOP & REVIEW**, pause for a shared discussion. **Do not change `tests/test_voltage_utils.cpp`.** Your goal is to make all provided tests pass by fixing `src/VoltageUtils.cpp`.

**Definition of done:** The project builds; all provided tests pass; only production code was changed for the core task; the solution is committed locally.

## Optional bonus

Implement `IsVoltageInRange(...)` and create your **own** tests in a separate test file. See the single bonus task in [TODO.md](TODO.md).
