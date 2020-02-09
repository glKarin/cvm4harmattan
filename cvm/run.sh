#!/bin/sh

BUILD_DIR=$PWD"/cdc/build/linux-arm-generic"
CVM=${BUILD_DIR}"/bin/cvm"
LIB=${BUILD_DIR}"/lib"
MIDP=${BUILD_DIR}"/midp"
JAR="/home/user/MyDocs/NETLizard/3Dshe_ji/3d_army_rangers_arctic_en_sonyericsson_k660_240x320_.jar"
JAR="/home/user/MyDocs/clone/360x640/640x360nok-3d_teni_egipta.jar"
MIDLET="NET_Lizard"
CP="-cp ${LIB}/nokia_api.jar -Xbootclasspath/a:${LIB}/nokia_api.jar"

if [ "x$2" != "x" ]; then
	JAR=$2
fi
if [ "x$1" != "x" ]; then
	MIDLET=$1
fi

if [ ! -x ${CVM} ]; then
	cp cvm ${CVM} -f
fi

cd ${BUILD_DIR}/bin
CMD="${CVM} -Xmx12m -Dmicroedition.profiles=MIDP-2.1 -Dmicroedition.location.version=1.0 -Dsun.midp.library.name=midp -Dsun.midp.home.path=${MIDP}/midp_linux_fb_gcc -Dcom.sun.midp.mainClass.name=com.sun.midp.main.CdcMIDletSuiteLoader sun.misc.MIDPLauncher -suitepath ${JAR} -1 ${MIDLET}"

echo ${CMD}

${CMD}
