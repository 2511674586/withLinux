#!/bin/sh
# Lumin, WithLinux

SCAN="README.md"
FILES=$(find . | grep -v '.git')

for ITEM in ${FILES}; do
  if [ -f ${ITEM} ]; then
    if ! grep "${ITEM})" ${SCAN} 2>&1 1>/dev/null; then
      printf "[%s] is missing in [%s].\n" ${ITEM} ${SCAN}
    fi
  else
    #printf "%s is not a regular file, skip...\n" ${ITEM}
	continue
  fi
done
