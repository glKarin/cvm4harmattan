#!/bin/sh

echo "CVM build system"

IN_CLEAN=0
IN_BUILD_TARGET=""
IN_DEBUG_OUTPUT=0
IN_PARAMS=""

IN_DEBUG_SYMBOL=0

echo -n "Checking in parameters...";

for i in $@
do
	if [ "x${i}" = "xclean" ]; then
		IN_CLEAN=1
	elif [ "x${i}" = "xlib" ]; then
		IN_BUILD_TARGET="lib"
	elif [ "x${i}" = "xbin" ]; then
		IN_BUILD_TARGET="bin"
	elif [ "x${i}" = "xdebug-output" ]; then
		IN_DEBUG_OUTPUT=1
	else
		if [ -z ${IN_PARAMS} ]; then
			IN_PARAMS=${i}
		else
			IN_PARAMS="${IN_PARAMS} ${i}"
		fi
	fi
done

echo "done";

echo -n "Clean building......";
if [ "x${IN_CLEAN}" = "x1" ]; then
	echo "yes";
else
	echo "no";
fi

echo -n "Build target......";
if [ "x${IN_BUILD_TARGET}" = "xbin" ]; then
	echo "binary";
elif [ "x${IN_BUILD_TARGET}" = "xlib" ]; then
	echo "binary";
else
	echo "none";
fi

echo -n "Debug output......";
if [ "x${IN_DEBUG_OUTPUT}" = "x1" ]; then
	echo "enabled";
else
	echo "disabled";
fi

echo "Other arguments......${IN_PARAMS}";

ARCH="arm"
export CVM_PATH=$PWD
export MAIN_MAKE_PATH=$PWD/cdc/build/linux-${ARCH}-generic
export CVM_TOOLS_DIR=/opt
export CVM_TARGET_TOOLS_PREFIX=/usr/bin/

echo "Start build cvm..."

echo "CVM_PATH=${CVM_PATH}"
echo "ARCH=${ARCH}"
echo "BUILD_OUTPUT_PATH=${MAIN_MAKE_PATH}"

echo "Set env...";
echo -n "Set base...";
export USE_AAPCS=true
export CVM_INCLUDE_COMMCONNECTION=true
export CVM_KNI=true
export CVM_STATICLINK_LIBS=true
export J2ME_CLASSLIB=foundation
export USE_CDC_FILE_PROTOCOL=false
export ENABLE_ISOLATES=true
export USE_MULTIPLE_ISOLATES=true
export CVM_INCLUDE_JAVACALL=false
export ABSTRACTIONS_DIR=${CVM_PATH}/abstractions
export CVM_JIT=true
export USE_JPEG=true
export JPEG_DIR=${CVM_PATH}/jpeg
export USE_JUMP=false
export JUMP_DIR=${CVM_PATH}/jump
export USE_MIDP=true
export MIDP_DIR=${CVM_PATH}/midp
export PCSL_DIR=${CVM_PATH}/pcsl
export USE_SSL=true
export RESTRICTED_CRYPTO_DIR=${CVM_PATH}/restricted_crypto
export PCSL_PLATFORM=linux_${ARCH}_gcc
export PCSL_OUTPUT_DIR=${CVM_PATH}/pcsl/output
export TOOLS_DIR=${CVM_PATH}/tools
export CDC_DIR=${CVM_PATH}/cdc
export CDC_DIST_DIR=$CDC_DIR/build/linux-${ARCH}-generic/
export CLDC_DIST_DIR=$CDC_DIST_DIR
export XMLPARSER_DIR=${CVM_PATH}/xmlparser
export JAVACALL_DIR=${CVM_PATH}/javacall
export DIRECTFB_INSTALL_DIR=/opt

if [ "x${IN_DEBUG_OUTPUT}" = "x1" ]; then
export USE_VERBOSE_MAKE=true
export VERBOSE_BUILD=true
else
export USE_VERBOSE_MAKE=false
export VERBOSE_BUILD=false
fi
if [ "x${IN_DEBUG_SYMBOL}" = "x1" ]; then 
	export CVM_DEBUG=true
else
	export CVM_DEBUG=false
fi

if [ "x${IN_BUILD_TARGET}" = "xlib" ]; then
export CVM_BUILD_SO=true
fi

echo "done";

echo -n "Set java env...";
# should be 1.4 for "javah -old"
export JDK_VERSION=jdk1.7.0_75
export JDK_HOME=${CVM_TOOLS_DIR}/${JDK_VERSION}
export JAVA_HOME=${JDK_HOME}
export CVM_JAVABIN=${JAVA_HOME}/bin
echo "done";

echo -n "Set build preload instead of -Xbootclasspath...";
export CVM_PRELOAD_LIB=true
export CVM_DUAL_STACK=true
export JAVAME_LEGAL_DIR=$PWD/legal
echo "done";

echo -n "Set build extensions...";
export USE_JSR_75=true
export JSR_75_DIR=${CVM_PATH}/jsr75
export JSR_75_PIM_HANDLER_IMPL=java

export USE_JSR_179=true

export USE_JSR_135=true
# Nokia API
export USE_NOKIA_API=true

#export USE_JSR_120=true
#export JSR_120_DIR=${CVM_PATH}/jsr120
#export USE_JSR_184=true
#export JSR_184_DIR=${CVM_PATH}/jsr184
echo "done";

if [ "x${IN_CLEAN}" = "x1" ]; then
	echo -n "Cleaning build......";
	rm -rf $PWD/tools/output
	make -C ${MAIN_MAKE_PATH} clean;
	if [ "x$?" = "x0" ]; then
		echo "done";
	else
		echo "error";
		exit 1;
	fi
fi

if [ "x${IN_BUILD_TARGET}" != "x" ]; then
	echo "Building start...";
	make -C ${MAIN_MAKE_PATH} \
		CVM_TARGET_TOOLS_PREFIX=${CVM_TARGET_TOOLS_PREFIX} #\
		#$@
	echo "Building finished......";
	if [ "x$?" = "x0" ]; then
		echo "done";
		if [ "x${IN_DEBUG_SYMBOL}" = "x1" -a "x${IN_BUILD_TARGET}" = "xlib" ]; then
			echo copy ${MAIN_MAKE_PATH}/bin/libcvm_g.so to ${MAIN_MAKE_PATH}/bin/libcvm.so;
			cp -f ${MAIN_MAKE_PATH}/bin/libcvm_g.so ${MAIN_MAKE_PATH}/bin/libcvm.so 
		fi
	else
		echo "error";
		exit 1;
	fi
fi

exit 0;
