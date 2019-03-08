all: dfs dijkstra floyd spfa bfs
dfs: dfs.cpp
	g++ dfs.cpp -o dfs
dijkstra: dijkstra.cpp
	g++ dijkstra.cpp -o dijkstra
floyd: floyd.cpp
	g++ floyd.cpp -o floyd
spfa: spfa.cpp
	g++ spfa.cpp -o spfa
bfs: bfs.cpp
	g++ bfs.cpp -o bfs
clean:
	rm bfs spfa floyd dijkstra dfs
