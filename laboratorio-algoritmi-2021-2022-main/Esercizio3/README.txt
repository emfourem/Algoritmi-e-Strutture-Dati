****COMPILAZIONE***

----PER COMPILARE LE CLASSI NEL PACKAGE minheap---
1) posizionarsi in .../Esercizio3/src
2) javac -d ../classes minheap/MinHeap.java

----PER COMPILARE LE CLASSI NEL PACKAGE minheapusage---
1) posizionarsi in .../Esercizio3/src
2) javac -d ../classes minheapusage/MinHeapUsage.java

----PER COMPILARE LE CLASSI DEL TESTS RUNNER---
1)Posizionarsi in src
2)Posizionare i file *.jar sotto la cartella Esercizio3
3)javac -d ../classes -cp .:../junit-4.12.jar:../hamcrest-core-1.3.jar minheap/*.java 

***ESECUZIONE***

---PER ESEGUIRE minheapusage/MinHeapUsage---
1) posizionarsi in .../Esercizio3/classes
2) java minheapusage/MinHeapUsage

---PER ESEGUIRE minheap/MinHeapTestsRunner---
1) posizionarsi in .../Esercizio3/classes
2)Riposizionare i file *.jar sotto la cartella Esercizio3 se sono stati spostati dopo la compilazione
3)java -cp .:../junit-4.12.jar:../hamcrest-core-1.3.jar  minheap/MinHeapTestsRunner


---Eliminazione file e cartella classes---
1)posizionarsi in .../Esercizio3
2)rm -rf classes
