# ft_printf - 42 School Project

A reimplementation of the standard `printf` function in C.

## Overview

This project recreates the behavior of the standard `printf` function, handling format specifiers for characters, strings, integers, unsigned integers, hexadecimal numbers, pointers, and the percent sign.

## Project Structure

```
printf/
├── src/           # Source files (.c)
├── inc/           # Header files (ft_printf.h)
├── test/          # Test suite
├── .obj/          # Compiled object files (generated)
├── .deps/         # External dependencies (generated)
├── Makefile       # Build configuration
└── libftprintf.a  # Compiled library (generated)
```

## Dependencies

This project depends on [libft](https://github.com/Davter17/42-00_Libft.git), which is automatically cloned from GitHub during compilation.

## Compilation

### Basic compilation
```bash
make
```
Clones libft (if needed) and compiles all functions into `libftprintf.a`.

### Clean build
```bash
make re
```
Removes all compiled files, dependencies, and recompiles everything.

### Cleaning
```bash
make clean    # Removes .obj/ directory
make fclean   # Removes .obj/, .deps/, and libftprintf.a
```

## Testing

Run the complete test suite:
```bash
make test
```

This compiles and runs tests for all format specifiers, comparing return values and output against the standard `printf`.

### Test Structure
Tests are organized in separate files by category:
- `test_printf.c` - All format specifiers (%c, %s, %p, %d, %i, %u, %x, %X, %%)

## Format Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Character |
| `%s` | String (handles NULL) |
| `%p` | Pointer address (hex with 0x prefix, handles NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

## Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old\n", "World", 42);
    ft_printf("Pointer: %p\n", main);
    ft_printf("Hex: %x | %X\n", 255, 255);
    ft_printf("Unsigned: %u\n", 4294967295U);
    return 0;
}
```

## Compilation with Your Project

```bash
# Compile ft_printf (includes libft)
make

# Compile your project with ft_printf
gcc -I./inc -I./.deps/libft/inc your_program.c -L. -lftprintf -o your_program
```

## Code Quality

- Complies with 42 school's norminette standards
- No memory leaks (verified with valgrind)
- Handles edge cases (NULL strings, INT_MIN, NULL pointers)
- Comprehensive test coverage

## Requirements

- GCC compiler
- Make
- Git (for cloning libft)
- Unix-like environment (Linux, macOS, or WSL)

## License

This project is part of the 42 school curriculum and follows its academic guidelines.
