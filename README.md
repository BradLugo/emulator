# Team C's emulator
A simple 16-bit CPU emulator written in C (targeting C99)

## Build &amp; Run

### Prerequisites
- [Git](https://git-scm.com/)
- C/C++ compiler tool chain
    - Windows (Work in progress; please report any issues)
        - [Visual Studio 2013 for Windows Desktop](https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2013-version-history), [Visual Studio 2015](https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2015-version-history), or [Visual Studio 2017](https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2017-relnotes), make sure to select the option to install all C++ tools and the Windows SDK.
    - Mac OS
        - [Xcode](https://developer.apple.com/xcode/downloads/) and the Command Line Tools
        (Xcode -> Preferences -> Downloads), which will install the related toolchain containing cmake
    - Linux (Work in progress; please report any issues)
        - [CMake 3.9+](https://cmake.org/download/)
        - [GCC](https://gcc.gnu.org/)

### Create Makefile (CMake)
From a terminal, where you have cloned the emulator repository, execute the following commands
```
mkdir cmake-build-debug
cd cmake-build-debug
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ..
```

### Build
From a terminal, where you have cloned the emulator repository, after you've used cmake, execute the following command
```
cmake --build cmake-build-debug --target main -- -j 4
```

### Run
From a terminal, where you have cloned the emulator repository, after you've built the project, execute the following command
```
cmake-build-debug/bin/main
```

### Unit Testing

#### Build
From a terminal, where you have cloned the emulator repository, after you've used cmake, execute the following command
```
cmake --build cmake-build-debug --target unit_tests -- -j 4
```

#### Run
From a terminal, where you have cloned the emulator repository, after you've built the unit test project, execute the following command
```
cmake-build-debug/bin/unit_tests
```

## Git Workflow &amp; Branching Strategy

### Master branch
The master branch represents something we can turn in if required. It should contain the most stable code and
should only accept merges from the develop branch after thorough testing

### Develop branch
The develop branch is the where all of the feature branches will be merged into. This will be fairly unstable code
until we're getting ready to make a merge to the master branch

### Feature branches
A feature branch should be branched from the develop branch and feature branches should be aptly named after what
you're trying to achieve. Once the developer has completed work on the feature branch, the feature branch should be
submitted for pull request to the develop branch via GitHub and another developer on the team should code review it.
Once the feature branch has passed code review, the code reviewer may accept the pull request.

Every feature branch should have unit tests before merging into the develop branch

### WIP branches
WIP branches, or Work In Progress branches, can be used for temporary storage and team collaboration when a commit or
branch is not yet ready for a pull request. WIP branches are the **only** branches that should be forcibly push to
(`git push origin <branch> --force`) 

### Commits
Make sure to use the imperative mood in the subject line. For writing good commit messages,
reference [How to Write a Git Commit Message](https://chris.beams.io/posts/git-commit/)

## Code Review & Style Guide

### Style Guideline
We're not going to be super strict on the coding styles. Just a few rules that'll keep the code clean and the
repository maintainable should be fine. These rules may change if the enough of the contributors decide if something
should be changed, added, or removed. 

The current style guideline is as follows:
- Each line of text in your code should be at most 120 characters long. (The usual line length is 80,
so contributors might want to change this in the future)         
- Use only spaces, and indent 4 spaces at a time. Do not use tabs
- Opening braces for functions and structs should be on the next line if the function is longer than one line

The code reviewer has the right to reject the pull request until the code in the pull request adheres to these
standards

### Unit Tests
We currently use [Unity](http://www.throwtheswitch.org/unity/) for unit testing. Be sure to checkout out
[their GitHub repo](https://github.com/ThrowTheSwitch/Unity) and the 
[docs within the repo](https://github.com/ThrowTheSwitch/Unity/tree/master/docs) for more information

The code reviewer has the right to reject the pull request until the feature has proper and comprehensive unit testing
for the feature