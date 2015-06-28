echo 'Enter a string'

read s

f=0

low=0

high=`expr length $s - 1`

while [ $low -lt $high ]

do

first=${s:low:1}

last=${s:high:1}

if [ $first = $last ]

then

nop=0

else

f=1

fi

low=`expr $low + 1`

high=`expr $high - 1`

done

if [ $f -eq 0 ]

then

echo 'Palindrome'

else

echo 'Not Palindrome'

fi
