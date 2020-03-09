Have all files in the same directory, not there are only codeword.h and codebook.h files that are included in driver.cpp because of them being template classes
Step 1: CC -std=c++11 driver.cpp mint.cpp melt.cpp libgenVal.a -o CFC
Step 2 For mint: ./CFC 0 seed length size modulus e.g ./CFC 0 5 3 4 10
Step 2: for melt ./CFC 1 seed length size e.g ./CFC 1 5 3 4