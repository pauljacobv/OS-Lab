echo -n "Enter the Lower Limit : "
read Start
echo -n "Enter the Upper Limit : "
read Ending

echo "Armstrong Numbers between $Start and $Ending are: "

while [ $Start -le $Ending ]
do
     Number=$Start
     Length=${#Number}
     Sum=0
     OldNumber=$Number

     while [ $Number -ne  0 ]
     do
          Rem=$((Number%10))
          Number=$((Number/10))
          Power=$(echo "$Rem ^ $Length" | bc )
          Sum=$((Sum+Power))
     done

     if [ $Sum -eq $OldNumber ]
     then
         echo -n "$OldNumber  "
     fi

     let Start++
done
echo
