import sys
import string
import time
from container import *

# ----------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('Incorrect command line! '
              '  Waited:\n'
              '     command -f <infile> <outfile>\n'
              '  Or:\n'
              '     command -n <number> <outfile>\n')
        exit()
    print('==> Start')
    print('Conteiner is initializing')
    container = Container()
    print('Conteiner is initialized')
    if sys.argv[1] == "-f":
        ifile = open(sys.argv[2])
        container.readFromFile(ifile)
        ifile.close()
        outputFileName = sys.argv[3]
    elif sys.argv[1] == "-n":
        size = int(sys.argv[2])
        if size < 1 or size > 10000:
            print('Incorrect numer of plants = {}. Set 0 < number <= 10000\n'.format(size))
            exit()
        container.setRandomPlants(size)
        outputFileName = sys.argv[3]
    else:
        print('Incorrect command line! '
              '  Waited:\n'
              '     command -f <infile> <outfile>\n'
              '  Or:\n'
              '     command -n <number> <outfile>\n')
        exit()

    print("Plants are created")

    ofile = open(outputFileName, 'w')
    ofile.write("Filled container:\n")
    container.write(ofile)
    print("Container is written to outfile")

    print("Container is sorting")
    start_time = time.time()
    container.quick_sort()
    sortingTime = time.time() - start_time
    print("Container is sorted")
    print("Sorting time: {}".format(sortingTime))
    ofile.write("Sorting time: {}".format(sortingTime))
    ofile.write("\nSorted container:\n")
    container.write(ofile)
    ofile.close()
    print("Sorted container is written to outfile")
    print('==> Finish')
