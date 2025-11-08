## Questions to be aware of

### Q1
The size of an empty (no member) struct is 1. g++ treats the empty structs as if they have a single member of type `char`. ([sauce](https://gcc.gnu.org/onlinedocs/gcc/Empty-Structures.html)).

The reason is that if they are of size 0, then two objects would have the same memory address.

### Q2
There's sth called the [operator precedence](https://en.cppreference.com/w/cpp/language/operator_precedence.html) rule in C++. It dictates which operator to evaluate first. 

For the case where two operator is of the same precedence level, we will evaluate according to the associativity (e.g. "left to right" or "right to left"). For example, `a + b - c` will be evaluated as `(a + b) - c` because the associativity for suffix increment is "left to right".

### Q4
The `virtual` keyword adds a pointer to the vtable to each object. Hence, the size of the class is the size of a pointer on the machine.

### Q6
If the given pointer to `delete` keyword is not a pointer obtained from the `new` keyword, then it is undefined behaviour. The reason is that `new` works like `malloc`, which has bookkeeping data (e.g. the size) about allocated memory. Hence, using `p+1` would invalidate the assumption compilers make about the given pointer.

The diagram belows show what is allocated when calling `new[]`:
```
[ array length | element 0 | element 1 | ... ]
                  ^
                  |
           pointer returned by new[]
```