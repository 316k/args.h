# args.h

Minimalist args parsing library inspired from the Plan9 libc.h macros

## Usage

Read `example.c` and `args.h` for examples.

## Example

```bash
$ gcc example
$ ./example --string test-1 --decimal 250 -f 10 -s test-2 end of the options
Initial argc=13
  str: test-1
  int: 250
  float: 10.000000
  str: test-2
Final argc=4
New args :
  0: end
  1: of
  2: the
  3: options
$ ./example --string test-1 --decimal 250 -f 10 -s test-2 end of the options
Initial argc=14
./example: wrong argument: --test
```
