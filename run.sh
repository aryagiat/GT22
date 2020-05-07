#!/bin/bash

echo "Launching GT22 game..."; make GT22 &> /dev/null
./GT22
make clean
clear
