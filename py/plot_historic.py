import subprocess
import json
import numpy as np
import time
from matplotlib import pyplot as plt


lista = "lista5"
exec = "heap/mainHeap"

def run_experiment(n=500, additional_args=[]):
    # data = subprocess.run(['lista2/randoms.out 30 | lista2/quicksort.out'], stdout=subprocess.PIPE).stdout.decode('utf-8')
    # print(data)
    
    # start_time = time.time()
    # numbers = subprocess.Popen([f"{lista}/{input_src}", str(n)], stdout=subprocess.PIPE)
    process = subprocess.Popen([f"{lista}/{exec}.exe", str(n)] + additional_args, stdout=subprocess.PIPE)
    output, _ = process.communicate()
    output = output.decode('utf-8').strip().split('\n')
    output = [int(line) for line in output if line]
    print(f"Output: {output}")
    
    return output


def plot_results(iteration=0):
    
    plt.figure(figsize=(19.2, 10.8))
    
    data = run_experiment()
    

    x_array = np.arange(0, len(data))
    plt.scatter(
        x_array,
        data,
        label="Comparisons after each operation",
        s=10  # size of points
    )
    plt.xlabel("n")
    plt.ylabel("time(s)")
    plt.title("Comparisons after each operation - Binomial Heap")

    plt.legend()
    plt.grid(True)
    # plt.show()
    
    plt.savefig(f"{lista}/plots/Historic comparisons - Binomial Heap_{iteration}", dpi=200, bbox_inches='tight')
    
    plt.close()
# Example usage

for i in range(5):
    plot_results(i)