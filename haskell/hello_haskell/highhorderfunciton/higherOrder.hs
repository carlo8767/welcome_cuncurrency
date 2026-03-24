-- FOLDR
addSumFoldRight :: [Int] -> Int
addSumFoldRight xs = foldr (+) 4 xs

-- FOLDL
addSumFoldLeft :: [Int] -> Int
addSumFoldLeft xs = foldl (+) 5 xs

--SUM VS SUM PRIME LESS MEMORY CONSUMPTION ->
-- addSumPrime :: [Int] -> Int
-- addSumPrime = foldl' (+) 0

--LOCAL BINDING USED IN ANOTHER EXPRESSION
squareSum :: Int -> Int -> Int 
squareSum x y = let    
                a = x * x
                b = y * y
                in a + b


--COMPHRENSION [ ( x , y ) | x <− [ 1 , 2 , 3 ] , y <− [ 4 , 5 ] ]
-- NESTED LOOP
squareXY :: Int -> Int -> [Int]
squareXY _ _ =  [ x^ y |x <- [1..3] , y <- [1..3]]

combining :: [Int] -> [Int]
combining xs = [n^3 | n <- xs ]


-- COMPHRENSION PREDICATES
combiningConditionsOdd :: [Int] -> [Int]
combiningConditionsOdd xs = [n^3 | n <- xs, odd n ]

-- COMPHRENSON STRING

-- COMPHRENSION ZIP ITEM
zipList :: [Int] -> [Int] -> [(Int, Int)]
zipList xs ts = zip xs ts 



foldAddSum :: [Int] -> Int -> [Int]
foldAddSum xs n = foldr (\elem acc -> (elem + n) : acc) [] xs

foldAssSumValue :: [Int] -> Int -> Int
foldAssSumValue xs n = foldr (\elem acc -> elem + acc) n xs

anotherFold :: [Int]  -> Int
anotherFold xs = foldr (\elem acc -> elem + acc ) 3 xs


anotherFolCond :: Int -> [Int] -> [Int]
anotherFolCond n xs =
    foldr (\elem acc -> if elem == n then elem : acc else acc) [] xs

anotherFolCondLeft :: Int -> [Int] -> [Int]
anotherFolCondLeft n xs =
    foldl(\elem acc -> if acc == n then acc : elem else elem) [] xs


sumListValue :: [Int] -> [Int]
sumListValue  xs = foldr (\elem acc-> (elem +1) : acc ) [] xs

sumListValueVary :: Int ->  [Int] -> Int
sumListValueVary p xs = foldr (\elem acc-> elem +acc ) p  xs

sumListInter :: [Int] -> Int
sumListInter  xs = sum xs



