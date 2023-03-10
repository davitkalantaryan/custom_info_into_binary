//
// file:			main_insert_custom_info_into_exe_test01.cpp
// path:			src/tests/main_insert_custom_info_into_exe_test01.cpp
// created on:		2023 Feb 27
// created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//

//#include <iostream>


#ifdef __cplusplus
#define CPPUTILS_EXTERN_C	extern "C"
#else
#define CPPUTILS_EXTERN_C
#endif

#define STRINGIZER(arg)    #arg
#define STRVAL(v)          STRINGIZER(v)
#define CPPUTILS_ID(_x)		_x

#define COMMIT_ID	e6ae7a2e4e7100532b6884d1534f4c8399067413

//#ifdef _MSC_VER
//#pragma section(".mysect",read)
//CPPUTILS_EXTERN_C __declspec(allocate(".mysect")) const char commit_id[] = "commit-id=" STRVAL(COMMIT_ID);
//#pragma comment(linker, "/include:commit_id")
//#else
//	const char commit_id[] __attribute__((section("mysection"))) = "commit-id=" STRVAL(COMMIT_ID);
//#endif


#ifdef _MSC_VER
#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(_sectionVar,_sectionName,_comment)				\
	__pragma(section(_sectionName,read))														\
	CPPUTILS_EXTERN_C __declspec(allocate(_sectionName)) const char _sectionVar[] = _comment;	\
	__pragma(comment(linker, "/include:" STRVAL(_sectionVar)))
#else
#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(_sectionVar,_sectionName,_comment)				\
	const char _sectionVar[] __attribute__((section(_sectionName))) = _comment;
#endif

CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(__section_var1, ".mysect", "commit-id=" STRVAL(COMMIT_ID))


#define CPPUTILS_NAME_WITH_NUM_RAWEX(_var,_num)		_var ## _nm
#define CPPUTILS_NAME_WITH_NUM_RAW(_var,_num)		CPPUTILS_NAME_WITH_NUM_RAWEX(_var,_num)
#define CPPUTILS_NAME_WITH_NUM(_var)				CPPUTILS_NAME_WITH_NUM_RAW(_var,__COUNTER__)


//#define CPPUTILS_NAME_WITH_NUM(_num)		__section_var_ ## _num


#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW(_sectionName,_comment)	\
	CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(CPPUTILS_NAME_WITH_NUM(___section_var_),_sectionName,_comment)

CPPUTILS_INSERT_COMMENT_TO_BIN_RAW(".mysect", "__commit-id=" STRVAL(COMMIT_ID))



int main(int a_argc, char* a_argv[])
{
	//(void)commit_id;
	(void)a_argc;
	(void)a_argv;
	return 0;
}
