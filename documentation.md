##Dokumentation Snake-Game 

###Gliederung: 
1. Idee
2. Umsetzung
3. Genutzte Library "Raylib" 
4. Fazit

###Idee: 
Die Idee des Projektes war die Erstellung eines einfachen Snake-Games. Dabei wird die Bibliothek "raylib" verwendet, um für mehr Übersichtlichkeit und Klarheit in der Entwicklung zu sorgen.

Snake selbst ist ein bereits lange existierendes Spiel mit foglendem Ziel: die Schlange soll so groß wie möglich werden. Die Schlange wird im vorgegebenen Feld mithilfe der Pfeiltasten (oder "wasd") gesteurt. Ziel ist es weder die Wand noch sich selbst zu berühren und dabei so viele Äpfel wie möglich einzusammeln. Beim Einsammeln eines Apfels wächst die Schlange um ein Körperteil. 
Um das Spiel ein wenig interessanter zu gestalten, gibt es weitere Power-Ups wie Bananen (Schlange wächst um zwei Körpereinheiten) oder Steine, die ebenfalls wie eine Wand den Effekt auf die Schlange haben, dass das Spiel beendet wird. 

Der Aktuelle Score soll gespeichert werden können, in einer json-Datei, um somit eine Art Bestenliste aufzustellen und mit einem Namen versehen werden können. 

### Umsetzung: 
Schritt 1: Programmieren des grundlegendes Spiels und der grundlegenden Logik 
            bei Apfel: Länge + 1
            bei Banane: Länge + 2 
            bei Stein/Schlange/Wand: Game Over
Schritt 2: 
