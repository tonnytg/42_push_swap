#!/bin/bash

for i in {1..100}
do
  # Gera três números aleatórios entre 1 e 100
  num1=$((RANDOM % 100 + 1))
  num2=$((RANDOM % 100 + 1))
  num3=$((RANDOM % 100 + 1))
  num4=$((RANDOM % 100 + 1))
  num5=$((RANDOM % 100 + 1))

  # Armazena os números aleatórios na variável ARGS
  export ARGS="$num1 $num2 $num3 $num4 $num5"

  # Exibe o conteúdo da variável ARGS
  ./push_swap $ARGS | ./checker_Mac $ARGS
  if [ $? -eq 0 ]
  then
    echo "OK"
  else
    echo $ARGS
    echo "KO"
    break
  fi
done