
Classes:
    1. structures.h
        - NP point structure to contain N-Dimensional point (double precision)
    2. csvParser.cpp
        - To parse csv file with any delimeter into vector string.
    3. csvParserTONDPoint.cpp extends csvParser
        - To parse csv file into NDPoint structure (structures.h)
    4. kMeans.cpp
        - Implements kMeans algorithm on passed NPPoint vector, k, and epochs
    5. main.cpp
        - driver class

Commands
    1. compile:
        make kmeans
    2. run:
        ./binary_name input_ND_points_file_name K
        eg: ./kmeans ndpoints.txt 2
    3. debugging
        make debug_kmeans
        make debug_csvparser
        make debug_all
    4. Output:
        cat KMeans_Clustering_Output.csv
    5. 2D python plotting script
        python3 2d-plotter.py