test:
	echo "hello"

monitor:
	fswatch -0 -l 2 ../driller ./test | xargs -0 -n 1 -I {} ./test
