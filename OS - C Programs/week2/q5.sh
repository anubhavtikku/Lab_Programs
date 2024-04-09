#!/bin/sh
cat>ab.txt
cat>ac.txt
sort -n -u ab.txt ac.txt>n.txt
exit 0
