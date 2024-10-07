#
# to generate random data:
# python ./gen_data.py 1 1000000 > 1000000.dat
#
# you can verify that data by
# cat 1000000.dat | sort -g >1000000s.dat
# vi 1000000s.dat
#

import sys
import random

start_num = int(sys.argv[1])
end_num = int(sys.argv[2])

data = range(start_num, end_num)
random.shuffle(data)

for x in range(len(data)):
#    print(str(data[x]) + '\n')
    print(data[x])

