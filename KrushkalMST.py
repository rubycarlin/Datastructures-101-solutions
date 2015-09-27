import os

def getData(graphData, cycleData):
    n = int(raw_input("Enter the number of Edges : "))
    print("Enter the source destination weight for " + str(n) + " Edges")
    for i in xrange(n):
        src, dest, weight = map(int, raw_input().split())
        graphData += [(src,dest,weight)]
        if(not cycleData.has_key(src)):
            cycleData[src] = src
        if(not cycleData.has_key(dest)):
            cycleData[dest] = dest

def getRoot(src, cycleData):
    current = src
    root = src
    while cycleData[current] != current:
        current = root = cycleData[current]
    return root

def cycleFound(cycleData, src, dest):
    srcRoot = getRoot(src, cycleData)
    destRoot = getRoot(dest, cycleData)
    if(srcRoot == destRoot):
        return True
    return False

def changeRoot(cycleData, root, dest):
    destRoot = getRoot(dest, cycleData)
    cycleData[destRoot] = root
    
def constructTree(graphData, cycleData):
    MSTEdges = []
    #Sort based on the weight
    graphData.sort(key=lambda k: k[2])
    print graphData
    print cycleData
    for data in graphData:
        if(not cycleFound(cycleData, data[0], data[1])):
            root =getRoot(data[0], cycleData)
            changeRoot(cycleData, root, data[1])
            print cycleData
            MSTEdges += [(data[0], data[1])]
    return MSTEdges
            

def MinimumSpanningTree():
    graphData = []
    cycleData = {}
    MSTEdges = []
    getData(graphData, cycleData)
    MSTEdges = constructTree(graphData, cycleData)
    print MSTEdges

MinimumSpanningTree()


    
