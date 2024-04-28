#!/bin/sh

set -e

remove() {
  [ -f /usr/share/applications/abaddon.desktop ] && unlink  '/usr/share/applications/abaddon.desktop'
  [ -f /usr/local/bin/abaddon ] && unlink  '/usr/local/bin/abaddon'
  [ -f /usr/share/abaddon/abaddon ] && rm -f  '/usr/share/abaddon/abaddon'
  [ -f /usr/share/abaddon/abaddon.desktop ] && rm -f  '/usr/share/abaddon/abaddon.desktop'
  echo "Remove" > /tmp/postremove-proof
}

purge() {
  [ -d /usr/share/abaddon ] && rm -rf '/usr/share/abaddon'
  echo "Purge" > /tmp/postremove-proof
}

upgrade() {
  [ -f /usr/local/bin/abaddon ] && unlink  '/usr/local/bin/abaddon'
  [ -f /usr/share/abaddon/abaddon ] && rm -f  '/usr/share/abaddon/abaddon'
  [ -f /usr/share/abaddon/abaddon.desktop ] && rm -f  '/usr/share/abaddon/abaddon.desktop'
  echo "Upgrade" > /tmp/postremove-proof
}

echo "$@"

action="$1"

case "$action" in
  "0" | "remove")
    remove
  ;;
  "1" | "upgrade")
    upgrade
  ;;
  "purge")
    remove
    purge
  ;;
  *)
    printf "\033[32m Alpine\033[0m"
    remove
    ;;
esac
