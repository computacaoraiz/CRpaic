#!/bin/bash

# Set temporary environment for quick tests:
export LDLP=$LD_LIBRARY_PATH
export LP=$LIBRARY_PATH
export CIP=$C_INCLUDE_PATH

unset LD_LIBRARY_PATH
unset LIBRARY_PATH
unset C_INCLUDE_PATH

export LD_LIBRARY_PATH="$HOME/CRpaic/build/lib"
export LIBRARY_PATH="$HOME/CRpaic/build/lib"
export C_INCLUDE_PATH="$HOME/CRpaic/build/include"
