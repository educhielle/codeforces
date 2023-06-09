#!/bin/bash

if [ $# -le 1 ]; then
    echo "Inform the directory and number of io files"
    exit
fi

dir=$1
nios=$2


if [ -d "$dir" ]; then
    if [ "$(ls -A $dir)" ]; then
        echo "Directory is not empty"
        exit
    fi
else
    mkdir -p $dir
fi


printf "#include <iostream>

using namespace std;

int main()
{

}
" > "$dir/main.cpp"

for i in $(seq 1 $nios); do
    touch "$dir/input$i.txt"
    touch "$dir/ouput$i.txt"
done
