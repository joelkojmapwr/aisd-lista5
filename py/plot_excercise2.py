import numpy as np

import matplotlib.pyplot as plt
import json

n_array = np.arange(400, 6001, 400)
lista = "lista5"

def get_averages(filename):
    data = ""
    with open(filename, "r") as f:
        for line in f:
            n_str, value_str = line.strip().split()
            if data == "":
                data = {}
            n = int(n_str)
            value = float(value_str)
            if n not in data:
                data[n] = []
            data[n].append(value)
    
    averages = []
    min_values = []
    max_values = []
    for i, (n, values) in enumerate(data.items()):
        # Initialize the nested dictionary structure
        
        averages.append(sum(value for value in values) / len(values))
        min_values.append(min(values))
        max_values.append(max(values))
    print("Averages:", averages)
    print("Min values:", min_values)
    print("Max values:", max_values)
            
    print(averages)
    return averages, min_values, max_values

def plot_results():
    
    plt.figure(figsize=(19.2, 10.8))
    
    averages, min_values, max_values = get_averages(f"{lista}/data/results.txt")

    x_array = n_array
    
    plt.plot(
        x_array,
        averages,
        label=f"Average",
    )
    plt.plot(
        x_array,
        min_values,
        label=f"Min",
        linestyle='--',
        color='green'
    )
    plt.plot(
        x_array,
        max_values,
        label=f"Max",
        linestyle='--',
        color='red'
    )
    plt.xlabel("n")
    plt.ylabel(f"Propagation cycles")
    plt.title(f"Propagation cycles - min, max and average comparison")

    plt.legend()
    plt.grid(True)
    # plt.show()
    
    plt.savefig(f"{lista}/plots/propagation_cycles", dpi=200, bbox_inches='tight')
    
    plt.close()
# Example usage
plot_results()