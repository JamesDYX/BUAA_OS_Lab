#!/bin/sh
cd ..
make
/OSLAB/gxemul -E testmips -C R3000 -M 64 ./gxemul/vmlinux -t
cd mm/

