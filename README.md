# Mini Java Compiler
 
Project for MIPT Compilers course

## Current state

- Correctly scans and parses Hello World!
```
class HelloWorld {
  public static void main () {
    System.out.println (12321);
  }
}
```

- Supports programs with single entities of each type (i.e single class, single method, single parameter in any method)

### Parser&Scanner
- Add support for multiple arguments of multiple entities
- Prepare interface for unit-testing