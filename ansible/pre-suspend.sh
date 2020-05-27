#!/bin/bash

if [ "${1}" == "pre" ]; then
#sh /path/to/script/to/run.sh
echo "none"
elif [ "${1}" == "post" ]; then
/usr/local/bin/chicony-ir-toggle on
fi
