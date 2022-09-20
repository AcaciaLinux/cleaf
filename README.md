# cleaf

The leaf C library and headers

Leaf is written in C++, that makes it difficult to use the leaf functions in other programming language due to C++'s name mangling. This wrapper library is meant to make this translation easier.

# Installation

Building and installing `cleaf` is not hard, but it requires a dependency: `leaf`, install it by either using your package manager (preferraby `leaf`), or you can install it by using the guide provided at the [leaf github repository](https://github.com/AcaciaLinux/leaf).

First of all, you need the `cleaf` source code, clone it by using the following command and entering the new directory:

```bash
git clone --recursive https://github.com/AcaciaLinux/cleaf
cd cleaf
```

Create a build directory and enter it:

```bash
mkdir -p build
cd build
```

Run `cmake` to generate build files:

```bash
cmake ..
```

Build `cleaf`:

```bash
make
```

And install it with superuser rights (`sudo` or `doas` as prefix):

```bash
make install
```

# Links

Using `cleaf` is quite easy, refer to the [usage](USAGE.md) article.
