clear
i=1
f=1
echo "Enter the n value:"
read n
while [ $i -le $n ]
do
f=`expr $f \* $i`
i=`expr $i + 1`
done
echo "The factorial of $n is":$f
