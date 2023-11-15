from sys import argv

def main():
    with open('reversed.csv', 'w') as f:
        for i in range(int(argv[1]), 1, -1):
            f.write(f'{i}\n')
        
        f.write('1')

main()