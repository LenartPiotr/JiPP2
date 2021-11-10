void ConstStaticZad2(){
    int v = 123;
    const int *val = &v;
    // *val = 123; <- Nie można
    const int val2 = 123;
    val = &val2;

    int cVal = 314;
    int *const p = &cVal;
    *p = 628;
    int cVal2 = 666;
    // p = &cVal2; <- Nie można

    // const int* const youCantModifyMe = cVal;
}