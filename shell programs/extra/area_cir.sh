#
echo -n "Enter the radius of a circle : "
#
read r
#
 
#
# use formula to get it
#
area=$(echo "scale=2;3.14 * ($r * $r)" | bc)
#
 
#
# use formula to get it
#
d=$(echo "scale=2;2 * $r"|bc)
#
circumference=$(echo "scale=2;3.14 * $d"| bc)
#
 
#
echo "Area of circle is $area"
#
echo "Circumference of circle is $circumference"
