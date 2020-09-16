# Please run "ex2_execution_without_race.sh"
# Write "1\n" into the file "numbers.txt" in advance

# After running one DOES NOT see multiple occurences of any numbers. 
# This happens because the process that works with a file,
#   locks it, so others have no access to this file

# if there is no such file
if test ! -f numbers.txt
then 
  echo 0 > numbers.txt
fi

# if there is another process using this file, just wait
while [ -f numbers.txt.lock ]
do
	:
done

# lock the file in order to prevent interuption
touch numbers.txt.lock

num=$(grep -Eo '^[0-9]+$' numbers.txt | tail -1)
echo $((num + 1)) >> numbers.txt

#removing the lock
rm numbers.txt.lock
