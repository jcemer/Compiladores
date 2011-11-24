#!/bin/bash

echo -n "Digite o Nome do Arquivo de teste: "
#read _NAME

printf "\n \n #### Resultado da Compilacao #### \n"
./src/pico -o output.tac ./Testes-E4/test01a.pico

printf "\n \n #### Saida da Execucao do script Python #### \n"
python tac2x86.py output.tac 

printf "\n \n #### Saida do as #### \n"
as output.s -o output.o

printf "\n \n #### Saida do Linker #### \n"
ld -dynamic-linker /lib/ld-linux.so.2 -o executavel -lc output.o

printf "\n \n #### RESULTADO DA EXECUCAO #### \n"
./executavel

#!rm output.o output.s output.tac executavel
