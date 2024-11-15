#!/bin/bash

# Set version and date for CRpaic library files.

# Verifica se os argumentos foram fornecidos
if [ $# -ne 2 ]; then
    echo "Usage: $0 <file> <version>"
    exit 1
fi

# Argumentos
ARQ=$1
VERSION=$2

# Data:
DATE=$(date +"%Y-%m-%d %H:%M")

# Comando sed para alterar a versão
sed -i "s/^ \* Version : .*/ \* Version : $VERSION/" "$ARQ"
sed -i "s/^ \* Date    : .*/ \* Date    : $DATE/" "$ARQ"

# Mensagem de confirmação
echo "A versão no arquivo '$ARQ' foi alterada para '$VERSION' e data para '$DATE'."

