-- example of pattern matching for a list type on the simple length function
my_length [] = 0
my_length (x:xs) = 1 + length xs

-- example of tail recursion in Haskell using reversing a list as an example
my_reverse l = my_reverse_aux l []

my_reverse_aux [] result = result
my_reverse_aux (x:xs) result = my_reverse_aux xs (x:result)

-- list cons syntax
create_list :: [Int] -> [Int]
create_list (x:xs) = x : xs  -- just return the same list


--concatenate one element
append_element :: ([Int] , [Int])  -> [Int] 
append_element ([x], [b]) =  [x] ++ [b]


--recursevely one element
append :: Int -> [Int] -> [Int]
append a [] = [a]
append a (x:xs) = x : append a xs


-- conditional_statement
odd_event :: Int -> String
odd_event (val)= if val `mod` 2 == 0
            then n
            else y
            where n = "even"
                  y = "odd"

-- recursevely sum three
sumThreeRec :: Int -> Int 
sumThreeRec (x) =  x + kn
                where kn = 3




