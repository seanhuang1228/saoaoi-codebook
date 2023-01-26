#!/bin/zsh

if [ $# != 1 ];
then
  echo "Usage: $0 CONTAINER_NAME"
else
  docker start $1
  docker exec -it -w /data $1 xelatex main.tex
fi
