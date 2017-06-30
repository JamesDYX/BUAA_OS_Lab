#!usr/bin
make clean
make
/OSLAB/gxemul -M 64 -C R3000 -E testmips -d gxemul/fs.img ./gxemul/vmlinux
