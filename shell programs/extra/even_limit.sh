echo “Enter upper limit”

read n

$i=2

while [$i -lt $n]

do

expr ‘$sum=$sum+$i’

expr ‘$i=$i+2’

done

echo “Sum is : $sum”
