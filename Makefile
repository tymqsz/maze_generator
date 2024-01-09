main: main.c data.c algs.c visual.c
	cc main.c data.c algs.c visual.c -lm -o main

clean:
	rm main
