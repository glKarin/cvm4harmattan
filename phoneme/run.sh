#!/bin/sh

CVM_PATH=~user/cvm/cvm
BUILD_DIR=${CVM_PATH}"/cdc/build/linux-arm-generic"
CVM=$PWD"/bin/cvm"
LIB=${BUILD_DIR}"/lib"
MIDP=${BUILD_DIR}"/midp"
JAR="/home/user/MyDocs/NETLizard/3Dshe_ji/3d_army_rangers_arctic_en_sonyericsson_k660_240x320_.jar"
JAR="/home/user/MyDocs/clone/360x640/640x360nok-3d_teni_egipta.jar"
MIDLET="NET_Lizard"
JAD=""
CP="-cp ${LIB}/nokia_api.jar -Xbootclasspath/a:${LIB}/nokia_api.jar"

if [ "x$2" != "x" ]; then
	JAR=$2
fi
if [ "x$1" != "x" ]; then
	MIDLET=$1
fi
if [ "x$3" != "x" ]; then
	JAD="-jadpath $3"
fi

export LD_LIBRARY_PATH=${BUILD_DIR}/bin:${LD_LIBRARY_PATH}
HARM_ARGS="-harm-background-color #D0D0D0"
cd $PWD/bin
CMD="${CVM} -Xmx12m -Dmicroedition.profiles=MIDP-2.1 -Dmicroedition.location.version=1.0 -Dsun.midp.library.name=midp -Dsun.midp.home.path=${MIDP}/midp_linux_fb_gcc -Dcom.sun.midp.mainClass.name=com.sun.midp.main.CdcMIDletSuiteLoader sun.misc.MIDPLauncher ${HARM_ARGS} " # -suitepath ${JAR} -1 ${MIDLET} ${JAD}"

date +"%Y-%m-%d %H:%M:%S";
echo ${CMD}

#gdb --args ${CMD} "$@"
${CMD} "$@"
#gdbtui --args ${CMD} "$@"
#valgrind ${CMD} "$@"
