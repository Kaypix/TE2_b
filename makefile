CPPC = g++
CFLAGS = -W -Wall -Wshadow -pedantic -std=c++17
SRCS = fcts.cpp util.cpp methodes.cpp main.cpp
RM = rm -f

OBJS = $(SRCS:.cpp=.o) # liste des fichiers objets

# Première règle => pour l'exécutable
TE2_1b.exe : $(OBJS)
	$(CPPC) $(CFLAGS) $^ -o $@ 

main.o : main.cpp fcts.h methodes.h util.h
	$(CPPC) -c $(CFLAGS) $<

# Exemple de règle pour fcts.o
fcts.o : fcts.cpp fcts.h
	$(CPPC) -c $(CFLAGS) fcts.cpp

# ou mieux avec $<, qui désigne la première dépendance
#	$(CPPC) -c $(CFLAGS) $<

# Ecrire ci-dessous les règles pour les autres fichiers sources
methodes.o : methodes.cpp methodes.h
	$(CPPC) -c $(CFLAGS) $<

util.o : util.cpp util.h
	$(CPPC) -c $(CFLAGS) $<

# Exemples de règles pour le ménage
.PHONY: clean super_clean

clean :
	$(RM) $(OBJS)

super_clean :
	$(RM) $(OBJS) TE2_1b.exe
