#!/bin/bash
CY='\e[33m'
CE='\e[0m'
ECHO='echo -e'
LINE=' ===== '

echo_and_exec(){
	${ECHO} ${CY}${LINE}$1${LINE}${CE}
	eval $1
}

build(){
	tar -cf .hello.tar . 2>/dev/null
	echo_and_exec 'autoreconf --install'
	echo_and_exec './configure'
	echo_and_exec 'make'
	echo_and_exec 'src/hello'
}

clean(){
	rm * -rf
	tar -xf .hello.tar
}

case $1 in
"build")
	;& # Fallthrough
"clean")
	eval $1
	;;
*)
	${ECHO} "usage:"
	${ECHO} "  $0 build"
	${ECHO} "  $0 clean"
	;;
esac
