
Compile el programa con: g++ *.cpp -o a
Para Valgrind:  valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./a
Dentro de la misma carpeta debe estar Autores.txt y Lecturas.txt
Corra el programa
Linux/macOS:  ./a