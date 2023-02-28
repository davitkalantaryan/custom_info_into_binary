//
// file:			insert_custom_info_into_bin_test02.c
// path:			src/tests/insert_custom_info_into_bin_test02/insert_custom_info_into_bin_test02.c
// created on:		2023 Feb 27
// created by:		Davit Kalantaryan (davit.kalantaryan@desy.de)
//


#define COMMIT_ID	e6ae7a2e4e7100532b6884d1534f4c8399067413

#ifdef __cplusplus
#define CPPUTILS_EXTERN_C	extern "C"
#else
#define CPPUTILS_EXTERN_C
#endif


//#ifdef _MSC_VER
//#pragma section(".mysect",read)
//CPPUTILS_EXTERN_C __declspec(allocate(".mysect")) const char commit_id[] = "commit-id=" STRVAL(COMMIT_ID);
//#pragma comment(linker, "/include:commit_id")
//#else
//	const char commit_id[] __attribute__((section("mysection"))) = "commit-id=" STRVAL(COMMIT_ID);
//#endif


#define CPPUTILS_STRINGIZER(_arg)		#_arg
#define CPPUTILS_STRVAL(_var)			CPPUTILS_STRINGIZER(_var)


#define CPPUTILS_NAME_WITH_NUM_RAWEX(_var,_num)		_var ## _num
#define CPPUTILS_NAME_WITH_NUM_RAW(_var,_num)		CPPUTILS_NAME_WITH_NUM_RAWEX(_var,_num)
#define CPPUTILS_NAME_WITH_CNTR(_var)				CPPUTILS_NAME_WITH_NUM_RAW(_var,__COUNTER__)
#define CPPUTILS_NAME_WITH_LINE(_var)				CPPUTILS_NAME_WITH_NUM_RAW(_var,__LINE__)

#ifdef _MSC_VER
#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(_sectionVar,_sectionName,_comment)				\
	__pragma(section(_sectionName,read))														\
	CPPUTILS_EXTERN_C __declspec(allocate(_sectionName)) const char _sectionVar[] = _comment;	\
	__pragma(comment(linker, "/include:" CPPUTILS_STRVAL(_sectionVar)))
#elif defined(CPPUTILS_GCC_FAMILY)
#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(_sectionVar,_sectionName,_comment)				\
	const char _sectionVar[] __attribute__((section(_sectionName))) = _comment;
#else
#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(_sectionVar,_sectionName,_comment)				\
	const char _sectionVar[] = _comment;
#endif


#define CPPUTILS_INSERT_COMMENT_TO_BIN_RAW(_sectionName,_comment)	\
	CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(CPPUTILS_NAME_WITH_LINE(CPPUTILS_NAME_WITH_CNTR(___section_var_)),_sectionName,_comment)


CPPUTILS_INSERT_COMMENT_TO_BIN_RAW_RAW(__section_var1, ".mysect", "commit-id=" CPPUTILS_STRVAL(COMMIT_ID))
CPPUTILS_INSERT_COMMENT_TO_BIN_RAW(".mysect", "__commit-id=" CPPUTILS_STRVAL(COMMIT_ID))
