#!/usr/bin/python3
""" a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """a method that determines if all the boxes can be opened"""
    result = [0]
    index_boxe = 0
    number_boxe = len(boxes)
    for index_boxe, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < number_boxe and key not in result and key != index_boxe:
                result.append(key)
    if len(result) == number_boxe:
        return True
    else:
        return False
