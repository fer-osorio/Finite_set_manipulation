#include"Set.hpp"

int main(int argc, char *argv[]) {
    ui32 test0[]={0,1,7,4,5,2,8,9,10,9,14}, test1[]={1,3,6,13,12,11,9,3,15};
    ui32 length0 = SIZE_ARRAY(test0), length1 = SIZE_ARRAY(test1);
    Set set0(test0,length0), set1(test1,length1), setUnion, setIntersection;
    set0.println();
    set1.println();
    std::cout << "(set0.maximum,set0.minimum) = (" << set0.get_maximum() << "," << set0.get_minimum() << ")\n";
    std::cout << "(set0.maximum,set0.minimum) = (" << set1.get_maximum() << "," << set1.get_minimum() << ")\n";
    setUnion = set0 + set1;
    std::cout << "set0 U set1 = ";
    setUnion.println();
    setIntersection = set0*set1;
    std::cout << "set0 n set1 = ";
    setIntersection.println();
    if(belongs(8, set0))
        std::cout << "8 belongs to set0\n";
    if(!belongs(0,set1))
        std::cout << "0 does not belong to set1\n";
    set0.deleteSet();
    set1.deleteSet();
    setUnion.deleteSet();
    setIntersection.deleteSet();

    return 0;
}
