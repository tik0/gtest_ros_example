# The gtest_ros_example package

This is just a simple bootstraped gtest example inspired by [ysonggit](http://ysonggit.github.io/coding/2014/12/19/use-gtest-in-ros-program.html) to test if applications build with [gtest](https://en.wikipedia.org/wiki/Google_Test).

Tested with Ubuntu 16.04 and ROS Kinetic.

## Build gtest

First of all one as to build gtest, because installing `libgtest-dev` under Ubuntu only gives you the sources.

    sudo apt-get install libgtest-dev
    mkdir /tmp/gtest_build && cd /tmp/gtest_build
    cmake /usr/src/gtest
    make
    #copy or symlink libgtest.a and ligtest_main.a to /usr/lib folder
    sudo cp *.a /usr/lib

***Optional***: It could happen that you work on a system where you do not have the rights to copy stuff into system folders.
In this case, just create your own library folder for example in your home:

    mkdir ~/lib
    cp *.a /usr/lib

In this case, you have to specify some environment variables before running `catkin_make`, which is discussed below.

## Build this package

First checkout this repository into some `src` folder of a catkin workspace.
Then just build the common execuatbles (which also include a  application) via:

   catkin_make

Catkin now builds `rostalker`, `roslistener`, and `simple_test`.
`simple_test` is just a gtest example w/o any catkin magic (c.f. CMakeLists.txt).
`rostalker` and `roslistener` don't have any gtest dependencies at all, and should build out of the box.

To build the test for the talker's `add` member function, call catkin like this:

    catkin_make tests

Catkin now builds `talker-test` and `simple_test_catkin`.
`simple_test_catkin` is just a gtest example w/ catkin magic (c.f. CMakeLists.txt).

## Running executables

One can run any executable like this (don't forget the `roscore`):

    rosrun gtest_ros_example <the executable name>

## Link gtest from non-standard library folders

If one has to install the gtest libraries in some other folder (e.g. into `~/lib/`), catkin has to be called like this:

    LIBRARY_PATH=~/lib GTEST_ROOT=~/lib catkin_make

`LIBRARY_PATH` tells the linker where to find the libraries, while `GTEST_ROOT` gives cmake the location hints for it's checks.
