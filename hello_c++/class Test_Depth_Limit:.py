class Test_Depth_Limit:

  """"
  
  
 You are given a 2D grid that represents a small map.

S = start position

G = goal position

# = obstacle (cannot cross)

. = free cell

Your task is to write a Python program that finds a path from S to G.

You must implement ONE of the following:

Uninformed Search → Breadth-First Search (BFS)

Informed Search → A* using Manhattan distance heuristi 
  
  
  
  
  
  
  
  
  

  
  """



















    def __init__(self):
        pass
    

    def structure_node (self):
      
      status = { 'A': ['B','C'], 'B':['D'], 'C':['G'] }
      status_backup = status.copy()
      goal = 'G'
      comb = dict()
      items = ''
      comb = self.dictionary_depth(status_backup, comb, goal)
      self.print_path(comb, goal)

    
    def index_goal (self, goal, status):
        key_value = goal
        possible_path = list()
        for s, v in status.items():
            possible_path.append(s,v)
            if v == goal:
                break
        next_key = possible_path[-1][0]
        for s in possible_path.reverse():
            k, v = s
            if v == next_key:
                next_key = k
                print(k)
    
    def dictionary_depth(self,status_backup, comb, goal):
      for i in status_backup.keys():
            # REVERT KEYS           
            for s in status_backup[i]:
                comb [(s)] = i
                if  goal in s:
                    return comb
                    break 

    def print_path(self, comb, goal):
       # { 'B': ['A']'C': [A], 'D' = 'B', 'G':['C'] }
        order  = comb[goal]
        next_key = order
        path = list()
        path.append(goal)
        list_keys = list({x for x in comb.keys()})
        list_keys.reverse()
        for k in list_keys:
            if next_key == k:
                path.append(k)
                next_key = comb[k]
        print(path.sort(reverse=True))

    


    
    def bread_first_search(self):
       status = { 'A': ['B','C'], 'B':['D'] }
       keys_list = list ({ x for x in status.keys()})
       keys_list.sort()
       path = list()
       path.append(keys_list[0])
       self.order_bread(keys_list[0], status, path, keys_list[-1])


    def order_bread(self, keys, status, path, key_last):
        add = path.pop(0)
        loop = status[keys]
        for n in loop:
                combine_path=  add + n
                path.append(combine_path)
        if key_last == keys:
            return path 
        ls = path.copy()[0]
        self.order_bread(ls[-1], status , path,  key_last)




    def get_last_state(path):
        return path [-1]

        

    def limit_search(self, status, goal, limit):
        current_path = list()
        visited_nodes = list()
        dictionary_path = dict()
        visited_nodes.append(status[-1])
        ns = self.depth_search_limit(status, current_path, visited_nodes, dictionary_path, limit)
    

    
    def depth_search_limit(self, status, current_path, visited_nodes, dictionary_path, limit):

        size_path =len((status[0]))
        index = 0
        for i in range(index, size_path-1):
            array_state = list(visited_nodes.copy()[-1])
            # I DO NOT NEED RANGE BECAUSE IT ALWAYS LAST
            for n in (i+1,size_path):
                prev = array_state [i]
                after = array_state [n]
                array_state [i] = after
                array_state [n] = prev
                if tuple(array_state) in visited_nodes:
                     visited_nodes[1:].clear()
                     break
                # I USE A LIST OF SET FOR UPDATE THE PATH IN DEPTH
                else:
                    visited_nodes.append(tuple(array_state))
                    dictionary_path[0] =  visited_nodes.copy()
                    if len(dictionary_path[0]) == limit -1:
                        return dictionary_path
                    # VERIFY IF I FIND MY GOAL
                    self.depth_search_limit(status, current_path, visited_nodes, dictionary_path)
        return visited_nodes





    def verifyPath(self, graph, destination, currentpath, root):
        for s in graph:
            root += s
            currentpath.append(root)

            

    def test_breadth_first_search (self):
        # from source to destination f
        graph = {"a": ["b", "c", "d"], "b": ["e"], "c": ["e"], "d": ["e"], "e": ["f"]}
        node_dest = "f"
        visited_nodes = list()
        visited_nodes.append("a")
        list_nodes = list(graph)
        find = True
        ts = self.visited_node(list_nodes.pop(0),graph, visited_nodes, node_dest, find)       
        while find:
            self.visited_node(visited_nodes[0][-1], graph, visited_nodes, node_dest, find)



    def visited_node(self, list_nodes, graph, visited_nodes, node_dest, find):
        # Visited nodes
        s = graph[list_nodes]
        # POP THE QUEEU FIFO AND APPEND THE COMBINATION OF THE NODES
        previous_nodes = visited_nodes.pop(0)
        for t in s:
            visited_nodes.append(previous_nodes+t)
            if t == node_dest:
                find = False
                print(previous_nodes+t)
                return find
        return visited_nodes
   

    



if __name__ == '__main__':
     f = Test_Depth_Limit()
     # f.test_breadth_first_search()
     path = [(1,2,3)]
     goal = [(3,2,1)]

     f.structure_node()