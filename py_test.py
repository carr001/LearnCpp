#pragma once
import os
import numpy as np
# 用C++调用Python失败原因：
# python中包无法加载numpy，numpy在release模式可以，在debug模式下不行
def hello():
    print("in hello")
def hello2():
    print("in hello2")
    print(np.zeros(2))
    print("out hello2")
def hello3(s):
    print("in hello3")
    print(type(s))
    print(s)
    print("out hello2")
    return s+" hello3 is out"

import os
import networkx as nx
import matplotlib.pyplot as plt
def display_binary_tree(edges):
    print("BBBBBBBBBBBBBBB")
    graph = nx.DiGraph()
    print(type(edges))
    print(edges)
    print("CCCCCCCCCCCCC")
    graph.add_edges_from(edges)
    print("DDDDDDDDDDDDD")
    nx.draw_networkx(graph)
    print("EEEEEEEEEEE")
    plt.show()





