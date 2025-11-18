This is a demonstration of using the xml-parsing example.
The code (xml.h and xml.cc) was automatically generated using vProto at https://cgen.dev
The application demonstrates the operation of both: full string and any byte-level data fragmentation.

The application uses input test data from 'input.txt' and outputs the result to the file 'output.txt'.

![](xml.png)

### cmake Build/Run/Clean:
To build, run, or clean projects using this Makefile, execute the following commands:
```bash
cmake -B build
```
```bash
cd ./build
```
```bash
make
```
```bash
make install
```
```bash
make uninstall
```

### Example of usage
- **Include** "xml.h" (#include "xml.h")
- **Declare** user functions from "xmlResult" (section "Don't forget to declare" from .h file)
- **Add Linking Library** -lxml (libxml.a)
