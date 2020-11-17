#echo "hello world "
#  read  PERSON
# echo $PERSON;

#echo "File Name $0"
#echo "first parameter $1";
#echo "Second paremeter $2";
#echo "Qouted Values $@";#single quoted values
#echo "Qouted values $*";#all quotes values
#echo "No of parameters:$#";


for var in  2 3 4 5 6 7 8 9
do
	if [ $((var%2)) -eq 0 ]
	then
		echo "Number is even"
	else
		echo "Number is odd"
	fi

done
a=0

while [ $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1`
done




