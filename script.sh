#!/bin/bash

export ARGS=()
for i in {1..20}
do
  for i in {1..5}
  do
    num=$((RANDOM % 100 + 1))
    if [[ ! "${ARGS[@]}" =~ "${num}" ]]; then
      ARGS[i]=$num
    fi
  done

  # Exibe o conteúdo da variável ARGS
  ./push_swap ${ARGS[@]} | ./checker_Mac ${ARGS[@]}
  if [ $? -eq 0 ]
  then
    moves=`./push_swap ${ARGS[@]} | wc -l`
    if [ $moves -gt 12 ]
    then
      echo "KO"
      echo ${ARGS[@]}
      break
    fi
    echo "OK"
  else
    echo "KO"
    echo $ARGS
    break
  fi
done