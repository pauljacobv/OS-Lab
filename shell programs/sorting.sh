echo 'Enter the number of terms in the array (n)'
read n
echo "Enter $n numbers"
for((i=0;i<n;i++))
do
read a[i]
done
echo 'Original array'
echo ${a[*]}
for((i=0;i<n-1;i++))
do
for((j=0;j<n-1-i;j++))
do
if [ ${a[j]} -gt ${a[j+1]} ]
then
t=${a[j]}
a[j]=${a[j+1]}
a[j+1]=$t
fi
done
done
echo 'Sorted array'
echo ${a[*]}
