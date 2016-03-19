#!/usr/bin/python3
#http://scipy.org/getting-started.html

import argparse
import numpy as np
from scipy import special, optimize
import matplotlib.pyplot as plot

def main():
    # parse command line arguments
    parser = argparse.ArgumentParser(usage=__doc__)
    parser.add_argument('--order', type=int, default=3, help='order of bessel function')
    parser.add_argument('--output', default='junk.png', help='output image file')
    args = parser.parse_args()

    # compute maximum
    f = lambda x: -special.jv(args.order, x)
    solution = optimize.minimize(f, 1.0)

    # plot
    x = np.linspace(0, 10, 5000)
    plot.plot(x, special.jv(args.order, x), '-', solution.x, -solution.fun, 'o')
    
    # produce output
    plot.savefig(args.output, dpi=96)

if __name__ == "__main__":
    main()
