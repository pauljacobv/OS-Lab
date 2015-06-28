clear
i="y"
a=0
t=0
while [ $i = "y" ]

do
clear
echo "1.Compare 2 strings :"
echo "2.Concatanet string"
echo "3.Find length of string"
echo "4.Occurance of word"
echo "5.Reverse of string"
echo "6.Exit"
echo "Enter your choice"
read ch
case $ch in
    1)echo "Enter first String"
     read s1
     echo "Enter second string "
     read s2
     if [ $s1 = $s2 ]
     then    
        echo "Two strings are equal "else
        echo "Two strings are not equal"
     fi;;
    2)echo "Enter one string "
      read s1
     echo "Enter second string "
     read s2
     echo $s1 $s2;;
    3)echo "Enter any String"
     read s1
     t=`echo $s1|wc -c`
     t=`expr $t - 1`
     echo "Length of "$s1" is "$t;;
    4)echo "Enter any String "
     read s1
     echo "Enter word u want to find occurance of:"
     read c1
     t=`echo $s1|wc -c`
     t=`expr $t - 1`
     echo "length "$t
         while [ $t -ne 0 ]
     do
          temp=`echo $s1|cut -c $t`
      temp2=`echo $temp2 $temp`
          #echo $temp2
       if [ $temp2 = $c1 ]
       then
        a=`expr $a + 1`
        t=`expr $t - 1`
       else
        t=`expr $t - 1`
       fi
    done
     echo "Occurance of "$c1" is "$a;;
    5)echo "Enter any string :"
      read s1
       t=`echo $s1|wc -c`
           t=`expr $t - 1`
           echo "length "$t
           while [ $t -ne 0 ]
       do
         temp=`echo $s1|cut -c $t`
         echo $temp
         temp2=`echo $temp2 $temp`
         t=`expr $t - 1`
      done
      echo $temp2;;
    6)exit;;
    *)echo "Invalid choice";;
esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done

