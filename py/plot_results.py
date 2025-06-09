import numpy as np

import matplotlib.pyplot as plt
import json

n_array = np.arange(500, 2000, 100)
k = 4
lista = "lista5"

algorithms = ["Prim", "Kruskal"]

# Create a map of colors where the key is the algorithm
color_map = {
    "quicksort": "blue",
    "hybridsort": "green",
    "dualpivot": "red",
    "joelsort": "purple",
    "insertionsort": "orange",
    "mergesort": "yellow"
}

def get_averages(filename):
    data = ""
    with open(filename, "r") as f:
        data = json.load(f)
    
    averages = []
    
    for i, (n, values) in enumerate(data.items()):
        # Initialize the nested dictionary structure
        
        averages.append(sum(value for value in values) / len(values))
            
    print(averages)
    return averages

def plot_results():
    
    plt.figure(figsize=(19.2, 10.8))
    for algorithm in algorithms:
        averages = get_averages(f"{lista}/data/{algorithm}.txt")

        x_array = n_array
        
        plt.plot(
            x_array,
            averages,
            label=f"{algorithm}",
        )
    plt.xlabel("n")
    plt.ylabel(f"time(s)")
    plt.title(f"{', '.join(algorithms)} - time comparison")

    plt.legend()
    plt.grid(True)
    # plt.show()
    
    plt.savefig(f"{lista}/plots/{', '.join(algorithms)}_comparison", dpi=200, bbox_inches='tight')
    
    plt.close()
# Example usage
plot_results()