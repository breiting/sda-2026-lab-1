# Lab 01 — Guided Checkpoints

## Checkpoint 1 — Clone and inspect

- [ ] Clone the published Lab 01 repository: `git clone <URL>` (URL provided in class).
- [ ] Enter the repository and run `git status`, `git log --oneline`, and `git remote -v`.
- [ ] Locate `CMakeLists.txt`, `include/`, `src/`, `app/`, and `tests/`.
- [ ] Find the function declaration, implementation, and tests for `ClampVoltage`.
- [ ] Explain why `git init` is not needed after cloning.

### QUESTIONS

- What is the difference between a Git repository and a working directory?
- What is the difference between `git init` and `git clone`?
- Where do you find the function's public interface?

## Checkpoint 2 — Build and run the existing tests

- [ ] Inspect the CMake file
- [ ] Configure: `cmake -S . -B build`.
- [ ] Build: `cmake --build build`.
- [ ] Run the application: `./build/voltage_demo`.
- [ ] Run the tests: `ctest --test-dir build --output-on-failure`.
- [ ] Observe: **the code compiles, but some tests fail**. This is intentional.
- [ ] Check `git status` and verify that `build/` and `.cache/` are ignored.

### QUESTIONS

- What is the difference between compilation success and passing tests?
- What do `-S` and `-B` mean?
- What does `target_link_libraries` do?

## Checkpoint 3 — Investigate the failing tests

- [ ] Read `tests/test_voltage_utils.cpp` **without modifying it**.
- [ ] Identify the expected behavior for values below, inside, and above the allowed interval.
- [ ] Inspect `include/sda/VoltageUtils.hpp` and `src/VoltageUtils.cpp`.
- [ ] Explain why the existing implementation does not satisfy the tests.
- [ ] Run `git diff` and verify that the test file is unchanged.

### QUESTIONS

- What do `EXPECT_DOUBLE_EQ` and a failing assertion tell us?
- Why are boundary cases important?
- Why should we fix the implementation rather than weaken the tests?

## Checkpoint 4 — Fix the implementation and make all tests pass

- [ ] Implement `ClampVoltage` **only in `src/VoltageUtils.cpp`**.
- [ ] Respect the documented precondition `minVoltage <= maxVoltage`.
- [ ] Rebuild: `cmake --build build`.
- [ ] Run: `ctest --test-dir build --output-on-failure`.
- [ ] Verify that **all provided tests pass** and the demo prints the clamped voltage.

### QUESTIONS

- How do the function declaration and definition differ?
- What is the purpose of the `sda` namespace?

## Checkpoint 5 — Inspect and commit the solution

- [ ] Run `git status` and `git diff`.
- [ ] Stage only the implementation: `git add src/VoltageUtils.cpp`.
- [ ] Commit: `git commit -m "Fix voltage clamping"`.
- [ ] Review the history with `git log --oneline` and check `git status` again.

### QUESTIONS

- What is the difference between working tree, staging area, and commit?
- What do `git add`, `git commit`, `git pull`, and `git push` do?
- Why can we commit locally without GitHub access?

## One Optional Bonus — Implement and test a new function

Implement `bool IsVoltageInRange(double value, double minVoltage, double maxVoltage)` in the `sda` namespace. Return `true` when `value` is inside the **inclusive** interval and `false` otherwise. Assume `minVoltage <= maxVoltage`.

- [ ] Add the declaration to `include/sda/VoltageUtils.hpp`.
- [ ] Add the implementation to `src/VoltageUtils.cpp`.
- [ ] **Write your own GoogleTests** in `tests/test_voltage_bonus.cpp` (create this file). Cover a value below the interval, a value inside it, a value above it, and both boundaries.
- [ ] Add a new test executable to `CMakeLists.txt` for the bonus tests and register it with CTest. Leave `tests/test_voltage_utils.cpp` unchanged.
- [ ] Rebuild and run all tests. Commit the bonus changes separately.

### QUESTIONS

- How does adding a new function differ from fixing an existing one?
- What must be updated when adding a new test source file?
