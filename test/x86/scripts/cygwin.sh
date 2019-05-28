if [ ! -e .build ]; then
mkdir .build
fi

cd .build
cmake .. -DCMAKE_C_COMPILER=clang
make -j4
./test_avx2
cd ..
