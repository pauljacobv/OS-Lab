echo " enter the no of elements : "
read n
echo " enter elements "
for((i=0;i<n;i++))
do
read arr[i]
done
for((i=0;i<n;i++))
do
((s=arr[i]))
if((($s%2)==0))
then
echo "${arr[i]} is even "
else
echo "${arr[i]} is odd "
fi
done
