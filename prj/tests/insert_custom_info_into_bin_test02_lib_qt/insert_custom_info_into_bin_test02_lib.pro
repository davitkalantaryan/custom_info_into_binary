#
# file:			any_quick_test.pro
# path:			prj/tests/any_quick_test_qt/any_quick_test.pro
# created on:	2021 Mar 07
# created by:	Davit Kalantaryan
#

TEMPLATE = lib

include ( "$${PWD}/../../common/common_qt/sys_common.pri" )
#include ( "$${PWD}/../../common/common_qt/flags_common.pri" )

DESTDIR     = "$${artifactRoot}/$${SYSTEM_PATH}/$$CONFIGURATION/test"

QT -= gui
QT -= core
QT -= widgets
CONFIG -= qt

LIBS += -pthread

repoRootPath=$${PWD}/../../..

INCLUDEPATH += "$${PWD}/../../../include"
DEFINES += CPPUTILS_USING_STATIC_LIB_OR_OBJECTS


SOURCES	+=		\
	"$${PWD}/../../../src/tests/insert_custom_info_into_bin_test02/entry_insert_custom_info_into_bin_test02_lib.cpp"		\
	"$${PWD}/../../../src/tests/insert_custom_info_into_bin_test02/insert_custom_info_into_bin_test02.c"

COMMON_HDRS	= $$files($${repoRootPath}/include/*.h,true)
COMMON_HDRSPP	= $$files($${repoRootPath}/include/*.hpp,true)

HEADERS += $$COMMON_HDRS
HEADERS += $$COMMON_HDRSPP
