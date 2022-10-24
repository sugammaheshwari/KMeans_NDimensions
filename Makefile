kmeans:
	g++ -std=c++11 main.cpp csvParser.cpp csvParserToNDPoint.cpp kMeans.cpp -o kmeans.out
debug_kmeans:
	g++ -std=c++11 main.cpp csvParser.cpp csvParserToNDPoint.cpp kMeans.cpp -DkmeansDebugger -o kmeans.out
debug_csvparser:
	g++ -std=c++11 main.cpp csvParser.cpp csvParserToNDPoint.cpp kMeans.cpp -DcsvParserDebugger -o kmeans.out
debug_all:
	g++ -std=c++11 main.cpp csvParser.cpp csvParserToNDPoint.cpp kMeans.cpp -DcsvParserDebugger -DkmeansDebugger -o kmeans.out