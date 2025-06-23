all:
	em++ main.cpp -O2 -s USE_PTHREADS=1 -s PTHREAD_POOL_SIZE=32 -s ALLOW_MEMORY_GROWTH -o index.html
	g++ main.cpp -O2 -o main

clean:
	rm main *.js *.wasm *.html
