data TaskStatus = Todo | InProgress | Done
  deriving (Show, Eq)

-- HOURS TASK STATUS

--Your goal is to write functions that convert a list such as study_sessions
  -- into a list of effective study hours.
-- For each tuple (h, s), the output should contain:
--- h * status_multiplier s
-- For example: (2.0, Todo)
--means a study session of 2 hours for a task yet to start.





map_hours :: [(Float, TaskStatus)] -> [Float]
map_hours xs = map(\(h,s)-> h * status_multiplier s)xs


foldr_hours :: [(Float, TaskStatus)] -> [Float]
foldr_hours xs = foldr (\(h, s) acc -> h * status_multiplier s :acc ) [] xs

foldl_hours :: [(Float, TaskStatus)] -> [Float]
foldl_hours xs = foldl (\acc (h,s) -> h * status_multiplier s :acc ) [] xs

compr_hours :: [(Float, TaskStatus)] -> [Float]
compr_hours xs = [ h * status_multiplier s| (h,s)<-xs]


-- rec_hours :: [(Float, TaskStatus)] -> [Float]
-- rec_hours [] = acc
--- rec_hours ((h, s)acc) = h * status_multiplier s : rec_hours acc


status_multiplier :: TaskStatus -> Float
status_multiplier Todo       = 1.0
status_multiplier InProgress = 0.5
status_multiplier Done       = 0.0


--1. total_hours_curr                                    [2 marks]
  -- Write a function total_hours_curr that takes as input
   --the number of days (a Float) since the study plan started and
  --internally uses study_sessions from Task 2.
   --It should return the total effective hours for each session up to that day.

  -- Example:
  -- If days = 2, the first two result values should be:
--- [4.0, 1.0, ...]


study_sessions :: [(Float, TaskStatus)]
study_sessions =
  [ (2.0, Todo)
  , (1.0, InProgress)
  , (3.0, Done)
  , (4.0, Todo)
  ]

-- NUMBERS OF HOURS
sessions_log :: [Float]
sessions_log =
  [ 3.0
  , 0.5
  , 1.0
  , 2.0
  ]




-- TAIL LIST 
sumArray :: [Int] -> Int
sumArray xs = f xs 0       -- pass the list and an initial accumulator Composition funtion
  where
    f [] acc     = acc     -- base case: empty list returns the accumulator
    f (x:xs) acc = f xs (x + acc)  -- tail-recursive step xs is the paramter the other is the operations



sumListTail :: [Int] -> Int
sumListTail xs = sumTail xs 0
  where sumTail [] acc     = acc
        sumTail (x:xs) acc = sumTail xs (acc + x)



functionP :: Num a => a -> Int -> a
functionP f x = f



newSumList :: [Int] -> Int
newSumList xs = f xs 3
        where   
          f [] acc = acc
          f (x:xs) acc = f xs (x + acc)


data Team = Inter String String | Milan String String
            deriving(Show)
getNameTeam :: Team -> String
getNameTeam (Inter n __) = n


newSumTail :: [Int] -> Int
newSumTail  xs = f xs 0
        where f [] acc = acc 
              f (x:xs)acc = f xs (x + acc)

newSumTailNoH :: [Int] -> Int -> Int
newSumTailNoH [] acc = acc
newSumTailNoH (x:xs)acc = newSumTailNoH xs (x+acc)

noSumTail :: [Int] -> Int
noSumTail [] = 0
noSumTail (x:xs) = x + newSumTail xs


reverseTail :: [a] -> [a]
reverseTail xs = f xs []
where f [] acc = acc
reverseTail (x:xs)acc = f xs (x:acc)

rec_versionMy :: [Int] -> [Int] -> [Int]
rec_versionMy [] acc = acc
rec_versionMy (x:xs) acc
  | x `mod` 2 == 0 = rec_versionMy xs (x:acc)
  | otherwise      = rec_versionMy xs acc




  --------------------------------------------------
{-
Consider a function that takes a list of integers as input and
returns a list containing only the even numbers.
---

