#!/bin/bash
CY='\e[33m'
CE='\e[0m'
ECHO='echo -e'
LINE=' ===== '

echo_and_exec(){
	${ECHO} ${CY}${LINE}$1${LINE}${CE}
	eval $1
}

echo_and_exec 'autoreconf --install'
echo_and_exec './configure'
echo_and_exec 'make'
echo_and_exec 'src/hello'
