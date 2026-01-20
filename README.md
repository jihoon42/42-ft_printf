# ft_printf

*This project has been created as part of the 42 curriculum by jkim2.* 

---

## 1. Description

The `ft_printf` project is a mandatory assignment in the 42 core curriculum designed to mimic the behavior of the standard C library's `printf()` function. The primary goal is to master the use of **variadic functions** in C and to implement a robust formatting logic that converts various data types into character strings. This implementation focuses on core logic without implementing the buffer management of the original function.

Supported Conversions 

* 
**%c**: Prints a single character.


* **%s**: Prints a string (handles `NULL` pointers by printing `(null)`).
* 
**%p**: Prints a `void *` pointer in hexadecimal format.


* 
**%d / %i**: Prints signed base 10 integers.


* 
**%u**: Prints unsigned base 10 numbers.


* 
**%x / %X**: Prints numbers in hexadecimal (base 16) lowercase or uppercase.


* 
**%%**: Prints a literal percent sign.



---

2. Instructions 

### Compilation

The library is compiled using a `Makefile` that follows the 42 Norm, utilizing `cc` with `-Wall -Wextra -Werror` flags. The `Makefile` is designed to prevent unnecessary relinking.

```bash
# Create the library (libftprintf.a)
make

# Remove object files and the library
make fclean

```

### Development Environment & Verification

* **Working Environment**: Developed on **macOS (Apple M1 Pro)** and cross-verified in the **42 Cluster Ubuntu** environment.
* 
**Memory Management**: Extensive checks were performed to ensure no memory leaks occur.


* **macOS**: Verified using `leaks -atExit -- ./test`.
* **Ubuntu**: Verified using `valgrind --leak-check=full ./test`.



---

3. Algorithm and Data Structure (Justification) 

### Hierarchical Modular Architecture

The project is structured into two layers: **Printers** (`/printers`) for specifier-specific logic and **Utils** (`/utils`) for low-level output.

* 
**Justification**: By isolating the logic for each conversion (e.g., `%p`, `%x`) into independent files, the system becomes highly extensible. This prevents modifications in one specifier from affecting others, facilitating easier debugging and maintenance.



### Universal Base Conversion Engine (`ft_putbase_ull`)

A generalized conversion engine was implemented to handle various bases using `unsigned long long` types.

* **Justification**: Since `%u`, `%x`, `%X`, and `%p` all involve representing numbers in different bases, a single stable engine reduces code duplication. Using a recursive approach allows for correct digit ordering without the need for manual buffer allocation, which eliminates potential memory leaks and adheres to functional programming principles.

### OS-Specific Pointer Handling

The project includes a platform-dependent macro (`NULL_PTR`) to handle pointer addresses.

* **Justification**: To maintain parity with the native libc `printf`, the code detects the OS at compile-time using `#ifdef __linux__`. This ensures the library outputs `(nil)` on Linux and `0x0` on macOS when a `NULL` pointer is passed, providing behavior identical to the host system.

---

4. Resources 

### References & Documentation

* **Personal Technical Blog**: [Restarting C - ft_printf Analysis (Korean)](https://velog.io/@vendredi/%EB%8B%A4%EC%8B%9C-%EC%8B%9C%EC%9E%91%ED%95%98%EB%8A%94-C-ep.0)
* **Test Suite**: [42-ft_printf-w-test](https://github.com/jihoon42/42-ft_printf-w-test) (A custom repository created to verify function robustness).
* **C Library Documentation**: Studied `printf(3)` and `stdarg(3)` man pages for variadic argument handling.

AI Usage Disclosure 

In compliance with the 42 AI policy, AI tools were utilized as a technical thought partner for the following tasks:

* **Architectural Refactoring**: Assisted in modularizing the `check_format` function to ensure it adheres to the 25-line limit required by the Norm.
* **Edge-Case Brainstorming**: Used to identify potential pitfalls regarding `INT_MIN` and the maximum range of `unsigned long long` types.
* **Documentation Refinement**: Assisted in structuring this README and refining the technical justifications to ensure clarity and professional presentation.
* 
**Countermeasures**: All AI-suggested logic was manually reviewed, understood, and tested in both macOS and Linux environments to ensure accuracy and compliance.