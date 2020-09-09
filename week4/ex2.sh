gcc ex2.c -o ex2

./ex2 & 

for i in {1..6}
do
	pstree
  sleep 4
done