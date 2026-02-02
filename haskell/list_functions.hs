-- example of pattern matching for a list type on the simple length function
my_length [] = 0
my_length (x:xs) = 1 + length xs

-- example of tail recursion in Haskell using reversing a list as an example
my_reverse l = my_reverse_aux l []

my_reverse_aux [] result = result
my_reverse_aux (x:xs) result = my_reverse_aux xs (x:result)

-- list cons syntax

create_list :[] list = list