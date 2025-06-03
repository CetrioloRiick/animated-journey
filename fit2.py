import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Load data from file
data = np.loadtxt('elabored_data/Acquisizione per misura incertezza ampiezza (R=330Ohm).txt', skiprows=1)

# Define the Gaussian function
def gaussian(x, a, x0, sigma):
    return a * np.exp(-(x - x0) ** 2 / (2 * sigma ** 2))

# Generate x data (assuming it's just the index of the data points)
x_data = np.arange(len(data))

# Fit the data to the Gaussian function
popt, pcov = curve_fit(gaussian, x_data, data)

# Plot the data and the fitted Gaussian curve
plt.scatter(x_data, data, label='Data')
plt.plot(x_data, gaussian(x_data, *popt), label='Fitted Gaussian', color='red')
plt.legend()
plt.show()