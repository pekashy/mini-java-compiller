# Mini Java Compiler
 
Project for MIPT Compilers course

## Current state

- Implemented scanning&parsing grammar according to https://github.com/akhtyamovpavel/CompilersCourse/blob/master/reqs-draft.md
- Correctly parses example program:
```
class Factorial {
  public static void main () {
    System.out.println (new Fac ().ComputeFac (10));
  }
}

class Fac {
  public int ComputeFac (int num) {
    assert (num > -1);
    int num_aux;
    if (num == 0)
      num_aux = 1;
    else 
      num_aux = num * this.ComputeFac (num-1);
    return num_aux;
  }
}
```
- Added several visitors, interprets programs like the simplified one:
```
class Factorial {
  public static void main () {
    int num_aux;
    assert(false);
    num_aux = 1;
    if ( 1 == 1)
        num_aux = 2;
    while(1)
        System.out.println(num_aux);
  }
}
```
- Implemented Symbol table structure
- Symbol Table Visitor
