-- 1. RECURSIVE FUNCTION ALWAYS PASS LIST IN COMPLEX
recursive_sum :: [Int] -> Int
recursive_sum [] = 0 -- BASE CASE 
recursive_sum (x:xs) = x + recursive_sum xs



-- count_even [1,2,3,4,6] = 3

count_even :: [Int] -> Int
count_even [] = 0
count_even (x:xs) | x  `mod` 2 == 0 = 1 + count_even xs
                  | otherwise = count_even xs


-- FOLDR ALWASY \elem acc FOLDL ALWASY \acc elem does not necessary apply the same name 

frecursive_sum :: [Int] -> Int
frecursive_sum xs = foldr (\elem acc -> acc + elem) 0 xs

frecursiveLeft :: [Int] -> Int
frecursiveLeft xs = foldl (\acc elem -> elem + acc) 0 xs

-- COMPHRENSION SUM SEPARATOR BETWEEN OUTPUT AND INPUT, RETURN A LIST ALWASY OR A TUPLE

compSum :: [Int] -> Int
compSum xs = sum [ x | x <- xs ]

--- CLASS NUM SPECIFY THE TYPE
numSum :: Num a => a -> a -> a
numSum a b = a + b

-- ISTANCE OF FRACTIONAL OTHERWISE RAIN AN ERROR
my_len :: Fractional a => [b] -> a
my_len [] = 0.0
my_len (x: xs) = 1 + (my_len xs)

-- TAIL RECURSIVE
length_rec :: [Int] -> Int
length_rec xs = helper xs 0
  where
    helper [] acc = acc
    helper (_:xs) acc = helper xs (acc + 1)



data RateUnit = Weekly | Daily
  deriving (Show)

conv :: RateUnit -> Float
conv Daily  = 1.0
conv Weekly = 1 / 7

habits_rate :: [(Float, RateUnit)]
habits_rate =
  [ (1.0, Daily)
  , (3.0, Weekly)
  , (1.0, Weekly)
  , (3.0, Weekly)
  ]

 -- In other words, for each tuple (r, ru), the output should contain:
-- r * conv ru

daily_frequency :: [(Float, RateUnit)] -> [Float]
daily_frequency xs = map (\(r, ru) -> r * conv ru) xs


-- f ((a,b):xs) = ... For tuple
-- list f [] = ...f (x:xs) = ... x ... f xs
rec_daily_frequency :: [(Float, RateUnit)] -> [Float]
rec_daily_frequency [] = []
rec_daily_frequency ((r, ru):xs) = r * conv ru : rec_daily_frequency xs

recMap :: [(Float, RateUnit)] -> [Float]
recMap xs = map (\(p, ru) -> p * conv ru) xs

recFold :: [(Float, RateUnit)] -> [Float] 
recFold xs = foldr(\(p,ru) acc -> p * conv ru : acc )[] xs


-- MAX TOTAL
safeMaximum :: Ord a => [a] -> Maybe a
safeMaximum [] = Nothing
safeMaximum xs = Just (maximum xs)

safeMaximum2 :: Ord a => [a] -> Either String a
safeMaximum2 [] = Left "empty list"
safeMaximum2 xs = Right (maximum xs)




-- DATA TYPE
data Football = Inter String Int
                deriving(Show)
getFootball :: Football -> String
getFootball (Inter n _) = n

-- CONCATENATE LIST

concatenateList :: [Int] ->  [Int] -> [Int]
concatenateList xs ys = xs ++ ys

-- EVEN
evenFoldr :: [Int] -> [Int]
evenFoldr xs = foldr(\elem acc -> if even elem then elem : acc else acc  ) [] xs

evenFoldl :: [Int] -> [Int]
evenFoldl xs = foldl(\acc elem -> if even elem then elem : acc else acc  ) [] xs

recursEvenTail :: [Int] -> [Int]
recursEvenTail xs = f xs []
              where f [] acc = acc
                    f (x:xs)acc = if even x then f xs (x:acc) else f xs acc


recursEven :: [Int] -> [Int]
recursEven xs = f xs 
              where f [] = []
                    f (x:xs) = if even x then x : recursEven xs
                               else f xs


recursEvenMeth :: [Int] -> [Int]
recursEvenMeth xs = f xs 
              where f [] = []
                    f (x:xs) = if even x then x : recursEven xs
                               else f xs
                               

recursEvenMethMet :: [Int] -> [Int]
recursEvenMethMet xs = f xs 
              where f [] = []
                    f (x:xs) = if even x then x : recursEven xs
                               else f xs


addIfEven :: Int -> [Int] -> [Int]
addIfEven x aList
  | even x    = x : aList
  | otherwise = aList

appendIfEven :: Int -> [Int] -> [Int]
appendIfEven x aList
  | even x    = aList ++ [x]
  | otherwise = aList

-- ANALYSE TEXT

-- (numberOfWords, numberOfUppercaseLetters, numberOfDigits)
analyzeText :: String -> Int
analyzeText xs = sum ([1| x <- xs])

