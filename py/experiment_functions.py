import subprocess
import json
import numpy as np
import time

n_array = np.arange(500, 2001, 100)

lista = "lista5"

def run_experiment(input_src="completeGraph.exe", algorithm="Prim", n=30, additional_args=[]):
    # data = subprocess.run(['lista2/randoms.out 30 | lista2/quicksort.out'], stdout=subprocess.PIPE).stdout.decode('utf-8')
    # print(data)
    
    start_time = time.time()
    numbers = subprocess.Popen([f"{lista}/{input_src}", str(n)], stdout=subprocess.PIPE)
    process = subprocess.Popen([f"{lista}/main{algorithm}.exe"] + additional_args, stdin=numbers.stdout, stdout=subprocess.PIPE)
    process.communicate()  # Wait for process to finish
    end_time = time.time()
    result = end_time - start_time
    print(f"Time: {result}")
    
    return result

def aggregate_experiments(algorithms=["Prim"], n_array=[40, 50], k=4):
    for algorithm in algorithms:
        with open(f"{lista}/data/{algorithm}.txt", "w") as f:
            results = {}
            for n in n_array:
                print(f"Running experiment for n={n} with algorithm={algorithm}")
                n_int = int(n)
                results[n_int] = []
                for i in range(k):
                    results[n_int].append(run_experiment(n=n_int, algorithm=algorithm))
                
            json.dump(results, f)
            f.write("\n")
    
    
# run_experiment(n=3000)

aggregate_experiments(n_array=n_array, algorithms=["Kruskal", "Prim"])
# inputs = ["randoms.exe", "ascending.exe"]
# for input_src in inputs:
#     aggregate_experiments(n_array=n_array, input_src=input_src, treeType="SplayTree", k=20)