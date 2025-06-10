import numpy as np

import matplotlib.pyplot as plt
import json

from run_heap import aggregate_experiments

n_array = np.arange(100, 10001, 100)
lista = "lista5"

def plot_results():
    
    plt.figure(figsize=(19.2, 10.8))
    
    data = aggregate_experiments(n_array=n_array)
    

    x_array = n_array
    data = data / x_array
    plt.plot(
        x_array,
        data,
        label=f"Average comparisons",
    )
    plt.xlabel("n")
    plt.ylabel(f"time(s)")
    plt.title(f"Average comparisons - Binomial Heap")

    plt.legend()
    plt.grid(True)
    # plt.show()
    
    plt.savefig(f"{lista}/plots/Average comparisons - Binomial Heap", dpi=200, bbox_inches='tight')
    
    plt.close()
# Example usage
plot_results()