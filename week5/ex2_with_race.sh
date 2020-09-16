# Please run "ex2_execution_with_race.sh"
# Write "1\n" into the file "numbers.txt" in advance

# After running one may see multiple occurences of some numbers. 
# This race condition happens because several processes are run simultaneously.

# After printing several numbers, a race condition MAY manifest itself. However, it depends on the system...

# the critical region here is the file "numbers.txt"

# if there is no such file
if test ! -f numbers.txt
then 
  echo 0 > numbers.txt
fi

for i in 'seq 1 100';
do
	num=$(grep -Eo '^[0-9]+$' numbers.txt | tail -1)
	echo $((num + 1)) >> numbers.txt
done
