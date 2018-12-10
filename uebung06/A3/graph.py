#python

import matplotlib.pyplot as plt
import numpy as np
import sys
import readline

words = []
probs = []

while(True):
    s = input()
    if(not sys.stdin.isatty()):
        break;
    words.append(s.split(": ")[0])
    probs.append(s.split(": ")[1])
    print(words, probs)

# sort your values in descending order
indSort = np.argsort(values)[::-1]

# rearrange your data
labels = np.array(labels)[indSort]
values = np.array(values)[indSort]

indexes = np.arange(len(labels))

bar_width = 0.35

plt.bar(indexes, values)

# add labels
plt.xticks(indexes + bar_width, labels)
plt.show()