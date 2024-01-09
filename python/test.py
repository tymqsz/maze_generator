def find_combination(weights, target, path, result):
    current_sum = sum([weights[node] for node in path])

    if current_sum == target:
        result.append(path)
        return

    if current_sum > target:
        return

    for node in weights:
        if node not in path:
            new_path = path + [node]
            find_combination(weights, target, new_path, result)

# Given weights
weights = {
    (1, 0): 2.2,
    (1, 3): 0.31,
    (2, 0): 1.2,
    (2, 1): 1.15,
    (3, 3): 1.15,
    (5, 3): 0.825,
    (6, 0): 0.61,
    (6, 1): 0.76,
    (6, 3): 0.71,
    (7, 3): 3.35,
    (8, 1): 2.55,
    (8, 3): 1.3,
    (9, 2): 2.05,
    (10, 3): 0.575,
    (11, 3): 1.15,
    (13, 1): 0.95,
    (13, 3): 0.75,
    (14, 3): 1.03,
    (15, 1): 0.8,
    (15, 3): 0.65,
    (16, 0): 0.8,
    (16, 1): 1.0,
    (19, 3): 0.93,
    (20, 1): 0.675,
    (21, 1): 0.34,
    (23, 0): 0.5,
    (24, 0): 0.985
}

# Target sum
target_sum = 4.36

# Initialize result list
result = []

# Find combinations that sum up to the target
find_combination(weights, target_sum, [], result)

# Display the combinations if found
if result:
    print(f"Weights that sum up to {target_sum}:")
    for combination in result:
        print(', '.join([f"g{node[0]}[{node[1]}] = {weights[node]}" for node in combination]))
else:
    print(f"No combination found that sums up to {target_sum}.")
