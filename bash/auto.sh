#!/bin/bash
cd ..

output_file="results.txt"
> "$output_file"  # Clear the output file

for ((n=400; n<=6000; n+=400)); do
    for ((i=0; i<10; i++)); do
        echo "Running for n=$n"
        echo -n "$n " >> "$output_file"
        ./completeGraph.exe "$n" | ./mainPrim.exe | ./propagateInfo.exe >> "$output_file"
    done
    
done