# FB-Infer-Tool
Contains necessary contents to present `FB Infer` tool in Software Maintenance course.

## Introduction
Infer is a static analysis tool to detect bugs in java, c, c++, objective c code. If you give Infer some Java or C/C++/Objective-C code it produces a list of potential bugs. It is written in OCaml. It was first developed at Facebook and open-sourced in 2015. Since then, it has gained popularity beyond Facebook, being adopted by other large companies. 

`Android and Java`    
Infer checks for null pointer exceptions, resource leaks, annotation reachability, missing lock guards, and concurrency race conditions in Android and Java code.

`C, C++, and iOS/Objective-C`    
Infer checks for null pointer dereferences, memory leaks, coding conventions and unavailable API’s.

> Infer is still evolving. 

> Current Version: 1.2.0 

## Getting started with Infer

There are three ways to download and install fbinfer. Those are:
- binary releases.
- use our Docker image.


Or to quick startup, we can use
codeboard.  
https://codeboard.io/projects/11587?view=2.1-21.0-22.0 


### Using wsl in windows and Linux system. 
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

run these commands respectively to save: `Ctrl + O`, `Enter`, `Ctrl + X` 

#### run the infer tool on code
```
infer run -- gcc test.c -o test
``` 

#### see the generated report
```
infer explore
cat infer-out/report.txt
``` 


### Using docker 

Docker commands
```
docker build -t infer .
# mount the local directory inside the image
docker run -it -v ${PWD}:/examples infer /bin/bash
# you should now be inside the docker container with a shell prompt, e.g.
# "root@5c3b9af90d59:/# "
```

Now, change the directory and run infer on codes. 
