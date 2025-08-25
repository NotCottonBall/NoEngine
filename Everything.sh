cd ./Libraries &&
cmake --preset Clang-Debug &&
cmake --build --preset Clang-Debug &&

cd ../ &&
cmake --preset Clang-Debug &&
cmake --build --preset Clang-Debug