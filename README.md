c-test-master project
==============

[![Travis](https://travis-ci.org/nakyto/Project_C.svg)](https://travis-ci.org/nakyto/Project_C)

 For the moment the program is not functional in this totality. The graphical interface (GUI) and documentation are functional , the programs for the rhymes the syllabation is in the course of finalization.

##### Author program

**Graphic interface :**
+ Mulamba Richard,
+ Allard Mathieu,

**Rhyme prgram :**
+ Demont Lilian,
+ Arrat Guillaume,
+ Claude Léonie,
+ Beugnard Baptiste,
+ Benlarbi Wayl,

**Syllable program:**
+ Drieu La Rochelle Loïc,
+ Le Gal Valentin,

**Documentation + Architecture:**
+ Matrat Corentin,
+ Brienne Matthias,
+ Berguig Théo.

Installation
------------

~~~bash
$ sudo apt install cmake gcc lcov cppcheck python-pip valgrind flawfinder doxygen dot
$ [sudo] pip install [--user] -r c-test/docs/requirements.txt
~~~

Usage
-----

### Compilation

~~~bash
$ mkdir build
$ cd build
$ cmake ../c-test -DBUILD_COVERAGE=1 -DBUILD_HTML_COVERAGE=1 -DUSE_VALGRIND=1 -DRUN_CPPCHECK=1
$ make
~~~

### Run test and code coverage

~~~bash
$ make test
$ make coverage
$ make html-coverage
~~~

### Check style

~~~bash
$ make cclint
~~~

### Run flaw finder

~~~bash
$ make flawfinder
~~~

### Build the docs

~~~bash
$ make docs
~~~

### Create archives

~~~bash
$ make package
$ make package_source
~~~

### Install package

~~~bash
$ make install
~~~
