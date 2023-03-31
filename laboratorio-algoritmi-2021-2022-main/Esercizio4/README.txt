--PER COMPILARE I TEST--

1)posizionarsi in Esercizio4/src
2)posizionare i file *.jar sotto la cartella Esercizio4
3)javac -d ../classes -cp .:../junit-4.12.jar:../hamcrest-core-1.3.jar graph/*.java graphtests/*.java

--PER COMPILARE GRAPH, GRAPHUTILS E GRAPHUSAGE--
1)posizionarsi in Esercizio4/src
2)javac -d ../classes graph/*.java graphutils/*.java graphusage/*.java minheap/*.java

--PER ESEGUIRE I TEST--

1)posizionarsi in Esercizio4/classes
2)posizionare i file *.jar sotto la cartella Esercizio4 se son stati spostati dopo la compilazione
3)java  -cp .:../junit-4.12.jar:../hamcrest-core-1.3.jar graphtests/GraphTestsRunner 

--PER ESEGUIRE GRAPHUSAGE (E ALGORITMO DI DIJKSTRA)--
1)posizionarsi in Esercizio4/classes
2)java graphusage/GraphUsage "/home/michele/Documenti/laboratorio-algoritmi-2021-2022-main/Esercizio4/italian_dist_graph.csv"

---PER ELIMINARE FILE .CLASS E CARTELLA CLASSES---
1)Posizionarsi sotto Esercizio4
2)rm -rf classes