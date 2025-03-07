import numpy as np
import matplotlib.pyplot as plt
import sys 


# Variable a modifier avant execution

list_fichier = ["eulerprog_0.200000.txt","eulerprog_0.100000.txt", "eulerprog_0.010000.txt", "pointMilieu_0.200000.txt", "pointMilieu_0.100000.txt", "pointMilieu_0.010000.txt", "rk4_0.200000.txt", "rk4_0.100000.txt", "rk4_0.010000.txt"]
list_legend = ["eulerprog0.2","eulerprog0.1", "eulerprog0.01", "pointMilieu0.2", "pointMilieu0.1", "pointMilieu0.01", "rk40.2", "rk40.1", "rk40.01"]
for fichier in list_fichier:
  tab = np.loadtxt(fichier)
  x = tab[:,0]
  estime = tab[:,2]
  err = tab[:,3]
  plt.plot(x, estime, label="Observée")
  print(fichier, "Le max de l'erreur est :", np.max(err))

tab_th = np.loadtxt("eulerprog_0.100000.txt")
exact = tab_th[:,1]
x_th = tab_th[:,0]
plt.plot(x_th, exact, label="Théorique")   

for legend in list_legend :
  plt.legend(legend)

#Erreur max : (5.17) pour 0.1 et (9.33) pour 0.2 pour la méthode d'euler

# Creation du graphique

#plt.title( titre, fontsize=8)
plt.grid()

plt.xlabel("x")                               # <== variable d'abscisse
plt.ylabel("y")                                   # <== variable d'ordonnee

plt.savefig("fig.pdf") # sauvegarde du fichier.
plt.show()
plt.clf() # nettoyage ('clear figure')

'''
plt.plot(x,err, label="Erreur entre les deux solutions")
plt.xlabel("x")                                   # <== variable d'abscisse
plt.ylabel("y")                                   # <== variable d'ordonnee

plt.legend()
plt.show()

#Lire l'entête

# ou bien indiquer le nom du fichier sur la ligne de commande
if len(sys.argv) > 1:
    nomfichier = sys.argv[1]

try:      # ouverture du fichier de donnees
  fich  = open(nomfichier, "r")
except:
  print(" ! Impossible d'ouvrir le fichier %s."%nomfichier )
  print(" ! Verifier le chemin.\n")
  exit()

# Lecture des lignes d'entete
ligne = fich.readline().replace("\n","") # sans caractere de fin de ligne
entete= [ ]
while( ligne[0] == "#" ):
   entete.append( ligne[1:] )
   ligne =  fich.readline().replace("\n","")
fich.close()
print( " > fichier %s : %d lignes d'entete"%( nomfichier, len(entete) ) )

# concatenation des entetes en une seule ligne de titre :
titre = " ".join(entete)
'''