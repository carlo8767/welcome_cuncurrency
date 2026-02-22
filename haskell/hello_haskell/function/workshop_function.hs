
-- USE TAKE
useTake :: Int -> [x] -> [x]
useTake n xs = take n xs

-- USE DROP
useDrop :: Int -> [x] -> [x]
useDrop r xs = drop r xs

-- USING INIT
useInit :: [x] -> [x] 
useInit xs = init xs

-- SPLIT LIST IN TWO PART
splitList ::Int -> [x] -> ([x], [x])
splitList n xs = (take n xs, drop n xs)

-- NON PARTIAL OPERATOR
sumNumList :: Int -> [Int] -> [Int]
sumNumList n xs = map (\x -> x + n) xs

-- PARTIAL OPERATOR APPLICATION
sumNumListPartial :: Int -> [Int] -> [Int]
sumNumListPartial n xs = map (+ n) xs


--RECIPROCAL 
reciprocal :: Float ->  Float
reciprocal x  =  1 /x 

-- GRADE FUNCTIONS
gradeStudent :: Int -> String
gradeStudent (x)    | x>= 90 && x <= 100 = "A"
                    | x>= 80 && x <= 89 = "B"
                    | x>= 70 && x <= 79 = "C"
                    | x>= 60 && x <= 69 = "D"
                    | x<60 = "F"
                    | otherwise =  error "ERROR"


multiply :: Int -> Int -> Int -> Int
multiply x y z = x * y * z

doubleAndMultiply ::  Int -> Int -> Int -> Int
doubleAndMultiply x y z = multiply (x * x) y z

