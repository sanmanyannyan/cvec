
#define TEST_CASE(func)                          \
do{                                              \
	if( TEST_FUNCTION(func)() ) {                \
		printf("test %s ", STR(func) );          \
		printf("passed");                        \
		printf(".\n")   ;                        \
	} else {                                     \
		printf("test %s ", STR(func) );          \
		printf("FAILED");                        \
		printf(".\n");                           \
	}                                            \
}while(0)

#define UNUSED(x) (void)(x)

#define STR(t) #t
#define TEST_FUNCTION(func) test_ ## func
