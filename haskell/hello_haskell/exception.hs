--
import Control.Exception

age2String :: Int -> String
age2String n | n < 25 = "You are young"
             | otherwise = "You are old"

-- YOU CAN ADD THE HANDLER ERROR CALL: with CATCH




--main :: IO ()
--main = 
  --  do
    ---    putStrLn "Wahat is your age ?"
     --- :  x <- getLine
      ---  let age = read x
       --- putStrLn ("Thanks!!")
       --- putStrLn(age2String age)

        --- reload  <>


-- FUNCTION AS PARAMETERT

sumFunction :: (Int -> Int -> Int) -> Int -> Int -> Int
sumFunction f x y = f x  y

ordMax :: (Int -> Int -> Int) -> [Int] -> Int
ordMax f (x:xs)  = foldl f x xs




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