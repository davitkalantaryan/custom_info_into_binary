# custom_info_into_binary  
  
This repository will demonstrate insertion of a custom info into a binary file  
  
  
## Introduction 
 
Insert source file with similar to below code to any library or executable creation compilation and you will have custom info there  
  
```cpp  
#ifdef __cplusplus
#define CPPUTILS_EXTERN_C	extern "C"
#else
#define CPPUTILS_EXTERN_C
#endif

#define STRINGIZER(arg)    #arg
#define STRVAL(v)          STRINGIZER(v)
#define CPPUTILS_ID(_x)		_x

#define COMMIT_ID	e6ae7a2e4e7100532b6884d1534f4c8399067413


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
```  
