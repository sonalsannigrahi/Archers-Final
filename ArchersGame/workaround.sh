#!/bin/bash

function change_permission {
  echo "Changing permission of $1"
  str=$(xattr -p com.apple.quarantine "$1" | sed 's/^0081/00c1/')
  xattr -w com.apple.quarantine "$str" "$1"
}

[ $(id -u) -eq 0 ] || { echo "Must be run as root. Try sudo."; exit; }

for f in /usr/local/lib/libsfml-* /Library/Frameworks/{freetype.framework,sfml*}; do
  change_permission $f
done
