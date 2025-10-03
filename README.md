# C++ Module 07 – Function and Class Templates (42 Cursus)

## Overview

This repository contains the solutions for **Module 07** of the 42 School C++ curriculum. The exercises in this module introduce and deepen your understanding of C++ templates, focusing on generic programming with function and class templates. All code follows the educational guidelines and coding conventions specified for the course.

## Learning Outcomes

- **Master C++ function and class templates** to write generic, reusable code.
- **Understand template instantiation and type deduction** for functions and classes.
- **Practice exception safety and robust memory management** in custom container implementations.
- **Explore template specialization, operator overloading, and compile-time polymorphism**.
- **Develop clean, readable, and maintainable code** using modern C++ best practices.
- **Enhance your problem-solving skills** by working through practical template-based algorithms and data structures.

## Educational Purpose

The main objectives of this module are:

- **Introduce generic programming with C++ templates** for both functions and classes.
- **Enable the creation of code that works with multiple types** without duplication.
- **Practice designing type-safe, robust abstractions** using template features.
- **Gain practical experience with template implementation strategies** including exception handling and deep copying for containers.
- **Strengthen foundational C++ skills** for future work with the STL and advanced C++ paradigms.

## Module Content and Implementation

### Exercise 00: Start with a Few Functions

**Directory:** `ex00/`  
**Main File:** `whatever.hpp`

- Implements three function templates:
  - `swap(T& a, T& b)`: Swaps the values of two parameters in place.
  - `min(const T& a, const T& b)`: Returns the smaller of two values (returns the second if equal).
  - `max(const T& a, const T& b)`: Returns the larger of two values (returns the second if equal).
- Templates are defined in the header file.
- Tested in `main.cpp` with both built-in and user-defined types.
- Demonstrates how templates enable code reuse across types supporting comparison operators.

### Exercise 01: Iter

**Directory:** `ex01/`  
**Main File:** `iter.hpp`

- Implements the function template:
  - `iter(T* array, size_t length, Func func)`: Applies a function to each element in a given array.
- Supports both const and non-const elements and functions.
- The callable can be a regular function, function object, or function template instance.
- Example usage in `main.cpp`: applies functions to arrays of various types, demonstrating template flexibility.

### Exercise 02: Array

**Directory:** `ex02/`  
**Main Files:** `Array.hpp`, optional `Array.tpp`

- Implements the class template `Array<T>`:
  - Default constructor: creates an empty array.
  - Constructor with size parameter: creates an array of specified size, elements default-initialized.
  - Copy constructor and assignment operator: deep copies to ensure independent arrays.
  - Overloaded subscript operator `[ ]` with bounds checking, throws `std::exception` on out-of-bounds access.
  - Member function `size()` returns the number of elements.
- Uses `new[]` for allocation, no preventive allocation, and never accesses non-allocated memory.
- Tested in `main.cpp` for correctness, deep copy, exception safety, and template instantiation with multiple types.

## How to Build and Run

Each exercise folder contains a `Makefile` for easy compilation.  
To build and run an exercise, for example `ex00`:

```bash
cd ex00
make
./ex00
```

Repeat for `ex01` and `ex02` with their respective executables.

```
