import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Definisci la funzione gaussiana
def gauss(x, A, mu, sigma):
    return A * np.exp(-(x - mu)**2 / (2 * sigma**2))

# Leggi i dati
filename = "elabored_data/Acquisizione per misura incertezza ampiezza (R=330Ohm).txt"  # Cambia con il tuo nome file
data = np.loadtxt(filename, skiprows=1, delimiter='\t')

# Crea l'istogramma
counts, bin_edges = np.histogram(data, bins=10, density=True)
bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2

# Valori iniziali approssimati
A0 = np.max(counts)
mu0 = bin_centers[np.argmax(counts)]
sigma0 = (np.max(bin_centers) - np.min(bin_centers)) / 10

p0 = [A0, mu0, sigma0]

# Fit
popt, pcov = curve_fit(gauss, bin_centers, counts, p0=p0)

# Plot
plt.bar(bin_centers, counts, width=np.diff(bin_edges), align='center', alpha=0.6, color='b', label='Istogramma')
plt.plot(bin_centers, gauss(bin_centers, *popt), 'r-', label='Fit Gaussiano')
plt.xlabel("Valore")
plt.ylabel("Densità")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# Stampa i parametri
print(f"A = {popt[0]:.5f}, mu = {popt[1]:.5f}, sigma = {popt[2]:.5f}")
""" 
# Leggi i dati
filename = "elabored_data/Acquisizione per misura incertezza ampiezza (R=330Ohm).txt"  # Cambia con il tuo nome file
data = np.loadtxt(filename, skiprows=1, delimiter='\t')

# Crea l'istogramma
counts, bin_edges = np.histogram(data, bins=10, density=True)
bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2

# Valori iniziali approssimati
A0 = np.max(counts)
mu0 = bin_centers[np.argmax(counts)]
sigma0 = (np.max(bin_centers) - np.min(bin_centers)) / 10

p0 = [A0, mu0, sigma0]

# Fit
popt, pcov = curve_fit(gauss, bin_centers, counts, p0=p0)

# Plot
plt.bar(bin_centers, counts, width=np.diff(bin_edges), align='center', alpha=0.6, color='b', label='Istogramma')
plt.plot(bin_centers, gauss(bin_centers, *popt), 'r-', label='Fit Gaussiano')
plt.xlabel("Valore")
plt.ylabel("Densità")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()

# Stampa i parametri
print(f"A = {popt[0]:.5f}, mu = {popt[1]:.5f}, sigma = {popt[2]:.5f}")



 """