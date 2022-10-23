set -x
set -e
base_dir=problems/$1/
g++ ${base_dir}solution.cpp --std=c++20 -O2 && ./a.out
rm a.out
