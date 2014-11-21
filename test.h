int test_arg_no_name(char);
int test_arg_no_name2(char*, int);
int test_arg_no_name3(char , short *, int);
int test_arg(char p1);
int test_arg2(char p1, int *);
int test_arg2(char , int *  p2);
int test_arg2(char* p1, int p2);
void test();
void test(void(*f1)(char), void(*f2)(int(*g1)()));

