#!/bin/sh

# Set this to the full path of your nimrod compiler
# since Xcode doesn't inherit your user environment.
PATH_TO_NIMROD=~/project/nimrod/root/bin/nimrod
# Set this to the location of the nimbase.h file so
# the script can update it if it changes.
PATH_TO_NIMBASE=~/project/nimrod/root/lib/nimbase.h

# Set to the directory where you want nimrod code generated.
NIMOBJ_DIR=generated_nimrod

# Force errors to fail script.
set -e

# If we are running from inside the scripts subdir, get out.
if [ ! -d nim ]
then
	cd ..
fi

DEST_NIMBASE="nim/${NIMOBJ_DIR}/nimbase.h"

# Ok, are we out now?
if [ -d nim ]
then
	$PATH_TO_NIMROD c --noMain  --app:lib \
		--nimcache:"${NIMOBJ_DIR}" --compileOnly \
		--header --cpu:i386 nim/rester.nim
	if [ "${PATH_TO_NIMBASE}" -nt "${DEST_NIMBASE}" ]
	then
		echo "Updating nimbase.h"
		cp "${PATH_TO_NIMBASE}" "${DEST_NIMBASE}"
	fi
else
	echo "Uh oh, nim directory not found?"
	exit 1
fi
