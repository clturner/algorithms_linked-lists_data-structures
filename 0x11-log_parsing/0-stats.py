#!/usr/bin/python3
"""
parses a log
"""

import sys
import os
import signal


def keyboardInterruptHandler(signal, frame):
    """keyboard interupt"""
    print("File size:", my_sum)
    for key in sorted(error_code_dict.keys()):
        if error_code_dict[key] > 0:
            print("{}: {}".format(key, error_code_dict[key]))
    exit(0)

signal.signal(signal.SIGINT, keyboardInterruptHandler)

line_count = 0
my_sum = 0

error_code_dict = {"200": 0, "301": 0, "400": 0, "401": 0,
                   "403": 0, "404": 0, "405": 0, "500": 0}

for line in sys.stdin:
    line_count += 1
    split = line.split(" ")
    my_sum = my_sum + int(split[-1])
    err_code = int(split[-2])

    if err_code == 301:
        error_code_dict["301"] += 1
    elif err_code == 200:
        error_code_dict["200"] += 1
    elif err_code == 400:
        error_code_dict["400"] += 1
    elif err_code == 401:
        error_code_dict["401"] += 1
    elif err_code == 403:
        error_code_dict["403"] += 1
    elif err_code == 404:
        error_code_dict["404"] += 1
    elif err_code == 405:
        error_code_dict["405"] += 1
    elif err_code == 500:
        error_code_dict["500"] += 1

    if line_count is 10:
        print("File size:", my_sum)
        for key in sorted(error_code_dict.keys()):
            if error_code_dict[key] > 0:
                print("{}: {}".format(key, error_code_dict[key]))
        line_count = 0
