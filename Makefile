#arguments pour l'étape de compilation: on met tous les avertissements
CPPFLAGS := -Wall -Wextra

# arguments pour l'édition de liens, bibliothèques externes
LDFLAGS := -lm 


# nom du compilateur 
CPP := g++


# Quelques remarques : -E fait uniquement la précompilation; -o <file> place l'output dans le fichier file; -c compile et assemble mais ne fait pas l'édition de liens


#cible par défaut
all: TD2


# Cible TD2, compilation de tous les fichiers .cpp du projet TD2, à partir des fichiers objets .o
# Ensuite l'édition de liens, ie la récupération de toutes les composantes que le programme utilise, est faite
# Enfin on éxecute directement le programme TD2
TD2: TD2.o point.o polygone.o
	$(CPP) -o TD2 $^ $(LDFLAGS)
	./TD2




#Compilation séparée de TD2.cpp dans le fichier TD2.o
TD2.o: TD2.cpp point.h polygone.h
	$(CPP) -o $@ -c $< $(CPPFLAGS)

# Compilation séparée (avec -c dans le fichier point.o avec -o) d'une classe en un fichier objet 
point.o: point.cpp point.h polygone.h
	$(CPP) -o $@ -c $< $(CPPFLAGS)



# Certains éditeurs créent aussi des .bak ou ~, mais apparemment pas ici 
clean: 
	rm -f *.o 


mrproper: clean 
	rm -f TD2

#aussi makedepend mais pas installé sur les ordis du magistère




