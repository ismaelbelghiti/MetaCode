#test -d build && rm -r build
test -d build || mkdir build
( cd build; cmake ..; make; )
