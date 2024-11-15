#arguments pour l'étape de compilation: on met tous les avertissements
CPPFLAGS := -Wall -Wextra

# arguments pour l'édition de liens, bibliothèques externes
LDFLAGS := -lm 


# nom du compilateur 
CPP := g++


# Quelques remarques : -E fait uniquement la précompilation; -o <file> place l'output dans le fichier file; -c compile et assemble mais ne fait pas l'édition de liens


#cible par défaut
all: TD3


# compilation finale (avec édition de liens)
TD3: TD3.o complexe.o reseau.o
	$(CPP) -o TD3 $^ $(LDFLAGS)
	./TD3


# compilation séparée
TD3.o: TD3.cpp complexe.h reseau.h 
	$(CPP) -o $@ -c $< $(CPPFLAGS)


complexe.o: complexe.cpp complexe.h
	$(CPP) -o $@ -c $< $(CPPFLAGS)

reseau.o: reseau.cpp reseau.h
	$(CPP) -o $@ -c $< $(CPPFLAGS)



# Certains éditeurs créent aussi des .bak ou ~, mais apparemment pas ici 
clean: 
	rm -f *.o 


mrproper: clean 
	rm -f TD2

#aussi makedepend mais pas installé sur les ordis du magistère




