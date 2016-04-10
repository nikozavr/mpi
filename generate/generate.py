import argparse
import numpy as np


parser = argparse.ArgumentParser(description='Generate some random float array and store to file')
parser.add_argument('--min', type=int)
parser.add_argument('--max', type=int)
parser.add_argument('--count', type=int)
parser.add_argument('--output', type=str)

args = parser.parse_args(sys.argv[1::])

s = np.random.uniform(args.min, args.max, args.count)

np.savetxt(args.output, s, delimiter=',') 