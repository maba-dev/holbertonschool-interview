#!/usr/bin/python3
"""
    a method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file
"""


def minOperations(n):
    """calculates the fewest number of operations needed to result"""
    if type(n) is not int or n < 2:
        return 0
    number_H = 1
    copy_H = 1
    result = 1
    while number_H < n:
        if n % number_H == 0 and number_H != copy_H:
            copy_H = number_H
            result = result + 1
        number_H = number_H + copy_H
        result = result + 1
    if number_H == n:
        return result
    return 0
