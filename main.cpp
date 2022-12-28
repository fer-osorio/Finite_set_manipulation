#include"Set.hpp"

int main(int argc, char *argv[]) {
    ui32 test[] = {0,2,4,5,7,8,9,10,14};
    ui32 length = SIZE_ARRAY(test);
    Set testSet(test,length);
    testSet.println();
    printBinary(testSet.container.elements(), testSet.container.length());
    std::cout << "\n";
    testSet.deleteSet();

    return 0;
}
