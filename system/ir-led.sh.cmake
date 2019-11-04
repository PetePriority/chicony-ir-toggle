#!/bin/sh

# Enable IR emitter after waking from suspend/hibernation
case $1 in
    post)
	@CMAKE_INSTALL_PREFIX@/bin/chicony-ir-toggle on
	;;
esac
