
data VOTE = GREATER| LESSER| EQUALS
            deriving(Show)

-- COMPARE ORDER
compareArguments :: Int -> Int -> VOTE
compareArguments x y| x < y = LESSER
                    | x == y = EQUALS
                    | x > y = GREATER 

data Student = Student {name::String, id::String, year_joiner::Int, programme::String }
                deriving(Show)


insertStudent :: Student -> [Student] -> [Student] 
insertStudent s xs = s:


data Tree = Tree