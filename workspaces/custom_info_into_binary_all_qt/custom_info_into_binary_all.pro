

TEMPLATE = subdirs
#CONFIG += ordered

#include ( "$${PWD}/../../prj/common/common_qt/flags_common.pri" )
repositoryRoot = $${PWD}/../..

SUBDIRS		+=	"$${repositoryRoot}/prj/tests/insert_custom_info_into_exe_test01_qt/insert_custom_info_into_exe_test01.pro"
SUBDIRS		+=	"$${repositoryRoot}/prj/tests/insert_custom_info_into_bin_test02_exe_qt/insert_custom_info_into_bin_test02_exe.pro"

#OTHER_FILES += $$files($${repositoryRoot}/docs/*.md,true)
#OTHER_FILES += $$files($${repositoryRoot}/docs/*.txt,true)

OTHER_FILES	+=	\
        "$${repositoryRoot}/.gitattributes"					\
	"$${repositoryRoot}/.gitignore"						\
	"$${repositoryRoot}/LICENSE"						\
	"$${repositoryRoot}/README.md"						

