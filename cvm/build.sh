#!/bin/sh

echo "Build cvm..."

ARCH="arm"

export CVM_PATH=$PWD
export MAIN_MAKE_PATH=$PWD/cdc/build/linux-${ARCH}-generic

echo "Set env..."
export USE_AAPCS=true
export CVM_DUAL_STACK=true
export CVM_INCLUDE_COMMCONNECTION=true
export CVM_KNI=true
export CVM_STATICLINK_LIBS=true
export USE_MIDP=true
export J2ME_CLASSLIB=foundation
export CVM_TOOLS_DIR=/opt
export CVM_TARGET_TOOLS_PREFIX=/usr/bin/
# add
export CVM_PRELOAD_LIB=true
# should be 1.4 for "javah -old"
export JDK_VERSION=jdk1.7.0_75
export JDK_HOME=${CVM_TOOLS_DIR}/${JDK_VERSION}
export JPEG_DIR=${CVM_PATH}/jpeg

export DIRECTFB_INSTALL_DIR=/opt
export PCSL_PLATFORM=linux_${ARCH}_gcc
export PCSL_OUTPUT_DIR=${CVM_PATH}/pcsl/output
export CDC_DIR=${CVM_PATH}/cdc
export CDC_DIST_DIR=$CDC_DIR/build/linux-${ARCH}-generic/
export TOOLS_DIR=${CVM_PATH}/tools
export CLDC_DIST_DIR=$CDC_DIST_DIR

export USE_VERBOSE_MAKE=true

echo "Building..."
# make -C ${MAIN_MAKE_PATH} clean

make -C ${MAIN_MAKE_PATH} \
	CVM_TARGET_TOOLS_PREFIX=${CVM_TARGET_TOOLS_PREFIX} \
	$@

echo "Done"

exit 0
