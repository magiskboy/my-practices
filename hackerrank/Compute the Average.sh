read n
s=0
for (( i=0; i<n; ++i )); do
    read ai
    s=$((s+ai))
done

printf "%.3f\n" $(bc -l <<< "$s / $n")
