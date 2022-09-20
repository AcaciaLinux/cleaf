# Usage

The main object to work with is the `cleafcore` object, that is implemented as a `void*` type in C.

> **Warning**
> 
> Altrough the main cleafcore pointer is a `void*` and can thus be casted to any type, it's highly recommended to be very careful with it. Misuse can lead to unexpected behaviour and crashes without any warnings or errors neither from the compilers side or leaf's side!

### cleaf setup

To initialize the `cleaf` environment, a call to the following function has to be made.

```c
#include <cleaf/cleaf.h>
void cleaf_init(enum loglevel level)
```

This will setup the `cleaf` environment, create the `Log` module for `leaf` and prepare it for instantiation.

> **Note**
> 
> You **HAVE** to call this function before doing **anything** other using `cleaf`, it will check if this function has been called and if not will not do **ANYTHING!**

### Instantiate the leafcore object

To instantiate a new `leafcore` object to do operations on, a call to the following function will be needed:

```c
#include <cleaf/cleaf.h>
void* cleafcore_new()
```

The return value `void*` is the newly created `leafcore` object, casted to `void*`, so C does not have to know anything about the `leaf` implementation being C++.

> **Note**
> 
> Do not `free()` this object, delete it using the following function:
> 
> ```c
> #include <cleaf/cleafcore.h>
> void cleafcore_delete(void* leafcore_instance)
> ```
> 
> It makes sure that `leaf` is shut down correctly and cleans up its memory accordingly.

### Updating the package lists

Before doing anything, leaf should update its package lists to ensure up-to-date packages and no errors while downloading packages due to non-existing package repositories.

The process of downloading the package lists is the following:

1. Initialize `cleaf`

2. Create the `leafcore` object

3. Calling the `a_update()` function

4. Cleaning up the `leafcore` object

```c
#include <cleaf/cleaf.h>
#include <cleaf/cleafcore.h>

int main(){
    cleaf_init(LOGLEVEL_U);                     //We use the Log::U level, the default
    void* cleafcore = cleafcore_new();          //Create the leafcore object

    int res = cleafcore_a_update(cleafcore);    //Try the call to Leafcore::a_update()

    if (res != 0){
        //Handle the error, 'res' is the error code thrown by Leafcore
    }

    cleafcore_delete(cleafcore);                //Clean up the leafcore object
    return 0;
}
```

Compiling this program is quite easy, assuming it is named `cleaf_update.c`, the compiler call is the following:

```bash
gcc cleaf_update.c -lcleaf
```

The resulting binary is called `a.out`.

> **Warning**
> 
> At this stage leaf has no configuration, except you have one located at `/etc/leaf/leaf.conf`. It will write to your ROOT (/) and installing any package can and will override your running system's programs, which will almost certainly lead to issues. Fortunately `leaf` warns you by exiting gently and giving you an error message explaining that the files of the package to install are already existing and that it can not continue its operation.

### Installing packages

Installing a package requires up-to-date package lists, this is the first thing we do, then the steps are the following:

1. Initialize `cleaf`

2. Create the `leafcore` object

3. Calling the `a_update()` function to update package lists

4. Reading the package list

5. Detecting already installed packages

6. Constructing the array of package to install

7. Calling the `a_install()` function to make the install operation

8. Cleaning up

```c
#include <cleaf/cleaf.h>
#include <cleaf/cleafcore.h>

int main(){
    cleaf_init(LOGLEVEL_U);                     //We use the Log::U level, the default
    void* cleafcore = cleafcore_new();          //Create the leafcore object

    int res = cleafcore_a_update(cleafcore);    //Try the call to Leafcore::a_update()
    if (res != 0){
        cleafcore_delete(cleafcore);            //Delete the leafcore object
        return -1;
    }

    res = cleafcore_readDefaultPackageList(cleafcore);
    if (res != 0){                              //We try reading the package list
        cleafcore_delete(cleafcore);            //Delete the leafcore object
        return -1;
    }

    res = cleafcore_parseInstalled(cleafcore);  //Try parse the installed packages
    if (res != 0){
        cleafcore_delete(cleafcore);            //Delete the leafcore object
        return -1;
    }

    char* packages[] = {                        //Create an array of package strings
        "base", "gcc"                           //These are the packages we install
    };
    int count_packages = 2;                     //We have 2 packages to install

    res = cleafcore_a_install(cleafcore, count_packages, packages);
    if (res != 0){                              //Try calling Leafcore::a_install()
        cleafcore_delete(cleafcore);            //Delete the leafcore object
        return -1;
    }

    cleafcore_delete(cleafcore);                //Clean up the leafcore object
    return 0;
}
```

Compiling this program is quite easy, assuming it is named `cleaf_install.c`, the compiler call is the following:

```bash
gcc cleaf_install.c -lcleaf
```

The resulting binary is called `a.out`.

> **Warning**
> 
> At this stage leaf has no configuration, except you have one located at `/etc/leaf/leaf.conf`. It will write to your ROOT (/) and installing any package can and will override your running system's programs, which will almost certainly lead to issues. Fortunately `leaf` warns you by exiting gently and giving you an error message explaining that the files of the package to install are already existing and that it can not continue its operation.
