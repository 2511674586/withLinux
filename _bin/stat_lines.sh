#!/bin/sh
# maintainer script, withlinux
find . -path ./.git -prune -o -name '*.pdf' -prune -o -type f -exec cat -n {} +
