import numpy as np
import matplotlib.pyplot as plt
import sys 

#---------- Position h=0.1 ----------

tab = np.loadtxt("eulerprog_0.100000.txt", skiprows=3)
t = tab[:,0]
pos_exact = tab[:,1]
plt.plot(t, pos_exact, label="Position théorique")

pos_estime1 = tab[:,3]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, pos_estime1, label="Position Euler")  

tab = np.loadtxt("pointMilieu_0.100000.txt", skiprows=3)
t = tab[:,0]
pos_estime2 = tab[:,3]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, pos_estime2, label="Position Point Milieu")  

tab = np.loadtxt("rk4_0.100000.txt", skiprows=3)
t = tab[:,0]
pos_estime3 = tab[:,3]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, pos_estime3, label="Position RK4")  

plt.legend(prop={'size': 7}) 
plt.title("Positions avec h=0.1", fontsize=8)
plt.grid()

plt.xlabel("t")                               # <== variable d'abscisse
plt.ylabel("positions")                                   # <== variable d'ordonnee

plt.savefig("positions0.1.pdf") # sauvegarde du fichier.
plt.show()

#---------- Vitesse h=0.1 ----------

tab = np.loadtxt("eulerprog_0.100000.txt", skiprows=3)
t = tab[:,0]
vit_exact = tab[:,2]
plt.plot(t, vit_exact, label="Vitesse théorique")

vit_estime1 = tab[:,4]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, vit_estime1, label="Vitesse Euler")  

tab = np.loadtxt("pointMilieu_0.100000.txt", skiprows=3)
t = tab[:,0]
vit_estime2 = tab[:,4]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, vit_estime2, label="Vitesse Point Milieu")  

tab = np.loadtxt("rk4_0.100000.txt", skiprows=3)
t = tab[:,0]
vit_estime3 = tab[:,4]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, vit_estime3, label="Vitesse RK4")  

plt.legend(prop={'size': 7}) 
plt.title("Vitesses avec h=0.1", fontsize=8)
plt.grid()

plt.xlabel("t")                              
plt.ylabel("vitesse")                                   

plt.savefig("vitesse0.1.pdf") # sauvegarde du fichier.
plt.show()

#---------- Vitesses en fonction de position 0.1 ----------

plt.plot(pos_estime1, vit_estime1, label="Euler")
plt.plot(pos_estime2, vit_estime2, label="Point Milieu")
plt.plot(pos_estime3, vit_estime3, label="RK4")
plt.legend(prop={'size': 7}) 
plt.title("Vitesses en fonction de la position pour h=0.1", fontsize=8)
plt.grid()

plt.xlabel("position")                               
plt.ylabel("vitesse")                                  

plt.savefig("vit(pos)0.1.pdf")
plt.show()

#---------- Position h=0.01 ----------

tab = np.loadtxt("eulerprog_0.010000.txt", skiprows=3)
t = tab[:,0]
pos_exact = tab[:,1]
plt.plot(t, pos_exact, label="Position théorique")
pos_estime1 = tab[:,3]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, pos_estime1, label="Position Euler")  

tab = np.loadtxt("pointMilieu_0.010000.txt", skiprows=3)
t = tab[:,0]
pos_exact = tab[:,1]
plt.plot(t, pos_exact, label="Position théorique")
pos_estime2 = tab[:,3]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, pos_estime2, label="Position Point Milieu")  

tab = np.loadtxt("rk4_0.010000.txt", skiprows=3)
t = tab[:,0]
pos_exact = tab[:,1]
plt.plot(t, pos_exact, label="Position théorique")
pos_estime3 = tab[:,3]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, pos_estime3, label="Position RK4")  

plt.legend(prop={'size': 7}) 
plt.title("Positions avec h=0.01", fontsize=8)
plt.grid()

plt.xlabel("t")
plt.ylabel("position")                                   

plt.savefig("position0.01.pdf") # sauvegarde du fichier.
plt.show()

#---------- Vitesse h=0.01 ----------

tab = np.loadtxt("eulerprog_0.010000.txt", skiprows=3)
t = tab[:,0]
vit_exact = tab[:,2]
plt.plot(t, pos_exact, label="Vitesse théorique")

vit_estime1 = tab[:,4]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, vit_estime1, label="Vitesse Euler")  

tab = np.loadtxt("pointMilieu_0.010000.txt", skiprows=3)
t = tab[:,0]
vit_exact = tab[:,2]
plt.plot(t, pos_exact, label="Vitesse théorique")
vit_estime2 = tab[:,4]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, vit_estime2, label="Vitesse Point Milieu")  

tab = np.loadtxt("rk4_0.010000.txt", skiprows=3)
t = tab[:,0]
vit_exact = tab[:,2]
plt.plot(t, pos_exact, label="Vitesse théorique")
vit_estime3 = tab[:,4]
#pos_err = tab[:,5]
#vit_err = tab[:,6]
plt.plot(t, vit_estime3, label="Vitesse RK4")  

plt.legend(prop={'size': 7}) 
plt.title("Vitesses avec h=0.01", fontsize=8)
plt.grid()

plt.xlabel("t")                               
plt.ylabel("vitesse")                                   

plt.savefig("vitesse0.01.pdf") # sauvegarde du fichier.
