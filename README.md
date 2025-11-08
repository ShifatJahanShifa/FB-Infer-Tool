# FB-Infer-Tool
Contains necessary contents to present `FB Infer` tool in Software Maintenance course.

## Introduction
Infer is a static analysis tool to detect bugs in java, c, c++, objective c code. if you give Infer some Java or C/C++/Objective-C code it produces a list of potential bugs. 

Infer is a static code analysis tool for Java, C, C++, and Objective-C, written in OCaml. It was first developed at Facebook and open-sourced in 2015. Since then, it has gained popularity beyond Facebook, being adopted by other large companies. 

**Android and Java**
Infer checks for null pointer exceptions, resource leaks, annotation reachability, missing lock guards, and concurrency race conditions in Android and Java code.

**C, C++, and iOS/Objective-C**
Infer checks for null pointer dereferences, memory leaks, coding conventions and unavailable API’s.

> Infer is still evolving. 

> Current Version: 1.2.0 

## Getting started with Infer

You can use our 
- binary releases
- build infer from source
- use our Docker image.

Link: codeboard 
https://codeboard.io/projects/11587?view=2.1-21.0-22.0 

**Option 2:** Build from Source (advanced, not recommended on native Windows)
You can technically compile Infer from source using OCaml, opam, and Cygwin or MSYS2, but it’s extremely complex and prone to errors (Infer depends heavily on Unix tooling and Clang).
Even Meta’s team does not support Windows builds officially.


### Using wsl in windows. 
#### Download the Infer tarball
```
    wget https://github.com/facebook/infer/releases/download/v1.2.0/infer-linux-x86_64-v1.2.0.tar.xz
```

#### Extract the downloaded tarball
```
tar -xf infer-linux-x86_64-v1.2.0.tar.xz
``` 

#### change the directory
```
    cd infer-linux-x86_64-v1.2.0
``` 

#### run this command
```
sudo cp -r bin/ lib/ share/ /usr/local/
```

#### see the version
```
    infer --version
``` 

#### open a c file
```
    nano test.c
``` 

#### copy this code
```c
#include <stdlib.h>

void leak() {
    int *p = malloc(sizeof(int));
    *p = 10;
}

int main() {
    leak();
    return 0;
}
```

run this command to save: `Ctrl + O`, `Enter`, `Ctrl + X` 

#### run this command
```
infer run -- gcc test.c -o test
``` 

#### run this command
```
    infer explore
    cat infer-out/report.txt
``` 


### Using docker 

Docker commands
```
docker build -t infer .
docker run -it -v ${PWD}:/examples infer /bin/bash
```

Now, change the directory and run infer on codes. 