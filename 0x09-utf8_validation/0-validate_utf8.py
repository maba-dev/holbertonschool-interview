#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding"""
    i = 0
    while i < len(data):
        num_bytes = 0
        if (data[i] & 128) == 0:
            num_bytes = 1
        elif (data[i] & 224) == 192:
            num_bytes = 2
        elif (data[i] & 240) == 224:
            num_bytes = 3
        elif (data[i] & 248) == 240:
            num_bytes = 4
        else:
            return False
        for j in range(1, num_bytes):
            if i + j >= len(data) or (data[i + j] & 192) != 128:
                return False
        i += num_bytes
    return True
