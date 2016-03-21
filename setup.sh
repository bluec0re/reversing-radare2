#!/bin/bash

if ! which cmake > /dev/null
then
    echo -e "\033[94mcmake\033[0m is \033[91mREQUIRED\033[0m"
    exit 1
fi


mkdir build
cd build
if ! cmake ..
then
    echo -e "\033[91mERROR\033[0m"
    exit 1
fi

echo
echo -e "Compile code by\n\$ \033[96mcd \033[94mbuild\033[0m\n\$ \033[96mmake\033[0m"
echo -e "Run sample 1 by\n\$ \033[96mcd \033[94mbuild\033[0m\n\$ \033[96m./sources/challenge01/challenge01\033[0m"
