import collections
class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        # complicated: convert to values for vertices => unweighted edges
        # here we use weighted edges
        # diveding => undirected
        # corner: zero (don't include to the graph)
        
        # define DFS method    
        def DFS(v1, v2, discoveredSet):
            """
            :type v1: str
            :type v2: str
            :type discoveredSet: set[str] # to avoid cycle
            :rtype: float
            """
            if v2 in G[v1]:
                discoveredSet.add(v2)
                return W[v1,v2]
            # to avoid infinity, record discover or not of a vertice
            else:
                for v in G[v1]:
                    if v not in discoveredSet:
                        discoveredSet.add(v)
                        re = DFS(v,v2,discoveredSet)
                        if re != 0:
                            return W[v1,v] * re
                return 0
            
        # generate a graph
        # use default to give 0 if the pair is not in W
        # globle v.r.s
        G, W = collections.defaultdict(set), collections.defaultdict(float)
        for (A, B), V in zip(equations, values):
            G[A], G[B] = G[A] | {B}, G[B] | {A}   # |:union set, do DFS/BFS later so not need enlarge to all hiden edges
            W[A, B], W[B, A] = V, 1.0 / V  # values for edges
            
        # all queries
        result = list()
        for i in queries:
            # globle in class, coz used in whole problem
            discoveredSet = set() 
            ri = DFS(i[0],i[1],discoveredSet)
            if ri == 0:
                result.append(-1.0)
            else:
                result.append(ri)
        return result
