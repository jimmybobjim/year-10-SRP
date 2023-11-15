from sys import argv
from time import time_ns



def bubbleSort(elems: list[int]) -> list[int]:
    for i in range(len(elems)):
        swapped = False

        for j in range(len(elems)-1):
            if elems[j] > elems[j+1]:
                swapped = True
                elems[j], elems[j+1] = elems[j+1], elems[j]
            
            #print(f'i: {i} j: {j}')
        
        if not swapped:
            break
            
    return elems



def main() -> None:
    output = False
    if len(argv) == 1:
        file = 'reversed.csv'
    else:
        file = argv[1]
    
    with open(f'../.numbers/{file}', 'r') as f:
        f = f.read().split('\n')

    for i, v in enumerate(f):
        f[i] = int(v)

    startTime = time_ns()
    result = bubbleSort(f)
    endTime = time_ns()

    if output:
        print(result)
        
    print(f'\nexecution time (ns): {endTime - startTime}')



if __name__ == '__main__':
    main()