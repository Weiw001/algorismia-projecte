all: RWTrie

RWTrie: main.cc RWTrie*.cc
	g++ main.cc RWTrie*.cc -o RWTrie

clean:
	rm -rf RWTrie
