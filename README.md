# U.S. Linguistics Machine Learning Model

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Read [this document](https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html) to understand the project
layout.

**Author**: Hrishikesh Deshmukh - [`hcd3@illinois.edu`](mailto:hcd3@illinois.edu)

## About

Despite all speaking the same language, there is a vast amount of variety in the continental United
States in our lingustic tendencies and what we call day-to-day items!  As you take this quiz, data collected
from the [Harvard Dialect Survey](http://www4.uwm.edu/FLL/linguistics/dialect/maps.html) helps train
the Machine Learning model to predict whether you are from the **Northeast**, **South**, **Midwest**, or 
**Pacific/Rockies**.

<img src="https://github.com/CS126SP20/final-project-hcd3/blob/master/data/Title126.png" height="504" width="504" alt="">

<img src="https://github.com/CS126SP20/final-project-hcd3/blob/master/data/Question126.png" height="504" width="504" alt="">

<img src="https://github.com/CS126SP20/final-project-hcd3/blob/master/data/Prediction126.png" height="504" width="504" alt="">

## Dependencies

- [Cmake](https://cmake.org/)
- [Cinder](https://libcinder.org/)
- [Clang](https://clang.llvm.org/) or [gcc](https://gcc.gnu.org/)
- [Dlib](http://dlib.net/compile.html)
- [Catch2](https://github.com/catchorg/Catch2)

This program was built and compiled in Ubuntu Linux and is written in **C++** utilizing the IDE Clion
(make sure you have your C compiler installed).
However, all the dependencies listed above are compatible with Windows and MacOS, as well as Linux.
Windows users should use [Visual Studio 2015](https://visualstudio.microsoft.com/) for this repository.
Use the links above to clone or download the corresponding repositories.  It may seem intimidating but
it's not that bad!

### Linux

#### Cmake

```console
$ mkdir build
$ cd build/
$ cmake ..
cmake --build . --config Release
```

#### Dlib

```console
$ git clone https://github.com/davisking/dlib
```

## Keyboard Controls
| Key            | Action                         |
|--------------- |--------------------------------|
| `n`            | Move to the next page          |
| `p`            | Move to the previous page      |
| `a`            | Select answer A                |
| `b`            | Select Answer B                |
| `c`            | Select Answer C                |
| `Right Arrow`  | Move to the next page          |
| `Left Arrow`   | Move to the previous page      |


