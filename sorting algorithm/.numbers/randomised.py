from sys import argv
from random import sample

def main():
    with open('random.csv', 'w') as f:
        for i in sample(list(range(1, int(argv[1])+1)), int(argv[1])):
            f.write(f'{i}\n')

main()