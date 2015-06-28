#! /bin/bash

binary()
{
        flag=0
        low=$1
        high=$2
while(( low <= high ))
do
        ((mid=(low+high)/2))
        if ((arr[mid] == search))
        then
                flag=1
        break
        elif [ arr[mid] < search ]
        then
                (( low=mid+1 ))
        elif [ arr[mid] > search ]
        then
                (( high=mid-1 ))
        fi
done
if((flag == 1))
then
        echo "Element found at $((mid+1))"
else
        echo "Not found"
fi
}

echo "Read the limit : "
read limit
echo "Enter the elements : "
for(( i=0;i<limit;i++ ))
do
        read arr[i]
done
((limit=limit-1))
echo "Enter search element : "
read search
binary 0 limit

