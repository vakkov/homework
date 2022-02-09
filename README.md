# A CMake C++ library skeleton

## Build

### Debug and Test

```bash
$ mkdir -p build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ../
$ cmake --build .
$ ctest
```

To see Google Tests' verbose output, do
```bash
$ ctest -V
```

## Release

```bash
$ mkdir -p build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ../
$ cmake --build .
```

## Install

```bash
$ cd build
$ cmake --build . --clean-first --target install
```
