import os

def getData(edgeData, parentData, levelData):
    n = int(raw_input("Enter the number of edges : "))
    print("Enter the src destination for " + str(n) + "edges")
    for i in xrange(n):
        src , dest = map(int, raw_input().split())
        edgeData += [(src, dest)]
        if (not parentData.has_key(src)):
            parentData[src] = src
        if (not parentData.has_key(dest)):
            parentData[dest] = dest
        if (not levelData.has_key(src)):
            levelData[src] = 0
        if (not levelData.has_key(dest)):
            levelData[dest] = 0
def findRoot(parentData, src):
    current = src
    while(parentData[current] != current):
        current = parentData[current]
    return current

def construct(edgeData, parentData, levelData):
    for edge in edgeData:
        #print parentData
        #print levelData
        srcRoot = findRoot(parentData, edge[0])
        destRoot = findRoot(parentData, edge[1])
        if( levelData[srcRoot] <= levelData[destRoot]):
            parentData[srcRoot] = destRoot
            if(levelData[destRoot] == levelData[srcRoot]):
                levelData[destRoot] += 1
                
        else:
            parentData[destRoot] = srcRoot
            if(levelData[destRoot] == levelData[srcRoot]):
                levelData[srcRoot] += 1
    print parentData
        
                
def pathCompressionUnionFind():
    edgeData = []
    parentData = {}
    levelData = {}
    getData(edgeData, parentData, levelData)
    construct(edgeData, parentData, levelData)
pathCompressionUnionFind()
