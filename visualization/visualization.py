#!/usr/bin/env python3
import matplotlib.pyplot as plt
import argparse
import sys
import numpy as np



class DataSet:
    xPoints = np.array([])
    yPoints = np.array([])
    path = None

    def __init__(self, filePath):
        self.path = filePath

    def parse(self):
        if self.path == None:
            print ("Path argument is empty. Refusing to parse")
            return 
        
        with open(self.path, "r") as file:
            lines = file.readlines()

        # data = []
        for line in lines[1:]:  # Skip the first line (header)
            parts = line.strip().split() # Split by whitespace
            if len(parts) == 2:
                x, y = map(float, parts)
                self.xPoints = np.append(self.xPoints, x)
                self.yPoints = np.append(self.yPoints, y)

    def plot(self):
        self.parse()

        plt.figure(figsize=(12, 6))
        plt.plot(self.xPoints, self.yPoints, markersize=1, marker="o", linestyle="-", linewidth=0.3, color="b", label="std_dev=45.0 kernel_size=55")

        plt.xlabel("X Values")
        plt.ylabel("Y Values")
        plt.title("Filtered visualization")
        plt.legend()
        plt.grid(True)

        # Save the plot as a file (change format as needed)
        # plt.savefig("plot.png", dpi=300, bbox_inches="tight")  # Save as PNG with high quality

        plt.show()  # Show the plot

                


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Generate a dataset for the test')
    parser.add_argument('--path', dest='path', help='path to save the dataset to.')
    parser.set_defaults(path=None)
    args = parser.parse_args()

    if args.path == None:
        print ("Path argument can't be empty")
        sys.exit()
    
    dataSet = DataSet(args.path)
    dataSet.plot()

