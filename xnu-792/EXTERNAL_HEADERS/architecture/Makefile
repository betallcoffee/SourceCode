export MakeInc_cmd=${SRCROOT}/makedefs/MakeInc.cmd
export MakeInc_def=${SRCROOT}/makedefs/MakeInc.def
export MakeInc_rule=${SRCROOT}/makedefs/MakeInc.rule
export MakeInc_dir=${SRCROOT}/makedefs/MakeInc.dir


include $(MakeInc_cmd)
include $(MakeInc_def)

INSTINC_SUBDIRS =

INSTINC_SUBDIRS_PPC = 	\
	ppc

INSTINC_SUBDIRS_I386 =	\
	i386

EXPORT_FILES = \
	byte_order.h

INSTALL_MI_LIST = 

INSTALL_MI_DIR = architecture

EXPORT_MI_LIST = ${EXPORT_FILES}

EXPORT_MI_DIR = architecture

include $(MakeInc_rule)
include $(MakeInc_dir)


