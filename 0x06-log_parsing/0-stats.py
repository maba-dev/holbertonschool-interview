#!/usr/bin/python3
""" a script that reads stdin line by line and computes metrics:"""


import sys


i = 1
status_code = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}
file_size = 0
for idx_line in sys.stdin:
    idx_line = idx_line.split()
    try:
        if (idx_line[len(idx_line) - 2] in status_code):
            status_code[idx_line[len(idx_line) - 2]] += 1
        if (idx_line[len(idx_line) - 1].isdigit()):
            file_size += int(idx_line[len(idx_line) - 1])
    except IndexError:
        continue
    if (i % 10 == 0 and i != 0):
        print("File size: {}".format(file_size))
        for key, value in sorted(status_code.items()):
            if value != 0:
                print("{}: {}".format(key, value))
    i += 1
print("File size: {}".format(file_size))
for key, value in sorted(status_code.items()):
        if value != 0:
            print("{}: {}".format(key, value))
