linklist: *.c *.h
	gcc $^ -o $@ -std=c99 -g
clean:
	rm -rf linklist 
