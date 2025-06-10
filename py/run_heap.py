import subprocess
import json
import numpy as np
import time

n_array = np.arange(100, 10001, 100)

lista = "lista5"
exec = "heap/mainHeap"

def run_experiment(n=30, additional_args=[]):
    # data = subprocess.run(['lista2/randoms.out 30 | lista2/quicksort.out'], stdout=subprocess.PIPE).stdout.decode('utf-8')
    # print(data)
    
    # start_time = time.time()
    # numbers = subprocess.Popen([f"{lista}/{input_src}", str(n)], stdout=subprocess.PIPE)
    process = subprocess.Popen([f"{lista}/{exec}.exe", str(n)] + additional_args, stdout=subprocess.PIPE)
    output, _ = process.communicate()
    output = int(output.decode('utf-8').strip())
    print(f"Output: {output}")
    
    return output


# inputs = ["randoms.exe", "ascending.exe"]
# for input_src in inputs:
#     aggregate_experiments(n_array=n_array, input_src=input_src, treeType="SplayTree", k=20)

def aggregate_experiments(n_array):
    results = []

    for n in n_array:
        results.append(run_experiment(n=n))
        
    return results

# aggregate_experiments(n_array=[10])