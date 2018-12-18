#!/bin/sh

#export CVM_TARGET_TOOLS_PREFIX=/opt/arm-2011.09/bin/arm-none-linux-gnueabi-
# scratchbox
#export CVM_TARGET_TOOLS_PREFIX=/scratchbox/compilers/cs2007q3-glibc2.5-arm7/bin/arm-none-linux-gnueabi-
# device
export CVM_TARGET_TOOLS_PREFIX=/usr/bin/

# set your jdk path
# only jdk7 has armel.
# now some changes for jdk version > 1.4, javah -old, StringBuilder
export JAVA_HOME=/opt/jdk1.7.0_75
export JAVA_PATH=$JAVA_HOME
export JDK_HOME=$JAVA_HOME
export CVM_JAVABIN=$JAVA_HOME/bin
export CVM_PRELOAD_LIB=true
export JAVAME_LEGAL_DIR=$PWD/legal
export PATH=$JAVA_HOME:$PATH
export USE_VERBOSE_MAKE=true
export VERBOSE_BUILD=true
export CVM_DEBUG=false

export CVM_JIT=true
export USE_AAPCS=true

export J2ME_CLASSLIB=foundation
export CVM_PRELOAD_LIB=true
export USE_MIDP=true
export USE_JPEG=true
export CVM_DUAL_STACK=true
export USE_JUMP=false

export USE_CDC_FILE_PROTOCOL=false
export ENABLE_ISOLATES=true
export USE_MULTIPLE_ISOLATES=true
export CVM_INCLUDE_COMMCONNECTION=true
export CVM_INCLUDE_JAVACALL=false
export USE_SSL=true

export WORK_DIR=$PWD

export ABSTRACTIONS_DIR=$WORK_DIR/abstractions
export JUMP_DIR=$WORK_DIR/jump
export MIDP_DIR=$WORK_DIR/midp
export PCSL_DIR=$WORK_DIR/pcsl
export TOOLS_DIR=$WORK_DIR/tools
export XMLPARSER_DIR=$WORK_DIR/xmlparser
export JAVACALL_DIR=$WORK_DIR/javacall
export RESTRICTED_CRYPTO_DIR=$WORK_DIR/restricted_crypto

export USE_JSR_75=true
export JSR_75_DIR=$WORK_DIR/jsr75
export JSR_75_PIM_HANDLER_IMPL=java
export USE_JSR_179=true
export USE_JSR_135=true


#echo "CVM_TARGET_TOOLS_PREFIX=$CVM_TARGET_TOOLS_PREFIX" >> cdc/build/linux-arm-generic/GNUmakefile

rm -rf tools/output
cd cdc/build/linux-arm-generic
make -f GNUmakefile bin USE_VERBOSE_MAKE=true CVM_TARGET_TOOLS_PREFIX=$CVM_TARGET_TOOLS_PREFIX $@

