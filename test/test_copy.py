import ast

with open('phone.txt', 'r') as file:
    data = file.readlines()
    data = ast.literal_eval(data[0][:-1])
    for d in data:
        print(d[:4]+''+d[4:])