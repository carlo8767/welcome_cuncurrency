data Unit = Daily | Weekly | Monthly
  deriving (Show)

convUnit :: Unit -> Float
convUnit Daily   = 1.0
convUnit Weekly  = 1/7
convUnit Monthly = 1/30

habits :: [(Float, Unit)]
habits = [(1.0, Daily), (2.0, Weekly), (3.0, Monthly)]

--- Goal: Write functions that convert `habits` into daily 
--- frequencies `r * convUnit u`.

-- FORGOT RECURSION FLOAT FORGET 
 -- MAP only pharentis ()
-- recFreq :: [(Float, Unit)] -> [[(Float, Unit)]]
-- recFreq [()] = []
--- recFreq (a , b) = a * recFreq (convUnit b)


recursiveFreq :: [(Float, Unit)] -> [Float]
recursiveFreq (r,u) = f (r,u) 0.0
            where f (r,u) acc = acc
                  f (r,u) acc =  f acc : (r * convUnit u )



          
foldrFreq :: [(Float, Unit)] -> [Float]
foldrFreq xs = foldr (\(r,u) acc -> r * (convUnit u):acc ) [] xs

foldlFreq :: [(Float, Unit)] -> [Float]
foldlFreq xs = foldl (\acc (r,u)  -> r * (convUnit u):acc ) [] xs

--- ONLY PARANTHESIS !
mapFreq :: [(Float, Unit)] -> [Float]
mapFreq xs = map(\(r,u) -> r * convUnit u)xs

-- COMPHRENSION ONLY | !
comprFreq :: [(Float, Unit)] -> [Float]
comprFreq  xs = [r * convUnit u | (r,u) <- xs ]




--- 1. Implement `applyNTimes :: Int -> (a -> a) -> a -> a` [5 marks]
---Applies a function `n` times to a value.
---applyNTimes:: Int -> (a->a) -> a -> a
--- applyNTimes _ = 0
--- applyNTimes x = applyNTimes x-1


-- LIST LENGHT RECURSIVE
len :: [a] -> Int
len [] = 0
len xs = 1 + len xs 





