
-- PASS A FUNCTION AS PARAMETER

reversedList :: ([a] -> [a]) -> [a] -> [a]
reversedList f xs = f xs

list_even_reverse :: [Int] -> ([Int] -> [Int]) -> [Int]
list_even_reverse xs f =
  f (foldr (\x acc -> if x `mod` 2 == 0 then x : acc else acc) [] xs)


-- LIST APPLY -- SPECIFY FUNCITON TYPE ([a]-> [a]) 
applyToList :: ([a]-> [a]) -> [a] -> [a]
applyToList f xs = f xs


oddThen :: [Int] -> ([Int] -> [Int]) -> [Int]
oddThen xs ff = ff (f xs)
  where
    f [] = []                           -- base case: empty list
    f (x:xs)
      | odd x   = x : f xs            -- keep odd numbers
      | otherwise = f xs                -- skip even numbers


-- FIND N ELEMENT FROM THE LIST
elementAt :: Int -> [Int] -> Int
elementAt n (x:xs)
    | n == 1    = x
    | n > 1     = elementAt (n-1) xs
    | otherwise = error "Index out of bounds"


addElement :: [Int] -> [Int]
addElement xs = let 
              y = 6
           in  xs ++ [y]

type Student = (String, [Int])
students :: [Student]
students =
  [ ("Alice", [12, 15, 14])
  , ("Bob", [9, 10, 8])
  , ("Charlie", [16, 18, 17])
  ]

averageSum :: [Int]  -> Int
averageSum xs = f xs 0
  where
    f [] acc = acc
    f (x:xs) acc = f xs (acc + x)

averageList :: [Int] -> Double
averageList [] = 0
averageList xs = fromIntegral (averageSum xs) / fromIntegral (length xs)


--RECURSION FUNCTION https://notes.tonyballantyne.com/Haskell/Recursive+Functions+in+Haskell
getEven :: [Int] -> [Int]
getEven xs = f xs 
             where 
              f []  = [] 
              f (x:xs) 
                 | even x  = x : f xs 
                 | otherwise = f xs 

sumList :: [Int] -> Int
sumList xs = f xs 
     where
      f [] = 0
      f (x:xs) = x + f xs 

-- EXTRACT AND PERFORM
lengthList :: [a] -> Int
lengthList xs = f xs 
        where
        f [] = 0
        f (x:xs) = 1 + f xs

reverseList :: [a] -> [a]
reverseList xs = f xs 
  where 
    f [] = []
    f (x:xs) = f xs ++ [x]

contains :: Int -> [Int] -> Bool
contains n xs = f n xs
  where
    f n [] = False
    f n (x:xs)
      | n == x    = True
      | otherwise = f n xs

containsSimple :: Int -> [Int] -> Bool
containsSimple n (x:xs) | x == n = True
                        | otherwise = containsSimple n xs

eitherEx :: Int -> Either Int Int
eitherEx 0 = Left 0
eitherEx x = Right x

adjustNo :: Int -> [Int] -> [Int]
adjustNo _ [] = []
adjustNo n (x:xs) | n > x   =  (  x + n) : adjustNo n xs
                  | otherwise = ( x - n ) : adjustNo n xs


-- adjustNTimes :: Int -> [Int] -> [Int]
-- adjustNTimes 0 xs = xs
-- adjustNTimes n xs = adjustNTimes (n - 1) (adjustNo n xs)


adjustNTimes :: Int -> [Int] -> [Int]
adjustNTimes n xs = helper n xs --- YOU CAN CREATE AN ADDITIONAL VALUE go` is a local helper function
  where
    helper 0 ys = ys
    helper k ys = helper (k - 1) (adjustNo n ys)


recurviseEvenk :: [Int] -> [Int]
recurviseEvenk xs = f xs 
              where
                f [] = []
                f (x:xs) | even x = x : f xs
                         | otherwise = f xs

-- DIVIDE BY SEVEN

listNumber :: [Int] -> [Double]
listNumber xs = map (\x -> fromIntegral x / 7)xs
 

-- MULTIPLE OF SIX
listMultipleSix :: [Int] -> [Int]
listMultipleSix  xs = filter(\x -> x `mod` 6 ==0)xs


-- COMPOSITE FUNCTION
squareNumber :: [Int] -> [Int]
squareNumber  = map (\x -> x * x) . filter (\x -> x `mod` 2 > 0)
 


 -- MULTIPLE DIVISION USING COMPOSITION
multipleTwoThree :: [Int] -> [Int]
multipleTwoThree  = filter (\x -> x `mod` 3 == 0) . filter (\x -> x `mod` 2 > 0)


--- MAP EVEN ANONYMOUS FUNCTION
mapEven :: [Int] -> [Int]
mapEven xs = map (\x -> x * x) (filter even xs)

mapComphrensionEvent :: [Int] -> [Int]
mapComphrensionEvent xs = [x^2 | x <-xs , even x ]



tupleMap :: [(Int, Int)] -> [Int]
tupleMap = map (\(x, y) -> x * y)


recursiveListEvent :: [Int] -> [Int]
recursiveListEvent xs = f xs 
              where f [] = []
                    f (x:xs) = if even x then x * x  : f xs 
                               else f xs 



recursiveTuple :: [(Int, Int)] -> [Int]
recursiveTuple xs = f xs []
  where
    f [] acc =  reverse acc
    f ((x,y):rest) acc = if even (x * y) then f rest ((x * y) : acc)
                else f rest acc



add_elementList :: [Int] -> Int -> [Int]
add_elementList xs a = [a] ++ xs 



reverseFunction :: ([Int]-> [Int])-> [Int] -> [Int]
reverseFunction f xs = f xs