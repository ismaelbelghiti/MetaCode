test -d build && rm -r build
mkdir build
( cd build; cmake ..; make; )
