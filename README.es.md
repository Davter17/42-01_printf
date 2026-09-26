# ft_printf - Proyecto de 42 School

Una reimplementación de la función estándar `printf` en C.

## Descripción General

Este proyecto recrea el comportamiento de la función estándar `printf`, manejando especificadores de formato para caracteres, cadenas, enteros, enteros sin signo, números hexadecimales, punteros y el signo de porcentaje.

## Estructura del Proyecto

```
printf/
├── src/           # Archivos fuente (.c)
├── inc/           # Archivos de cabecera (ft_printf.h)
├── test/          # Suite de pruebas
├── .obj/          # Archivos objeto compilados (generados)
├── .deps/         # Dependencias externas (generadas)
├── Makefile       # Configuración de compilación
└── libftprintf.a  # Biblioteca compilada (generada)
```

## Dependencias

Este proyecto depende de [libft](https://github.com/Davter17/42-00_Libft.git), que se clona automáticamente desde GitHub durante la compilación.

## Compilación

### Compilación básica
```bash
make
```
Clona libft (si es necesario) y compila todas las funciones en `libftprintf.a`.

### Compilación limpia
```bash
make re
```
Elimina todos los archivos compilados, dependencias y recompila todo.

### Limpieza
```bash
make clean    # Elimina el directorio .obj/
make fclean   # Elimina .obj/, .deps/ y libftprintf.a
```

## Pruebas

Ejecuta la suite de pruebas completa:
```bash
make test
```

Esto compila y ejecuta pruebas para todos los especificadores de formato, comparando valores de retorno y salida con el `printf` estándar.

### Estructura de Pruebas
Las pruebas están organizadas en archivos separados por categoría:
- `test_printf.c` - Todos los especificadores de formato (%c, %s, %p, %d, %i, %u, %x, %X, %%)

## Especificadores de Formato

| Especificador | Descripción |
|---------------|-------------|
| `%c` | Carácter |
| `%s` | Cadena (maneja NULL) |
| `%p` | Dirección de puntero (hex con prefijo 0x, maneja NULL) |
| `%d` | Entero decimal con signo |
| `%i` | Entero decimal con signo |
| `%u` | Entero decimal sin signo |
| `%x` | Hexadecimal (minúsculas) |
| `%X` | Hexadecimal (mayúsculas) |
| `%%` | Signo de porcentaje |

## Ejemplo de Uso

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s, tienes %d años\n", "Mundo", 42);
    ft_printf("Puntero: %p\n", main);
    ft_printf("Hex: %x | %X\n", 255, 255);
    ft_printf("Sin signo: %u\n", 4294967295U);
    return 0;
}
```

## Compilación con Tu Proyecto

```bash
# Compilar ft_printf (incluye libft)
make

# Compilar tu proyecto con ft_printf
gcc -I./inc -I./.deps/libft/inc tu_programa.c -L. -lftprintf -o tu_programa
```

## Calidad del Código

- Cumple con los estándares de norminette de la escuela 42
- Sin fugas de memoria (verificado con valgrind)
- Maneja casos extremos (cadenas NULL, INT_MIN, punteros NULL)
- Cobertura de pruebas exhaustiva

## Requisitos

- Compilador GCC
- Make
- Git (para clonar libft)
- Entorno tipo Unix (Linux, macOS o WSL)

## Licencia

Este proyecto forma parte del plan de estudios de la escuela 42 y sigue sus directrices académicas.
