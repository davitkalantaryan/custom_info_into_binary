//
// file:			main_url_capture_api_test01.cpp
// path:			src/tests/main_url_capture_api_test01.cpp
// created on:		2022 Dec 28
// created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//


// pragma_directive_const_seg.cpp
// compile with: /EHsc
#include <iostream>

const int i = 7;               // inlined, not stored in .rdata
const char sz1[] = "test1";     // stored in .rdata

#pragma section(".mydata",read)
__declspec(allocate(".mydata")) const char sz2[] = "This_is_my_custom_data";     // stored in .my_data1

//#pragma const_seg()

//#pragma const_seg(push, stack1, ".my_data2")
const char sz3[] = "test3";     // stored in .my_data2

//#pragma const_seg(pop, stack1) // pop stack1 from stack
const char sz4[] = "test4";     // stored in .my_data1


int main() {
	using namespace std;
	// const data must be referenced to be put in .obj
	cout << sz1 << endl;
	cout << sz2 << endl;
	cout << sz3 << endl;
	cout << sz4 << endl;
}


#if 0

#define STRINGIZER(arg)    #arg
#define STRVAL(v)          STRINGIZER(v)

#define COMMIT_ID	e6ae7a2e4e7100532b6884d1534f4c8399067413

#ifdef _MSC_VER
#pragma data_seg(".mysection")
const char commit_id[] = "commit-id=" STRVAL(COMMIT_ID);
#pragma data_seg()
#else
const char commit_id[] __attribute__((section("mysection"))) = "commit-id=" STRVAL(COMMIT_ID);
#endif

#if 0

#ifdef _MSC_VER
#define CPPUTILS_INSERT_COMMENT_TO_BIN(_section,_comment)	\
	__pragma( data_seg(STRVAL(_section)) )					\
	const char __section_var##_section [] = _comment;		\
	__pragma( data_seg() )
#else
#define CPPUTILS_INSERT_COMMENT_TO_BIN(_section,_comment)	\
	const char __section_var##_section[] __attribute__((section(STRVAL(_section)))) = _comment;
#endif

CPPUTILS_INSERT_COMMENT_TO_BIN(mysection, "commit-id=" STRVAL(COMMIT_ID))


#endif


int main(int a_argc, char* a_argv[])
{
	(void)a_argc;
	(void)a_argv;
	return 0;
}


#endif
